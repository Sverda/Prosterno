#include "Person.h"
#include<cstring>

Person::Person()
{
	strcpy(name, "Damian");
	mark = Field::Friend;
}

Person::Person(char * _name, Field _mark)
{
	strcpy(name, _name);
	mark = _mark;
}

Person::~Person()
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
