#include "FileHandler.h"

std::string FileHandler::directoryName = "Simon Says";
std::string FileHandler::highScoreFileName = "HighScore.Txt";
size_t FileHandler::highScore = 0;
std::string FileHandler::highScoreFilePath = "";
std::string FileHandler::appDataDirectoryPath = "";

void FileHandler::CreateAppDataDirectory()
{
	char* pValue;
	size_t len;
	if (_dupenv_s(&pValue, &len, "APPDATA") == 0)
	{
		std::stringstream ss;
		ss << pValue << "\\" << directoryName << "\\";
		appDataDirectoryPath = ss.str();
		if (!std::filesystem::exists(appDataDirectoryPath))
		{
			std::filesystem::create_directory(appDataDirectoryPath);
		}
		highScoreFilePath = appDataDirectoryPath + highScoreFileName;
	}
	else
	{
		throw std::exception::exception("HighScore file creation failed");
	}
	free(pValue);
}

size_t FileHandler::ReadHighScoreFromFile()
{
	std::ifstream inputStream(FileHandler::highScoreFilePath);
	std::string line;
	while (std::getline(inputStream, line).good() && !line.empty())
	{
		std::stringstream ss;
		ss << line;
		ss >> highScore;
	}
	inputStream.close();
	return highScore;
}

void FileHandler::WriteHighScoreToFile(const size_t _highScore)
{
	std::ofstream outStream(FileHandler::highScoreFilePath);
	if (highScore < _highScore)
	{
		highScore = _highScore;
		outStream << std::to_string(highScore) << std::endl;
	}
	outStream.close();
}
