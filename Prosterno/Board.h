#pragma once
#include"BoardChange.h"
#include"Field.h"
#define BOARD_ROWS 8
#define BOARD_COLS 9

class Board
{
private:
	Field board[BOARD_ROWS][BOARD_COLS];
public:
	Board();
	~Board();
	void PrintBoard();
	bool InputChange(BoardChange& change);	// true - zmiany wprowadzone pomyslnie, false - wpp
};

