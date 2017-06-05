#include"AI.h"
#include<cstdlib>
#define FIG_COUNT 9 /*iloœæ figur przypadaj¹ca na jednego gracza*/

AI::AI(Board& _boardManager) :Person("Przeciwnik", Field::Enemy), boardManager(_boardManager), board(_boardManager.board)
{
}

AI::~AI()
{
}

BoardChange AI::MakeMove()
{
	// Zbieranie wszystkich dostêpnych pionków na planszy...
	int positions[FIG_COUNT][2];
	int positionCount = 0;
	for (int row = 0; row < BOARD_ROWS; row++)
	{
		for (int col = 0; col < BOARD_COLS; col++)
		{
			if (board[row][col] == mark)
			{
				positions[positionCount][0] = row;
				positions[positionCount][1] = col;
				positionCount++;
			}
		}
	}
	// ...losowanie ktory ma sie ruszyc i gdzie
	int prevRow, prevCol;	// Pozycja wylosowanej figury
	int nextRow, nextCol;	// Przewidywan pozycja wylosowanej figury
	int figure;				// Indeks wylosowanej figury
	do
	{
		figure = rand() % positionCount;
		prevRow = positions[figure][0];
		prevCol = positions[figure][1];
		nextRow = prevRow + 1;
		// Ruch tylko na skos
		nextCol = rand() % 2;
		if (nextCol == 0)
		{
			nextCol -= 1;
		}
		nextCol += prevCol;
	} while (!boardManager.InputChange(BoardChange(prevRow, prevCol, nextRow, nextCol, mark)));
	return BoardChange();
}
