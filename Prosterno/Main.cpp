#include<cstdio>
#include<cstdlib>
#include"Game.h"

int main()
{
	// Menu
	GameBase* game;
	printf("Wybierz tryb gry: \n");
	printf("1. Gracz vs Gracz\n");
	printf("2. Gracz vs Komputer\n");
	printf("3. Komputer vs Komputer\n");
	int choice;
	printf("Podaj numer trybu: ");
	scanf("%d", &choice);
	switch (choice)
	{
	case 1:
		game = new Game<Player, Player>();
		break;
	case 2:
		game = new Game<Player, AI>();
		break;
	default:
		game = new Game<AI, AI>();
		break;
	}
	printf("Wczytac wczesniej zapisana gre? \n");
	printf("1. Tak\n");
	printf("2. Nie\n");
	scanf("%d", &choice);
	if (choice == 1)
	{
		game->LoadBoard();
	}
	while (!game->CheckEndgame())
	{
		game->PlayRound();
	}
	printf("\nKoniec gry\n\n");
	delete game;
}