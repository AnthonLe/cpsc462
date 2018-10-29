#include "game.h"
#include "menu.h"
#include "board.h"
#include "block.h"
#include "brain.h"
#include <iostream>
#include <conio.h>

using namespace std;

Game::Game() {

}


void Game::StartNewGame(Game &gameobj, Brain &brainobj)
{

	//Create board object to create and display the board
	Board *boardTest = new Board();
	boardTest->CreateBoard(gameobj);
	UpdateGame(gameobj, brainobj, *boardTest);

}

void Game::UpdateGame(Game &gameobj, Brain &brainobj, Board &boardobj)
{
	size_t timer = 0;

	//Create the first block
	Block *blockTest = new Block();
	blockTest->CreateBlock(boardobj, gameobj);
	//cout << "\nhey bitch\n";

	while (gameobj.gameover != true)
	{
		//cout << "hey im alive\n";

		//run this code only for windows
		#ifdef _WIN32
		//_kbhit() checks if a key was pressed
		if (_kbhit())
		{
			blockTest->PlayerInput(gameobj, boardobj);
		}
		#endif

		//time increments until it reaches the limit set by the GAMESPEED
		if (timer < brainobj.gamespeed)
		{
			timer++;
		}
		//timer resets to 0 and spawns a new block
		else
		{
			blockTest->SpawnBlock(boardobj, gameobj);
			timer = 0;
		}

	}
	

}