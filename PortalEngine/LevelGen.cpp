#include "LevelGen.h"

LevelGen::LevelGen()
{
	srand(time(NULL));
}

void LevelGen::GenPartNames()
{		
	std::string starttxt = "./levels/random/easy/";
	std::string endtxt = ".txt";
	for (int i = 0; i < 34; i++)
	{
		std::string levelpart;
		std::string randnum = std::to_string((rand() % 10) + 1);

		levelpart = starttxt;
		levelpart.append(randnum);
		levelpart.append(endtxt);

		partNames.push_back(levelpart);
	}
}

std::vector<std::string> LevelGen::GenLevel()
{
	std::string data;
	std::string lineData[MAX];

	GenPartNames();
	for (int i = 0; i < MAX; i++)
	{
		for (int j = 0; j < 34; j++) // 34 is the length of the level
		{
			std::ifstream levelfile(partNames[j]);
			if (!levelfile)
			{
				std::cout << "Error in level gen" << std::endl;
				exit(1);
			}

			switch (i) // moves to correct line in file
			{
			case 1:
				for (int j = 0; j < i; j++)
					std::getline(levelfile, data);
				break;
			case 2:
				for (int j = 0; j < i; j++)
					std::getline(levelfile, data);
				break;
			case 3:
				for (int j = 0; j < i; j++)
					std::getline(levelfile, data);
				break;
			case 4:
				for (int j = 0; j < i; j++)
					std::getline(levelfile, data);
				break;
			case 5:
				for (int j = 0; j < i; j++)
					std::getline(levelfile, data);
				break;
			case 6:
				for (int j = 0; j < i; j++)
					std::getline(levelfile, data);
				break;
			case 7:
				for (int j = 0; j < i; j++)
					std::getline(levelfile, data);
				break;
			case 8:
				for (int j = 0; j < i; j++)
					std::getline(levelfile, data);
				break;

			}

			std::getline(levelfile, data);
			lineData[i].append(data);

			levelfile.close();
		}
		currentLevel.push_back(lineData[i]);
	}
	return currentLevel;
}
