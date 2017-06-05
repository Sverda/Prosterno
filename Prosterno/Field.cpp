#include"Field.h"

const Field operator!(const Field field)
{
	if (field == Field::Empty)
	{
		return field;
	}
	else if (field == Field::Enemy)
	{
		return Field::Friend;
	}
	else
	{
		return Field::Enemy;
	}
}