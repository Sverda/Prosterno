#include "Board.h"
#include<cstdio>



Board::Board()
{
	//Startowe rozmieszczenie pionkow na planszy
	for (int row = 0; row < BOARD_ROWS; row++)
	{
		for (int col = 0; col < BOARD_COLS; col++)
		{
			if (row == 0)
			{
				if (col%2 == 1)
				{
					board[row][col] = Field::Enemy;
				}
				else
				{
					board[row][col] = Field::Empty;
				}
			}
			else if (row == 1)
			{
				if (col % 2 == 0)
				{
					board[row][col] = Field::Enemy;
				}
				else
				{
					board[row][col] = Field::Empty;
				}
			}
			else if (row == 6)
			{
				if (col % 2 == 0)
				{
					board[row][col] = Field::Friend;
				}
				else
				{
					board[row][col] = Field::Empty;
				}
			}
			else if (row == 7)
			{
				if (col % 2 == 1)
				{
					board[row][col] = Field::Friend;
				}
				else
				{
					board[row][col] = Field::Empty;
				}
			}
			else
			{
				board[row][col] = Field::Empty;
			}
		}
	}
}


Board::~Board()
{
}

void Board::PrintBoard()
{
	//TODO: Implement board game, example: https://camo.githubusercontent.com/2585c1c742042de7781976bf005ea81c41ee234f/687474703a2f2f692e696d6775722e636f6d2f417358686876432e706e67
	// Górne litery pomocnicze
	char horizontalLetter = 'a';
	printf("   ");
	for (int i = 0; i < BOARD_COLS; i++)
	{
		printf("%2c", horizontalLetter++);
	}
	printf("\n\n");

	// Plansza
	int verticalNumber = 1;
	for (int i = 0; i < BOARD_ROWS; i++)
	{
		// Lewe cyfry pomocnicze
		printf("%-3d", verticalNumber);
		//Pole gry
		for (int j = 0; j < BOARD_COLS; j++)
		{
			printf("%2c", board[i][j]);
		}
		// Prawe cyfry pomocnicze
		printf("%4d\n", verticalNumber++);
	}

	// Dolne litery pomocnicze
	horizontalLetter = 'a';
	printf("\n   ");
	for (int i = 0; i < BOARD_COLS; i++)
	{
		printf("%2c", horizontalLetter++);
	}
	printf("\n\n");
}

void Board::PrintInstruction()
{
	/*printf("Gra polega na dostaniu sie swoim pionkiem do\n");
	printf("drugiego kranca planszy. \n");*/
	printf("Twoje pionki (lub I gracza) sa oznaczone jako: P\n");
	printf("Pionki przeciwnika (lub II gracza) natomiast jako: W\n\n");
}
