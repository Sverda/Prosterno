#pragma once
#include"BoardChange.h"

//TODO: Czy konstruktor siê wykona jeœli to klasa abstrakcyjna?
class Person
{
protected:
	char* name;
	Field mark;	// Oznaczenie gracza
	Person();
	Person(char* _name, Field _mark);
	~Person();
	virtual BoardChange MakeMove() = 0;
};

