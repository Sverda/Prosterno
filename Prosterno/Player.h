#pragma once
#include"BoardChange.h"
#define CHAR40 40

class Player
{
private:
	char name[CHAR40];
	Field mark;	// Oznaczenie gracza
public:
	Player();
	~Player();
	BoardChange MakeMove();
};

