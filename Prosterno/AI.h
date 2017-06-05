#pragma once
#include"Board.h"
#include "Person.h"
class AI :
	public Person
{
private:
	Board& boardManager;	// Ten sam obiekt co w klasie Game
	Field (&board)[BOARD_ROWS][BOARD_COLS];
public:
	AI(Board& _boardManager);
	~AI();
	BoardChange MakeMove();
};

