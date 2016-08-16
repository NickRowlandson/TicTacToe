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

		// colors!
		hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

		do
		{
			board();
			if (player % 2)
			{
				player = 1;
			}
			else 
			{
				player = 2;
			}

			SetConsoleTextAttribute(hConsole, yellow);
			cout << "\t  ==> ";
			SetConsoleTextAttribute(hConsole, white);
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

		// if i is equal to 'winner' then state the winner, else display game draw 
		if (i == "winner")
		{
			SetConsoleTextAttribute(hConsole, yellow);
			cout << "\a\t  ==> ";
			SetConsoleTextAttribute(hConsole, white);
			cout << "Player " << --player << " wins!";
		}
		else
		{
			SetConsoleTextAttribute(hConsole, yellow);
			cout << "\a\t  ==> ";
			SetConsoleTextAttribute(hConsole, white);
			cout << "Game draw...";
		}

		cin.ignore();
		cin.get();

		// check to make sure valid selection for play again was made 
		while(!correctSelection)
		{
			// ask if player wants to go again
			SetConsoleTextAttribute(hConsole, yellow);
			cout << "\t  ==> ";
			SetConsoleTextAttribute(hConsole, white);
			cout <<"Would you like to play again?(y/n): ";

			cin >> playAgainChoice;

			// if 'y' then set playAgain to true, else if 'n' terminate program
			if (playAgainChoice == "y" || playAgainChoice == "Y" || playAgainChoice == "yes")
			{
				// set items in slot array back to original characters
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
				SetConsoleTextAttribute(hConsole, yellow);
				cout << "\t  ==> ";
				SetConsoleTextAttribute(hConsole, white);
				cout << "Enter a valid response. type 'y' to keep playing or 'n' to close application." << endl;
				correctSelection = false;
			}
		}
	};

	// close the application
	return 0;
}

/*********************************************
This function draws the TicTacToe board using values from the slot array. Player choices formatted with color(X = green, O = red).
*********************************************/
void board()
{
	// colors!
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	// clear screen 
	system("cls");

	// game title 
	cout << "\n\n\t\t   Tic Tac Toe\n\n";
	cout << "\t  Player 1 (X)  -  Player 2 (O)" << endl << endl;
	cout << endl;
	cout << "\t\t _________________" << endl;
	cout << "\t\t|     |     |     |" << endl;
	cout << "\t\t|  ";

	// if character in slot 1 is 'X' then mark it green, else if mark is 'O' mark it red
	if (slot[1] == 'X')
	{
		SetConsoleTextAttribute(hConsole, red);
	}
	else if (slot[1] == 'O')
	{
		SetConsoleTextAttribute(hConsole, green);
	}
	cout << slot[1];
	SetConsoleTextAttribute(hConsole, white);
	cout << "  |  ";

	// if character in slot 2 is 'X' then mark it green, else if mark is 'O' mark it red
	if (slot[2] == 'X')
	{
		SetConsoleTextAttribute(hConsole, red);
	}
	else if (slot[2] == 'O')
	{
		SetConsoleTextAttribute(hConsole, green);
	}
	cout << slot[2];
	SetConsoleTextAttribute(hConsole, white);
	cout << "  |  ";

	// if character in slot 3 is 'X' then mark it green, else if mark is 'O' mark it red
	if (slot[3] == 'X')
	{
		SetConsoleTextAttribute(hConsole, red);
	}
	else if (slot[3] == 'O')
	{
		SetConsoleTextAttribute(hConsole, green);
	}
	cout << slot[3];
	SetConsoleTextAttribute(hConsole, white);
	cout <<  "  |" << endl;
	cout << "\t\t|_____|_____|_____|" << endl;
	cout << "\t\t|     |     |     |" << endl;
	cout << "\t\t|  ";

	// if character in slot 4 is 'X' then mark it green, else if mark is 'O' mark it red
	if (slot[4] == 'X')
	{
		SetConsoleTextAttribute(hConsole, red);
	}
	else if (slot[4] == 'O')
	{
		SetConsoleTextAttribute(hConsole, green);
	}
	cout << slot[4];
	SetConsoleTextAttribute(hConsole, white);
	cout << "  |  ";

	// if character in slot 5 is 'X' then mark it green, else if mark is 'O' mark it red
	if (slot[5] == 'X')
	{
		SetConsoleTextAttribute(hConsole, red);
	}
	else if (slot[5] == 'O')
	{
		SetConsoleTextAttribute(hConsole, green);
	}
	cout << slot[5];
	SetConsoleTextAttribute(hConsole, white);
	cout << "  |  ";

	// if character in slot 6 is 'X' then mark it green, else if mark is 'O' mark it red
	if (slot[6] == 'X')
	{
		SetConsoleTextAttribute(hConsole, red);
	}
	else if (slot[6] == 'O')
	{
		SetConsoleTextAttribute(hConsole, green);
	}
	cout << slot[6];
	SetConsoleTextAttribute(hConsole, white);
	cout << "  |" << endl;
	cout << "\t\t|_____|_____|_____|" << endl;
	cout << "\t\t|     |     |     |" << endl ;
	cout << "\t\t|  ";

	// if character in slot 7 is 'X' then mark it green, else if mark is 'O' mark it red
	if (slot[7] == 'X')
	{
		SetConsoleTextAttribute(hConsole, red);
	}
	else if (slot[7] == 'O')
	{
		SetConsoleTextAttribute(hConsole, green);
	}
	cout << slot[7];
	SetConsoleTextAttribute(hConsole, white);
	cout << "  |  ";

	// if character in slot 8 is 'X' then mark it green, else if mark is 'O' mark it red
	if (slot[8] == 'X')
	{
		SetConsoleTextAttribute(hConsole, red);
	}
	else if (slot[8] == 'O')
	{
		SetConsoleTextAttribute(hConsole, green);
	}
	cout << slot[8];
	SetConsoleTextAttribute(hConsole, white);
	cout << "  |  ";

	// if character in slot 9 is 'X' then mark it green, else if mark is 'O' mark it red
	if (slot[9] == 'X')
	{
		SetConsoleTextAttribute(hConsole, red);
	}
	else if (slot[9] == 'O')
	{
		SetConsoleTextAttribute(hConsole, green);
	}
	cout << slot[9];
	SetConsoleTextAttribute(hConsole, white);
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
