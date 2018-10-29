#pragma once
//#include "board.h"

class Board;

class Game
{
public:
	Game();
	bool gameover = false;
	void StartNewGame(Game &obj);
	void UpdateGame(Game &obj, Board &obj2);

private:

	

};