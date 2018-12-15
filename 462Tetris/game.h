#pragma once

class Board;
class Brain;
class Score;

class Game
{
public:
	bool gameover = false;
	void StartNewGame(Game &obj, Brain &obj3, Score &obj4);
	void UpdateGame(Game &obj, Brain &obj3, Board &obj2, Score &obj4);
	int nScore = 0;

};