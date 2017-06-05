#pragma once
#include"BoardChange.h"
#include"Field.h"
#define BOARD_ROWS 8
#define BOARD_COLS 9

class Board
{
private:
	Field board[BOARD_ROWS][BOARD_COLS];
	// Przesuwa pionki
	void pushFigure(BoardChange& change);
	// Analizuje stan planszy sprawdzaj¹cy czy nale¿y przesunaæ jakieœ pionki. Zwraca który pionke nale¿y przesun¹æ. 
	BoardChange** analyzeBoard(Field& player);
public:
	Board();
	~Board();
	void PrintBoard();
	// Funkcja s³u¿y do aktualizowania zmian na planszy na podstawie ruchu gracza
	bool InputChange(BoardChange& change);	// true - zmiany wprowadzone pomyslnie, false - wpp
};

