//Matthew Coffey
//minesweeper.cpp


#include <iostream>
#include <vector>
#include <cmath>
#include <time.h>
using namespace std; 
#include "minesweeper.h"
#include "gfx.h"

Minesweeper::Minesweeper() { 
    srand(time (NULL)); 
    for (int i=0; i<SIDE; i++) { 
        for (int j=0; j<SIDE; j++) { 
            Board[i][j] = '-';
        } 
    } 
    return; 
}  
 
Minesweeper::~Minesweeper() {} 

bool Minesweeper::isValid(int row, int col) { //real
    return (row >= 0) && (row < SIDE) && 
           (col >= 0) && (col < SIDE); 
} 

bool Minesweeper::isMine (int row, int col) { //real
    if (Board[row][col] == '*') 
        return (true); 
    else
        return (false); 
} 
  
char Minesweeper::makeMove(int *x, int *y) { //real
    char c;
    cout<<"Enter your move, (row, column) -> "<<endl;
    cin >> c; 
    cin >>  *x;
    cin >> *y;
    return c; 
} 
void Minesweeper::printBoard(){
    cout <<"    ";
    for (int i=0; i<SIDE; i++){
        cout << i/10;
        }
    cout << endl;
    cout <<"    ";
    for (int i=0; i<SIDE; i++){
        cout << i%10;
    }
    cout << endl;
    cout << endl;
    for (int i=0; i<SIDE; i++) {
  	if (i < 10)
           cout <<"0" <<i << "  " ;
        else
	   cout << i << "  ";
        for (int j=0; j<SIDE; j++){
            if (Board[i][j] != '*'){
                cout << Board[i][j];
            }
            else
                cout << "-";
        }
                cout << endl;
    }
    return;
}
  

void Minesweeper::printBoardWithMines(int mines[][2]) { //my
    for (int i =0; i < MINES; i++){
        Board[mines[i][0]][mines[i][1]] ='*';
    }
    cout <<"    "; 
  
    for (int i=0; i<SIDE; i++){ 
        cout << i/10; 
	}
    cout << endl;
    cout <<"    ";
    for (int i=0; i <SIDE; i++){
        cout << i%10;
    } 
    cout << endl;
    cout << endl; 
    for (int i=0; i<SIDE; i++) { 
        if (i < 10)
            cout <<"0" <<i << "  " ; 
	else
	    cout << i << "  ";
        for (int j=0; j<SIDE; j++){
	    if (Board[i][j] != '*'){ 
                cout << Board[i][j]; 
	    }
            else
                cout << "*";
        }
		cout << endl; 
    } 
    return; 
} 
  
int Minesweeper::countAdjacentMines(int row, int col, int mines[][2]) { //real
    int count = 0; 
		for (int r =-1; r < 2; r++){
			for (int c=-1; c < 2; c++){
				if (!(r == 0 && c == 0)){
					if (isValid(row+r, col+c)){
						if (isMine(row+r, col+c)){
							count++;
						}
					}
				}
			}
		}
        
    return count; 
} 

char Minesweeper::getStatus(int row, int col){
    return Board[row][col];
}

bool Minesweeper::playMinesweeperRecur(int mines[][2], int row, int col, int *movesLeft) { //my
    if (Board[row][col] != '-' && Board[row][col] != '*') // Base Case of Recursion 
        return (false); 
    
    if (Board[row][col] == '*') {  // You opened a mine 
        Board[row][col]='*'; 
        printBoardWithMines(mines); 
        cout<<"\nYou lost!"<<endl; 
        return (true) ; 
    } 
    else{ // Calculate the number of adjacent mines and put it on board
        int count = countAdjacentMines(row, col, mines); 
        (*movesLeft)--; 
        Board[row][col] = count + '0'; 
        if (count == 0) {  
			for (int r =-1; r < 2; r++){
				for (int c=-1; c < 2; c++){
					if (!(r == 0 && c == 0)){
						if (isValid(row+r, col+c)){
							if (isMine (row+r, col+c) == false) 
								playMinesweeperRecur(mines, row+r, col+c, movesLeft); 
						}
					}
				}
			}
		}
        return (false); 
    } 
} 
  
void Minesweeper::placeMines(int mines[][2]) { //real
	bool mark[SIDE*SIDE] = {false}; 
    for (int i=0; i<MINES; ) { 
        int random = rand() % (SIDE*SIDE); 
        int x = random / SIDE; 
        int y = random % SIDE; 
        if (mark[random] == false) { 
            mines[i][0]= x;  
            mines[i][1] = y;  //rows and columns are stored in columns on this array
            Board[mines[i][0]][mines[i][1]] = '*'; 
            mark[random] = true; 
            i++; 
        } 
    } 
    return; 
}
void Minesweeper::flag(int x, int y){
    Board[x][y] = 'X';
}
void Minesweeper::deflag(int x, int y, int mines[][2]){
    Board[x][y] = '-';
    for (int i=0; i<MINES; i++){
        if (Board[mines[i][0]][mines[i][1]] == '-'){
	    Board[mines[i][0]][mines[i][1]] ='*';
	}
    }
    return;
}

//void Minesweeper::graphicBoard(){
//   int ht = 700, wd = 700, mrgn = 30;
//   gfx_open(ht, wd, "Minesweeper");
//   gfx_clear();
//   gfx_color (255, 255, 255);
//   gfx_circle (350, 350, 50);
//   for (int i = 0; i <= SIDE; i++){
//	gfx_line(mrgn+i*(wd-2*mrgn)/SIDE, mrgn, mrgn+i*(wd-2*mrgn)/SIDE, ht-mrgn);
//   }
//} 
