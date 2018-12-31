//Matthew Coffey
//minesweeper.h

const int SIDE = 25;
const int MINES = 40;
class Minesweeper{
	public:
		Minesweeper();
		~Minesweeper();
		bool isValid(int, int);
		bool isMine(int, int);
		char  makeMove(int*, int*);
		void printBoard();
		void printBoardWithMines(int[][2]);
		int countAdjacentMines(int, int, int[][2]);
		char getStatus(int, int);
		bool playMinesweeperRecur(int [][2], int, int, int *);
		void placeMines(int [][2]);
		void flag(int, int);
		void deflag(int, int, int[][2]);
		void graphicBoard();
	private:
		char Board[SIDE][SIDE];
};
