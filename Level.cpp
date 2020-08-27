#include "Level.h"


Level::Level(float width, float height)
{
	font.loadFromFile("films.dynasty.ttf");

	level[0].setFont(font);
	level[0].setFillColor(sf::Color::White);
	level[0].setString("Easy");
	level[0].setPosition(sf::Vector2f((width / 2) - 50, height / (MAX_NUMBER_OF_LEVELS + 1) * 1));

	level[1].setFont(font);
	level[1].setFillColor(sf::Color::Black);
	level[1].setString("Meduim");
	level[1].setPosition(sf::Vector2f((width / 2) - 50, height / (MAX_NUMBER_OF_LEVELS + 1) * 2));

	level[2].setFont(font);
	level[2].setFillColor(sf::Color::Black);
	level[2].setString("Hard");
	level[2].setPosition(sf::Vector2f((width / 2) - 50, height / (MAX_NUMBER_OF_LEVELS + 1) * 3));

	level[3].setFont(font);
	level[3].setFillColor(sf::Color::Black);
	level[3].setString("Back");
	level[3].setPosition(sf::Vector2f((width / 2) - 50, height / (MAX_NUMBER_OF_LEVELS + 1) * 4));
}

void Level::Draw(sf::RenderWindow &window)
{
	for (int i = 0; i < MAX_NUMBER_OF_LEVELS; i++)
	{
		window.draw(level[i]);
	}
}

void Level::MoveUp()
{
	if (selectedItemIndex - 1 >= 0)
	{
		level[selectedItemIndex].setFillColor(sf::Color::Black);
		selectedItemIndex--;
		level[selectedItemIndex].setFillColor(sf::Color::White);
	}
}

void Level::MoveDown()
{
	if (selectedItemIndex + 1 < MAX_NUMBER_OF_LEVELS)
	{
		level[selectedItemIndex].setFillColor(sf::Color::Black);
		selectedItemIndex++;
		level[selectedItemIndex].setFillColor(sf::Color::White);
	}
}

Level::~Level()
{
}
