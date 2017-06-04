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
	// G�rne litery pomocnicze
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

bool Board::InputChange(BoardChange& change)
{
	// Sprawdzenie, czy na odpowiednim polu znajduje si� pion nale��cy do gracza
	if (board[change.prevRow][change.prevCol] == change.player)
	{
		// Nie mo�na si� ruszy� na swojego pionka
		if (board[change.nextRow][change.nextCol] == change.player)
		{
			return false;
		}
		// Sprawdzanie, czy pionek ruszy si� na dozwolone pole
		//TODO: Uwzgl�dni� to �e pionek mo�e si� cofa� tylko gdy mo�e popchn�� pionka. 
		//TODO: Uwzgl�dni� �eby pionek nie m�g� wyj�� poza plansz�. 
		if ((change.nextRow == (change.prevRow + 1) || change.nextRow == (change.prevRow - 1)) &&
			(change.nextCol == (change.prevCol + 1) || change.nextCol == (change.prevCol - 1)))
		{
			// Ruch pionka
			board[change.prevRow][change.prevCol] = Field::Empty;
			board[change.nextRow][change.nextCol] = change.player;
			// Poruszanie reszt� pionk�w - reakcja �a�cuchowa
			while (pushFigure(change))
			{
				change.player = !change.player;
			}
		}
		else
		{
			return false;
		}
	}
	else
	{
		return false;
	}
	return true;
}

bool Board::pushFigure(BoardChange& change)
{
	Field opponent = !change.player;
	
	//TODO: Uwzgl�dni� zakres tablicy
	// Pionek g�rny
	if (change.nextRow + 1 >= BOARD_ROWS 
		|| board[change.nextRow + 1][change.nextCol] == opponent)	// Wykrywanie przeciwnika
	{
		// Sprawdzanie, czy pionek mo�e si� przesun�� o dwa pola, je�li nie mo�e to zostanie zdj�ty z planszy. 
		if (change.nextRow + 1 + 2 >= BOARD_ROWS
			|| board[change.nextRow + 1 + 2][change.nextCol] == opponent)
		{
			board[change.nextRow + 1][change.nextCol] = Field::Empty;
		}
		else
		{
			board[change.nextRow + 1][change.nextCol] = Field::Empty;
			board[change.nextRow + 1 + 2][change.nextCol] = opponent;
		}
	}
	// Pionek prawy
	if (change.nextCol + 1 >= BOARD_COLS
		|| board[change.nextRow][change.nextCol + 1] == opponent)
	{
		if (change.nextCol + 1 + 2 >= BOARD_COLS
			|| board[change.nextRow][change.nextCol + 1 + 2] == opponent)
		{
			board[change.nextRow][change.nextCol + 1] = Field::Empty;
		}
		else
		{
			board[change.nextRow][change.nextCol + 1] = Field::Empty;
			board[change.nextRow][change.nextCol + 1 + 2] = opponent;
		}
	}
	// Pionek dolny
	if (change.nextRow - 1 < 0
		|| board[change.nextRow - 1][change.nextCol] == opponent)
	{
		if (change.nextRow - 1 - 2 < 0
			|| board[change.nextRow - 1 - 2][change.nextCol] == opponent)
		{
			board[change.nextRow - 1][change.nextCol] = Field::Empty;
		}
		else
		{
			board[change.nextRow - 1][change.nextCol] = Field::Empty;
			board[change.nextRow - 1 - 2][change.nextCol] = opponent;
		}
	}
	// Pionek lewy
	if (change.nextCol - 1 < 0
		|| board[change.nextRow][change.nextCol - 1] == opponent)
	{
		if (change.nextCol - 1 - 2 < 0
			|| board[change.nextRow][change.nextCol - 1 - 2] == opponent)
		{
			board[change.nextRow][change.nextCol - 1] = Field::Empty;
		}
		else
		{
			board[change.nextRow][change.nextCol - 1] = Field::Empty;
			board[change.nextRow][change.nextCol - 1 - 2] = opponent;
		}
	}
}