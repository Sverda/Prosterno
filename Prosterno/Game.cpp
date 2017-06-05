#include "Game.h"
#include<cstdio>

Game::Game(): ai(board)
{
	PrintStartInstruction();
	board.PrintBoard();
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

void Game::PlayRoundWithAI()
{
	bool result;
	BoardChange playerMove = player.MakeMove();
	if (playerMove == BoardChange())
	{
		result = false;
	}
	else
	{
		result = board.InputChange(playerMove);
	}
	if (!result)
	{
		printf("\nRuch nie moze zostac wykonany. \n");
		return;
	}
	board.PrintBoard();
	ai.MakeMove();
	board.PrintBoard();
	endgame = board.CheckEndgame();
}

bool Game::CheckEndgame()
{
	return endgame;
}