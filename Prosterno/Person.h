#pragma once
#include"BoardChange.h"
#define CHAR30 30

//TODO: Czy konstruktor siê wykona jeœli to klasa abstrakcyjna?
class Person
{
protected:
	char name[CHAR30];
	Field mark;	// Oznaczenie gracza
	Person();
	Person(char* _name, Field _mark);
	~Person();
	virtual BoardChange MakeMove() = 0;
public:
	char* GetName();
};

