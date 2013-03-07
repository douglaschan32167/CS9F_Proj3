#include <iostream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;



#ifndef GAMEBOARD_H
#define GAMEBOARD_H
class GameBoard {
public:
	GameBoard();
	void setCell(int player, int row, int col, char c);
	void print(int player);
	int main();
private:
	vector<vector <char> > board;

};
	
#endif
