#include <iostream>
#include <string>
#include <vector>
#include "GameBoard.h"
using namespace std;


	GameBoard::GameBoard() 
	{
		board = vector< vector< char > >(19, vector<char>(19));
		for (int i = 0; i < 19; i++) {
			for(int j = 0; j < 19; j++) {
				board[i] [j] = '.';
			}
		}
	
	
	}
		void GameBoard::setCell(int player, int row, int col, char c) {
		if ( player == 0) {
			board[row][col] = c;
		} else if (player == 1) {
			board[18-row][18 - col] = c;
		} else {
			cout << "That is not a valid player" << endl;
		}
	}

	void GameBoard::print(int player) {
		if (player == 0) {
			for(int i = 0; i < 19; i++) {
				for(int j = 0; j < 19; j++) {
					cout << board[i][j];
				}
				cout << endl;
			}
		
		} else if (player == 1) {
			for(int i = 18; i > -1; i--) {
				for(int j = 18; j > -1; j--) {
					cout << board[i][j];
				}
				cout << endl;
			}

		}			


	}
	