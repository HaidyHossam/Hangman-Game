#pragma once
#include "hangman.h"

Levels::Levels(string filename)
{
	// we create a vector of categories to but in its member words the words from the file
	categories v;
	// we open the file and take the words it by content so we can do the comparison
	fstream file;
	file.open(filename);
	string content;
	if (file.is_open()) {
		while (!file.eof()) {
			file >> content;
			//the comparison checks if we finished with all words in this category as we Separate between 
			//categories with $ + catrgory name so we compare the fist char in the string content to $
			if (content[0] == '$') {
				//we insert the category name and the the words in the caterories map
				cat.insert(pair <string, categories>(content.substr(1, content.size() - 1), v));
				//then we clear the vector words to make the size = 0
				v.words.clear();
				//continue statement for not putting $ in the vector v
				continue;
			}
			//we push the words from the file to the vector of words in v
			v.words.push_back(content);

		}
	}
}



vector<string> Levels::word(string r) {
	vector<string> v;
	//using srand() for not generating the same words every time
	srand(time(0));
	//we compare the string taken from the user with options
	if (r == "Random") {
		//we generate a random int number to make it the index of the map 
		int i = rand() % cat.size();
		//create an iterator to accsess the categories in the map
		unordered_map<string, categories>::iterator it;
		it = cat.begin();
		//advance function takes an iterator and an int number then gets the value of this index in the map
		//and put it in the iterator
		advance(it, i);
		categories random_vec = it->second;
		//we generate another int to make it the index of the vector of wards 
		int j = rand() % random_vec.words.size();
		v.push_back(random_vec.words[j]);
		v.push_back(it->first);
		return v;
	}
	else
	{
		//accsess the vector of words in the map by using the category name taken from the user
		//as a key 
		int i = rand() % cat[r].words.size();
		v.push_back(cat[r].words[i]);
		v.push_back(r);
		return v;

	}
}

Levels::~Levels()
{

}

categories::categories() {

}

categories::~categories() {

}

hangman::hangman()
{
}

vector<int> hangman::checkLetter(string Word, char Letter, int &correct, int &incorrect)
{
	vector <int> x;
	bool gotIT = false;
	for (int j = 0; j < Word.length(); j++)
	{
		if (Letter == Word[j])
		{
			correct++;
			x.push_back(j);
			gotIT = true;
		}
	}
	if (gotIT == false)
	{
		incorrect++;
	}
	return x;
}
bool hangman::isWinner(int inCorrect, int correct, string SentWord)
{
	if (inCorrect == 9)
		return false;
	else if (correct == SentWord.size())
	{
		return true;
	}
}
hangman::~hangman()
{

}
