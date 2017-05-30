#pragma once
class Board
{
public:
	enum class Field
	{
		Friend = 1,
		Empty = 0,
		Enemy = -1,
	};
private:
	Field board[8][9];
public:
	Board();
	~Board();
	void Print();
};

