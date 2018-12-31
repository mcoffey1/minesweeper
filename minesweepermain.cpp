//Matthew Coffey
//minesweepermain.cpp

#include <iostream>
#include <vector>
#include <cmath>
#include <time.h>
using namespace std;
#include "gfx.h"
#include "minesweeper.h"


void playMinesweeper();

int main() 
{ 
    playMinesweeper (); 
  
    return (0); 
}

void playMinesweeper () { 
    bool gameOver = false; 
    Minesweeper realBoard;
    int movesLeft = SIDE * SIDE - MINES, x, y; 
    int mines[MINES][2]; // stores (x,y) coordinates of all mines. 
    realBoard.placeMines(mines); 
    char c;
    cout << "Rules: \n The first character you input will determine whether you flag, deflag or check. The second two are the x and y coordinates. \n f: flag \n d: deflag \n all others: check"<< endl; 
    while (gameOver == false) 
     {  
//	realBoard.graphicBoard();
        cout << "Current Board : "<< endl; 
        realBoard.printBoard(); 
        c = realBoard.makeMove(&x, &y); 
	if (c == 'f')
	    realBoard.flag(x, y);
	else if (c == 'd')
            realBoard.deflag(x, y, mines);
	else
            gameOver =realBoard.playMinesweeperRecur (mines, x, y, &movesLeft); 
        if ((gameOver == false) && (movesLeft == 0)) { 
            cout << "\nYou won !"; 
            gameOver = true; 
         } 
    } 
    return; 
} 
