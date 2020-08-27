#pragma once
#include<iostream>
#include<string>
#include<vector>
#include <unordered_map>
#include <cstdlib>
#include <time.h>
#include <fstream>
using namespace std;

class categories {
public:

	vector<string> words;
	categories();
	~categories();
};
class Levels
{
public:
	unordered_map<string, categories>cat;
	Levels(string);
	vector<string> word(string);
	~Levels();
};

class hangman
{
private:
	hangman();
	~hangman();
public:
	static vector <int> checkLetter(string, char, int &, int &);
	static bool isWinner(int inCorrect, int correct, string SentWord);
};





