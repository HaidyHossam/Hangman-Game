#include "Category.h"



Category::Category(float width, float height)
{
	font.loadFromFile("films.dynasty.ttf");
	cat[0].setFont(font);
	cat[0].setFillColor(sf::Color::White);
	cat[0].setString("Actors");
	cat[0].setPosition(sf::Vector2f((width / 2) - 50, height / (MAX_NUMBER_OF_CAT + 1) * 1));

	cat[1].setFont(font);
	cat[1].setFillColor(sf::Color::Black);
	cat[1].setString("Animals");
	cat[1].setPosition(sf::Vector2f((width / 2) - 50, height / (MAX_NUMBER_OF_CAT + 1) * 2));

	cat[2].setFont(font);
	cat[2].setFillColor(sf::Color::Black);
	cat[2].setString("Cars");
	cat[2].setPosition(sf::Vector2f((width / 2) - 50, height / (MAX_NUMBER_OF_CAT + 1) * 3));

	cat[3].setFont(font);
	cat[3].setFillColor(sf::Color::Black);
	cat[3].setString("Countries");
	cat[3].setPosition(sf::Vector2f((width / 2) - 50, height / (MAX_NUMBER_OF_CAT + 1) * 4));

	cat[4].setFont(font);
	cat[4].setFillColor(sf::Color::Black);
	cat[4].setString("Food");
	cat[4].setPosition(sf::Vector2f((width / 2) - 50, height / (MAX_NUMBER_OF_CAT + 1) * 5));

	cat[5].setFont(font);
	cat[5].setFillColor(sf::Color::Black);
	cat[5].setString("Harry Potter");
	cat[5].setPosition(sf::Vector2f((width / 2) - 50, height / (MAX_NUMBER_OF_CAT + 1) * 6));

	cat[6].setFont(font);
	cat[6].setFillColor(sf::Color::Black);
	cat[6].setString("Marvel");
	cat[6].setPosition(sf::Vector2f((width / 2) - 50, height / (MAX_NUMBER_OF_CAT + 1) * 7));

	cat[7].setFont(font);
	cat[7].setFillColor(sf::Color::Black);
	cat[7].setString("Movies");
	cat[7].setPosition(sf::Vector2f((width / 2) - 50, height / (MAX_NUMBER_OF_CAT + 1) * 8));

	cat[8].setFont(font);
	cat[8].setFillColor(sf::Color::Black);
	cat[8].setString("Songs");
	cat[8].setPosition(sf::Vector2f((width / 2) - 50, height / (MAX_NUMBER_OF_CAT + 1) * 9));

	cat[9].setFont(font);
	cat[9].setFillColor(sf::Color::Black);
	cat[9].setString("Random");
	cat[9].setPosition(sf::Vector2f((width / 2) - 50, height / (MAX_NUMBER_OF_CAT + 1) * 10));
}

void Category::Draw(sf::RenderWindow &window)
{
	for (int i = 0; i < MAX_NUMBER_OF_CAT; i++)
	{
		window.draw(cat[i]);
	}
}

void Category::MoveUp()
{
	if (selectedItemIndex - 1 >= 0)
	{
		cat[selectedItemIndex].setFillColor(sf::Color::Black);
		selectedItemIndex--;
		cat[selectedItemIndex].setFillColor(sf::Color::White);
	}
}

void Category::MoveDown()
{
	if (selectedItemIndex + 1 < MAX_NUMBER_OF_CAT)
	{
		cat[selectedItemIndex].setFillColor(sf::Color::Black);
		selectedItemIndex++;
		cat[selectedItemIndex].setFillColor(sf::Color::White);
	}
}

Category::~Category()
{
}
