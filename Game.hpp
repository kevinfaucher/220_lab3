#ifndef GAME_HPP
#define GAME_HPP
#include "Player.hpp"


class Game {
    char ** board;  // the gameboard, will be initialized to size x size characters in makeBoard()
    // The board size should be anywhere between 3x3 and 11x11 
    // that size is set in the field below.

    int size;  // the size of the board matrix (it's a size x size matrix)
    int numPlayers;  // the number of players (must be between 2 and 5)
    Player **players;  // an array of pointers to Player objects, or the array of players of the game
    int turn;  // indicating which player's turn it is (the index into the players array)
    bool boardFull; //for whether the board is full or not (whether there are more moves)
    int compplayers;  // for the number of automated (computer) players, used when initializing the game


public:

    Game();
//    This constructor asks for user input (cin) to determine the size of the gameboard, the number of 
//    and the number of players who are computers (automated).  It then sets the size, numplayers, and 
//    compplayers and calls the makeBoard method to create the board, calls the getPlayers function to 
//    create an array of pointers to Player objects, sets turn to 0 (for the index of teh current player's
//    turn), and sets won to be false.

    Game(bool);
//    This constructor takes as input a boolean value indicating whether the game is completely automated
//    or not.  If the game is automated (true boolean value), the numplayers and the compplayers are both
//    set to 2 (meaning that there are 2 players, and they're both automatic, not human).  The board is 
//    matrix is created as a random square size between 3 and 11 and calling makeBoard()), turn is set 
//    to 0 (the first player), won is set to false, and the getPlayers function is called to create an array
//    of pointers to Player objects.
//    If the game is not automated (boolean value is false), the Game() constructor is called.
//   This constructor is awesome for testing and for working on Artificial Intelligence.  

    void makeBoard();
//    Creates the board to be a matrix of size x size chars, and fills each cell in the matrix with a '.';

    void printBoard();
//    Prints the board, with each character in a row printed out, separated by a tab ('\t').  
//    Right after the makeBoard() method is called, the board should be sizexsize .'s
//    e.g.,
//    .   .   .   .   .
//    .   .   .   .   .
//    .   .   .   .   .
//    .   .   .   .   .
    
    void getPlayers(); 
//   This method sets up the dynamically created array of Players (players array).  
//   I did this by including an array of names that was as long as the maximum number of players I could have in the 
//   game, and an equally long array of characters for those players.  
//   This function then dynamically allocated an array of players, and for each computer player (compplayers) it 
//   created a new player object with a name from the name array and a character from the character array.  It then
//  initialized each human player by asking (cout) for the player’s name and reading it in (cin) and then asking for the
// player’s character and reading that in, and then creating a new player for the player array.

    void printPlayers(); 
//      This method's sole purpose was to make sure that initializing array of pointers to Players worked
//      You may choose not to implement it - but then you need to be confident that your getPlayers() method worked.  
 
    void playGame();
//    This method is called from the Game() constructors last - it is what starts the playing of the game, and it 
//    continues until the board is full (there are no '.' characters left on the board and boardFull is false.
//    While the board loops, it calls the findMoves method to find the next move a player in the game is going to make.   It then calls the checkWin() method to determine who won and prints out 
//    the winner (Note that this method prints out the board after each player's turn, as well as each player's score
//    so far, so you can watch the game progress).
    
 //   bool findMoves(char v);
//    Regular version, this method continues to generate random x,y values until that cell on the
//    board is empty, then places the player's character v on the board, and checks to see if a 
//    square is completed using checkFour.  If so, true is returned and that player’s score goes up by 1 in the 
//    playGame method, and that player gets to take another turn (so turn does not increase by 1).  Otherwise turn 
//    increases so that it becomes the next player’s turn (turn must loop back to 0 when it gets to be >= numPlayers)  
    
    bool findMoves(char v);
    //Extra Credit Version of findMoves:
    //This method dynamically creates and returns a list of 3 movesList objects
    // the first movesList is for the moves that have highest priority (would complete
    // a square for the player.
    // the second movesList is for the moves that have medium priority (relatively neutral 
    // moves
    // the third movesList is for moves that are notably bad (would create 3 out of 
    // four sides of a square, thus allowing the next player to complete a square
    
    bool checkFour(int x, int y);
    //This method checks to see if adding the character v to the cell x,y in the board will complete a square, and, if
    // so, returns true 
    //In the regular, this will result in the score of player[turn] going up by one and player[turn]'s character being 
    //added to the board at x,y
    //In the Extra Credit, (this will lead to findMoves adding this cell to the MovesList object (e.g., 
    //allMovesls[0].potentialMoves[allMovesls.numMoves].resetCell(x,y,v);
    
    void getWinner();
    // When the board is full, this method finds which player has the highest score, and is thus the winner
    
    
    /************* This method is only necessary for the AI Extra Credit *******************/
    bool checkThree(int x, int y);
    //This method checks to see if adding the character v to the cell x,y in the board will create 3/4 of a square, and, if
    // so, returns true (this will lead to findMoves adding this cell to the MovesList object (e.g., 
    //allMovesls[2].potentialMoves[allMovesls.numMoves].resetCell(x,y,v);
    
};

#endif /* GAME_HPP */