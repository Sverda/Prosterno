#pragma once
#include"Board.h"
#include"Player.h"
#include"AI.h"
#include<cstdio>
#include<cstdlib>
#include<ctime>

// Zarz¹dza ogólnym przebiegiem gry i jest poœrednikiem pomiêdzy main a systemem gry. 
template <typename P, typename E>	// P - player, E - enemy
class Game
{
private:
	Board board;
	Person* player;
	Person* enemy;
	bool endgame;	// Okreœla, czy nast¹pi³ koniec gry
	void PrintStartInstruction();
public:
	Game();
	~Game();
	void PlayRound();
	bool CheckEndgame();
}; 



template <typename P, typename E>
Game<P, E>::Game()
{
	player = new P("Gracz", Field::Friend, board);
	enemy = new E("Przeciwnik", Field::Enemy, board);
	srand((int)time(NULL));	// Losowanie dla AI
	PrintStartInstruction();
	endgame = false;
}

template <typename P, typename E>
Game<P, E>::~Game()
{
	delete player;
	delete enemy;
}

template <typename P, typename E>
void Game<P, E>::PrintStartInstruction()
{
	printf("Twoje pionki (lub I gracza) sa oznaczone jako: P\n");
	printf("Pionki przeciwnika (lub II gracza) natomiast jako: W\n\n");
	printf("Ruszanie pionka: RzadKolumna Rzad2Kolumna2\n");
}

template <typename P, typename E>
void Game<P, E>::PlayRound()
{
	board.PrintBoard();
	player->MakeMove();

	//board.PrintBoard();
	enemy->MakeMove();

	//board.PrintBoard();
	endgame = board.CheckEndgame();
}

template <typename P, typename E>
bool Game<P, E>::CheckEndgame()
{
	return endgame;
}