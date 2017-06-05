#include<cstdio>
#include<cstdlib>
#include"Game.h"

int main()
{
	Game game;
	while (!game.CheckEndgame())
	{
		game.PlayRound();
		//system("cls");
	}
}