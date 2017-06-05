#include<cstdio>
#include<cstdlib>
#include<ctime>
#include"Game.h"

int main()
{
	srand((int)time(NULL));	// Losowanie dla AI
	Game game;
	game.PlayRound();
}