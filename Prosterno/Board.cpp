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

bool Board::InputChange(BoardChange& change)
{
	// Sprawdzenie, czy na odpowiednim polu znajduje siê pion nale¿¹cy do gracza
	if (board[change.prevRow][change.prevCol] == change.player)
	{
		// Nie mo¿na siê ruszyæ na swojego pionka
		if (board[change.nextRow][change.nextCol] == change.player)
		{
			return false;
		}
		// Sprawdzanie, czy pionek ruszy siê na dozwolone pole
		//TODO: Uwzglêdniæ to ¿e pionek mo¿e siê cofaæ tylko gdy mo¿e popchn¹æ pionka. 
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
	// Wykrywanie przeciwników
	bool enemies[4];	// enemies[0] - góra, enemies[1] - prawa, enemies[2] - dó³, enemies[3] - lewa
						// Wartoœæ true oznacza ¿e znajduje siê tam pionek przeciwnika
	// Góra
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
	// Dó³
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
	//TODO: Przesun¹æ figury wroga i ewentualnie wykonaæ reakcjê ³añcuchow¹. 
}