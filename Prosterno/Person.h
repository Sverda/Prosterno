#pragma once
#include"BoardChange.h"

//TODO: Czy konstruktor siê wykona jeœli to klasa abstrakcyjna?
class Person
{
protected:
	char* name;
	Field mark;	// Oznaczenie gracza
	Person();
	~Person();
	virtual BoardChange MakeMove() = 0;
};

