#include "Board.h"
#define BOARD_ROWS 8
#define BOARD_COLS 9



Board::Board()
{
	for (int i = 0; i < BOARD_ROWS; i++)
	{
		for (int j = 0; j < BOARD_COLS; j++)
		{
			board[i][j] = Field::Empty;
		}
	}
}


Board::~Board()
{
}

void Board::Print()
{
	//TODO: Implement board game
	// https://camo.githubusercontent.com/2585c1c742042de7781976bf005ea81c41ee234f/687474703a2f2f692e696d6775722e636f6d2f417358686876432e706e67
}
