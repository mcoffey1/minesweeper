Matthew Coffey
mcoffey1
Working Solo
Final Project

	In this project I made a text based version of the classic game Minesweeper. The rules are listed at the start of each turn. The user will enter a three part inuput with the fist character determining whether to flag, deflag, or check a square and the second two providing the coordinates for the square. The user may quit by inputting two q's (creator's note: this is becuase I have fat fingers and accidentally quit an intense game by hitting q instead of 1). The board will then display in its new state on the screen.
	The class Minesweeper contains a private char array that holds the value of each square, as well as methods to dispaly the board (with and without mines visible), get the status of an individual squares, flag and deflag scores, check if a square is valid, check if a square is a mine, and an algorithm to check that square and play the game.
	The game is controlled by a recursive method that recurses every time an adjacent square is adjacent to zero mines. 
	Thanks a lot, go easy on the grading.

