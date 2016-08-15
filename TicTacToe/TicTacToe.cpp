// TIC TAC TOE
// Timothy Harasym - 200186529
// Nicholas Rowlandson - 200167125

#include "header.h"

using namespace std;

char slot[10] = { 'o','1','2','3','4','5','6','7','8','9' };
int checkWin();
void board();

int main()
{
	int player = 1, i, choice;
	char mark;

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
			cout << "Invalid Selection ";

			player--;
			cin.ignore();
			cin.get();
		}
		i = checkWin();

		player++;
	} while (i == -1);

	board();

	if (i == 1)
	{
		cout << "==>\aPlayer " << --player << " win ";
	}
	else
	{
		cout << "==>\aGame Draw";
	}

	cin.ignore();
	cin.get();
	return 0;
}

/*********************************************
Function returns game status
1 FOR GAME IS OVER WITH RESULT
-1 FOR GAME IS IN PROGRESS
O GAME IS OVER AND NO RESULT
**********************************************/

int checkWin()
{
	if (slot[1] == slot[2] && slot[2] == slot[3])
	{
		return 1;
	}
	else if (slot[4] == slot[5] && slot[5] == slot[6])
	{
		return 1;
	}
	else if (slot[7] == slot[8] && slot[8] == slot[9])
	{
		return 1;
	}
	else if (slot[1] == slot[4] && slot[4] == slot[7])
	{
		return 1;
	}
	else if (slot[2] == slot[5] && slot[5] == slot[8])
	{
		return 1;
	}
	else if (slot[3] == slot[6] && slot[6] == slot[9])
	{
		return 1;
	}
	else if (slot[1] == slot[5] && slot[5] == slot[9])
	{
		return 1;
	}
	else if (slot[3] == slot[5] && slot[5] == slot[7])
	{
		return 1;
	}
	else if (slot[1] != '1' && slot[2] != '2' && slot[3] != '3'
		&& slot[4] != '4' && slot[5] != '5' && slot[6] != '6'
		&& slot[7] != '7' && slot[8] != '8' && slot[9] != '9')
	{
		return 0;
	}
	else
	{
		return -1;
	}

}


//FUNCTION TO DRAW BOARD OF TIC TAC TOE WITH PLAYERS MARK

void board()
{
	system("cls");
	cout << "\n\n\tTic Tac Toe\n\n";

	cout << "Player 1 (X)  -  Player 2 (O)" << endl << endl;
	cout << endl;

	cout << "     |     |     " << endl;
	cout << "  " << slot[1] << "  |  " << slot[2] << "  |  " << slot[3] << endl;

	cout << "_____|_____|_____" << endl;
	cout << "     |     |     " << endl;

	cout << "  " << slot[4] << "  |  " << slot[5] << "  |  " << slot[6] << endl;

	cout << "_____|_____|_____" << endl;
	cout << "     |     |     " << endl;

	cout << "  " << slot[7] << "  |  " << slot[8] << "  |  " << slot[9] << endl;

	cout << "     |     |     " << endl << endl;
}

//END OF PROJECT
