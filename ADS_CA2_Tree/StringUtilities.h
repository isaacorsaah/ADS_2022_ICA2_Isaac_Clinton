#pragma once
#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <regex>
#include <random>
using namespace std;

string getRandomLowercase(int minLength, int maxLength) {
	if (minLength == 0 || maxLength == 0 || maxLength < minLength)
		throw invalid_argument("One or more parameters is incorrect!");

	//generate random length in range min-max
	srand(time(0));
	int randLength = rand() % maxLength + minLength;

	//create an array of characters to store the string
	char* pCharArr = new char[randLength];

	//random generate lowercase letters
	for (int i = 0; i < randLength; i++)
	{
		pCharArr[i] = char('a' + rand() % 26);
	}

	//copy contents to a string
	string strOut = to_string(pCharArr, randLength);

	//delete the char array
	delete[] pCharArr;

	//return the string
	return strOut;
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