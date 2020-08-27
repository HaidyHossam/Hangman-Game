#pragma once
#include <SFML\Graphics.hpp>
#include <iostream>

using namespace std;

class PlayerName
{
public:
	sf::Text Name;
	sf::Font font;
	string Player;
	sf::Text *Dashes = new sf::Text[4];
	int i = 0;

	void Draw(sf::RenderWindow&);
	PlayerName(float width, float height);
	~PlayerName();
};

