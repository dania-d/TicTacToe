//============================================================================
// Name        : TicTacToe.cpp
// Author      : Dania Dababo
// Copyright   :
// Description : 3X3 TicTacToe game that takes in row/column input from the user
//============================================================================

#include <iostream>
using namespace std;

bool isWon(char, char[3][3]);
bool isDraw(char[3][3]);
void displayBoard(char[3][3]);
void makeAMove(char[3][3], char);

int main() {
	char board[3][3] =
			{ { ' ', ' ', ' ' }, { ' ', ' ', ' ' }, { ' ', ' ', ' ' } };
	displayBoard(board);

	while (true) {
		// The first player makes a move
		makeAMove(board, 'X');
		displayBoard(board);

		if (isWon('X', board)) {
			cout << "X player won" << endl;
			exit(0);
		} else if (isDraw(board)) {
			cout << "No winner" << endl;
			exit(0);
		}

		// The second player makes a move
		makeAMove(board, 'O');
		displayBoard(board);

		if (isWon('O', board)) {
			cout << "O player won" << endl;
			exit(0);
		} else if (isDraw(board)) {
			cout << "No winner" << endl;
			exit(0);
		}
	}
	return 0;
}

void makeAMove(char board[3][3], char playersCharacter) {//takes in board and 'X' or 'O'
	int row, column;	// row and column entered by player

	while ((row < 0 || row > 2) || (column < 0 || column > 2)) {// loop until 0, 1, or 2 is entered
		cout << "Enter a row (0, 1, 2) for player " << playersCharacter << " : ";
		cin >> row;
		cout << "Enter a column (0, 1, 2) for player " << playersCharacter << " : ";
		cin >> column;

		char cellContent = board[row][column];	// cell occupant

		if (cellContent == 'X' || cellContent == 'O') {		// cell is not empty
			cout << "This cell is already occupied. Try a different cell\n";
			makeAMove(board, playersCharacter);			// call makeAMove again

		} else {	// cell is empty
			board[row][column] = playersCharacter;// add playerCharacter to board
		}
	}

}
// display board and its contents
void displayBoard(char board[3][3]) {

	for (int i = 0; i < 3; i++) {
		cout << "-------------\n";
		for (int j = 0; j < 3; j++) {
			if (j == 0) {
				cout << "| " << board[i][j];
			}
			if (j == 1) {
				cout << " | " << board[i][j];
			}
			if (j == 2) {
				cout << " | " << board[i][j] << " |\n";
			}
		}
	}
	cout << "-------------\n";
}
// check for a winner
bool isWon(char playerCharacter, char board[3][3]) {
	int count = 0;	// number of moves made

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (board[i][j] == playerCharacter) {
				count++;
			}
		}
	}

	if (count < 3) {	// less than 3 moves made, win not possible yet
		return false;
	}

	for (int i = 0; i < 3; i++) {
		// column win
		if ((board[0][i] == playerCharacter) && (board[1][i] == playerCharacter)
				&& (board[2][i] == playerCharacter)) {
			return true;
		}
		// row win
		if ((board[i][0] == playerCharacter) && (board[i][1] == playerCharacter)
				&& (board[i][2] == playerCharacter)) {
			return true;
		}

	}
	// diagonal win
	if ((board[0][0] == playerCharacter && board[1][1] == playerCharacter && board[2][2] == playerCharacter)
			|| (board[0][2] == playerCharacter && board[1][1] == playerCharacter && board[2][0] == playerCharacter)) {
		return true;
	} else {
		return false;
	}
	return false;
}

// board is full with no winner
bool isDraw(char board[3][3]) {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (board[i][j] == ' ') {// if any cell is unoccupied, return false
				return false;
			}
		}
	}
	return true;
}

