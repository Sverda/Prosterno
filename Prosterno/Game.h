#pragma once
#include"Board.h"
#include"Player.h"

class Game
{
private:
	Board board;
	Player player;
public:
	Game();
	~Game();
	void PrintStartInstruction();
	void PlayRound();
};

