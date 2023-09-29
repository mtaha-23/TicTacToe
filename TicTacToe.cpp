#include <iostream>
#include <cstdlib>
using namespace std;

int main()
{
	system("color 3F");

	cout << "\n\n\t\t TIC TAC TOE GAME\t\n\n";

	//Menu
	int menu = 0;
	while (menu != 4)
	{
		system("cls");
		cout << "\nMENU\n";
		cout << "\n1. Instructions " << "\n2. Play Game" << "\n3. Exit";
		do
		{
			cout << "\nEnter choice : ";
			cin >> menu;
		} while (menu < 1 || menu > 3);
		switch (menu)
		{
		case 1: //Instruction will display if 1 is entered
		{
			system("cls");
			cout << "\n======INSTRUCTIONS=======\n\n";
			cout << "\nThe goal of tic-tac-toe is to be the first player to get three symbols in a row on a 3-by-3 grid\n";
			cout << "In a 3-by-3 grid game, players alternate placing Xs and Os on the board until either player has three\n";
			cout << "symbol in a row, horizontally, vertically, or diagonally or until all squares on the grid are filled.\n";
			cout << "If a player is able to draw three Xs or three Os in a row, then that player wins.If all squares\n";
			cout << "are filled and neither player has made a complete row of Xs or Os, then the game is a draw.\n";
			cout << "Enter the row position of the cell either to mark .\n";
			system("pause");
			break;
		}
		case 2:  //gameplay if 2 is entered.
		{
			int player = 0;
			char mark;
			int choice = 0;
			int results = 0;
			bool toss = false;
			char one = '1', two = '2', three = '3', four = '4', five = '5', six = '6', seven = '7', eight = '8', nine = '9';
			cout << "Choose Player 1 (X) or Player 2 (O)?\nEnter player: ";
			cin >> player;
			while (player < 1 || player > 2)
			{
				cout << "Invalid input. Enter again: ";
				cin >> player;
			}

			// TOSS for PLAYERS 
			int tosschoice = 0;
			cout << "Choose either to toss? \n1.Head  \n2.Tail \nEnter:  ";
			cin >> tosschoice;
			while (tosschoice < 1 || tosschoice > 2)
			{
				cout << "Invalid input. Enter again: ";
				cin >> tosschoice;
			}
			int randomNumber = 1 + rand() % 2;
			if (randomNumber == 1)
			{
				if (tosschoice == 1)
				{
					cout << "You won the toss. You will play first\n";
					system("pause");
					toss = true;
				}
				else
					toss = false;
			}
			else
			{
				if (tosschoice == 2)
				{
					cout << "You won the toss. You will play first\n";
					toss = true;
					system("pause");
				}
				else
					toss = false;
			}
			if (!toss)
			{
				player == 1 ? player++ : player--;
				cout << "You lost the toss. Player " << player << " will play first!\n";
				system("pause");
			}

			// PLAY GAME 
			do
			{
				system("cls");
				cout << "\nPlayer " << player << "'s Turn";
				cout << "\n\nPlayer 1 (X) - Player 2 (O)\n\n\n";
				cout << "    " << "     |     |     \n";
				cout << "    " << "  " << one << "  |  " << two << "  |  " << three << "\n";

				cout << "    " << "_____|_____|_____" << "\n";
				cout << "    " << "     |     |     " << "\n";

				cout << "    " << "  " << four << "  |  " << five << "  |  " << six << "\n";

				cout << "    " << "_____|_____|_____" << "\n";
				cout << "    " << "     |     |     " << "\n";

				cout << "    " << "  " << seven << "  |  " << eight << "  |  " << nine << "\n";

				cout << "    " << "     |     |     " << "\n\n";

				cout << "Player " << player << ", please enter a number to mark:  ";
				cin >> choice;
				while (choice > 9 || (choice == 1 && one != '1') || (choice == 2 && two != '2') || (choice == 3 && three != '3') ||
					(choice == 4 && four != '4') || (choice == 5 && five != '5') || (choice == 6 && six != '6') ||
					(choice == 7 && seven != '7') || (choice == 8 && eight != '8') || (choice == 9 && nine != '9'))
				{

					cout << "Invalid input. Enter again: ";
					cin >> choice;
				}

				//ENtering

				mark = (player == 1) ? 'X' : 'O';
				if (choice == 1)
					one = mark;
				else if (choice == 2)
					two = mark;
				else if (choice == 3)
					three = mark;
				else if (choice == 4)
					four = mark;
				else if (choice == 5)
					five = mark;
				else if (choice == 6)
					six = mark;
				else if (choice == 7)
					seven = mark;
				else if (choice == 8)
					eight = mark;
				else if (choice == 9)
					nine = mark;

				// checking WIN CONDITIONS
				if (one == two && two == three)
					results = 1;
				else if (four == five && five == six)
					results = 1;
				else if (seven == eight && eight == nine)
					results = 1;
				else if (one == four && four == seven)
					results = 1;
				else if (two == five && five == eight)
					results = 1;
				else if (three == six && six == nine)
					results = 1;
				else if (one == five && five == nine)
					results = 1;
				else if (three == five && five == seven)
					results = 1; // to check win
				else if (one != '1' && two != '2' && three != '3' && four != '4' && five != '5' && six != '6'
					&& seven != '7' && eight != '8' && nine != '9')
					results = -1;// to check draw
				else
					results = 0; // to continue game

				player == 1 ? player++ : player--;
			} while (results == 0);

			//DRAW BOARD AGAIN
			system("cls");
			cout << "\n\nPlayer 1 (X) - Player 2 (O)\n\n\n";
			cout << "    " << "     |     |     \n";
			cout << "    " << "  " << one << "  |  " << two << "  |  " << three << "\n";

			cout << "    " << "_____|_____|_____" << "\n";
			cout << "    " << "     |     |     " << "\n";

			cout << "    " << "  " << four << "  |  " << five << "  |  " << six << "\n";

			cout << "    " << "_____|_____|_____" << "\n";
			cout << "    " << "     |     |     " << "\n";

			cout << "    " << "  " << seven << "  |  " << eight << "  |  " << nine << "\n";

			cout << "    " << "     |     |     " << "\n\n";

			if (results == 1)
				player == 2 ? cout << "Player 1 WINS!\n" : cout << "Player 2 WINS!\n";
			else
				cout << "GAME DRAW! \n";


			system("pause");
			break;
		}
		case 3:
			cout << "\nTHANK YOU FOR PLAYING!\n";
			break;
		}
	}

	return 0;
}
