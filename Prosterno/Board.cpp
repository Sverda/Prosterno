#include "Board.h"
#include<cstdio>
#define MOVES 20 /*iloœæ ruchów przechowywanych w buforze moves*/

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
		//TODO: Uwzglêdniæ ¿eby pionek nie móg³ wyjœæ poza planszê. 
		if ((change.nextRow == (change.prevRow + 1) || change.nextRow == (change.prevRow - 1)) &&
			(change.nextCol == (change.prevCol + 1) || change.nextCol == (change.prevCol - 1)))
		{
			// Ruch pionka
			board[change.prevRow][change.prevCol] = Field::Empty;
			board[change.nextRow][change.nextCol] = change.player;
			// Poruszanie reszt¹ pionków - reakcja ³añcuchowa
			BoardChange** moves;
			int nulls;	// iloœæ poruszonych figur
			do
			{
				nulls = 0;
				moves = analyzeBoard(change.player);
				for (int i = 0; i < MOVES; i++)
				{
					if (moves[i] != nullptr)
					{
						pushFigure(*moves[i]);
					}
					else
					{
						nulls++;
					}
				}
				change.player = !change.player;
			} while (nulls != MOVES);
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
	// Sprawdzanie, czy pionek mo¿e siê przesun¹æ o dwa pola, jeœli nie mo¿e to zostanie zdjêty z planszy. 
	if (change.nextRow >= BOARD_ROWS
		|| change.nextRow < 0
		|| change.nextCol >= BOARD_COLS
		|| change.nextCol < 0
		|| board[change.nextRow][change.nextCol] == opponent)
	{
		board[change.prevRow][change.prevCol] = Field::Empty;
	}
	else
	{
		board[change.prevRow][change.prevCol] = Field::Empty;
		board[change.nextRow][change.nextCol] = opponent;
	}
}

BoardChange** Board::analyzeBoard(Field & player)
{
	Field opponent = !player;
	BoardChange* moves[MOVES];
	int i;
	for (i = 0; i < MOVES; i++)
	{
		moves[i] = nullptr;
	}
	i = 0;
	for (int row = 0; row < BOARD_ROWS; row++)
	{
		for (int col = 0; col < BOARD_COLS; col++)
		{
			if (board[row][col] != player)
			{
				continue;
			}
			// Wykrywanie przeciwników wokó³ pionka
			// Pionek dolny
			if (row + 1 < BOARD_ROWS
				&& board[row + 1][col] == opponent)
			{
				moves[i++] = new BoardChange(row + 1, col, row + 3, col, opponent);
			}
			// Pionek prawy
			if (col + 1 < BOARD_COLS
				&& board[row][col + 1] == opponent)
			{
				moves[i++] = new BoardChange(row, col + 1, row, col + 3, opponent);
			}
			// Pionek górny
			if (row - 1 >= 0
				&& board[row - 1][col] == opponent)
			{
				moves[i++] = new BoardChange(row - 1, col, row - 3, col, opponent);
			}
			// Pionek lewy
			if (col - 1 >= 0
				&& board[row][col - 1] == opponent)
			{
				moves[i++] = new BoardChange(row, col - 1, row, col - 3, opponent);
			}
			if (i >= MOVES)
			{
				return moves;
			}
		}
	}
	return moves;
}
