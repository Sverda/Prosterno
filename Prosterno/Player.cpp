#include "Player.h"
#include<cstdio>
#include<ctype.h>
#include<cstring>

Player::Player(Board& _boardManager) :Person(_boardManager)
{
}

Player::Player(Field _mark, Board& _boardManager) : Person(_mark, _boardManager)
{
}

Player::~Player()
{
}

void Player::MakeMove()
{
	//TODO: Wczytaæ dane prosto do prevRow etc.
	char figure[3];
	char destination[3];
	int prevRow, prevCol;
	int nextRow, nextCol;
	bool loop;
	do
	{
		loop = false;
		printf("Podaj ruch: ");
		scanf("%s %s", figure, destination);
		// Zapisywanie gry
		if (figure[0] == 's' &&
			figure[1] == 's' &&
			destination[0] == 's' &&
			destination[1] == 's')
		{
			boardManager.Save(SAVEFILE);
			printf("Gra zostala zapisana. \n");
			loop = true;
		}
		// Prosta kontrola danych
		else if (figure[0] < '0' || figure[0] >= '8' ||
			figure[1] < 'a' || figure[1] >= 'i' ||
			destination[0] < '0' || destination[0] >= '8' ||
			destination[1] < 'a' || destination[1] >= 'i')
		{
			printf("Nie mozna zrealizowac tego ruchu. \n");
			loop = true;
		}
		else
		{
			prevRow = figure[0] - '0';
			prevCol = figure[1] - 'a';
			nextRow = destination[0] - '0';
			nextCol = destination[1] - 'a';
		}

		// Cofanie siê pionka tylko w wyj¹tkowej sytuacji
		//TODO: Uzwglêdniæ cofanie siê dla gracza górnego i dolnego
		if (((nextRow == (prevRow + 1) && mark == Field::Friend) ||
			(nextRow == (prevRow - 1) && mark == Field::Enemy)))
		{
			// Symulowanie poruszenia pionkiem, aby zobaczyæ czy bêdzie jakiœ pionek do popchniêcia
			BoardChange* moves[MOVES];
			int nulls = 0;
			board[prevRow][prevCol] = Field::Empty;
			board[nextRow][nextCol] = mark;
			boardManager.analyzeBoard(mark, moves);
			for (int i = 0; i < MOVES; i++)
			{
				if (moves[i] == nullptr)
				{
					nulls++;
				}
			}
			for (int i = 0; i < MOVES; i++)
			{
				delete moves[i];
			}
			if (nulls == MOVES)
			{
				loop = true;
			}
			board[prevRow][prevCol] = mark;
			board[nextRow][nextCol] = Field::Empty;
		}
	} while (loop || !boardManager.InputChange(BoardChange(prevRow, prevCol, nextCol, nextCol, mark)));
}