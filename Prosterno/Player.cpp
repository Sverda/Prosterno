#include "Player.h"
#include<cstdio>
#include<ctype.h>
#include<cstring>

Player::Player(Board& _boardManager):Person(_boardManager)
{
}

Player::Player(char * _name, Field _mark, Board& _boardManager):Person(_name, _mark, _boardManager)
{
}

Player::~Player()
{
}

void Player::MakeMove()
{
	char figure[3];
	char destination[3];
	printf("Wykonywanie ruchu.\n");
	bool loop;
	do
	{
		loop = false;
		printf("Podaj ruch: ");
		scanf("%s %s", figure, destination);
		if (figure[0] < '0' || figure[0] >= '8' ||
			figure[1] < 'a' || figure[1] >= 'i' ||
			destination[0] < '0' || destination[0] >= '8' ||
			destination[1] < 'a' || destination[1] >= 'i')
		{
			printf("Nie mozna zrealizowac tego ruchu. \n");
			loop = true;
		}
	} while (loop || !boardManager.InputChange(BoardChange(figure[0] - '0', figure[1] - 'a', destination[0] - '0', destination[1] - 'a', mark)));
}