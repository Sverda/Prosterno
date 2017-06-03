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
		if ((change.nextRow == (change.prevRow + 1) || change.nextRow == (change.prevRow - 1)) &&
			(change.nextCol == (change.prevCol + 1) || change.nextCol == (change.prevCol - 1)))
		{
			pushFigure(change);
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

void Board::pushFigure(BoardChange& change)
{
	Field opponent = !change.player;
	// Ruch pionka
	board[change.prevRow][change.prevCol] = Field::Empty;
	board[change.nextRow][change.nextCol] = change.player;
	// Wykrywanie przeciwnik�w
	bool enemies[4];	// enemies[0] - g�ra, enemies[1] - prawa, enemies[2] - d�, enemies[3] - lewa
						// Warto�� true oznacza �e znajduje si� tam pionek przeciwnika
	// G�ra
	if (board[change.nextRow + 1][change.nextCol] == opponent)
	{
		enemies[0] = true;
	}
	else
	{
		enemies[0] = false;
	}
	// Prawa
	if (board[change.nextRow][change.nextCol + 1] == opponent)
	{
		enemies[1] = true;
	}
	else
	{
		enemies[1] = false;
	}
	// D�
	if (board[change.nextRow - 1][change.nextCol] == opponent)
	{
		enemies[2] = true;
	}
	else
	{
		enemies[2] = false;
	}
	// Lewa
	if (board[change.nextRow][change.nextCol - 1] == opponent)
	{
		enemies[3] = true;
	}
	else
	{
		enemies[3] = false;
	}
	//TODO: Przesun�� figury wroga i ewentualnie wykona� reakcj� �a�cuchow�. 
}