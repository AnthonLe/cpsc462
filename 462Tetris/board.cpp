#include "board.h"
#include "game.h"
#include "clear.h"
#include "score.h"
#include <string>
#include <iostream>


void Board::CreateBoard(Game &gameobj, Score &scoreobj)
{

	//20 is the board height
	for (size_t i = 0; i <= BOARD_HEIGHT; i++)
	{
		//11 is the board width 
		for (size_t j = 0; j <= (BOARD_WIDTH+1); j++)
		{
			//if the current index is a left, right, or bottom border, give it a value of 9
			//this value 9 is used by the display() function to set this index with a X symbol
			if ((j == 0) || (j == (BOARD_WIDTH+1)) || (i == BOARD_HEIGHT))
			{
				board[i][j] = stage[i][j] = 9;
			}
			//otherwise give it the value 0 for an empty space
			else
			{
				board[i][j] = stage[i][j] = 0;
			}
		}
	}

	DisplayBoard(gameobj, scoreobj);
}

void Board::DisplayBoard(Game &gameobj, Score &scoreobj)
{
	//clear the terminal
	ClearScreen();

	//iterate through the multidimensional board array
	for (size_t i = 0; i < (BOARD_HEIGHT+1); i++)
	{
		for (size_t j = 0; j < (BOARD_WIDTH+2); j++)
		{
			//used the values stored from the CreateBoard() function to create the border and empty space
			switch (board[i][j])
			{
			case 0:
				std::cout << " " << std::flush;
				break;
			case 9:		//border made of X
				std::cout << "X" << std::flush;
				break;
			default:	//blocks made of #
				std::cout << "#" << std::flush;
				break;
			}
		}
		std::cout << std::endl;
	}

	std::cout << "Score: " << gameobj.nScore << "\n\n";

	std::cout << "Controls:\tA = Left\n\t\tS = Down\n\t\tD = Right\n\t\tSpace = Rotate";

	//check the gameover status
	if (gameobj.gameover == true)
	{
		DisplayGameOver(gameobj, scoreobj);
		ClearScreen();

	}
}

int Board::DisplayGameOver(Game gameobj, Score &scoreobj)
{
	ClearScreen();
	cout << 
		"==================================================================\n"
		" #####  #####  ##   ## ######    #####  #     # ###### ######  #\n"
		"#      #     # # # # # #        #     # #     # #      #     # #\n"
		"#  ### ####### #  #  # ######   #     #  #   #  ###### ######  #\n"
		"#    # #     # #     # #        #     #   # #   #      #   #    \n"
		"###### #     # #     # ######    #####     #    ###### #    #  #\n"

		"==================================================================\n";

	//-25 to offset score from block spawned at the end
	cout << "Final Score: " << gameobj.nScore -25<< "\n\n";
	cout << "Save Score? 1 = Yes/ 2 = No\n"
		">>";
	int c;
	string name;
	cin >> c;
	if (c == 1) {
		cout << "Enter name >> ";
		cin >> name;
		cout << "\nScore Saved...\n";
		scoreobj.SaveScore(name, gameobj.nScore);
		system("pause");
	}

	return 0;
}