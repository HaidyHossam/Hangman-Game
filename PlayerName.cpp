#include "PlayerName.h"





PlayerName::PlayerName(float width, float height)
{
	font.loadFromFile("films.dynasty.ttf");
	Name.setFont(font);
	Name.setCharacterSize(40);
	Name.setString("Name: ");
	Name.setPosition(sf::Vector2f((width / 2) - 115, height / 2));
	
	for (int i = 0; i < 4; i++)
	{
		Dashes[i].setFont(font);
		Dashes[i].setString("_ ");
		Dashes[i].setFillColor(sf::Color::White);
		Dashes[i].setPosition((width / (20) * (i +10)), (height / 2));
	}

}
void PlayerName::Draw(sf::RenderWindow &window)
{
	for (int i = 0; i < 4; i++)
	{
	    window.draw(Name);
		window.draw(Dashes[i]);
	}
	sf::Event event;

	while (window.pollEvent(event))
	{
		if (event.type == sf::Event::TextEntered)
		{
			if (event.text.unicode >= 97 && event.text.unicode <= 122)
			{
				Player.push_back( static_cast<char>(event.text.unicode));
				Dashes[i].setFont(font);
				Dashes[i].setString(static_cast<char>(event.text.unicode));
				Dashes[i].setFillColor(sf::Color::White);
				i = (i + 1) % 4;	
			}
		}
	}
}

PlayerName::~PlayerName()
{
}
