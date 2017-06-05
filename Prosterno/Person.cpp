#include "Person.h"
#include<cstring>

Person::Person(Board& _boardManager): boardManager(_boardManager), board(_boardManager.board)
{
	strcpy(name, "Gracz");
	mark = Field::Friend;
}

Person::Person(char * _name, Field _mark, Board& _boardManager): boardManager(_boardManager), board(_boardManager.board)
{
	strcpy(name, _name);
	mark = _mark;
}

Person::~Person()
{
}

void Person::MakeMove()
{
}

char * Person::GetName()
{
	int len = (int)strlen(name);
	char* nametmp = new char[len];
	strcpy(nametmp, name);
	return nametmp;
	//TODO: Nie zapomnij dealokowaæ zmiennej nametmp. 
}
