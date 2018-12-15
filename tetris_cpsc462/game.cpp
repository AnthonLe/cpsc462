#include "game.h"
#include "SimpleUI.h"
#include "board.h"
#include "block.h"
#include "brain.h"
#include "PlayerList.h"

#include <iostream>
#include <conio.h> //for getch and kbhit


namespace Tetris
{
	// Default constructor
	Game::Game()
		: _persistentData(new Persistence::PlayerList),
		_loggerPtr(new Logging::CLogger),
		_game(new Game)

	{
		_logger << "Game has been successfully initialized";
	}



	// Destructor
	Game::~Game() 
	{
		_logger << "Game shutdown successfully";
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

		while (gameobj.gameover != true)
		{

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


	/*void Game::StartNewGame(Game &gameTest, Brain &brainTest)
	{
		//Create board object to create and display the board
		std::unique_ptr<Game> gameTest;
		std::unique_ptr<Brain> brainTest;
		std::unique_ptr<Board> boardTest;

		_boards->CreateBoard(gameTest);
		_game->UpdateGame(gameTest, brainTest, *boardTest);
		Board *boardTest = new Board();
		boardTest->CreateBoard(gameobj);
		UpdateGame(gameobj, brainobj, *boardTest);

	}

	void Game::UpdateGame(Game &gameTest, Brain &brainTest, Board &boardTest)
	{
		size_t timer = 0;

		//Create the first block
		std::unique_ptr<Block> blockTest;
		_block->CreateBlock(boardTest, gameTest);
		//Block *blockTest = new Block();
		//blockTest->CreateBlock(boardobj, gameobj);

		while (gameTest.gameover != true)
		{

			//run this code only for windows
#ifdef _WIN32
//_kbhit() checks if a key was pressed
			if (_kbhit())
			{
				_block->PlayerInput(gameTest, boardTest);
				//blockTest->PlayerInput(gameobj, boardobj);
			}
#endif

			//time increments until it reaches the limit set by the GAMESPEED
			if (timer < brainTest.gamespeed)
			{
				timer++;
			}
			//timer resets to 0 and spawns a new block
			else
			{
				_block->SpawnBlock(boardTest, gameTest);
				//blockTest->SpawnBlock(boardobj, gameobj);
				timer = 0;
			}
		}
	}*/
}