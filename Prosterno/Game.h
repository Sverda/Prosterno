#pragma once
#include"Board.h"
#include"Player.h"
#include"AI.h"

class Game
{
private:
	Board board;
	Player player;
	AI ai;
public:
	Game();
	~Game();
	void PrintStartInstruction();
	void PlayRound();
};