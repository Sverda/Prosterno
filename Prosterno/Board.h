#pragma once
#include"BoardChange.h"
#include"Field.h"
#define BOARD_ROWS 8
#define BOARD_COLS 9

class Board
{
private:
	Field board[BOARD_ROWS][BOARD_COLS];
	// Przemieszcza pionek do konkretnego pola i popycha znajduj¹ce siê tam pionki przeciwnika
	void pushFigure(BoardChange& change);
public:
	Board();
	~Board();
	void PrintBoard();
	// Funkcja s³u¿y do aktualizowania zmian na planszy na podstawie ruchu gracza
	bool InputChange(BoardChange& change);	// true - zmiany wprowadzone pomyslnie, false - wpp
};

