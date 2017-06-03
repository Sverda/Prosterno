#pragma once

// Zwieksza czytelnosc kodu
enum class Field
{
	Friend = 'P',	// Pionki I gracza
	Empty = 'x',	// Brak zadnego pionka
	Enemy = 'W',	// Pionki II gracza
};

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