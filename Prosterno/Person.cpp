#include "Person.h"
#include<cstring>

Person::Person(Board& _boardManager): boardManager(_boardManager), board(_boardManager.board)
{
	mark = Field::Friend;
}

Person::Person(Field _mark, Board& _boardManager): boardManager(_boardManager), board(_boardManager.board)
{
	mark = _mark;
}

Person::~Person()
{
}

void Person::MakeMove()
{
}