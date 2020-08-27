#pragma once
#include <SFML\Graphics.hpp>

#define MAX_NUMBER_OF_CAT 10

class Category
{
public:
	Category(float width, float height);
	~Category();

	void Draw(sf::RenderWindow &window);
	void MoveUp();
	void MoveDown();
	int GetPressedItem() { return selectedItemIndex; }
private:
	int selectedItemIndex = 0;
	sf::Font font;
	sf::Text cat[MAX_NUMBER_OF_CAT];
};

