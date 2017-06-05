#pragma once
#include"BoardChange.h"
#include"Board.h"
#define CHAR30 30

//TODO: Czy konstruktor siê wykona jeœli to klasa abstrakcyjna?
class Person
{
protected:
	char name[CHAR30];
	Field mark;				// Oznaczenie gracza
	Board& boardManager;	// Ten sam obiekt co w klasie Game
	Field(&board)[BOARD_ROWS][BOARD_COLS];
	Person(Board& _boardManager);
	Person(char* _name, Field _mark, Board& _boardManager);
	~Person();
	virtual void MakeMove() = 0;
public:
	char* GetName();
};

