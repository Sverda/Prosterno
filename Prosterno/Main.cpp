#include<cstdio>
#include<cstdlib>
#include"Game.h"

int main()
{
	Game<AI, AI> game;
	while (!game.CheckEndgame())
	{
		game.PlayRound();
		//system("cls");
	}
	printf("\nKoniec gry\n\n");
}