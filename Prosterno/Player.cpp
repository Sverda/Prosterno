#include "Player.h"
#include<cstdio>
#include<ctype.h>

Player::Player()
{
}

Player::~Player()
{
}

BoardChange Player::MakeMove()
{
	char userInput[5];
	printf("Wykonaj ruch: ");
	scanf("%s", userInput);
	//TODO: Kontrola poprawnosci danych
	return BoardChange(userInput[0], userInput[1], userInput[3], userInput[4], Field::Friend);
}