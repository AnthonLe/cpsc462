#pragma once

using namespace std;

class loginMenu;
class Game;
class Brain;

class Admin
{
public:
	int choice;
	void displayAdminMenu();
	void SetChoice(Brain &, int);
	void viewPlayerList(ifstream &);
	void removePlayer();
	
private:
	int DoChoice(Brain &, int);
};

