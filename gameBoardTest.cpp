#include "gameBoard.h"

using namespace std;

int main() {
	GameBoard testBoard1;
	testBoard1.setCell(1, 0, 0, 'k');
	testBoard1.setCell(0, 0, 2, ':');
	testBoard1.setCell(1, 0, 2, 'm');
	testBoard1.setCell(0, 4, 17, '#');
	for (int i = 0; i < 19; i++) {
		testBoard1.setCell(0, i, 15, 'p');
	}
	cout << "player 0 sees" << endl;
	testBoard1.print(0);
	cout << endl << "player 1 sees" << endl;
	testBoard1.print(1);
	



}