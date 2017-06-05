#include "Game.h"
#include<cstdio>
#include<cstdlib>
#include<ctime>

Game::Game():player("Gracz", Field::Friend, board), ai(board), enemy("Przeciwnik", Field::Enemy, board)
{
	srand((int)time(NULL));	// Losowanie dla AI
	PrintStartInstruction();
	endgame = false;
}

Game::~Game()
{
}

void Game::PrintStartInstruction()
{
	printf("Twoje pionki (lub I gracza) sa oznaczone jako: P\n");
	printf("Pionki przeciwnika (lub II gracza) natomiast jako: W\n\n");
	printf("Ruszanie pionka: RzadKolumna Rzad2Kolumna2\n");
}

void Game::PlayRound()
{
	//TODO: Obs³uga b³êdów
	board.PrintBoard();
	player.MakeMove();

	board.PrintBoard();
	ai.MakeMove();

	board.PrintBoard();
	endgame = board.CheckEndgame();
}

bool Game::CheckEndgame()
{
	return endgame;
}