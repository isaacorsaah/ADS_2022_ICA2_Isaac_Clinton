#pragma once
#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <regex>
#include <random>
using namespace std;

//method declarations
vector<vector<string>> readDelimitedRows(string fileName);
string to_string(char* a, int size);
vector<string> splitString(string str, string delimiter);
string getRandomLowercase(int minLength, int maxLength);
string to_string(char* a, int size);


vector<vector<string>> readDelimitedRows(string fileName)
{
	ifstream fin(fileName);
	if (!fin)
		throw runtime_error(fileName + " was not found! Is file in the correct sub-folder with main CPP file?");

	string rowStr;
	string field = "";
	vector<vector<string>> allRows;
	vector<string> rowFields;

	while (!fin.eof())
	{
		getline(fin, rowStr);
		bool quoteOpen = false;
		for (int i = 0; i < rowStr.length(); i++)
		{
			if (rowStr[i] == '"')
			{
				quoteOpen = !quoteOpen;
			}
			else if (!quoteOpen && rowStr[i] == ',')
			{
				rowFields.push_back(field);
				field = "";
			}
			else
			{
				field += rowStr[i];
			}
		}
		if (field != "")
		{
			rowFields.push_back(field);
		}
		field = "";

		if (rowFields.size() != 0)
			allRows.push_back(rowFields);

		rowFields.clear();
	}
	return allRows;
}

vector<string> splitString(string str, string delimiter)
{
	vector<string> words;
	size_t pos = 0;
	std::string subString;
	while ((pos = str.find(delimiter)) != std::string::npos) {
		words.push_back(str.substr(0, pos));
		str.erase(0, pos + delimiter.length());
	}
	words.push_back(str);

	return words;
}


string getRandomString(size_t length)
{
	const string CHARACTERS = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";

	random_device random_device;
	mt19937 generator(random_device());
	uniform_int_distribution<> distribution(0, CHARACTERS.size() - 1);

	std::string random_string;

	for (std::size_t i = 0; i < length; ++i)
	{
		random_string += CHARACTERS[distribution(generator)];
	}

	return random_string;
}

string to_string(char* a, int size)
{
	int i;
	string s = "";
	for (i = 0; i < size; i++) {
		s = s + a[i];
	}
	return s;
}