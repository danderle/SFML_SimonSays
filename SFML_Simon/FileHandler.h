#pragma once
#include <filesystem>
#include <vector>
#include <sstream>
#include <fstream>

class FileHandler
{
public:
	FileHandler() = default;

	static void CreateAppDataDirectory();
	static size_t ReadHighScoreFromFile();
	static void WriteHighScoreToFile(const size_t highScore);
	
private:
	static std::string directoryName;
	static std::string highScoreFileName;
	static size_t highScore;
	static std::string appDataDirectoryPath;
	static std::string highScoreFilePath;
};

