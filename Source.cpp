#include <SFML\Graphics.hpp>
#include <iostream>
#include <vector>
#include "Menu.h"
#include "Level.h"
#include "Category.h"
#include "Game.h"
#include "hangman.h"
#include "PlayerName.h"
#include "Player.h"
#include "Scores.h"

enum State { MAIN_MENU, PLAY, SCORES, INSTRUCTIONS, EXIT, Diff, INGAME,PLAYERNAME };


static const float View_Height = 512.0F;

void run(sf::RenderWindow&);

void ViewResize(sf::RenderWindow &window, sf::View &view)
{
	float aspectRatio = float(window.getSize().x / window.getSize().y);
	view.setSize(View_Height*aspectRatio, View_Height);
}

int main()
{

	sf::RenderWindow window(sf::VideoMode(900, 600), "Hangman Game", sf::Style::Close | sf::Style::Resize);
	run(window);
	return 0;
}

void run(sf::RenderWindow& window)
{
	State Gamestate = MAIN_MENU;
	string dificulty;
	string cat;
	vector<string> SentWord;
	string Player2;

	bool x = false;

	//we declare our levels at first and give it its words file name to load the words in its categories vector
	Levels Easy("easy.txt");
	Levels Medium("medium.txt");
	Levels Hard("hard.txt");


	sf::View view(sf::Vector2f(0.0f, 0.0f), sf::Vector2f(View_Height, View_Height));



	sf::Texture texture;
	texture.loadFromFile("57007.JPG");
	sf::RectangleShape background;
	background.setSize(sf::Vector2f(window.getSize().x, window.getSize().y));
	background.setTexture(&texture);

	sf::Texture ING;
	ING.loadFromFile("123.JPG");
	sf::RectangleShape INGbackground;
	INGbackground.setSize(sf::Vector2f(window.getSize().x, window.getSize().y));
	INGbackground.setTexture(&ING);

	sf::Texture INS;
	INS.loadFromFile("INS.PNG");
	sf::RectangleShape Instructions;
	Instructions.setSize(sf::Vector2f(window.getSize().x, window.getSize().y));
	Instructions.setTexture(&INS);

	sf::Texture Score;
	Score.loadFromFile("Scores.PNG");
	sf::RectangleShape SCORE;
	SCORE.setSize(sf::Vector2f(window.getSize().x, window.getSize().y));
	SCORE.setTexture(&Score);


	Menu menu(window.getSize().x, window.getSize().y);
	Level level(window.getSize().x, window.getSize().y);
	Category category(window.getSize().x, window.getSize().y);
	PlayerName player(window.getSize().x, window.getSize().y);
	Game game;
	Scores scores(window.getSize().x, window.getSize().y);



	while (window.isOpen())
	{
		sf::Event event;
		if (Gamestate == MAIN_MENU)
		{
			window.clear();
			window.draw(background);
			menu.Draw(window);
			window.display();
			while (window.pollEvent(event))
			{
				if (event.type == sf::Event::KeyReleased)
				{
					if (event.key.code == sf::Keyboard::Up)
					{
						menu.MoveUp();
						break;
					}
					if (event.key.code == sf::Keyboard::Down)
					{
						menu.MoveDown();
						break;
					}
					if (event.key.code == sf::Keyboard::Return)
					{
						if (menu.GetPressedItem() == 0)
						{
							Gamestate = PLAY;
							break;
						}
						if (menu.GetPressedItem() == 1)
						{
							Gamestate = SCORES;
							break;
						}
						if (menu.GetPressedItem() == 2)
						{
							Gamestate = INSTRUCTIONS;
							break;
						}
						if (menu.GetPressedItem() == 3)
						{
							Gamestate = EXIT;
							break;
						}
					}
				}
				if (event.type == sf::Event::Resized)
				{
					ViewResize(window, view);
					break;
				}
				if (event.type == sf::Event::Closed)
				{
					window.close();
					break;
				}
			}
		}
		else if (Gamestate == PLAY)
		{
			window.clear();
			window.draw(background);
			level.Draw(window);
			window.display();
			while (window.pollEvent(event))
			{
				if (event.type == sf::Event::KeyReleased)
				{
					if (event.key.code == sf::Keyboard::Up)
					{
						level.MoveUp();
						break;
					}
					if (event.key.code == sf::Keyboard::Down)
					{
						level.MoveDown();
						break;
					}
					if (event.key.code == sf::Keyboard::Return)
					{
						if (level.GetPressedItem() == 0)
						{
							dificulty = "Easy";
							Gamestate = Diff;
							break;
						}
						if (level.GetPressedItem() == 1)
						{
							dificulty = "Medium";
							Gamestate = Diff;
							break;
						}
						if (level.GetPressedItem() == 2)
						{
							dificulty = "Hard";
							Gamestate = Diff;
							break;
						}
						if (level.GetPressedItem() == 3)
						{
							Gamestate = MAIN_MENU;
							break;
						}
					}
				}
				if (event.type == sf::Event::Resized)
				{
					ViewResize(window, view);
					break;
				}
				if (event.type == sf::Event::Closed)
				{
					window.close();
					break;
				}
			}
		}
		else if (Gamestate == Diff)
		{
			window.clear();
			window.draw(background);
			category.Draw(window);
			window.display();
			while (window.pollEvent(event))
			{
				if (event.type == sf::Event::KeyPressed)
				{
					if (event.key.code == sf::Keyboard::Up)
					{
						category.MoveUp();
						break;
					}
					if (event.key.code == sf::Keyboard::Down)
					{
						category.MoveDown();
						break;
					}
					if (event.key.code == sf::Keyboard::Return)
					{
						if (category.GetPressedItem() == 0)
						{

							cat = "Actors";
							Gamestate = PLAYERNAME;
							break;
						}
						else if (category.GetPressedItem() == 1)
						{
							cat = "Animals";
							Gamestate = PLAYERNAME;
							break;
						}
						else if (category.GetPressedItem() == 2)
						{
							cat = "Cars";
							Gamestate = PLAYERNAME;
							break;
						}
						else if (category.GetPressedItem() == 3)
						{
							cat = "Countries";
							Gamestate = PLAYERNAME;
							break;
						}
						else if (category.GetPressedItem() == 4)
						{
							cat = "Food";
							Gamestate = PLAYERNAME;
							break;
						}
						else if (category.GetPressedItem() == 5)
						{
							cat = "Harry_Potter";
							Gamestate = PLAYERNAME;
							break;
						}
						else if (category.GetPressedItem() == 6)
						{
							cat = "Marvel";
							Gamestate = PLAYERNAME;
							break;
						}
						else if (category.GetPressedItem() == 7)
						{
							cat = "Movies";
							Gamestate = PLAYERNAME;
							break;
						}
						else if (category.GetPressedItem() == 8)
						{
							cat = "Songs";
							Gamestate = PLAYERNAME;
							break;
						}
						else if (category.GetPressedItem() == 9)
						{
							cat = "Random";
							Gamestate = PLAYERNAME;
							break;
						}
					}
				}
				if (event.type == sf::Event::Resized)
				{
					ViewResize(window, view);
					break;
				}
				if (event.type == sf::Event::Closed)
				{
					window.close();
					break;
				}
			}
		}
		else if (Gamestate == PLAYERNAME)
		{
			while (window.pollEvent(event))
			{
				window.clear();
				window.draw(background);
				player.Draw(window);
				Player2 = player.Player;
				window.display();

				if (event.type == sf::Event::KeyPressed)
				{
					if (event.key.code == sf::Keyboard::Key::Return)
					{
						Gamestate = INGAME;
					}
				}
			}
		}
		else if (Gamestate == INGAME)
		{
			game.Player1.name = Player2;
			while (window.pollEvent(event))
			{
				if (dificulty == "Easy")
				{
					window.clear(sf::Color::Black);
					window.draw(INGbackground);
					if (!x)
					{
						SentWord = Easy.word(cat);
						game.SentWord = SentWord;
						game.Initialize(window.getSize().x, window.getSize().y, cat);
						x = true;
					}
					game.Draw(window, window.getSize().x, window.getSize().y);
					window.display();
				}

				else if (dificulty == "Medium")
				{
					window.clear(sf::Color::Black);
					window.draw(INGbackground);
					if (!x)
					{
						SentWord = Medium.word(cat);
						game.SentWord = SentWord;
						game.Initialize(window.getSize().x, window.getSize().y, cat);
						x = true;
					}
					game.Draw(window, window.getSize().x, window.getSize().y);
					window.display();
				}
				else if (dificulty == "Hard")
				{
					window.clear(sf::Color::Black);
					window.draw(INGbackground);
					if (!x)
					{
						SentWord = Hard.word(cat);
						game.SentWord = SentWord;
						game.Initialize(window.getSize().x, window.getSize().y, cat);
						x = true;
					}
					game.Draw(window, window.getSize().x, window.getSize().y);
					window.display();
				}
				if (event.type == sf::Event::KeyReleased)
				{
					if (event.key.code == sf::Keyboard::Escape)
					{
					   run(window);
					}
				}

				if (event.type == sf::Event::Resized)
				{
					ViewResize(window, view);
					break;
				}
				if (event.type == sf::Event::Closed)
				{
					window.close();
					break;
				}
			}
		}
		else if (Gamestate == SCORES)
		{
			window.clear();
			window.draw(SCORE);
			scores.Draw(window);
			window.display();
			while (window.pollEvent(event))
			{
				if (event.type == sf::Event::KeyReleased)
				{
					if (event.key.code == sf::Keyboard::Escape)
					{
						Gamestate = MAIN_MENU;
					}
				}
				if (event.type == sf::Event::Resized)
				{
					ViewResize(window, view);
					break;
				}
				if (event.type == sf::Event::Closed)
				{
					window.close();
					break;
				}
			}
		}
		else if (Gamestate == INSTRUCTIONS)
		{
			window.clear();
			window.draw(Instructions);
			window.display();
			while (window.pollEvent(event))
			{
				if (event.type == sf::Event::KeyReleased)
				{
					if (event.key.code == sf::Keyboard::Escape)
					{
						Gamestate = MAIN_MENU;
					}
				}
				if (event.type == sf::Event::Resized)
				{
					ViewResize(window, view);
					break;
				}
				if (event.type == sf::Event::Closed)
				{
					window.close();
					break;
				}
			}
		}
		else if (Gamestate == EXIT)
		{
			window.close();
			
		}
	}
}
