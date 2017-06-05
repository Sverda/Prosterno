#pragma once
#include"Field.h"

// Klasa s�u�y do przekazywania zmian kt�re nale�y wprowadzi� do rozmieszczenia pionk�w na planszy. 
// W przypadku nie wykonania poprawnej akcji wszystkie wartosci kolum i wierszy s� ustalone na -1, a player na Empty
class BoardChange
{
private:
	int prevRow;	// Rz�d pionka kt�ry musi zosta� przemieszczony
	int prevCol;	// Kolumna pionka kt�ry musi zosta� przemieszczony
	int nextRow;	// Rz�d do kt�rego pionek musi zosta� przemieszczony
	int nextCol;	// Kolumna do kt�rej pionek musi zosta� przemieszczony
	Field player;	// Gracz kt�ry wykona� ruch
public:
	BoardChange();
	BoardChange(Field _player);
	BoardChange(const BoardChange& mk);
	BoardChange(int _prevRow, int _prevCol, int _nextRow, int _nextCol, Field _player): 
		prevRow(_prevRow), prevCol(_prevCol), 
		nextRow(_nextRow), nextCol(_nextCol), player(_player){}
	~BoardChange();
	bool operator==(const BoardChange b);
	friend class Board;
};

