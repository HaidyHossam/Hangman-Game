#pragma once
#include<SFML\Graphics.hpp>

#define MAX_NUMBER_OF_LEVELS 4

class Level
{
public:

	Level(float width, float height);
	~Level();

	void Draw(sf::RenderWindow &window);
	void MoveUp();
	void MoveDown();
	int GetPressedItem() { return selectedItemIndex; }

private:
	int selectedItemIndex = 0;
	sf::Font font;
	sf::Text level[MAX_NUMBER_OF_LEVELS];

};

