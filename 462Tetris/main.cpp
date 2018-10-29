#include <iostream>
#include <vector>
#include <random>
#include <iomanip>
//#include <conio.h> //for kbhit and getch functions

#include "menu.h"
using namespace std;

int main() {
	Menu Test;
	Test.DisplayWelcomeInterface();
	int c = 0;
	cin >> c;
	Test.SetChoice(c);

	Test.DisplayGameOver();


	
	return 0;
}