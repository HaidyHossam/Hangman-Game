#pragma once
#include <SFML\Graphics.hpp>
#include <iostream>
#include <vector>
#include <fstream>
#include "Player.h"

using namespace std;

class Scores
{
	vector<Player> players;
	vector<Player> top5;
	sf::Text names[5];
	sf::Text score[5];
	sf::Font font;

public:
	void Draw(sf::RenderWindow & window);
	Scores(float width, float height);
	~Scores();
};

