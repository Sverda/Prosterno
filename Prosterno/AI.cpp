#include"AI.h"
#include<cstdio>
#include<cstdlib>
#include<iostream>
using namespace std;
#define FIG_COUNT 9 /*iloœæ figur przypadaj¹ca na jednego gracza*/

AI::AI(Board& _boardManager) :Person(Field::Enemy, _boardManager)
{
}

AI::AI(Field _mark, Board & _boardManager) : Person(_mark, _boardManager)
{
}

AI::~AI()
{
}

void AI::MakeMove()
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
		// Friend zawsze na dole, a Enamy na górze
		if (mark == Field::Enemy)
		{
			nextRow = prevRow + 1;
		}
		else if (mark == Field::Friend)
		{
			nextRow = prevRow - 1;
		}
		// Ruch tylko na skos
		nextCol = rand() % 2;
		if (nextCol == 0)
		{
			nextCol -= 1;
		}
		nextCol += prevCol;
	} while (!boardManager.InputChange(BoardChange(prevRow, prevCol, nextRow, nextCol, mark)));
	printf("Wykonano ruch: %d%c %d%c\n", prevRow, prevCol + 'a', nextRow, nextCol + 'a');

}
