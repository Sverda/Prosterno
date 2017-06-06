#include "Board.h"
#include<cstdio>
#include<cstdlib>

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

//U¿yto printf dla ³atwiejszego formatowania danych
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
	int verticalNumber = 0;
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
		if (change.nextCol >= 0 && change.nextCol < 9 && 
			(change.nextRow == (change.prevRow + 1) || change.nextRow == (change.prevRow - 1)) &&
			(change.nextCol == (change.prevCol + 1) || change.nextCol == (change.prevCol - 1)))
		{
			Save(TEMPSAVE);
			int nulls;	// iloœæ nie poruszonych figur
			BoardChange* moves[MOVES];
			// Ruch pionka
			board[change.prevRow][change.prevCol] = Field::Empty;
			board[change.nextRow][change.nextCol] = change.player;
			// Poruszanie reszt¹ pionków - reakcja ³añcuchowa
			do
			{
				nulls = 0;
				analyzeBoard(change.player, moves);
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
				for (int i = 0; i < MOVES; i++)
				{
					delete moves[i];
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

bool Board::CheckEndgame()
{
	bool endgame = false;
	// Sprawdzanie, czy któryœ z graczy nie ma ju¿ pionków
	int figuresCount = 0;
	for (int row = 0; row < BOARD_ROWS; row++)
	{
		for (int col = 0; col < BOARD_COLS; col++)
		{
			if (board[row][col] == Field::Friend)
			{
				figuresCount++;
			}
		}
	}
	if (figuresCount == 0)
	{
		endgame = true;
	}
	figuresCount = 0;
	for (int row = 0; row < BOARD_ROWS; row++)
	{
		for (int col = 0; col < BOARD_COLS; col++)
		{
			if (board[row][col] == Field::Enemy)
			{
				figuresCount++;
			}
		}
	}
	if (figuresCount == 0)
	{
		endgame = true;
	}
	// Sprawdzanie, czy któryœ z graczy doszed³ do koñca planszy
	for (int col = 0; col < BOARD_COLS; col++)
	{
		// Przyjazny gracz zawsze zaczyna na dole
		if (board[BOARD_ROWS - 1][col] == Field::Enemy)
		{
			endgame = true;
		}
		// Nieprzyjazny gracz zawsze zaczyna na górze
		if (board[0][col] == Field::Friend)
		{
			endgame = true;
		}
	}
	return endgame;
}

void Board::Save(char* fname)
{
	//TODO: Sprawdzanie struktury pliku
	FILE* file;
	file = fopen(fname, "r");
	if (file == NULL)
	{
		perror("Nie udalo sie otworzyc pliku");
		return;
	}
	for (int row = 0; row < BOARD_ROWS; row++)
	{
		for (int col = 0; col < BOARD_COLS; col++)
		{
			fprintf(file, "%d ", board[row][col]);
		}
		fprintf(file, "\n");
	}
	fclose(file);
}

void Board::Load(char* fname)
{
	FILE* file;
	file = fopen(fname, "r");
	if (file == NULL)
	{
		return;
	}
	int temp;
	for (int row = 0; row < BOARD_ROWS; row++)
	{
		for (int col = 0; col < BOARD_COLS; col++)
		{
			fscanf(file, "%d ", &temp);
			board[row][col] = (Field)temp;
		}
		fscanf(file, "\n");
	}
	fclose(file);
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
		board[change.nextRow][change.nextCol] = change.player;
	}
}

void Board::analyzeBoard(Field & player, BoardChange** moves)
{
	Field opponent = !player;
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
				return;
			}
		}
	}
}
