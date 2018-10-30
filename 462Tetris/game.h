#pragma once
//#include "board.h"

class Board;
class Brain;

class Game
{
public:
	Game();
	bool gameover = false;
	void StartNewGame(Game &obj, Brain &obj3);
	void UpdateGame(Game &obj, Brain &obj3, Board &obj2);
	int nScore = 0;

private:

	

};