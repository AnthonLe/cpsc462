#include "block.h"
#include <vector>
#include <random>
#include <iostream>
#include <conio.h>
using namespace std;



bool Block::CreateBlock(Board &boardobj, Game &gameobj)
{
	//reeset coordinates to starting position
	x = 4;
	y = 0;

	random_device rd; // obtain a random number from hardware
	mt19937 eng(rd()); // seed the generator
	uniform_int_distribution<> distr(0, 6); // define the range

	//Create one of the 7 blocktypes randomly
	int blocktype = distr(eng);
	//cout << "\nblocktype: " << blocktype << endl;

	//iterate through a 4x4 matrix to create a block using the randomly chosen blocktype integer
	for (size_t i = 0; i < 4; i++)
	{
		for (size_t j = 0; j < 4; j++)
		{
			//reset the block index to be 0 first
			block[i][j] = 0;
			block[i][j] = block_list[blocktype][i][j];
		}
	}


	for (size_t i = 0; i < 4; i++)
	{
		for (size_t j = 0; j < 4; j++)
		{
			//Move the generated block to the starting position on the board
			boardobj.board[i][j + 4] = boardobj.stage[i][j + 4] + block[i][j];
			//if the starting position is blocked, its a gameover
			if (boardobj.board[i][j + 4] > 1)
			{
				gameobj.gameover = true;
				return true;
			}
		}
	}
	return false;

}

void Block :: SpawnBlock(Board &boardobj, Game &gameobj)
{
	if (!Collide(boardobj, x, y + 1))
	{
		MoveBlock(gameobj, boardobj, x, y + 1);
	}
	else
	{
		Collidable(boardobj);
		CreateBlock(boardobj, gameobj);
		boardobj.DisplayBoard(gameobj);
	}



}

bool Block::Collide(Board &boardobj, int bx, int by)
{
	//check the block's 4x4 matrix
	for (size_t i = 0; i < 4; i++)
	{
		for (size_t j = 0; j < 4; j++)
		{
			//if there is an overlap, the block collided 
			if (block[i][j] && boardobj.stage[by + i][bx + j] != 0)
			{
				return true;
			}
		}
	}
	return false;

}

void Block::Collidable(Board &boardobj) {
	for (size_t i = 0; i < (BOARD_HEIGHT+1); i++)
	{
		for (size_t j = 0; j < (BOARD_WIDTH+2); j++)
		{
			boardobj.stage[i][j] = boardobj.board[i][j];
		}
	}
}

void Block::PlayerInput(Game &gameobj, Board &boardobj)
{
	char key;

	//get the key that was pressed
	#ifdef _WIN32
	key = _getch();
	#endif

	//first checks if the block collided with anything, if it didn't, the block will move according to the key pressed
	switch (key)
	{
	case 'd': //right
		if (!Collide(boardobj, x + 1, y))
		{
			MoveBlock(gameobj, boardobj, x + 1, y);
		}
		break;
	case 'a': //left
		if (!Collide(boardobj, x - 1, y))
		{
			MoveBlock(gameobj, boardobj, x - 1, y);
		}
		break;
	case 's': //down
		if (!Collide(boardobj, x, y + 1))
		{
			MoveBlock(gameobj, boardobj, x, y + 1);
		}
		break;
	//case ' ': //spacebar
	//	rotateBlock();
	}

}

void Block::MoveBlock(Game &gameobj, Board &boardobj, int bx, int by)
{
	//Remove block
	for (size_t i = 0; i < 4; i++)
	{
		for (size_t j = 0; j < 4; j++)
		{
			boardobj.board[y + i][x + j] -= block[i][j];
		}
	}

	//Update coordinates
	x = bx;
	y = by;

	// assign a block with the updated value
	for (size_t i = 0; i < 4; i++)
	{
		for (size_t j = 0; j < 4; j++)
		{
			boardobj.board[y + i][x + j] += block[i][j];
		}
	}
	//redisplay the block in its new position 
	boardobj.DisplayBoard(gameobj);

}