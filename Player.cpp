#include "Player.h"

Player::Player()
{
	score = 0;
}

int Player::calculatingScore(bool iscorrect) {
	if (iscorrect)
		score += 10;
	else if (!iscorrect)
		score -= 5;
	return score;
}
void Player::reading(vector<Player>& players)
{
	Player temp;
	fstream myFile;
	myFile.open("playerVec.txt");
	if (myFile.is_open()) {
		while (myFile >> temp.name >> temp.score) {
			players.push_back(temp);
		}
	}
	myFile.close();
}
void Player::returning(vector<Player> &players)
{
	ofstream ofile;
	ofile.open("playerVec.txt", ios::out);
	for (int i = 0; i < players.size(); i++) {
		ofile << players[i].name << "\n";
		ofile << players[i].score << "\n";
	}
	ofile.close();
}
void Player::sorting(vector<Player> players)
{
	vector<Player> x;
	bool swapped;
	do {
		swapped = false;
		for (int i = 0; i < players.size() - 1; i++) {
			if (players[i].score < players[i + 1].score) {
				swap(players[i], players[i + 1]);
				swapped = true;
			}
		}
	} while (swapped);
}
void Player::checkingPlayer(vector<Player> &players , Player P1)
{
	int max = P1.score;
	bool isExist = false;
	for (int i = 0; i < players.size(); i++) {
		if (players[i].name == P1.name)
		{
			if (players[i].score <= max) {
				players[i].score = max;

			}
			isExist = true;
		}
	}
	if (isExist == false) {
		players.push_back(P1);
	}
}
Player::~Player()
{
}
