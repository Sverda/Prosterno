#pragma once
#include"Field.h"

// Klasa s³u¿y do przekazywania zmian które nale¿y wprowadziæ do rozmieszczenia pionków na planszy. 
// W przypadku nie wykonania poprawnej akcji wszystkie wartosci s¹ ustalone na -1
class BoardChange
{
private:
	int prevRow;	// Rz¹d pionka który musi zostaæ przemieszczony
	int prevCol;	// Kolumna pionka który musi zostaæ przemieszczony
	int nextRow;	// Rz¹d do którego pionek musi zostaæ przemieszczony
	int nextCol;	// Kolumna do której pionek musi zostaæ przemieszczony
	Field player;	// Gracz który wykona³ ruch
public:
	BoardChange(int _prevRow, int _prevCol, int _nextRow, int _nextCol): 
		prevRow(_prevRow), prevCol(_prevCol), 
		nextRow(_nextRow), nextCol(_nextCol){}
	~BoardChange();
	friend class Board;
};

