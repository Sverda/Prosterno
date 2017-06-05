#include<cstdio>
#include<cstdlib>
#include<ctime>
#include"Game.h"

int main()
{
	srand((int)time(NULL));	// Losowanie dla AI
	Game game;
	while (!game.CheckEndgame())
	{
		game.PlayRoundWithAI();
		system("cls");
	}
}