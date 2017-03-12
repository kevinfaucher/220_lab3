#include "Game.hpp"
#include <cstdlib>
#include <iostream>
using namespace std;

Game::Game() {  
// for non-automatized version - asks for board size, num players, num of computer players, and then initializes
 // everything
  cout << "Please enter the size of the board: " << endl;
    cin >> size;
    cout << "Please enter the number of players: " << endl;
    cin >> numPlayers;
    cout << "Please enter the number of computer players: " << endl;
    cin >> compplayers;
}//Game

Game::Game(bool b) {
//for the automated version - if b is true, randomly generate the size of the board, set the num of players and the
//num of compplayers to 2, and the, of course initialize everything
    int size = rand() % 100 + 1; //random board size
    int compplayers = int numPlayers = 2;
}//Game

void Game::makeBoard(){
// dynamically generates the board to be size by size, with each cell initially set to '.'
//your code goes here
    board = new char*[size];
    for(int i = 0; i < size; i++){
    	board[i] = new char[size];
    	for(int j = 0; j < size; j++){
    		board[i][j] = '.';
    	}
    }
}//makeBoard

void Game::printBoard() {
//Note: I'm giving you this one
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            cout << board[i][j]<<"\t";
        }
        cout << endl;
    }
}//printBoard
void Game::printBoard() {
//Note: I'm giving you this one
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            cout << board[i][j]<<"\t";
        }
        cout << endl;
    }
}//printBoard
void Game::getPlayers() {
    //This method dynamically generates an array of players, and then, for each element in the array, creates a new 
    //player object with a name and a character.  For the number of players that are computers, I used an array of names
    // and an array of characters, and then just selected the next name and character in the list for my player object.
    // for humans I called the Player constructor with no input parameters (that one asked the user for their name and 
    // their preferec character.
    // your code goes here
}

void Game::printPlayers() {
    // this method is optional – I wrote it so I could test my getPlayers() method to make sure it generated all my Players
    // correctly.  If you choose not to include this method, that is fine.
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

bool findMoves(char v); //is this meant to be a bracket? - toby
//    Regular version, this method continues to generate random x,y values until that cell on the
//    board is empty, then places the player's character v on the board, and checks to see if a 
//    square is completed using checkFour.  If so, true is returned and that player’s score goes up by 1 in the 
//    playGame method, and that player gets to take another turn (so turn does not increase by 1).  


// movesList * Game::findMoves(char v) {
// The extra credit version of this method – this method dynamically creates a list of 3 movesList objects.  It then goes
// through the entire board and classifies each possible move left on the board as being either good (will complete a 
// square, in which case it’s added to the new list of movesLists at [0], neutral (doesn’t do anything), in which it’s 
// added to the second of the movesLists, or bad (3/4 of a square), in which case it’s added to the third of the 
// movesLists.
// This method uses checkFour() method to determine whether a move is good, checkThree to determine if a move is
// bad, and if neither of those is true, then the move is considered neutral.
// This method returns the list of three movesList objects.
}

bool Game::checkFour(int x, int y) {
    // this method checks to see if placing a piece at x and y on the board will complete a square, and, if so, it
    // returns true.  Otherwise it returns false.
}

void Game::getWinner() {
    // This method determines which of the players in the array of Players has the highest score, and prints out 
    // that player’s name and their score.
}

bool Game::checkThree(int x, int y) {
    // Only needed for Extra Credit
    // This method determines whether placing a piece on the board at x and y will complete ¾ of a square and, if so, it 
    // returns true.  Otherwise it returns false.
}