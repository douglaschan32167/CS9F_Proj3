using namespace std;

class gameBoard {
public:
	gameBoard();
	void setCell(int player, int row, int col, char c);
	void print(int player);
	
private:
	char** board;

}
	