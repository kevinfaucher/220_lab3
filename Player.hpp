#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <cstring>
#include <iostream>
#include "cell.hpp"
#include "moveslist.hpp"  // for extra credit only
using namespace std;

class Player {
    string name;  // the player's name
    char c;  // the player's character that they're placing on the board each turn
    int score;  // keeps track of the player's score (number of completed squares
    bool isComputer;  // indicates whether this player is a computer or a human

    // allMoves is for the extra credit only
    movesList *allMoves; //a dynamically allocated array of 3 movesLists
    // the first movesList is for the moves that have highest priority (would complete
    // a square for the player.
    // the second movesList is for the moves that have medium priority (relatively neutral 
    // moves
    // the third movesList is for moves that are notably bad (would create 3 out of 
    // four sides of a square, thus allowing the next player to complete a square
    
public:
    friend class Game;  // so Game has access to all private fields and methods
    Player();  
    // constructor that uses cin to ask user for player's name and character.  Initializes 
    // score to 0, isComputer to false.
    Player(string n, char ic, bool x);
    //constructor that initializes name to n, c to ic, and bool to x.  Initializes score
    // to 0.
};

#endif