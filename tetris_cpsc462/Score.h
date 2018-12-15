#ifndef Score_h
#define Score_h

#include <string>

class Score
{
public:

	void DisplayScores();
	void SaveScore(std::string n, int s);
	void SetChoice(int c);
	int DoChoice(int c);

private:

};
#endif // Score_h
