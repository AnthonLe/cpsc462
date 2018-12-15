#pragma once

class Game;
class Brain;
class Score; 

class Menu
{
public:
	int choice;
	void SetChoice(Game &obj, Brain &obj2, Score &obj3, int c);
	void DisplayWelcomeInterface();

private:
	//int getChoice() { return choice; }
	int DoChoice(Game &obj, Brain &obj2, Score &obj3, int choice);
};