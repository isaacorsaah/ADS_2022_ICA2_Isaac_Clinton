#pragma once
#include "Client.h"
class Key
{
	string user_id;
	int rating;
	string country; 

public:
	//void setItem(T item);
	
	Key(string u, int r, string c)
	{
		user_id = u;
		rating = r;
		country = c;
	}

	Key()
	{
		user_id = "User ID";
		rating = -1;
		country = "Country";
	}
	bool operator<(const Key& other)
	{
		return user_id < other.user_id;
	}
	bool operator>(const Key& other)
	{
		return user_id > other.user_id;
	}
	bool operator==(const Key& other)
	{
		return user_id == other.user_id;
	}
	friend ostream& operator<<(ostream& out, const Key& other)
	{
		out << "{" << other.user_id << " from " << other.country << " rating is" << other.rating << "}";
		return out;
	}
};