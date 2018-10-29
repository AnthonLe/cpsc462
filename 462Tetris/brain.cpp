#include "brain.h";
#include<iostream>
#include<iomanip>
using namespace std;



void Brain::clear()
{
	int n;
	for (n = 0; n < 10; n++)
		printf("\n\n\n\n\n\n\n\n\n\n");
}

void Brain :: SetSpeed() {
	cout << "Set difficulty from 1-10 (Low number = slow speed, High number = fast speed)\n"
		">>";
	int s;
	cin >> s;

	//40000 is the speed for the slowest setting
	//4000 for the fastest
	gamespeed = 40000 / s;
	difficulty = s;

	cout << "\nDifficulty is set to: " << difficulty << endl;
	system("pause");
}

void Brain::DisplaySettingsMenu()
{
	clear();
	cout << "===========================================================\n"
		" #####   ###### #####  #####  ###  ##    #    ######   #####   \n"
		"#        #        #      #     #   # #   #   #        #        \n"
		" #####   #####    #      #     #   #  #  #  #    ###   #####  \n"
		"      #  #        #      #     #   #   # #   #     #        # \n"
		" #####   ######   #      #    ###  #    ##    #####    #####  \n"
		"===========================================================\n";
	cout << "Options\n"
		"1) Difficulty Level (Fall Speed)\tCurrent Level:  " << difficulty << "\n"
		"2) Music Volume\t\t\t\tCurrent Volume: N/A\n"
		"3) Exit Settings\n"
		">> ";
	int c;
	cin >> c;
	SetChoice(c);
}


void Brain::SetChoice(int c)
{
	switch (c)
	{
	case 1:
	case 2:
	case 3:
		break;
		//if any number other than 1,2,3 is chosen, reset choice to 0
	default:
		c = 0;
		break;
	}

	int choice = c;
	DoChoice(choice);
}

//call the correct option according to the player choice
int Brain::DoChoice(int choice)
{

	switch (choice)
	{
	case 1:
		SetSpeed();
		break;
	case 2:
		cout << "Work in Progress\n";
		system("pause");
		break;
	case 3:
		return 0;
	case 0:
		cerr << "None of the options were chosen" << std::endl;
		system("pause");
		return -1;
	}
	return 0;


}