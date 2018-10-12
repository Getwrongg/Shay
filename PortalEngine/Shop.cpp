#include "Shop.h"

Shop::Shop()
{
	skin eight_ball = skin("8BALL", 11, 10);
	SkinList.push_back(eight_ball);

	skin space_ball = skin("STAR", 21, 15);
	SkinList.push_back(space_ball);

	skin kaleidoscope_ball = skin("KALEIDOSCOPE", 31, 20);
	SkinList.push_back(kaleidoscope_ball);

	skin rainbow_ball = skin("RAINBOW", 12, 20);
	SkinList.push_back(rainbow_ball);
}

void Shop::showShop(const int totalCoins)
{		
	std::cout << std::endl;
	std::cout << "WASD to change position, SPACE BAR to select skin, e to reshow this screen " << std::endl;
	std::cout << std::endl;
	std::cout << "Total Coins: " << totalCoins << std::endl;
	std::cout << "Skin List:"<< std::endl;
	for (int i = 0; i < SkinList.size(); i++) {
		std::cout <<"Skin: " << SkinList[i].name << std::endl;
		std::cout <<"Cost: "<< SkinList[i].cost << std::endl;
		std::cout <<"Location: "<< SkinList[i].location << std::endl;
		std::cout << std::endl;
	}
}

void Shop::SetCurrent(const int x, const int y)
{
	currentLocation = x * 10 + y;
}

int Shop::BuySkin(int totalCoins)
{
	for (int i = 0; i < SkinList.size(); i++)
	{
		if (SkinList[i].location == currentLocation && !SkinList[i].isUnlocked && totalCoins >= SkinList[i].cost)
		{
			currentSkin = SkinList[i].name;
			SkinList[i].isUnlocked = true;

			std::cout << "You Brought : " << SkinList[i].name <<" for "<<SkinList[i].cost<<" coins."<< std::endl;
			std::cout <<"You have "<< totalCoins - SkinList[i].cost <<" coins remaining."<< std::endl;
			std::cout << std::endl;

			return totalCoins - SkinList[i].cost;
		}
		else {
			std::cout << "You do not have enough coins" << std::endl;
		}
		if (SkinList[i].location == currentLocation && SkinList[i].isUnlocked)
		{
			currentSkin = SkinList[i].name;
			std::cout << "You Selected : " << SkinList[i].name << std::endl;
			std::cout << std::endl;

			return totalCoins;
		}
	}
	return totalCoins;
}

std::string Shop::GetCurrentSkin()
{
	return currentSkin;
}