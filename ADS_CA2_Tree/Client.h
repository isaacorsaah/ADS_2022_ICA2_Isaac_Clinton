#pragma once
#include <ostream>
#include <string>
#include "Date.h"
using namespace std;

/// <summary>
/// Represents a row of data in a CSV file of Client records
/// </summary>
class Client {
#pragma region Fields
	string user_id;
	int current_ranking;
	string first_name;
	string last_name;
	string gender;
	Date dateOfBirth;
	string email;
	string phone;
	string postcode;
	string address;
	string country;
	Date last_log_on_date;
	double last_log_on_time;
	Date joined_on;
	double account_credit;
#pragma endregion

public:
#pragma region Constructors
	Client(string user_id, int current_ranking, string first_name, string last_name, string gender, Date dateOfBirth,
	string email,
	string phone,
	string postcode,
	string address,
	string country,
	Date last_log_on_date,
	double last_log_on_time,
	Date joined_on,
	double account_credit)
	:user_id(user_id), current_ranking(current_ranking), first_name(first_name), last_name(last_name), gender(gender), dateOfBirth(dateOfBirth),
	email(email), phone(phone), postcode(postcode), address(address), country(country), last_log_on_date(last_log_on_date), last_log_on_time(last_log_on_time),
	joined_on(joined_on), account_credit(account_credit)
	{
	}
#pragma endregion

#pragma region Get/Set
	string getUserID() const { return this->user_id; }
	int getCurrentRank() const { return this->current_ranking; }
	string getFirstName() const { return this->first_name; }
	string getLastName() const { return this->last_name; }
	string getGender() const { return this->gender; }
	Date getDOB() const { return this->dateOfBirth; }
	string getEmail() const { return this->email; }
	string getPhone() const { return this->phone; }
	string getPostcode() const { return this->postcode; }
	string getAddress() const { return this->address; }
	string getCountry() const { return this->country; }
	Date getLastLogDate() const { return this->last_log_on_date; }
	double getLastLogTime() const { return this->last_log_on_time; }
	Date getDateJoined() const { return this->joined_on; }
	double getCreditAccount() const { return this->account_credit; }
#pragma endregion

#pragma region Operators & Hash

	bool operator==(const Client& student)
	{
		return this->user_id == student.user_id
			&& this->current_ranking == student.current_ranking
			&& this->first_name == student.first_name
			&& this->last_name == student.last_name
			&& this->gender == student.gender
			&& this->dateOfBirth == student.dateOfBirth
			&& this->email == student.email
			&& this->phone == student.phone
			&& this->postcode == student.postcode
			&& this->address == student.address
			&& this->country == student.country
			&& this->last_log_on_date == student.last_log_on_date
			&& this->last_log_on_time == student.last_log_on_time
			&& this->joined_on == student.joined_on
			&& this->account_credit == student.account_credit;
	}

	friend ostream& operator<<(ostream& output, Client& student) {
		output << student.user_id << ",";
		output << student.current_ranking << ",";
		output << student.first_name << ",";
		output << student.last_name << ",";
		output << student.gender << ",";
		output << student.dateOfBirth << ",";
		output << student.email << ",";
		output << student.phone << ",";
		output << student.postcode << ",";
		output << student.address << ",";
		output << student.country << ",";
		output << student.last_log_on_date << ",";
		output << student.last_log_on_time << ",";
		output << student.joined_on << ",";
		output << student.account_credit;
		return output;
	}

	friend istream& operator>>(istream& input, Client& student) {
		string studentAsStr;
		input >> studentAsStr;

		return input;
	}

	//std::size_t hash() const
	//{
	//	//What is the size of size_t? https://www.geeksforgeeks.org/size_t-data-type-c-language/
	//	//What are these numbers? https://en.wikipedia.org/wiki/List_of_prime_numbers#The_first_1000_prime_numbers
	//	size_t hash = std::hash<string>()(this->user_id)
	//		+ 31 * std::hash<int>()(this->year)
	//		+ 57 * std::hash<double>()(this->price)
	//		+ 349 * date.hash();
	//}

#pragma endregion
};