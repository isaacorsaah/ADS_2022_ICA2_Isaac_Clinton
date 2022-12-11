// ADS_CA2_Tree.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include "Utilities.h"
#include "Client.h"
#include "Date.h"
#include "Time.h"
#include "BinaryTree.h"
using namespace std;

void demoSimpleHash();
void demoDateHash();
void demoTimeHash();
void demoCSVToObject();
void demoBenchmarkVectorFindLast();
void demoReadFromFileToData();

int main()
{
	TNode* root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	root->left->left = newNode(4);
	root->left->right = newNode(5);
	root->left->right->right = newNode(6);

	vector<int> output = longestPath(root);
	int n = output.size();

	cout << output[n - 1];
	for (int i = n - 2; i >= 0; i--) {
		cout << " -> " << output[i];
	}
	cout << endl << "demoSimpleHash()..........." << endl;
	demoSimpleHash();

	cout << endl << "demoDateHash()..........." << endl;
	demoDateHash();

	cout << endl << "demoTimeHash()..........." << endl;
	demoTimeHash();

	cout << endl << "demoCSVToObject()..........." << endl;
	demoCSVToObject();

	cout << endl << "demoBenchmarkVectorFindLast()..........." << endl;
	demoBenchmarkVectorFindLast();
	cout << endl << "demoReadFromFileToData()..........." << endl;
	demoReadFromFileToData();

	return 0;
}
/*********************************** Hashing Objects ***********************************/
void demoSimpleHash() {
	//hasher for strings
	hash<string> hasherStr;
	string user_id = "WBC88XPE6LP";
	cout << "hash[" << user_id << "]: " << hasherStr(user_id) << endl;

	//hasher for integers
	hash<int> hasherInt;
	int current_ranking = 70;
	cout << "hash[" << current_ranking << "]: " << hasherInt(current_ranking) << endl;

	//we can re-use a hasher
	string country = "Peru";
	cout << "hash[" << country << "]: " << hasherStr(country) << endl;

	//we can store the hash value using size_t (basically an unsigned int)
	size_t myHash = hasherStr("this is a hash value store in a uint");
	cout << myHash << endl;
}
void demoDateHash() {
	Date myDate(25, 12, 2022);
	cout << myDate << endl;
	cout << "hash[" << myDate << "]: " << myDate.hash() << endl;
}
void demoTimeHash() {
	Time myTime(03, 23);
	cout << myTime << endl;
	cout << "hash[" << myTime << "]: " << myTime.hash() << endl;
}

/*********************************** File IO ***********************************/
//best - supports rows of data that contain commas and parenthesis - thanks for Derek!
void demoCSVToObject()
{
	//note: data is a sub-folder under the folder with main CPP file
	string fileName = "data/data_3.csv";
	vector<vector<string>> allData = readDelimitedRows(fileName);

	for (vector<string> row : allData) {
		for (string field : row) {
			cout << field << ",";
		}
		cout << endl;
	}
}

/*********************************** String parsing ***********************************/
void demoReadFromFileToData()
{
	string str = "WBC88XPE6LP,70,Colby,Burks,Male, 10/07/1983, rutrum.non@aol.org, 1-704-685-7028, 6723 EV, 460-8248 Tempor Rd.,Peru, 11/11/2023, 03:23, 29/11/2018, 121.31";
	string delimiter = ",";

	vector<string> rowFromData = splitString(str, delimiter);
	//vector<string> rowFromData = splitString("WBC88XPE6LP,70,Colby,Burks,Male, 10/07/1983, rutrum.non@aol.org, 1-704-685-7028, 6723 EV, 460-8248 Tempor Rd.,Peru, 11/11/2023, 03:23, 29/11/2018, 121.31",",");
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

		if (dateWords.size() == 4,10,12)
		{
			int date_day = stoi(dateWords[0]);
			int date_month = stoi(dateWords[1]);
			int date_year = stoi(dateWords[2]);

			Date dateOfBirth(date_day, date_month, date_year);
			Date last_log_on_date(date_day, date_month, date_year);
			Date joined_on(date_day, date_month, date_year);

			Client myClient(user_id, current_ranking, first_name, last_name, dateOfBirth,email,phone,postcode,address,country,last_log_on_date,last_log_on_time,joined_on,account_credit);

			//cout << "Car: " << myCar << endl;
		}
		if (last_log_on_time.size() == 15)
		{
			int time_hrs = stoi(last_log_on_time[0]);
			int time_mins = stoi(last_log_on_time[1]);

			Time last_log_on_time(time_hrs, time_mins);

			Client myClient(user_id, current_ranking, first_name, last_name, dateOfBirth, email, phone, postcode, address, country);

			//cout << "Car: " << myCar << endl;
		}
	}
}
/*********************************** Benchmarking ***********************************/

/// <summary>
/// Search for a T in a vector of T objects
/// </summary>
/// <typeparam name="T"></typeparam>
/// <param name="data"></param>
/// <param name="value"></param>
/// <returns></returns>
template <typename T>
int linearSearch(vector<T> data, T value)
{
	for (int i = 0; i < data.size(); i++)
		if (data[i] == value) return i;
	return -1;
}

/// <summary>
/// A functor that we make to test the linearSearch in a vector - we need a functor because that's what measureTime takes!
/// </summary>
class LinearStringSearchFunctor {
	vector<string> data;
	string target;
public:
	LinearStringSearchFunctor(vector<string> data, string target) : data(data), target(target) {};

	int operator()() {
		return linearSearch(data, target);
	}
};

vector<string> loadData(int N)
{
	vector<string> data;

	//load data (e.g., random strings) into a vector (this is like your tree or linked list)
	int stringLength = 4;

	for (int i = 0; i < N; i++)
		data.push_back(getRandomString(stringLength));

	return data;
}

//lets benchmark how long it takes to find the last string in a vector
//we should repeat the test below and run multiple tests on finding last string in a vector and get average run time
void demoBenchmarkVectorFindLast() {
	//number of strings in the vector (like your CSV where N=1000,10000,100000)
	int N = 1000;

	//get some data (yours would be data from CSV in a list/vector vs your BinaryTree)
	vector<string> data = loadData(N);

	//pick the last string in the structure
	string searchString = data[data.size() - 1];

	/******************************* IMPORTANT PART > *******************************/
	int numberOfTests = 100;
	double totalTestTimeInNS = 0;
	for (int i = 0; i < numberOfTests; i++)
	{
		//make up the functor
		LinearStringSearchFunctor searchFunc(data, searchString);

		//pass the functor into measureTime
		totalTestTimeInNS += measureTime(searchFunc);
	}

	//get average across all tests
	double averageSearchTimeInMS = totalTestTimeInNS / numberOfTests;

	//convert ns to ms
	averageSearchTimeInMS /= 1000;

	//see how long it takes to find the string
	cout << "Vector - Average last element search time [Nr = " << N << ",Tests = " << numberOfTests << "]: " << averageSearchTimeInMS << "ms" << endl;

	/******************************* < IMPORTANT PART *******************************/
}