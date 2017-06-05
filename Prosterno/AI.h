#pragma once
#include "Person.h"
class AI :
	public Person
{
public:
	AI(Board& _boardManager);
	AI(char* _name, Field _mark, Board& _boardManager);
	~AI();
	void MakeMove();
};

