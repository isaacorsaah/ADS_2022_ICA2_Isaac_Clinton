#pragma once
#include <ostream>
#include <string>
using namespace std;

class Time {
#pragma region Fields
	//pick data types that minimize space requirements
	unsigned short int hrs;		//2 bytes
	unsigned short int mins;	//2 bytes
#pragma endregion

public:

#pragma region Constructors
	Time(unsigned short int hrs, unsigned short int mins)
		: hrs(hrs), mins(mins) {}

	//takes a string and parses out data - useful!
	Time(string timeAsString) {
	}

#pragma endregion

#pragma region Get & Set
	unsigned short int getHrs() const { return this->hrs; }
	unsigned short int getMins() const { return this->mins; }
#pragma endregion

#pragma region Operators & Hash

	bool operator==(const Time& time)
	{
		return this->hrs == time.hrs
			&& this->mins == time.mins;
	}

	std::size_t hash() const
	{
		size_t hash = std::hash<int>()(this->hrs)
			+ 101 * std::hash<int>()(this->mins);
		return hash;
	}

	friend ostream& operator<<(ostream& out, const Time& time) {
		out << time.hrs << " : " << time.mins;
		return out;
	}
#pragma endregion
};
