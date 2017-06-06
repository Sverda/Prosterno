#pragma once
#include"BoardChange.h"
#include"Board.h"
#define CHAR30 30

class Person
{
protected:
	Field mark;				// Oznaczenie gracza
	Board& boardManager;	// Ten sam obiekt co w klasie Game
	Field(&board)[BOARD_ROWS][BOARD_COLS];
public:
	Person(Board& _boardManager);
	Person(Field _mark, Board& _boardManager);
	~Person();
	virtual void MakeMove();
};

