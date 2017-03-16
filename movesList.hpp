
#ifndef MOVESLIST_HPP
#define MOVESLIST_HPP
#include "cell.hpp"
class movesList {
    friend class Player;
    friend class Game;
    cell *potentialMoves; // a list of cells (x,y coordinates) that are potential moves
    // Note that for simplicity's sake, this list is dynamically allocated to be an array, and the length of
    // this array will be the game board's size x size. This means
    // there will almost always be fewer potential cells than the size of the list.
    // In other words, when you first start, the number of potential moves that a player could make would be
    // the board's size x size because the absolute largest number of moves is the number of cells on the board.
    // As the game
    // progresses, the board will start to fill, and there will be fewer potential moves. However, for
    // simplicity's sake, in the Game's findMoves() method, this will still be initialized to the board's 
    // size x size length. That means that the numMoves field (below) will hold the actual number of potential
    // moves in the potentialMoves array (and there will be spaces at teh end of the array that are unused).

    // one more point: This is a clear example of a list that would be MUCH BETTER as a linked list

    int numMoves; // the number of potential moves
public:
    movesList(); // constructor, initializes potentialMoves to NULL and numMoves to 0;
    void makeList(int s);
    // initializes a new, dynamically allocated array of square objects of length s, and sets the
    // nummoves to 0.
};
#endif