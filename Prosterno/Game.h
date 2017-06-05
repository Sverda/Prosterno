#pragma once
#include"Board.h"
#include"Player.h"
#include"AI.h"

// Zarz¹dza ogólnym przebiegiem gry i jest poœrednikiem pomiêdzy main a systemem gry. 
class Game
{
private:
	Board board;
	Player player;
	Player enemy;
	AI ai;
	bool endgame;	// Okreœla, czy nast¹pi³ koniec gry
	void PrintStartInstruction();
public:
	Game();
	~Game();
	void PlayRound();
	bool CheckEndgame();
};