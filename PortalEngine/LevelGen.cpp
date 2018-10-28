#include "LevelGen.h"

LevelGen::LevelGen()
{
	srand(time(NULL));
}

void LevelGen::outputLevel(std::vector<std::string> level)
{
	std::string name;
	std::string front = "./levels/genedLevels/";
	std::string end = ".txt";
	std::string nameLvl = "level";
	std::string nameNum = std::to_string(nameCounter);
	
	name.append(front).append(nameLvl).append(nameNum).append(end);
	std::ofstream levelOutput(name);

	nameCounter++;
	for (unsigned i = 0; i < HEIGHT; i++)
	{
		for (unsigned j = 0; j < level[i].length(); j++)
		{
			levelOutput << level[i].at(j);
		}
		levelOutput << std::endl;
	}
	levelOutput.close();
}

std::vector<std::string> LevelGen::GenPartNames()
{		
	std::vector<std::string> partNames;

	std::string starttxt = "./levels/random/easy/";
	std::string endtxt = ".txt";
	for (int i = 0; i < LENGTH; i++)
	{
		std::string levelpart;
		std::string randnum = std::to_string((rand() % 15) + 1);

		levelpart = starttxt;
		levelpart.append(randnum);
		levelpart.append(endtxt);

		partNames.push_back(levelpart);
	}
	return partNames;
}

std::vector<std::string> LevelGen::GenLevel()
{
	std::string data;
	std::string lineData[HEIGHT];
	std::ifstream levelfile;

	std::vector<std::string> generatedLevel;
	std::vector<std::string> partNames = GenPartNames();

	for (int i = 0; i < HEIGHT; i++)
	{
		for (int j = 0; j < LENGTH; j++) 
		{
			if (j == LENGTH-1)
			{
				levelfile.open("./levels/random/required/end.txt");
				if (!levelfile)
				{
					std::cout << "Error in level gen" << std::endl;
					exit(1);
				}
			}
			else if (j % 2 == 0)
			{
				levelfile.open("./levels/random/required/gap.txt");
				if (!levelfile)
				{
					std::cout << "Error in level gen" << std::endl;
					exit(1);
				}
			}
			else
			{
				levelfile.open(partNames[j]);
				if (!levelfile)
				{
					std::cout << "Error in level gen" << std::endl;
					exit(1);
				}
			}

			for (int j = 0; j < i; j++) // moves to correct line in file
			{
				std::getline(levelfile, data); 
			}

			std::getline(levelfile, data);
			lineData[i].append(data);

			levelfile.close();
		}
		generatedLevel.push_back(lineData[i]);
	}

	outputLevel(generatedLevel);

	return generatedLevel;
}
