#pragma once
#include"BoardChange.h"
#define BOARD_ROWS 8
#define BOARD_COLS 9
#define SAVEFILE "save.txt"
//#define TEMPSAVE "tempsave.txt"	/*plik do kt�rego jest zapisywany co rund� stan gry*/
#define MOVES 20 /*ilo�� ruch�w przechowywanych w buforze moves*/

class Board
{
private:
	Field board[BOARD_ROWS][BOARD_COLS];
	// Przesuwa pionki
	void pushFigure(BoardChange& change);
	// Analizuje stan planszy sprawdzaj�cy czy nale�y przesuna� jakie� pionki. Zwraca kt�ry pionke nale�y przesun��. 
	void analyzeBoard(Field& player, BoardChange** moves);
public:
	Board();
	~Board();
	void PrintBoard();
	// Funkcja s�u�y do aktualizowania zmian na planszy na podstawie ruchu gracza
	bool InputChange(BoardChange& change);	// true - zmiany wprowadzone pomyslnie, false - wpp
	bool CheckEndgame();
	void Save(char* fname);
	void Load(char* fname);
	friend class Person;
	friend class Player;
};

