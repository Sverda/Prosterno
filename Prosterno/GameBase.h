#pragma once

// Klasa abstrakcyja potrzebna aby w Menu funkcji main() by³o mo¿liwe utworzenie obiektu klasy Game dynamicznie.
// Problemem by³ szablon klasy. 
class GameBase
{
public:
	GameBase() {}
	~GameBase() {}
	virtual void PlayRound() = 0;
	virtual bool CheckEndgame() = 0;
	virtual void LoadBoard() = 0;
};