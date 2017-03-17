/* 
 * File:   main.cpp
 * Author: Kevin Faucher, Alexia Nebrao
 *
 * Created on March 7, 2017, 9:01 PM
 */

#include <cstdlib>
#include "Game.hpp"
using namespace std;

int main(int argc, char** argv) {
	cout << "hello world!!!" << endl;
	Game game;
	game.makeBoard();
	game.getPlayers();
	game.printBoard();
	game.printPlayers();
	game.getWinner();
	return 0;
}