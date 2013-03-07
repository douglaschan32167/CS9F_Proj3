#include <iostream>
#include <string>
#include <sstream>
#include <vector>


class gameBoard {
public:
	gameBoard();
	void setCell(int player, int row, int col, char c);
	void print(int player);
	int main();
private:
	vector< vector<char> > board;

};
	
