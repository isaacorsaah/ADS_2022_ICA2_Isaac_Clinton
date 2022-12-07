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
};


