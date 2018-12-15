#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <vector>
#include "clear.h"
#include "score.h";

void Score::DisplayScores()
{
	ClearScreen();
	std::cout << "======================================================\n"
		"        #####    #####   #####    ######   ######  #####        \n"
		"       #        #       #     #   #     #  #      #             \n"
		"        #####   #      #       #  ######   ######  #####        \n"
		"             #  #       #     #   #   #    #            #       \n"
		"        #####    #####   #####    #     #  ######  #####        \n"


		"======================================================\n";

	//read playername and scores into list
	std::vector<std::string> sList;
	std::ifstream readFile("ScoreList.txt");
	if (readFile.is_open())
	{

		//storing all the usernames and password into a vector string
		//vector<string> sList;
		std::string read = "";

		while (readFile >> read)
		{
			sList.push_back(read);
		}

		//display list of players and scores
		for (std::vector<std::string>::iterator it = sList.begin(); it != sList.end(); it += 2)
		{
			std::cout << "Player name: ";
			std::cout << *it << " Score: " << *(it+1) << std::endl;
		}

		readFile.close();
	}


	std::cout << "1) Go Back\n"
		">> ";
	int c;
	std::cin >> c;
	SetChoice(c);
}

//Save score to file
void Score::SaveScore(std::string n, int s) {

	std::ifstream readFile("ScoreList.txt");
	std::ofstream writeFile("ScoreList.txt", std::ios::app);

	//adding name and score to ScoreList txt file
	if (writeFile.is_open())
	{
		writeFile << n << std::endl;
		writeFile << s << std::endl;
		writeFile.close();
	}

	else
	{
		std::cout << "Unable to open file";
	}
}

void Score::SetChoice(int c)
{
	switch (c)
	{
	case 1:
		break;
		//if any number other than 1 is chosen, reset choice to 0
	default:
		c = 0;
		break;
	}

	int choice = c;
	DoChoice(choice);
}

//call the correct option according to the player choice
int Score::DoChoice(int choice)
{

	switch (choice)
	{
	case 1:
		ClearScreen();
		return 0;
	case 0:
		std::cerr << "None of the options were chosen" << std::endl;
		system("pause");
		ClearScreen();
		return -1;
	}
	return 0;

}