// TIC TAC TOE
// Timothy Harasym - 200186529
// Nicholas Rowlandson - 200167125

#include "header.h"

using namespace std;

char slot[10] = { 'o','1','2','3','4','5','6','7','8','9' };

string checkWin();
void board();

int main()
{
	bool playAgain = true, correctSelection = false;
	int player = 1, choice;
	string i, playAgainChoice;
	char mark;

	while(playAgain)
	{
		do
		{
			board();
			player = (player % 2) ? 1 : 2;

			cout << "Player " << player << ", enter a number:  ";
			cin >> choice;

			mark = (player == 1) ? 'X' : 'O';

			if (choice == 1 && slot[1] == '1')
			{
				slot[1] = mark;
			}
			else if (choice == 2 && slot[2] == '2')
			{
				slot[2] = mark;
			}
			else if (choice == 3 && slot[3] == '3')
			{
				slot[3] = mark;
			}
			else if (choice == 4 && slot[4] == '4')
			{
				slot[4] = mark;
			}
			else if (choice == 5 && slot[5] == '5')
			{
				slot[5] = mark;
			}
			else if (choice == 6 && slot[6] == '6')
			{
				slot[6] = mark;
			}
			else if (choice == 7 && slot[7] == '7')
			{
				slot[7] = mark;
			}
			else if (choice == 8 && slot[8] == '8')
			{
				slot[8] = mark;
			}
			else if (choice == 9 && slot[9] == '9')
			{
				slot[9] = mark;
			}
			else
			{
				cout << "Invalid Selection. Select an empty slot. ";

				player--;
				cin.ignore();
				cin.get();
			}
			i = checkWin();
			player++;
		} while (i == "inProgress");

		board();

		if (i == "winner")
		{
			cout << "==>\aPlayer " << --player << " win!";
		}
		else
		{
			cout << "==>\aGame Draw...";
		}

		cin.ignore();
		cin.get();

		// check to make sure 
		while(!correctSelection)
		{
			cout << "Would you like to play again?(y/n): ";
			cin >> playAgainChoice;

			if (playAgainChoice == "y" || playAgainChoice == "Y" || playAgainChoice == "yes")
			{
				slot[1] = { '1' };
				slot[2] = { '2' };
				slot[3] = { '3' };
				slot[4] = { '4' };
				slot[5] = { '5' };
				slot[6] = { '6' };
				slot[7] = { '7' };
				slot[8] = { '8' };
				slot[9] = { '9' };
				correctSelection = true;
				playAgain = true;
			}
			else if (playAgainChoice == "n" || playAgainChoice == "N" || playAgainChoice == "no")
			{
				correctSelection = true;
				playAgain = false;
			}
			else
			{
				cout << "Enter a valid response. type 'y' to keep playing or 'n' to close application.";
				correctSelection = false;
			}
		}
		
	};

	// close the application
	return 0;
}

//FUNCTION TO DRAW BOARD OF TIC TAC TOE WITH PLAYERS MARK
void board()
{
	// clear screen 
	system("cls");

	cout << "\n\n\t\t   Tic Tac Toe\n\n";

	cout << "\t  Player 1 (X)  -  Player 2 (O)" << endl << endl;
	cout << endl;

	cout << "\t\t _________________" << endl;
	cout << "\t\t|     |     |     |" << endl;
	cout << "\t\t|  " << slot[1] << "  |  " << slot[2] << "  |  " << slot[3] <<  "  |" << endl;

	cout << "\t\t|_____|_____|_____|" << endl;
	cout << "\t\t|     |     |     |" << endl;

	cout << "\t\t|  " << slot[4] << "  |  " << slot[5] << "  |  " << slot[6] << "  |" << endl;

	cout << "\t\t|_____|_____|_____|" << endl;
	cout << "\t\t|     |     |     |" << endl ;

	cout << "\t\t|  " << slot[7] << "  |  " << slot[8] << "  |  " << slot[9] << "  |" << endl;

	cout << "\t\t|_____|_____|_____|" << endl << endl;
	cout << endl;
}

/*********************************************
This function returns the game status.
winner = game over with winner
inProgress = game is still in progress
tie =  tie between player one and two
**********************************************/
string checkWin()
{
	if (slot[1] == slot[2] && slot[2] == slot[3])
	{
		return "inProgress";
	}
	else if (slot[4] == slot[5] && slot[5] == slot[6])
	{
		return "inProgress";
	}
	else if (slot[7] == slot[8] && slot[8] == slot[9])
	{
		return "inProgress";
	}
	else if (slot[1] == slot[4] && slot[4] == slot[7])
	{
		return "inProgress";
	}
	else if (slot[2] == slot[5] && slot[5] == slot[8])
	{
		return "inProgress";
	}
	else if (slot[3] == slot[6] && slot[6] == slot[9])
	{
		return "inProgress";
	}
	else if (slot[1] == slot[5] && slot[5] == slot[9])
	{
		return "inProgress";
	}
	else if (slot[3] == slot[5] && slot[5] == slot[7])
	{
		return "inProgress";
	}
	else if (slot[1] != '1' && slot[2] != '2' && slot[3] != '3'
		&& slot[4] != '4' && slot[5] != '5' && slot[6] != '6'
		&& slot[7] != '7' && slot[8] != '8' && slot[9] != '9')
	{
		return "tie";
	}
	else
	{
		return "winner";
	}

}

//END OF PROJECT
