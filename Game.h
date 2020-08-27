#pragma once
#include <SFML\Graphics.hpp>
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
#include "hangman.h"
#include "PlayerName.h"
#include "Player.h"

using namespace std;

class Game
{
public:

	vector <string> SentWord;
	Player Player1;
	vector <Player> players;
	vector <sf::Text> Dashes;
	
	vector<char> Letters;
	vector<sf::Text> WrongLetters;
	sf::Text Winner, PlayAgain, Loser, Cat,Score,AScore;

	bool isCorrect = false;
	sf::Font font;

	int correct = 0, incorrect = 0;
	void Draw(sf::RenderWindow &window, float width, float height);
	void Initialize(float width, float height, string);


	Game();
	~Game();
};

