#pragma once
#define BOARD_ROWS 8
#define BOARD_COLS 9

class Board
{
public:
	enum class Field	// Zwieksza czytelnosc kodu
	{
		Friend = 'P',	// Pionki I gracza
		Empty = 'x',	// Brak zadnego pionka
		Enemy = 'W',	// Pionki II gracza
	};
private:
	Field board[BOARD_ROWS][BOARD_COLS];
public:
	Board();
	~Board();
	void PrintBoard();
	void PrintInstruction();
};

