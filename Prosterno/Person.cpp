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
	delete name;
}

char * Person::GetName()
{
	char nametmp[CHAR30];
	strcpy(nametmp, name);
	return ;
}
