#pragma once
#include"BoardChange.h"
#define BOARD_ROWS 8
#define BOARD_COLS 9
#define SAVEFILE "save.txt"
//#define TEMPSAVE "tempsave.txt"	/*plik do którego jest zapisywany co rundê stan gry*/
#define MOVES 20 /*iloœæ ruchów przechowywanych w buforze moves*/

class Board
{
private:
	Field board[BOARD_ROWS][BOARD_COLS];
	// Przesuwa pionki
	void pushFigure(BoardChange& change);
	// Analizuje stan planszy sprawdzaj¹cy czy nale¿y przesunaæ jakieœ pionki. Zwraca który pionke nale¿y przesun¹æ. 
	void analyzeBoard(Field& player, BoardChange** moves);
public:
	Board();
	~Board();
	void PrintBoard();
	// Funkcja s³u¿y do aktualizowania zmian na planszy na podstawie ruchu gracza
	bool InputChange(BoardChange& change);	// true - zmiany wprowadzone pomyslnie, false - wpp
	bool CheckEndgame();
	void Save(char* fname);
	void Load(char* fname);
	friend class Person;
	friend class Player;
};

