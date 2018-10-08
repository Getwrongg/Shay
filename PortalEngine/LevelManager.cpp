#include "LevelManager.h"

void LevelManager::LoadTexture()
{
	cubedraw.CreateTexture();
	coindraw.CreateTexture();
	audio.LoadWAV("COIN_PICKUP", "sounds/coin_pickup.wav");
	audio.LoadWAV("FAIL", "sounds/missionfailed.wav");
	audio.AudioVolume(1, 80);
}

void LevelManager::AnimateCoin(const GLfloat timeSincePrevFrame)
{
	coindraw.AnimateCoin(timeSincePrevFrame);
}

void LevelManager::LoadLevel(const std::string levelName, const char *file) // ./levels/level.txt
{ 

	std::ifstream levelfile(file);
	if (!levelfile) 
	{
		std::cout << "Unable to Load Level" << std::endl;
		return;
	}

	std::string line[MAX_HEIGHT];
	std::vector<std::string> levelVec;
	for (int i = 0; i < MAX_HEIGHT; i++) 
	{
		std::getline(levelfile, line[i]);
		levelVec.push_back(line[i]);
	}
	LevelStorage[levelName] = levelVec;

	levelfile.close();
}

void LevelManager::LoadLevelIndex(const char *file) // ./levels/level.txt
{
	std::ifstream indexfile(file);
	if (!indexfile) 
	{
		std::cout << "File not found" << std::endl;
		return;
	}

	std::vector<std::string> filename;
	std::string fName;
	while (!indexfile.eof()) {  //Cant be any empty new lines in the met_index.txt file.
		indexfile >> fName;
		filename.push_back(fName);
	}
	std::string levelName;
	for (unsigned i = 0; i < filename.size(); i++) //Add directory to file name then read data in from each file
	{ 
		std::string location = "./levels/"; //add ./level/ to name in level_index.txt
		levelName = filename[i];
		levelName.resize(levelName.size() - 4); //remove .txt from levelName
		location.append(filename[i]);

		std::ifstream datafile(location); // Open level and read in
		std::string line[MAX_HEIGHT];
		std::vector<std::string> levelVec;
		for (int i = 0; i < MAX_HEIGHT; i++)
		{
			std::getline(datafile, line[i]);
			levelVec.push_back(line[i]);
		}
		LevelStorage[levelName] = levelVec; // Store level
		Level_Index.push_back(levelName); //Store name

		std::cout << "File " << location << " Loaded" << std::endl;
		datafile.close();
	}
	indexfile.close();
}

void LevelManager::DrawLevel(const Coordinates pos)
{
	int reverse = MAX_HEIGHT-1;
	std::string currentnumber;
	for (unsigned i = 0; i < MAX_HEIGHT; i++) 
	{
		for (unsigned j = 0; j < currentLevel[reverse].length(); j++) 
		{
			currentnumber = currentLevel[reverse].at(j);
			if (currentnumber == "1") 
			{
				if (CheckCollision(pos, j, i)) {
					audio.PlayAudioChannel("FAIL", 1, 0);
					failed = true; 
				}
				else 
				{
					cubedraw.Draw((float)j, (float)i, 0.0f);
				}
			}
			if (currentnumber == "2") 
			{
				if (CheckCollision(pos, j, i)) 
				{
					coinscollected++;
					audio.PlayAudioChannel("COIN_PICKUP", 2, 0);
					currentLevel[reverse].replace(j, 1, "0"); //Remove coin from level
				}
				else 
				{
					coindraw.DrawCoin((float)j, (float)i, 0.0f);
				}
			}
			if (currentnumber == "3") {
				if (CheckCollision(pos, j, i))
				{
					if(!HasEndedRound())
					{
						SetNextLevel();
					}
						
				}
			}
		}
		reverse--;
	}
}

void LevelManager::SetLevel(const std::string levelName)
{
	currentLevel = LevelStorage.find(levelName)->second;
	currentLevelName = levelName;	

	endRound = false;
}

void LevelManager::SetNextLevel()
{
	currentlevelNumber++;
	if (Level_Index.size() > currentlevelNumber) 
	{
		SetLevel(Level_Index[currentlevelNumber]);
	}
	else 
	{
		SetLevel(Level_Index[0]);
		currentlevelNumber = 0;
	}
	endRound = true;
}

bool LevelManager::CheckCollision(Coordinates pos, unsigned x, unsigned y) 
{
	pos.x = (GLfloat)(pos.x / 14.5)-1; //Divide by scaling factor atm is 14.5 and take 1 but not sure why
	pos.y = (GLfloat)(pos.y / 14.5);

	if ((pos.x > x - 0.25 && pos.x < x + 1.3)&& (pos.y > y-0.25  && pos.y < y + 1.3 ) ) 
	{  
 		return true;
	}
	return false;;
}

int LevelManager::GetCoinsCollected()
{
	return coinscollected;
}

bool LevelManager::HasEndedRound()
{
	return endRound;
}

bool LevelManager::HasFailed() 
{
	return failed;
}

void LevelManager::ResetLevel() 
{
	SetLevel(currentLevelName);
	coinscollected = 0;
	failed = false;
}