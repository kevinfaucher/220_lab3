#include "Game.hpp"
#include <cstdlib>
#include <iostream>
using namespace std;

//    This constructor asks for user input (cin) to determine the size of the 
//gameboard, the number of 
//    and the number of players who are computers (automated).  
//It then sets the size, numplayers, and 
//    compplayers and calls the makeBoard method to create the board, 
//calls the getPlayers function to 
//    create an array of pointers to Player objects, 
//sets turn to 0 (for the index of teh current player's
//    turn), and sets won to be false.

Game::Game() {
    // for non-automatized version - asks for board size, num players, 
    //num of computer players, and then initializes
    // everything
    cout << "Please enter the size of the board: " << endl;
    cin >> size;
    cout << "Please enter the number of players: " << endl;
    cin >> numPlayers;
    cout << "Please enter the number of computer players: " << endl;
    cin >> compplayers;
    turn = 0; //set turn to 0
    won = false; //sets won to false
    makeBoard(); //call the makeBoard function
    getPlayers(); //call the getPlayers function

}//Game

//    This constructor takes as input a boolean value indicating whether 
//the game is completely automated
//    or not.  If the game is automated (true boolean value), 
//the numplayers and the compplayers are both
//    set to 2 (meaning that there are 2 players, 
//and they're both automatic, not human).  The board is 
//    matrix is created as a random square size between 3 and 11 and 
//calling makeBoard()), turn is set 
//    to 0 (the first player), won is set to false, and the 
//getPlayers function is called to create an array
//    of pointers to Player objects.
//    If the game is not automated (boolean value is false), 
//the Game() constructor is called.
//   This constructor is awesome for testing and for working
//on Artificial Intelligence. 

Game::Game(bool b) {
    //for the automated version - if b is true, 
    //randomly generate the size of the board, set the num of players and the
    //num of compplayers to 2, and the, of course initialize everything

    //check if b is true
    if (b)//if true then that means the game is fully automated
    {
        //if game is fully automated, the set numPlayers and compPlayers to 2
        numPlayers = 2;
        compplayers = 2;
        //now set size as a random number between 3 and 11
        size = rand() % 11 + 3; //random board size. here it should be +3 as size
        //starts from 3 and not from 1
        //after size is set we call the makeBoard()
        makeBoard();
        turn = 0; //turn is set to 0
        won = false//won is set to false
                getPlayers(); //getPlayers is called
    } else {
        //if the game is not fully automated, then simply call the constructor Game()
        Game();
    }
}//Game

void Game::makeBoard() {
    // dynamically generates the board to be size by size,
    //with each cell initially set to '.'
    //your code goes here
    board = new char*[size];
    for (int i = 0; i < size; i++) {
        board[i] = new char[size];
        for (int j = 0; j < size; j++) {
            board[i][j] = '.';
        }
    }
}//makeBoard

void Game::printBoard() {
    //Note: I'm giving you this one
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            cout << board[i][j] << "\t";
        }
        cout << endl;
    }
}//printBoard


//   This method sets up the dynamically created array of Players (players array).  
//   I did this by including an array of names that was as long as the maximum 
//number of players I could have in the 
//   game, and an equally long array of characters for those players.  
//   This function then dynamically allocated an array of players, and for 
//each computer player (compplayers) it 
//   created a new player object with a name from the name array and a
//character from the character array.  It then
//  initialized each human player by asking (cout) for the player’s name and 
//reading it in (cin) and then asking for the
// player’s character and reading that in, and then creating a
//new player for the player array.

void Game::getPlayers() {
    //This method dynamically generates an array of players, and then, 
    //for each element in the array, creates a new 
    //player object with a name and a character.  
    //For the number of players that are computers, I used an array of names
    // and an array of characters, and then just selected the next name 
    //and character in the list for my player object.
    // for humans I called the Player constructor with no 
    //input parameters (that one asked the user for their name and 
    // their preferec character.

    //first create players for compPlayers
    //it is given in the instruction to use an array of names.
    string compplayerNames = new string[compplayers]; //create an array to fill names
    //array size equals number of compPlayers

    char compplayerChar = new char[compplayers]; //create an array to fill chars to fill the board
    //this array size again equals number of compPlayers

    //fill these two arrays now
    //declare a char here
    char c = 'A'; //c starts with A
    for (int i = 0; i < compplayers; i++)//loop from 0 to number of players
    {
        compplayerNames[i] = "CP" + to_string(i + 1); //to_string() function will convert
        //integer value to string. it is an inbuilt function
        //so when you call it, it converts 1,2,3 to string and set names as CP1,CP2...

        compplayerChar[i] = c; //set c
        c++; //increment c for next letter
    }


    //declare an integer to get total number of objects we are to create
    int totalPlayers = numPlayers + compplayers; //total players is sum of human players and compPlayers

    //now we need to create an array of objects to class Player
    Player* myPlayers = new Player[totalPlayers]; //create an array of player objects
    //whose size is equal to totalPlayers

    //now let us create human players first
    int plIndex = 0; //declare integer for playerIndex

    for (plIndex = 0; plIndex < numPlayers; plIndex++) {
        myPlayers[plIndex] = new Player(); //create new Player object with default constructor
    }

    //now plIndex holds array index.. so you need not have to initialize it 
    // one more time in the coming for loop
    for (int k = 0; plIndex < totalPlayers; plIndex++, k++)//k is the variable to get compPlayerName from the array
    {
        myPlayers[plIndex] = new Player(compplayerNames[k], compplayerChar[k], true);
    }
}

void Game::printPlayers() {
    // this method is optional – I wrote it so I could test my getPlayers() method to make sure it generated all my Players
    // correctly.  If you choose not to include this method, that is fine.
	for (int i = 0; i < numPlayers; i++){
	        cout << (*players[i]).name << endl;
}

void Game::playGame() {
    // This is the heart of the game.  I called this method directly from my Game constructor(s) as the very last thing.
    //This method loops until the board is full.  
    // In each loop, the next player either chooses where to place their character (if human) or the x,y coordinates are 
    // randomly generated (and checked to make sure the player isn’t overwriting a piece already on the board).
    //It checks to see if the new piece completes a square, and, if so, that player’s score goes up by 1 and that player 
    // takes another turn.  At the end of each round, the board is printed out and each player’s name and score is printed.

    //Your code goes here

    //Note: for the extra credit version, the findMoves method returns a dynamically created array of 3 different moveLists. 
    // The first of the 3  contains the list of moves that would complete a square. The second of the 3 contains a list of 
    // neutral moves, and the third of the 3 contains the list of moves that place a third corner on a square (which are bad 
    // moves because the next player will then be able to complete a square.
    // In this version, the next move is chosen by first trying to pick (randomly) among potential moves that would 
    // complete a square, and then by trying to pick a move that is, in essence, neutral, and then last, it chooses from the
    // list of bad moves as a last resort.
}

bool Game::findMoves(char v) {
    //    Regular version, this method continues to generate random x,y values until that cell on the
    //    board is empty, then places the player's character v on the board, and checks to see if a 
    //    square is completed using checkFour.  If so, true is returned and that player's score goes up by 1 in the
    //    playGame method, and that player gets to take another turn (so turn does not increase by 1).  
    int playerIndex;
    bool placed = false;
    //finds index of player playing
    for (int i = 0; i < numPlayers; i++) {
        if ((*players[i]).c == v) {
            playerIndex = i;
        }
    }
    int xval = rand() % size;
    int yval = rand() % size;
    for (int i = 0; i < 100; i++) {
        if (board[xval][yval] == '.') {
            board[xval][yval] = v;
            placed = true;
            if (checkFour(xval, yval) == 1) {
                (*players[playerIndex]).score++;
                findMoves(v);
            } else {
                break;
            }
        }
        xval = rand() % size;
        yval = rand() % size;
    }
    //100 tries to randomly generate values and place on an empty space
    if (placed == false) { //if no empty spaces found we iterate through entire board sequentially
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                if (board[xval][yval] == '.') {
                    board[xval][yval] = v;
                    placed = true;
                    if (checkFour(xval, yval) == 1) {
                        (*players[playerIndex]).score++;
                        findMoves(v);
                    } else {
                        break;
                    }
                }
            }
        }
    }
    // movesList * Game::findMoves(char v) {
    // The extra credit version of this method - this method dynamically creates a list of 3 movesList objects.  It then goes
    // through the entire board and classifies each possible move left on the board as being either good (will complete a 
    // square, in which case it's added to the new list of movesLists at [0], neutral (doesn't do anything), in which it's
    // added to the second of the movesLists, or bad (3/4 of a square), in which case it's added to the third of the
    // movesLists.
    // This method uses checkFour() method to determine whether a move is good, checkThree to determine if a move is
    // bad, and if neither of those is true, then the move is considered neutral.
    // This method returns the list of three movesList objects.
}//findMoves

bool Game::checkFour(int x, int y) {
    string potChars = ""; //make list of characters in use
    string compChars[] = {"a", "b", "c", "d", "e"};
    for (int i = 0; i < compplayers; i++) {
        potChars += (compChars[i]);
    }
    for (int i = compplayers; i < numPlayers; i++) {
        potChars += (*players[i]).c;
    }
    cout << (board[x][y] == '.');
    if ((potChars.find(board[x - 1][y - 1]) != std::string::npos) && (potChars.find(board[x][y - 1]) != std::string::npos) && (potChars.find(board[x - 1][y]) != std::string::npos)) {
        return true;
    } else if ((potChars.find(board[x + 1][y - 1]) != std::string::npos) && (potChars.find(board[x][y - 1]) != std::string::npos) && (potChars.find(board[x + 1][y]) != std::string::npos)) {
        return true;
    }
    else if ((potChars.find(board[x + 1][y + 1]) != std::string::npos) && (potChars.find(board[x][y + 1]) != std::string::npos) && (potChars.find(board[x + 1][y]) != std::string::npos)) {
        return true;
    } else if ((potChars.find(board[x - 1][y + 1]) != std::string::npos) && (potChars.find(board[x][y + 1]) != std::string::npos) && (potChars.find(board[x - 1][y]) != std::string::npos)) {
        return true;
    } else {
        return false;
    }
    // this method checks to see if placing a piece at x and y on the board will complete a square, and, if so, it
    // returns true.  Otherwise it returns false.
}//checkFour

void Game::getWinner() {
    int highestScore = -1;
    int indexOfWinner;
    for (int i = 0; i < numPlayers; i++) {
        if ((*players[i]).score > highestScore) {
            highestScore = (*players[i]).score;
        }//if
    }//for
    for (int i = 0; i < numPlayers; i++) {
        if ((*players[i]).score == highestScore) {
            cout << "Winner: " << (*players[i]).name << "!" << endl;
        }
    }
    //multiple players printed in the case of a tie
    // This method determines which of the players in the array of Players has the highest score, and prints out 
    // that player's name and their score.
}//getWinner

bool Game::checkThree(int x, int y) {
    // Only needed for Extra Credit
    // This method determines whether placing a piece on the board at x and y will complete ¾ of a square and, if so, it 
    // returns true.  Otherwise it returns false.
}
