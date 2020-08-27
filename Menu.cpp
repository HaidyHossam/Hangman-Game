#include "Menu.h"


Menu::Menu(float width, float height)
{
	font.loadFromFile("films.dynasty.ttf");

	menu[0].setFont(font);
	menu[0].setCharacterSize(70);
	menu[0].setFillColor(sf::Color::White);
	menu[0].setString("Play");
	menu[0].setPosition(sf::Vector2f((width / 2) - 50, height / (MAX_NUMBER_OF_BUTTONS + 1) * 1));

	menu[1].setFont(font);
	menu[1].setFillColor(sf::Color::Black);
	menu[1].setString("Scores");
	menu[1].setPosition(sf::Vector2f((width / 2) - 50, height / (MAX_NUMBER_OF_BUTTONS + 1) * 2));

	menu[2].setFont(font);
	menu[2].setFillColor(sf::Color::Black);
	menu[2].setString("Instructions");
	menu[2].setPosition(sf::Vector2f((width / 2) - 50, height / (MAX_NUMBER_OF_BUTTONS + 1) * 3));

	menu[3].setFont(font);
	menu[3].setFillColor(sf::Color::Black);
	menu[3].setString("Exit");
	menu[3].setPosition(sf::Vector2f((width / 2) - 50, height / (MAX_NUMBER_OF_BUTTONS + 1) * 4));
}

void Menu::Draw(sf::RenderWindow &window)
{
	for (int i = 0; i < MAX_NUMBER_OF_BUTTONS; i++)
	{
		window.draw(menu[i]);
	}
}

void Menu::MoveUp()
{
	if (selectedItemIndex - 1 >= 0)
	{
		menu[selectedItemIndex].setFillColor(sf::Color::Black);
		selectedItemIndex--;
		menu[selectedItemIndex].setFillColor(sf::Color::White);
	}
}

void Menu::MoveDown()
{
	if (selectedItemIndex + 1 < MAX_NUMBER_OF_BUTTONS)
	{
		menu[selectedItemIndex].setFillColor(sf::Color::Black);
		selectedItemIndex++;
		menu[selectedItemIndex].setFillColor(sf::Color::White);
	}
}

Menu::~Menu()
{
}
