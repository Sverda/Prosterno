#include<iostream>
#include"Game.h"
using namespace std;

int main()
{
	// Menu
	GameBase* game;
	cout << "Wybierz tryb gry: " << endl;
	cout << "1. Gracz vs Gracz" << endl;
	cout << "2. Gracz vs Komputer" << endl;
	cout << "3. Komputer vs Komputer" << endl;
	int choice;
	cout << "Podaj numer trybu: ";
	while (scanf("%d", &choice) != 1 || choice < 1 || choice > 3)
	{
		printf("Brak podanej opcji. \n");
		cout << "Podaj numer trybu: ";
	}
	//scanf("%d", &choice);
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
	cout << "Wczytac wczesniej zapisana gre? " << endl;
	cout << "1. Tak" << endl;
	cout << "2. Nie" << endl;
	cout << "Podaj numer: ";
	while (scanf("%d", &choice) != 1 || choice < 1 || choice > 2)
	{
		printf("Brak podanej opcji. \n");
		cout << "Podaj numer: ";
	}
	if (choice == 1)
	{
		game->LoadBoard();
	}

	while (!game->CheckEndgame())
	{
		game->PlayRound();
	}
	cout << "\nKoniec gry" << endl;
	delete game;
}