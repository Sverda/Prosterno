#include "Player.h"
#include<cstdio>
#include<ctype.h>

Player::Player():Person()
{
}

Player::~Player()
{
}

BoardChange Player::MakeMove()
{
	char figure[5];
	char destination[5];
	printf("Wykonywanie ruchu.\n");
	printf("Podaj figure: ");
	scanf("%s", figure);
	scanf("%s", destination);
	if (figure[0] < '0' || figure[0] >= '8' ||
		figure[1] < 'a' || figure[1] >= 'i' || 
		destination[0] < '0' || destination[0] >= '8' ||
		destination[1] < 'a' || destination[1] >= 'i')
	{
		return BoardChange();
	}
	return BoardChange(figure[0] - '0', figure[1] - 'a', destination[0] - '0', destination[1] - 'a', Field::Friend);
}