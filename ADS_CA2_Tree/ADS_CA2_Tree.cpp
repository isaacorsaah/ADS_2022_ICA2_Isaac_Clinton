// ADS_CA2_Tree.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include "Utilities.h"
#include "Client.h"
#include "Date.h"
using namespace std;

void demoSimpleHash();
void demoDateHash();
void demoReadFromFileToData();

int main()
{
	cout << endl << "demoSimpleHash()..........." << endl;
	demoSimpleHash();

	cout << endl << "demoDateHash()..........." << endl;
	demoDateHash();

	cout << endl << "demoReadFromFileToData()..........." << endl;
	demoReadFromFileToData();

	return 0;
}

void demoSimpleHash() {
	//hasher for strings
	hash<string> hasherStr;
	string email = "john.smith@hotmail.com";
	cout << "hash[" << email << "]: " << hasherStr(email) << endl;

	//hasher for doubles
	hash<double> hasherDbl;
	double price = 123123.322;
	cout << "hash[" << price << "]: " << hasherDbl(price) << endl;

	//we can re-use a hasher
	double weight = 12345.9897;
	cout << "hash[" << weight << "]: " << hasherDbl(weight) << endl;

	//we can store the hash value using size_t (basically an unsigned int)
	size_t myHash = hasherStr("this is a hash value store in a uint");
	cout << myHash << endl;
}

void demoDateHash() {
	Date myDate(25, 12, 2022);
	cout << myDate << endl;
	cout << "hash[" << myDate << "]: " << myDate.hash() << endl;
}


void demoReadFromFileToData()
{
	vector<string> rowFromData = splitString("WBC88XPE6LP,70,Colby,Burks,Male, 10/07/1983, rutrum.non@aol.org, 1-704-685-7028, 6723 EV, 460-8248 Tempor Rd.,Peru, 11/11/2023, 03:23, 29/11/2018, 121.31",",");
	if (rowFromData.size() == 15)
	{
		string user_id = rowFromData[0];
		int current_ranking = stoi(rowFromData[1]);
		string first_name = rowFromData[2];
		string last_name = rowFromData[3];
		vector<string> dateWords = splitString(rowFromData[4], "/");
		string email = rowFromData[5];
		string phone = rowFromData[6];
		string postcode = rowFromData[7];
		string address = rowFromData[8];
		string country = rowFromData[9];
		vector<string> dateWords = splitString(rowFromData[10], "/");
		vector<string> last_log_on_time = splitString(rowFromData[11], ":");
		vector<string> dateWords = splitString(rowFromData[12], "/");
		vector<string> account_credit = splitString(rowFromData[13], ".");

		if (dateWords.size() == 4)
		{
			int date_day = stoi(dateWords[0]);
			int date_month = stoi(dateWords[1]);
			int date_year = stoi(dateWords[2]);

			Date dateOfBirth(date_day, date_month, date_year);
			Date last_log_on_date(date_day, date_month, date_year);
			Date joined_on(date_day, date_month, date_year);

			Client myClient(user_id, current_ranking, first_name, last_name, dateOfBirth,email,phone,postcode,address,country);

			//cout << "Car: " << myCar << endl;
		}
	}
}