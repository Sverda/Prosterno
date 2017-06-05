#include "BoardChange.h"

BoardChange::BoardChange()
{
	prevRow = -1;
	prevCol = -1;
	nextRow = -1;
	nextCol = -1;
	player = Field::Empty;
}

BoardChange::BoardChange(Field _player)
{
	prevRow = -1;
	prevCol = -1;
	nextRow = -1;
	nextCol = -1;
	player = _player;
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

bool BoardChange::operator==(const BoardChange b)
{
	if (prevRow == b.prevRow &&
		prevCol == b.prevCol &&
		nextRow == b.nextRow &&
		nextCol == b.nextCol &&
		player == b.player)
	{
		return true;
	}
	return false;
}
