#include "Game.h"
#include<cstdio>

Game::Game()
{
	PrintStartInstruction();
}

Game::~Game()
{
}

void Game::PrintStartInstruction()
{
	/*printf("Gra polega na dostaniu sie swoim pionkiem do\n");
	printf("drugiego kranca planszy. \n");*/
	printf("Twoje pionki (lub I gracza) sa oznaczone jako: P\n");
	printf("Pionki przeciwnika (lub II gracza) natomiast jako: W\n\n");
	printf("Ruszanie pionka: RzadKolumna Rzad2Kolumna2\n");
	printf("RzadKolumna - miejsce z ktorego ruszamy pionkiem \nRzadKolumna2 - miejce do ktorego chcemy ruszyc pionka\n");
}

void Game::PlayRound()
{
	board.PrintBoard();
	bool result = board.InputChange(player.MakeMove());
	if (!result)
	{
		printf("\Ruch nie moze zostac wykonany. \n");
		return;
	}
}
