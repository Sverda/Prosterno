#pragma once
#include "Person.h"
class AI :
	public Person
{
public:
	AI(Board& _boardManager);
	AI(Field _mark, Board& _boardManager);
	~AI();
	void MakeMove();
};

