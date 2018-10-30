#pragma once

using namespace std;

class Game;
class Brain;


class loginMenu
{
public:
	int choice;
	char userName[10];
	char pword[10];

	void sendNAME();
	void sendPWORD();
	void DisplayLoginMenu();
	void SetChoice(int);
	void login(ifstream &);
	void registerPlayer(ofstream & );

private:
	int DoChoice(int);
	void clear();
};

