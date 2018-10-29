#pragma once
#include "board.h"
#include "game.h"

class Block
{
public:
	//creates a new block
	bool CreateBlock(Board &obj, Game &obj2);

	//
	void SpawnBlock(Board &obj, Game &obj2);

	bool Collide(Board &obj, int, int);
	void Collidable(Board &obj);
	void PlayerInput(Game &obj2, Board &obj);
	void MoveBlock(Game &obj2, Board &obj, int, int);
	bool RotateBlock(Board &obj, Game &obj2);

	//The starting position coordinates for the blocks
	int x = 4;
	int y = 0;

	//Block definition is a 4x4 matrix
	vector<vector<int>> block =
	{
		{ 0, 0, 0, 0 },
		{ 0, 0, 0, 0 },
		{ 0, 0, 0, 0 },
		{ 0, 0, 0, 0 }
	};
	//Multidimensional vector holding all the 7 blocks 
	vector<vector<vector<int>>> block_list =
	{
		{	//Block 0
			{ 0, 1, 0, 0 },
			{ 0, 1, 0, 0 },
			{ 0, 1, 0, 0 },
			{ 0, 1, 0, 0 }
		},
		{	//Block 1
			{ 0, 0, 0, 0 },
			{ 0, 1, 1, 0 },
			{ 0, 1, 0, 0 },
			{ 0, 1, 0, 0 }
		},
		{	//Block 2
			{ 0, 0, 1, 0 },
			{ 0, 1, 1, 0 },
			{ 0, 1, 0, 0 },
			{ 0, 0, 0, 0 }
		},
		{	//Block 3
			{ 0, 1, 0, 0 },
			{ 0, 1, 1, 0 },
			{ 0, 0, 1, 0 },
			{ 0, 0, 0, 0 }
		},
		{	//Block 4
			{ 0, 0, 0, 0 },
			{ 0, 1, 0, 0 },
			{ 1, 1, 1, 0 },
			{ 0, 0, 0, 0 }
		},
		{	//Block 5
			{ 0, 0, 0, 0 },
			{ 0, 1, 1, 0 },
			{ 0, 1, 1, 0 },
			{ 0, 0, 0, 0 }
		},
		{	//Block 6
			{ 0, 0, 0, 0 },
			{ 0, 1, 1, 0 },
			{ 0, 0, 1, 0 },
			{ 0, 0, 1, 0 }
		}
	};

private:
	

};


