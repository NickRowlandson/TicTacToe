// TIC TAC TOE
// Timothy Harasym - 200186529
// Nicholas Rowlandson - 200167125

#include "header.h"

using namespace std;

char slot[10] = { 'o','1','2','3','4','5','6','7','8','9' };

string checkStatus();
void board();

int main()
{
	bool playAgain = true;

	while(playAgain)
	{
		bool correctSelection = false;
		int player = 1, choice;
		string i, playAgainChoice;
		char mark;

		hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

		do
		{
			board();
			player = (player % 2) ? 1 : 2;

			SetConsoleTextAttribute(hConsole, 14);
			cout << "\t  ==> ";
			SetConsoleTextAttribute(hConsole, 15);
			cout << "Player " << player << ", enter a number:  ";

			cin >> choice;

			if (player == 1)
			{
				mark = 'X';
			}
			else
			{
				mark = 'O';
			}

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
				cout << "\t  Invalid Selection. Select an empty slot. ";

				player--;
				cin.ignore();
				cin.get();
			}
			i = checkStatus();
			player++;
		} while (i == "inProgress");

		board();

		if (i == "winner")
		{
			SetConsoleTextAttribute(hConsole, 14);
			cout << "\a\t  ==> ";
			SetConsoleTextAttribute(hConsole, 15);
			cout << "Player " << --player << " wins!";
		}
		else
		{
			SetConsoleTextAttribute(hConsole, 14);
			cout << "\a\t  ==> ";
			SetConsoleTextAttribute(hConsole, 15);
			cout << "Game draw...";
		}

		cin.ignore();
		cin.get();

		// check to make sure correct selection for play again was made 
		while(!correctSelection)
		{
			SetConsoleTextAttribute(hConsole, 14);
			cout << "\t  ==> ";
			SetConsoleTextAttribute(hConsole, 15);
			cout <<"Would you like to play again?(y/n): ";

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
				SetConsoleTextAttribute(hConsole, 14);
				cout << "\t  ==> ";
				SetConsoleTextAttribute(hConsole, 15);
				cout << "Enter a valid response. type 'y' to keep playing or 'n' to close application." << endl;
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
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	// clear screen 
	system("cls");

	cout << "\n\n\t\t   Tic Tac Toe\n\n";

	cout << "\t  Player 1 (X)  -  Player 2 (O)" << endl << endl;
	cout << endl;

	cout << "\t\t _________________" << endl;
	cout << "\t\t|     |     |     |" << endl;

	cout << "\t\t|  ";

	if (slot[1] == 'X')
	{
		SetConsoleTextAttribute(hConsole, 10);
	}
	else if (slot[1] == 'O')
	{
		SetConsoleTextAttribute(hConsole, 12);
	}
	cout << slot[1];

	SetConsoleTextAttribute(hConsole, 15);
	cout << "  |  ";

	if (slot[2] == 'X')
	{
		SetConsoleTextAttribute(hConsole, 10);
	}
	else if (slot[2] == 'O')
	{
		SetConsoleTextAttribute(hConsole, 12);
	}
	cout << slot[2];

	SetConsoleTextAttribute(hConsole, 15);
	cout << "  |  ";

	if (slot[3] == 'X')
	{
		SetConsoleTextAttribute(hConsole, 10);
	}
	else if (slot[3] == 'O')
	{
		SetConsoleTextAttribute(hConsole, 12);
	}
	cout << slot[3];

	SetConsoleTextAttribute(hConsole, 15);
	cout <<  "  |" << endl;

	cout << "\t\t|_____|_____|_____|" << endl;
	cout << "\t\t|     |     |     |" << endl;
	cout << "\t\t|  ";

	// colors!
	if (slot[4] == 'X')
	{
		SetConsoleTextAttribute(hConsole, 10);
	}
	else if (slot[4] == 'O')
	{
		SetConsoleTextAttribute(hConsole, 12);
	}
	cout << slot[4];

	SetConsoleTextAttribute(hConsole, 15);
	cout << "  |  ";

	if (slot[5] == 'X')
	{
		SetConsoleTextAttribute(hConsole, 10);
	}
	else if (slot[5] == 'O')
	{
		SetConsoleTextAttribute(hConsole, 12);
	}
	cout << slot[5];

	SetConsoleTextAttribute(hConsole, 15);
	cout << "  |  ";

	if (slot[6] == 'X')
	{
		SetConsoleTextAttribute(hConsole, 10);
	}
	else if (slot[6] == 'O')
	{
		SetConsoleTextAttribute(hConsole, 12);
	}
	cout << slot[6];

	SetConsoleTextAttribute(hConsole, 15);
	cout << "  |" << endl;

	cout << "\t\t|_____|_____|_____|" << endl;
	cout << "\t\t|     |     |     |" << endl ;

	cout << "\t\t|  ";

	if (slot[7] == 'X')
	{
		SetConsoleTextAttribute(hConsole, 10);
	}
	else if (slot[7] == 'O')
	{
		SetConsoleTextAttribute(hConsole, 12);
	}
	cout << slot[7];

	SetConsoleTextAttribute(hConsole, 15);
	cout << "  |  ";

	if (slot[8] == 'X')
	{
		SetConsoleTextAttribute(hConsole, 10);
	}
	else if (slot[8] == 'O')
	{
		SetConsoleTextAttribute(hConsole, 12);
	}
	cout << slot[8];

	SetConsoleTextAttribute(hConsole, 15);
	cout << "  |  ";

	if (slot[9] == 'X')
	{
		SetConsoleTextAttribute(hConsole, 10);
	}
	else if (slot[9] == 'O')
	{
		SetConsoleTextAttribute(hConsole, 12);
	}
	cout << slot[9];

	SetConsoleTextAttribute(hConsole, 15);
	cout << "  |" << endl;

	cout << "\t\t|_____|_____|_____|" << endl << endl;
	cout << endl;
}

/*********************************************
This function returns the game status.
winner = game over with winner
inProgress = game is still in progress
tie =  tie between player one and two
**********************************************/
string checkStatus()
{
	if (slot[1] == slot[2] && slot[2] == slot[3])
	{
		return "winner";
	}
	else if (slot[4] == slot[5] && slot[5] == slot[6])
	{
		return "winner";
	}
	else if (slot[7] == slot[8] && slot[8] == slot[9])
	{
		return "winner";
	}
	else if (slot[1] == slot[4] && slot[4] == slot[7])
	{
		return "winner";
	}
	else if (slot[2] == slot[5] && slot[5] == slot[8])
	{
		return "winner";
	}
	else if (slot[3] == slot[6] && slot[6] == slot[9])
	{
		return "winner";
	}
	else if (slot[1] == slot[5] && slot[5] == slot[9])
	{
		return "winner";
	}
	else if (slot[3] == slot[5] && slot[5] == slot[7])
	{
		return "winner";
	}
	else if (slot[1] != '1' && slot[2] != '2' && slot[3] != '3'
		&& slot[4] != '4' && slot[5] != '5' && slot[6] != '6'
		&& slot[7] != '7' && slot[8] != '8' && slot[9] != '9')
	{
		return "tie";
	}
	else
	{
		return "inProgress";
	}

}

//END OF PROJECT
