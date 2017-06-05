#include "Person.h"
#include<cstring>

Person::Person()
{
	name = new char[7] {"Damian"};
	mark = Field::Friend;
}

Person::Person(char * _name, Field _mark)
{
	int len = (int)strlen(_name);
	name = new char[len + 1];
	strcpy(name, _name);
	mark = _mark;
}

Person::~Person()
{
	delete name;
}
