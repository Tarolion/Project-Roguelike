#include "Settings.h"

std::string			Settings::GameDirectoryPath;

// Graphics
int					Settings::WindowWidth = 800;
int					Settings::WindowHeight = 600;
int					Settings::TileSize = 16;
bool				Settings::Windowed = false;

bool Settings::LoadSettingsFile()
{
	// Get Current Directory Path and store.
	TCHAR path[MAX_PATH];
	GetCurrentDirectory(MAX_PATH, path);
	Settings::GameDirectoryPath = path;

	// Now we want to load our Settings INI File in the resources folder.
	std::string settingsFilePath = Settings::GameDirectoryPath + "\\Resources\\Settings.ini";
	IniFileReader* fileReader = new IniFileReader();
	if (fileReader->ReadFile(settingsFilePath.c_str()))
	{
		try
		{
			std::size_t sz;
			// Graphics Section.
			Settings::WindowWidth			= std::stoi(fileReader->GetData("Graphics", "Width"), &sz);

			Settings::WindowHeight			= std::stoi(fileReader->GetData("Graphics", "Height"), &sz);

			Settings::TileSize				= std::stoi(fileReader->GetData("Graphics", "TileSize"), &sz);

			Settings::Windowed				= (fileReader->GetData("Graphics", "Windowed") == "true") ? true : false;
		}
		catch (const std::exception& ex) 
		{
			std::cout << "ERROR: " << ex.what() << std::endl;
			std::cout << "Could not load the Settings File..." << std::endl;
			return false;
		}
		catch (const std::string& ex) 
		{
			std::cout << "ERROR: " << ex << std::endl;
			std::cout << "Could not load the Settings File..." << std::endl;
			return false;
		}
	}
	else
	{
		std::cout << "Could not find the Settings File..." << std::endl;
		return false;
	}

	return true;
}