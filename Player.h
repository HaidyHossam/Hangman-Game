#pragma once
#include<iostream>
#include<string>
#include <vector>
#include <fstream>
using namespace std;
class Player
{
private:

public:
	int score;
	string name;
	int calculatingScore(bool iscorrect);
	static void reading(vector<Player>&);
	static void returning(vector<Player>&);
	static void sorting(vector<Player>);
	static void checkingPlayer(vector<Player>& ,Player);
	Player();
	~Player();
};
