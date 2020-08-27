#include "Game.h"

Game::Game()
{
}
void Game::Initialize(float width, float height, string category)
{
	Player::reading(players);
	font.loadFromFile("films.dynasty.ttf");
	if (category == "Random")
	{
		Cat.setFont(font);
		Cat.setCharacterSize(40);
		Cat.setPosition(300.f, 0.f);
		Cat.setString(SentWord[1]);
	}

	for (int i = 0; i < SentWord[0].size(); i++)
	{
		sf::Text Dash;
		Dash.setFont(font);
		if (SentWord[0][i] == '_')
		{
			Dash.setString(" ");
		}
		else
		{
            Dash.setString("_ ");
		}
		Dash.setFillColor(sf::Color::White);
		Dash.setPosition(sf::Vector2f((width / (20) * (i + 1)), (height / 2)));
		Dashes.push_back(Dash);
	}
	for (int i = 0; i < SentWord[0].size(); i++)
	{
		if (SentWord[0][i] == '_')
		{
			correct++;
		}
	}
} 


void Game::Draw(sf::RenderWindow & window,float width,float height)
{
	for (int i = 0; i < SentWord[0].size(); i++)
	{
		window.draw(Cat);
		window.draw(Dashes[i]);
	}
	for (int i = 0; i < WrongLetters.size(); i++)
	{
		WrongLetters[i].setPosition((width / (20) * (i + 1)), (height / 4));
		window.draw(WrongLetters[i]);
	}

	sf::RectangleShape LeftLeg(sf::Vector2f(50.f, 2.f));
	LeftLeg.rotate(135.f);
	LeftLeg.setPosition(710.f, 380.f);

	sf::RectangleShape RightLeg(sf::Vector2f(50.f, 2.f));
	RightLeg.rotate(45.f);
	RightLeg.setPosition(710.f, 380.f);

	sf::RectangleShape LeftHand(sf::Vector2f(50.f, 2.f));
	LeftHand.rotate(135.f);
	LeftHand.setPosition(710.f, 300.f);

	sf::RectangleShape RightHand(sf::Vector2f(50.f, 2.f));
	RightHand.rotate(45.f);
	RightHand.setPosition(710.f, 300.f);

	sf::RectangleShape Body(sf::Vector2f(100.f, 2.f));
	Body.rotate(90.f);
	Body.setPosition(710.f, 280.f);

	sf::CircleShape Head(40.f);
	Head.setFillColor(sf::Color::Transparent);
	Head.setOutlineThickness(2.f);
	Head.setOutlineColor(sf::Color::White);
	Head.setPointCount(100);
	Head.setPosition(670.f, 200.f);

	sf::RectangleShape Line2[2];
	Line2[0].setSize(sf::Vector2f(100.f, 2.f));
	Line2[0].setPosition(610.f, 145.f);
	Line2[1].setSize(sf::Vector2f(50.f, 2.f));
	Line2[1].rotate(90.f);
	Line2[1].setPosition(710.f, 145.f);


	sf::RectangleShape Line1(sf::Vector2f(300.f, 2.f));
	Line1.rotate(90.f);
	Line1.setPosition(610.f, 145.f);

	sf::RectangleShape Base(sf::Vector2f(50.f, 100.f));
	Base.setFillColor(sf::Color::Transparent);
	Base.setOutlineThickness(2.f);
	Base.setOutlineColor(sf::Color::White);
	Base.rotate(90.f);
	Base.setPosition(657.f, 445.f);
	
	Score.setFont(font);
	Score.setCharacterSize(40);
	Score.setString("Score: " );
	Score.setPosition(0.f, 500.f);

	
	AScore.setFont(font);
	AScore.setCharacterSize(40);
	AScore.setString(to_string (Player1.score));
	AScore.setPosition(100.f, 500.f);

	Winner.setFont(font);
	Winner.setCharacterSize(40);
	Winner.setString("Congrats,You win");

	Loser.setFont(font);
	Loser.setCharacterSize(40);
	Loser.setString("Game Over!");

	PlayAgain.setFont(font);
	PlayAgain.setCharacterSize(40);
	PlayAgain.setPosition(0.f, 50.f);
	PlayAgain.setString("Press Esc to return to main menu");

	vector<int> y;
	sf::Event event;
	while (window.pollEvent(event))
	{
		if (correct == SentWord[0].size() || incorrect == 9)
		{
			break;
		}
		else if (event.type == sf::Event::TextEntered)
		{
			if (event.text.unicode >= 97 && event.text.unicode <= 122 && find(Letters.begin(), Letters.end(), static_cast<char>(event.text.unicode)) == Letters.end())
			{
				char x;
				x = static_cast<char>(event.text.unicode);
				Letters.push_back(x);
				y = hangman::checkLetter(SentWord[0], static_cast<char>(event.text.unicode), correct, incorrect);
				if (y.size() > 0)
				{
					isCorrect = true;
					Player1.calculatingScore(isCorrect);
					for (int i = 0; i < y.size(); i++)
					{
						Dashes[y[i]].setFont(font);
						Dashes[y[i]].setString(static_cast<char>(event.text.unicode));
						Dashes[y[i]].setFillColor(sf::Color::White);
						Dashes[y[i]].setPosition(sf::Vector2f((width / (20) * (y[i] + 1)), (height / 2)));
					}
				}
				else
				{
					isCorrect = false;
					Player1.calculatingScore(isCorrect);
					sf::Text letter;
					letter.setFont(font);
					letter.setString(static_cast<char>(event.text.unicode));
					WrongLetters.push_back(letter);
				}
			}
		}
	}
	if (correct == SentWord[0].size())
	{
		window.draw(Winner);
		window.draw(PlayAgain);
		window.draw(Score);
		window.draw(AScore);
		Player::checkingPlayer(players, Player1);
		Player::returning(players);
	}

	if (incorrect == 1)
	{
		window.draw(Base);
	}
	if (incorrect == 2)
	{
		window.draw(Base);
		window.draw(Line1);
	}
	if (incorrect == 3)
	{
		window.draw(Base);
		window.draw(Line1);
		window.draw(Line2[0]);
		window.draw(Line2[1]);
	}
	if (incorrect == 4)
	{
		window.draw(Base);
		window.draw(Line1);
		window.draw(Line2[0]);
		window.draw(Line2[1]);
		window.draw(Head);
	}
	if (incorrect == 5)
	{
		window.draw(Base);
		window.draw(Line1);
		window.draw(Line2[0]);
		window.draw(Line2[1]);
		window.draw(Head);
		window.draw(Body);
	}
	if (incorrect == 6)
	{
		window.draw(Base);
		window.draw(Line1);
		window.draw(Line2[0]);
		window.draw(Line2[1]);
		window.draw(Head);
		window.draw(Body);
		window.draw(RightHand);
	}
	if (incorrect == 7)
	{
		window.draw(Base);
		window.draw(Line1);
		window.draw(Line2[0]);
		window.draw(Line2[1]);
		window.draw(Head);
		window.draw(Body);
		window.draw(RightHand);
		window.draw(LeftHand);
	}

	if (incorrect == 8)
	{
		window.draw(Base);
		window.draw(Line1);
		window.draw(Line2[0]);
		window.draw(Line2[1]);
		window.draw(Head);
		window.draw(Body);
		window.draw(RightHand);
		window.draw(LeftHand);
		window.draw(RightLeg);
	}
	if (incorrect == 9)
	{
		window.draw(Base);
		window.draw(Line1);
		window.draw(Line2[0]);
		window.draw(Line2[1]);
		window.draw(Head);
		window.draw(Body);
		window.draw(RightHand);
		window.draw(LeftHand);
		window.draw(RightLeg);
		window.draw(LeftLeg);
		window.draw(Loser);
		for (int i = 0; i < SentWord[0].size(); i++)
		{
			if (Dashes[i].getString() == ' ')
			{
				Dashes[i].setString(' ');
			}
			else
			{
				Dashes[i].setString(SentWord[0][i]);
			}
			Dashes[i].setFont(font);
			Dashes[i].setFillColor(sf::Color::White);
			Dashes[i].setPosition(sf::Vector2f((width / (20) * (i + 1)), (height / 2)));
		}
		window.draw(PlayAgain);
	}
}


Game::~Game()
{

}
