#pragma once

// Klasa abstrakcyja potrzebna aby w Menu funkcji main() by�o mo�liwe utworzenie obiektu klasy Game dynamicznie.
// Problemem by� szablon klasy. 
class GameBase
{
public:
	GameBase() {}
	~GameBase() {}
	virtual void PlayRound() = 0;
	virtual bool CheckEndgame() = 0;
	virtual void LoadBoard() = 0;
};