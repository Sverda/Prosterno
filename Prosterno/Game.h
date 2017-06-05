#pragma once
#include"Board.h"
#include"Player.h"
#include"AI.h"

// Zarz�dz og�lnym przebiegiem gry i jest po�rednikiem pomi�dzy main a systemem gry. 
class Game
{
private:
	Board board;
	Player player;
	AI ai;
	bool endgame;	// Okre�la, czy nast�pi� koniec gry
	void PrintStartInstruction();
public:
	Game();
	~Game();
	void PlayRoundWithAI();
	bool CheckEndgame();
};