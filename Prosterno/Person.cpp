#include "Person.h"

Person::Person()
{
	name = new char[] {"Damian"};
	mark = Field::Friend;
}

Person::~Person()
{
	delete name;
}
