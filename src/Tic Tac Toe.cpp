//============================================================================
// Name        : Tic.cpp
// Author      : Nathan Kong
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
#include <iostream>
#include <vector>

using namespace std;

void drawBoard(const vector <char> &gameBoard) {
   for (int i = 0; i < 9; i += 3) {
      cout << "  " << gameBoard.at(i) << "  |  " << gameBoard.at(i + 1) << "  |  "
    	   << gameBoard.at(i + 2) << "  " << endl;
      if (i < 6) {
         cout << "-----|-----|-----" << endl;
      }
   }
   cout << endl;

   return;
}

void initVector(vector <char> &v) {

   for (unsigned int i = 0; i < v.size(); ++i)
      v.at(i) = static_cast<char> (97 + i);
}

int convertPosition(char boardPosition) {

   return boardPosition - 97;
}

bool validPlacement(const vector<char>  &gameBoard, int positionIndex) {
   bool tempBool = false;

   if (positionIndex >= gameBoard.size() || positionIndex < 0)
      return tempBool;
   else if ((gameBoard.at(positionIndex) >= 97) && (gameBoard.at(positionIndex) <= 105))
      tempBool = true;

   return tempBool;
}

int getPlay(const vector<char> &gameBoard) {
   unsigned char boardPosition = ' ';

   cout << "Please choose a position: " << endl;
   cin >> boardPosition;

   while (!(validPlacement (gameBoard, convertPosition(boardPosition)))) {
	   cout << "Invalid option, please choose another position: " << endl;
       cin >> boardPosition;
   }

   return convertPosition(boardPosition);
}

bool gameWon(const vector<char> &gameBoard) {
   bool gameWin = false;

      if ((gameBoard.at(0) == gameBoard.at(1)) && (gameBoard.at(0) == gameBoard.at(2)))
         gameWin = true;
      else if ((gameBoard.at(3) == gameBoard.at(4)) && (gameBoard.at(4)== gameBoard.at(5)))
         gameWin = true;
      else if ((gameBoard.at(6) == gameBoard.at(7)) && (gameBoard.at(7) == gameBoard.at(8)))
         gameWin = true;
      else if ((gameBoard.at(0) == gameBoard.at(3)) && (gameBoard.at(3) == gameBoard.at(6)))
         gameWin = true;
      else if ((gameBoard.at(1) == gameBoard.at(4)) && (gameBoard.at(4) == gameBoard.at(7)))
         gameWin = true;
      else if ((gameBoard.at(2) == gameBoard.at(5)) && (gameBoard.at(5) == gameBoard.at(8)))
         gameWin = true;
      else if ((gameBoard.at(0) == gameBoard.at(4)) && (gameBoard.at(4) == gameBoard.at(8)))
         gameWin = true;
      else if ((gameBoard.at(2) == gameBoard.at(4)) && (gameBoard.at(4) == gameBoard.at(6)))
         gameWin = true;

   return gameWin;
}

bool boardFull(const vector<char> &gameBoard) {
   bool fullBoard = true;

   for (unsigned int i = 0; i < gameBoard.size(); ++i) {
	   if (gameBoard.at(i) >= 97 && gameBoard.at(i) <= 105) {
         fullBoard = false;
         break;
       }
   }

   return fullBoard;
}

int main() {
	vector<char> gameBoard(9);
	string playerWinner = "Player 1";
	char playAgain = 'Y';

	while (playAgain == 'Y') {
		initVector(gameBoard);
		drawBoard(gameBoard);

		while (!boardFull(gameBoard) && !gameWon(gameBoard)) {
			cout << "Player 1's turn." << endl;
			gameBoard.at(getPlay(gameBoard)) = 'X';
			drawBoard(gameBoard);
			playerWinner = "Player 1";

			if (!boardFull(gameBoard) && !gameWon(gameBoard)) {
				cout << "Player 2's turn." << endl;
				gameBoard.at(getPlay(gameBoard)) = 'O';
				drawBoard(gameBoard);
				playerWinner = "Player 2";
			}
		}

		if (gameWon(gameBoard))
			cout << playerWinner << " Wins!" << endl;
		else
			cout << "No one wins." << endl;

		cout << "Play again? Type Y or N." << endl;
		cin >> playAgain;

		while (playAgain != 'N' && playAgain != 'Y') {
			cout << "Please only enter Y or N. Try again." << endl;
			cin >> playAgain;
		}
	}

	if (playAgain == 'N')
		cout << "Alright, good bye." << endl;

	return 0;
}
