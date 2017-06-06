#pragma once
#include"GameBase.h"
#include"Board.h"
#include"Player.h"
#include"AI.h"
#include<cstdio>
#include<cstdlib>
#include<ctime>

// Zarz¹dza ogólnym przebiegiem gry i jest poœrednikiem pomiêdzy main a systemem gry. 
template <typename P, typename E>	// P - player, E - enemy
class Game: public GameBase
{
private:
	Board board;
	Person* player;
	Person* enemy;
	bool endgame;	// Okreœla, czy nast¹pi³ koniec gry
	void printStartInstruction();
public:
	Game();
	~Game();
	void PlayRound();
	bool CheckEndgame();
	void LoadBoard();
}; 



template <typename P, typename E>
Game<P, E>::Game()
{
	player = new P("Gracz", Field::Friend, board);
	enemy = new E("Przeciwnik", Field::Enemy, board);
	srand((int)time(NULL));	// Losowanie dla AI
	printStartInstruction();
	//board.PrintBoard();
	endgame = false;
}

template <typename P, typename E>
Game<P, E>::~Game()
{
	delete player;
	delete enemy;
}

template <typename P, typename E>
void Game<P, E>::printStartInstruction()
{
	printf("Twoje pionki (lub I gracza) sa oznaczone jako: P\n");
	printf("Pionki przeciwnika (lub II gracza) natomiast jako: W\n\n");
	printf("Ruszanie pionka: RzadKolumna Rzad2Kolumna2\n");
	printf("Aby zapisac wprowadz: ss ss, zamiast ruchu. \n");
}

template <typename P, typename E>
void Game<P, E>::PlayRound()
{
	board.PrintBoard();
	printf("Ruch I gracza\n");
	player->MakeMove();
	board.PrintBoard();
	endgame = board.CheckEndgame();
	if (endgame)
	{
		return;
	}
	printf("Ruch II gracza\n");
	enemy->MakeMove();
	endgame = board.CheckEndgame();
}

template <typename P, typename E>
bool Game<P, E>::CheckEndgame()
{
	return endgame;
}

template<typename P, typename E>
void Game<P, E>::LoadBoard()
{
	board.Load(SAVEFILE);
}
