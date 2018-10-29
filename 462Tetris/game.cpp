#include "game.h"
#include "menu.h"
#include "board.h"
#include "block.h"
#include <iostream>
#include <conio.h>

using namespace std;

Game::Game() {

}


void Game::StartNewGame(Game &gameobj)
{

	//Create board object to create and display the board
	Board *boardTest = new Board();
	boardTest->CreateBoard(gameobj);
	UpdateGame(gameobj, *boardTest);

}

void Game::UpdateGame(Game &gameobj, Board &boardobj)
{
	size_t timer = 0;
	//determines the fall speed of the blocks
	//lower number = faster speed
	size_t gamespeed = 20000;

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
		if (timer < gamespeed)
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