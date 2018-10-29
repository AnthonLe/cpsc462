#pragma once

class Menu
{
public:
	int choice;
	void SetChoice(int c);
	void DisplayWelcomeInterface();
	void DisplaySettingsMenu();
	int DisplayGameOver();

private:
	//int getChoice() { return choice; }
	int DoChoice(int choice);
	//clear the terminal
	void clear();
};