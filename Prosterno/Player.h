#pragma once
#include"Person.h"

class Player: public Person
{
public:
	Player(Board& _boardManager);
	Player(Field _mark, Board& _boardManager);
	~Player();
	void MakeMove();
};

