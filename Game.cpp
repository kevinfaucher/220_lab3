#include "Game.hpp"
#include <cstdlib>
#include <iostream>
#include <time.h>
using namespace std;

Game::Game() {  
//Game constructor for non-automatized version - asks for board size, num players, num of computer players, and then initializes
//everything
    cout << "Dots and Boxes" << endl;
    cout << "Please enter the board size: ";
    cin >> size;
    cout << "Please enter the total amount of players: ";
    cin >> numPlayers;
    cout << "How many of the total players are AI: ";
    cin >> compplayers;
    boardFull = false;
    turn = 0;
    if (boardFull == false){ //should always be true
        makeBoard();   
        printBoard();
        getPlayers();  
        printPlayers();
        playGame();    
    } 
}//Game

Game::Game(bool b) {
//Game constructor for the automated game version - if b is true, randomly generate the size of the board, set the num of players and the
//num of compplayers to 2, and the, of course initialize everything
    if (b==1){  //as long as b is true we initialize appropriate values
        cout << "Dots and Boxes (AI)" << endl;
        srand(time(NULL));
        size = rand()%9+3;
        numPlayers = 2;
        compplayers = 2;
        boardFull = false;
        turn = 0;
    }
    if (boardFull == false){ //should always be true
        makeBoard();    
        printBoard();   
        cout << endl;
        getPlayers();  
        printPlayers();
        playGame();    
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
//Note: I'm giving you this one. This function prints the board by iterating with a for loop. Nothing is input and nothing is returned.
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            cout << board[i][j]<<"\t";
        }
        cout << endl << endl;   //added another print line for better spacing
    }
}//printBoard

void Game::getPlayers() {
    //This method dynamically generates an array of players, and then, for each element in the array, creates a new 
    //player object with a name and a character.  For the number of players that are computers, I used an array of names
    // and an array of characters, and then just selected the next name and character in the list for my player object.
    // for humans I called the Player constructor with no input parameters (that one asked the user for their name and 
    // their preferred character.
    string compPlayerNames[] = {"PLAYER1", "PLAYER2", "PLAYER3", "PLAYER4", "PLAYER5"};
    char compplayerChar[] = {'A', 'B', 'C', 'D', 'E'};
    players = NULL;
    int cp = compplayers;
    players = new Player*[numPlayers];
    for (int i = 0; i < numPlayers; i++) {
        if (cp > 0) {
            players[i] = new Player(compPlayerNames[i], compplayerChar[i], 1);
            cp--;
        } else {
            players[i] = new Player();
        }
    }
}//getPlayers

void Game::printPlayers() {
    // this method is optional – I wrote it so I could test my getPlayers() method to make sure it generated all my Players
    // correctly.  If you choose not to include this method, that is fine.
    for (int i = 0; i < numPlayers; i++) {
        cout << (*players[i]).name << endl;
    }
}

void Game::playGame() {

//The function checks to see if the new piece completes a square, and, if so, that player's score goes up by 1 and that player
// takes another turn.  At the end of each round, the board is printed out and each player's name and score is printed.
//The chance to play another game is also offered.
    
    //Keeps track of the number of game loops
    int numGameIterations = 0;   
    
    //x and y values are set to one initially
    int xvalue = -1;   
    int yvalue = -1;
    
    //Continue the game variable--for coordinate placement
    bool gameContinue = true;       
    
    //Initally player placement condition is set to true
    bool initPlace = true;     
    
    int playMore; 
    int matrixSize = size*size;
    //Keep going as long as there are spaces on the board
    while (numGameIterations < matrixSize){ 
        
        //Check to see if it is an AI player
        if ((*players[turn]).isComputer == true){   
            
            //If the continue var is true and the AI completes a square
            //Update loop iterations and continue var
            while (gameContinue == true){  
                if (findMoves((*players[turn]).c) == true){ 
                    numGameIterations++; 
                    if (numGameIterations == matrixSize){ 
                        gameContinue = false;  
                    }
                }
                else{  
                    numGameIterations = numGameIterations + 1;
                    gameContinue = false;   
                    printPlayers();     
                }       
            }
        }
        //Condition for if it is human player's turn
        else{  
            while (gameContinue == true){   
                //Check to see if they can keep placing and what to do if they can
                
                while (initPlace == true || xvalue >= size || yvalue >= size || xvalue < 0 || yvalue < 0 || board[yvalue][xvalue] != '.' ){    //as long as they start placing or do not choose an appropriate placement; we ask for input coordinates
                    cout << (*players[turn]).name << " Enter your x value coordinate: ";
                    cin >> xvalue; 
                    cout << " Now enter your y value coordinate";
                    cin >> yvalue;
                    //This is no longer the first placement on the board, setting the boolean accordingly
                    initPlace = false;
                }
                //Fill in the location of the board based on player input
                board[yvalue][xvalue] = (*players[turn]).c;  
                
                
                //Checking if a player completed a square
                if (checkFour(yvalue, xvalue) == true){   
                    
                    //Give the player a point if they make a square
                    (*players[turn]).score++;
                    cout << endl << "Score +1 for Player " << (*players[turn]).name << endl;    //score + 1 printed
                    
                    //Display the updated game board and player info
                    printBoard();
                    printPlayers();
                    numGameIterations = numGameIterations + 1;      
                    
                    
                    if (numGameIterations == matrixSize){ 
                        gameContinue = false;   
                    }
                }
                else{   
                    //if a player does not complete a square the turn var is incremented
                    turn = turn + 1; 
                    
                    //cycle back through turns 
                    if (turn == numPlayers){    
                        turn = 0;
                    }
                    numGameIterations = numGameIterations + 1;
                    gameContinue = false;  
                    
                    //Display the board and player info
                    printBoard();   
                    printPlayers(); 
                }
            }
        }
        gameContinue = true; 
    }
    //When there are no more spaces on the matrix call getWinner to output which player won
    getWinner();    
    
    //Determine if the player want to play again
    cout << "\nEnter '1' to play again, '2' to watch a computer match or "<< endl << " '3' to stop playing";
    cin >> playMore;
    
    //PvC or PVP match
    if (playMore == 1){    
        cout << endl;
        //Call non automated match contructor
        Game game; 
    }
    if (playMore == 2){    //AI game started; useful for testing
        cout << endl;
        Game(1);
    }
    boardFull = true;   
}

bool Game::findMoves(char v){
    
    //Var to keep track of the index of the player
    int indexP;
    
    //Var to check if placed
    bool set = false;
    
    //Locates player index
    for (int i = 0; i < numPlayers; i++){   
        if ((*players[i]).c == v){          
            indexP = i;                
        }
    }
    
    //Generate random x and y values for AI
    int ranXval = rand()%size;               
    int ranYval = rand()%size;
    
    for (int i = 0; i < size*size; i++){      
        
        //find an open spot on the board
        if (board[ranYval][ranXval] == '.'){ 
           
            //set down there
            board[ranYval][ranXval] = v;      
            set = true;
            if (checkFour(ranYval, ranXval) == 1){    
                (*players[indexP]).score++;    
                printBoard();                       
                cout << "Score has increased by 1 for " << (*players[turn]).name << endl << endl;    
                printPlayers();                    
                return true;    
            }
            else{           
                turn++;     
                if (turn == numPlayers){  
                    turn = 0;              
                }
                printBoard();               
                return false;   
            }
        }
    ranXval = rand()%size;   
    ranYval = rand()%size;
    }
   //no moves found
    return false;

}

bool Game::checkFour(int y, int x) {
    //This method checks to see if adding the character v to the cell x,y in the board will complete a square, and, if
    // so, returns true 
   
    //list of chars being used by human players
    string playerChars = "";  

    //list of characters useable by AI
    string aiChars[] = {"A","B","C","D","E"}; 

    //add player characters to array
    for (int i = 0; i < compplayers; i++){  
        playerChars += (aiChars[i]);        
    }
    for (int i = compplayers; i < numPlayers; i++){ 
        playerChars += (*players[i]).c;    
    }

    //left side
    if (x == 0){ 
        if (y == 0){   
            if ((playerChars.find(board[y+1][x+1]) != std::string::npos) &&
                (playerChars.find(board[y+1][x]) != std::string::npos) && 
                (playerChars.find(board[y][x+1]) != std::string::npos)){  
                return true;   
            }
            else{
                return false;
            }  
        }
        else if (y == size-1){   
            
            if ((playerChars.find(board[y][x+1]) != std::string::npos) && 
                (playerChars.find(board[y-1][x]) != std::string::npos) && 
                (playerChars.find(board[y-1][x+1]) != std::string::npos)){
                return true;    
                //true if surrounding cells are filled
            }
            else{
                return false;
            }
        }
        else{  
            
            if (((playerChars.find(board[y+1][x+1]) != std::string::npos) &&
                    (playerChars.find(board[y+1][x]) != std::string::npos) &&
                    (playerChars.find(board[y][x+1]) != std::string::npos)) || 
                    ((playerChars.find(board[y-1][x+1]) != std::string::npos) && 
                    (playerChars.find(board[y-1][x]) != std::string::npos) && 
                    (playerChars.find(board[y][x+1]) != std::string::npos))){
                return true;    
            }
            else{
                return false;
            }
        }
    }
    //relative rightmost side of matrix
    else if (x == size-1){
        if (y == 0){  
          
            if ((playerChars.find(board[y+1][x-1]) != std::string::npos) && 
                (playerChars.find(board[y+1][x]) != std::string::npos) && 
                (playerChars.find(board[y][x-1]) != std::string::npos)){
                return true;  
            }
            else{
                return false;
            }  
        }
        else if (y == size-1){    
          
            if ((playerChars.find(board[y-1][x-1]) != std::string::npos) &&
                    (playerChars.find(board[y-1][x]) != std::string::npos) &&
                    (playerChars.find(board[y][x-1]) != std::string::npos)){
                return true;    
            }
            else{
                return false;
            }
        }
        else{   
           
            if (((playerChars.find(board[y+1][x-1]) != std::string::npos) && 
                    (playerChars.find(board[y+1][x]) != std::string::npos) && 
                    (playerChars.find(board[y][x-1]) != std::string::npos)) || 
                    ((playerChars.find(board[y-1][x-1]) != std::string::npos) &&
                    (playerChars.find(board[y-1][x]) != std::string::npos) &&
                    (playerChars.find(board[y][x-1]) != std::string::npos))){
                return true;
            }
            else {
                return false;
            }
        }
    }
    else if (y == 0){  
        if (((playerChars.find(board[y+1][x-1])
                != std::string::npos) && (playerChars.find(board[y+1][x]) != std::string::npos) && 
                (playerChars.find(board[y][x-1]) != std::string::npos)) ||
                ((playerChars.find(board[y+1][x+1]) != std::string::npos) && 
                (playerChars.find(board[y+1][x]) != std::string::npos) &&
                (playerChars.find(board[y][x+1]) != std::string::npos))){
            return true;
        }
        else{
            return false;
        }
    }
    else if (y == size-1){
        //relative bottom of matrix 
        if (((playerChars.find(board[y][x-1]) != std::string::npos) &&
                (playerChars.find(board[y-1][x]) != std::string::npos) && 
                (playerChars.find(board[y-1][x-1]) != std::string::npos)) ||
                ((playerChars.find(board[y][x+1]) != std::string::npos) && 
                (playerChars.find(board[y-1][x]) != std::string::npos) && 
                (playerChars.find(board[y-1][x+1]) != std::string::npos))){
            return true;
        }
        else{
            return false;
        }
    }
    
    //central cell checks
    else{  
        if ((playerChars.find(board[y-1][x-1]) != std::string::npos) && 
                (playerChars.find(board[y-1][x]) != std::string::npos) && 
                (playerChars.find(board[y][x-1]) != std::string::npos)){
            return true;
        }
        else if ((playerChars.find(board[y-1][x+1]) != std::string::npos) &&
                (playerChars.find(board[y-1][x]) != std::string::npos) && 
                (playerChars.find(board[y][x+1]) != std::string::npos)){
            return true;
        } 
        else if ((playerChars.find(board[y+1][x+1]) != std::string::npos) &&
                (playerChars.find(board[y+1][x]) != std::string::npos) &&
                (playerChars.find(board[y][x+1]) != std::string::npos)){
            return true;    
        }
        else if ((playerChars.find(board[y+1][x-1]) != std::string::npos) &&
                (playerChars.find(board[y+1][x]) != std::string::npos) &&
                (playerChars.find(board[y][x-1]) != std::string::npos)){
            return true;
        }
        else {
            return false;
        }
    }
    return false; 
}

void Game::getWinner() {
// This method determines which of the players in the array of Players has the highest score, and prints out 
// that player's name and their score. If multiple players have the highest score, they are all winners!
//Nothing is input and nothing is returned.
    
    int currentHighScore = -1; 
    
    //loop through players to figure out who has the highest score
    for(int i = 0; i < numPlayers; i++){      
	if((*players[i]).score > currentHighScore){ 
            currentHighScore = (*players[i]).score; 
	}
        if ((*players[i]).score == currentHighScore){   
            //Output with winner
            cout << "The winner is: " << (*players[i]).name << " with a score of: " << (*players[i]).score << endl;   
        }
    
    
}
}


bool Game::checkThree(int x, int y) {
// Only needed for Extra Credit
// This method determines whether placing a piece on the board at x and y will complete - of a square and, if so, it
// returns true.  Otherwise it returns false.
}//checkThree