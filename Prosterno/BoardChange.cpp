#include "BoardChange.h"

BoardChange::BoardChange()
{
	prevRow = -1;
	prevCol = -1;
	nextRow = -1;
	nextCol = -1;
	player = Field::Empty;
}

BoardChange::BoardChange(const BoardChange & mk)
{
	prevRow = mk.prevRow;
	prevCol = mk.prevCol;
	nextRow = mk.nextRow;
	nextCol = mk.nextCol;
	player = mk.player;
}

BoardChange::~BoardChange()
{
}
