#include <string>
#include <vector>
#include <iostream>

#pragma once
struct skin {
	std::string name;
	int location;
	int cost;
	bool isUnlocked;

	skin(std::string S_name, int S_location, int S_cost)
	{
		name = S_name;
		location = S_location;
		cost = S_cost;
		isUnlocked = false;
	}
};


class Shop
{
public:
	Shop();
	void showShop(const int totalCoins);
	void SetCurrent(const int x, const int y);
	int BuySkin(int totalCoins);
	std::string GetCurrentSkin();



private:
	int currentLocation = 0;
	std::string currentSkin;
	
	std::vector < skin > SkinList;
};

