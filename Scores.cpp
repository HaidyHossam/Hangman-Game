#include "Scores.h"

Scores::Scores(float width, float height)
{
	Player::reading(players);
	font.loadFromFile("films.dynasty.ttf");
	Player::sorting(players);

	for (int i = 0; i < 5; i++)
	{
	    top5.push_back(players[i]);
	}

	for (int i = 0; i < top5.size(); i++)
	{
		names[i].setFont(font);
		names[i].setCharacterSize(40);
		names[i].setFillColor(sf::Color::White);
		names[i].setString(top5[i].name);
		names[i].setPosition(sf::Vector2f((width / 3) - 220, ((height / 6)) * (i+1.5)));
	}
	for (int i = 0; i < top5.size(); i++)
	{
		score[i].setFont(font);
		score[i].setCharacterSize(40);
		score[i].setFillColor(sf::Color::White);
		score[i].setString(to_string(top5[i].score));
		score[i].setPosition(sf::Vector2f((width / 1) - 200, ((height / 6)) * (i + 1.5)));
	}
}

void Scores::Draw(sf::RenderWindow & window)
{
	for (int i = 0; i < 5; i++)
	{
		window.draw(names[i]);
	}
	for (int i = 0; i < 5; i++)
	{
		window.draw(score[i]);
	}
}

Scores::~Scores()
{
}
