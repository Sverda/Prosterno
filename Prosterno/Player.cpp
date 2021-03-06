#include "Player.h"
#include<cstdio>
#include<ctype.h>
#include<cstring>
#include<iostream>
using namespace std;


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
	//TODO: Wczyta� dane prosto do prevRow etc.
	char figure[3];
	char destination[3];
	int prevRow, prevCol;
	int nextRow, nextCol;
	bool loop;
	do
	{
		loop = false;
		cout << "Wskaz pionka: ";
		while (scanf("%s", figure) != 1)
		{
			printf("Prosze podac poprawne wartosci. \n");
		}
		cout << "Wskaz pole: ";
		while (scanf("%s", destination) != 1)
		{
			printf("Prosze podac poprawne wartosci. \n");
		}
		// Zapisywanie gry
		if (figure[0] == 's' &&
			figure[1] == 's' &&
			destination[0] == 's' &&
			destination[1] == 's')
		{
			boardManager.Save(SAVEFILE);
			cout << "Gra zostala zapisana. " << endl;
			loop = true;
		}
		// Prosta kontrola danych
		else if (figure[0] < '0' || figure[0] >= '8' ||
			figure[1] < 'a' || figure[1] >= 'i' ||
			destination[0] < '0' || destination[0] >= '8' ||
			destination[1] < 'a' || destination[1] >= 'i')
		{
			loop = true;
		}
		else
		{
			prevRow = figure[0] - '0';
			prevCol = figure[1] - 'a';
			nextRow = destination[0] - '0';
			nextCol = destination[1] - 'a';
		}

		// Cofanie si� pionka tylko w wyj�tkowej sytuacji
		if (((nextRow == (prevRow + 1) && mark == Field::Friend) ||
			(nextRow == (prevRow - 1) && mark == Field::Enemy)))
		{
			// Symulowanie poruszenia pionkiem, aby zobaczy� czy b�dzie jaki� pionek do popchni�cia
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
			if (loop)
			{
				cout << "Nie mozna zrealizowac tego ruchu. " << endl;
			}
		}
	} while (loop || !boardManager.InputChange(BoardChange(prevRow, prevCol, nextRow, nextCol, mark)));
}