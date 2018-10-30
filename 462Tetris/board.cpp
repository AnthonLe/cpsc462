#include "board.h"
#include "game.h"
#include <vector>
#include <iostream>

//clear the console/terminal by creating a lot of newlines
void Board::clear()
{
	int n;
	for (n = 0; n < 10; n++)
		printf("\n\n\n\n\n\n\n\n\n\n");
}

void Board::CreateBoard(Game &gameobj)
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

	DisplayBoard(gameobj);
}

void Board::DisplayBoard(Game &gameobj)
{
	//clear the terminal
	clear();

	//iterate through the multidimensional board vector
	for (size_t i = 0; i < (BOARD_HEIGHT+1); i++)
	{
		for (size_t j = 0; j < (BOARD_WIDTH+2); j++)
		{
			//used the values stored from the initGame() function to create the border and empty space
			switch (board[i][j])
			{
			case 0:
				std::cout << " " << std::flush;
				break;
			case 9:
				std::cout << "X" << std::flush;
				break;
			default:
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
		DisplayGameOver(gameobj);
		clear();

	}
}

int Board::DisplayGameOver(Game gameobj)
{
	clear();
	cout << 
		"==================================================================\n"
		" #####  #####  #     # ######    #####  #       # ######  #####  #\n"
		"#      #     # # # # # #        #     #  #     #  #      #     # #\n"
		"#  ### ####### #  #  # ######   #     #   #   #   ###### # ####  #\n"
		"#    # #     # #     # #        #     #    # #    #      #   #    \n"
		"###### #     # #     # ######    #####      #     ###### #    #  #\n"

		"==================================================================\n";

	cout << "Final Score: " << gameobj.nScore << "\n\n";

	system("pause");

	return 0;
}