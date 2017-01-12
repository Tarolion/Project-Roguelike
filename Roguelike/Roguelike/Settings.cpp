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
	std::string data = "";

	if (fileReader->ReadFile(settingsFilePath.c_str()))
	{
		try
		{
			std::size_t sz;
			// Graphics Section.
			data = fileReader->GetData("Graphics", "Width");
			if (data != "") { Settings::WindowWidth = std::stoi(data, &sz); }
			else { fileReader->SetData("Graphics", "Width", std::to_string(Settings::WindowWidth)); }

			data = fileReader->GetData("Graphics", "Height");
			if (data != "") 
			{
				Settings::WindowHeight = std::stoi(data, &sz); 
			}
			else 
			{ 
				fileReader->SetData("Graphics", "Height", std::to_string(Settings::WindowHeight)); 
			}

			data = fileReader->GetData("Graphics", "TileSize");
			if (data != "") { Settings::TileSize = std::stoi(data, &sz); }
			else { fileReader->SetData("Graphics", "TileSize", std::to_string(Settings::TileSize)); }

			data = fileReader->GetData("Graphics", "Windowed");
			if (data != "") { Settings::Windowed = (data =="true") ? true : false;}
			else { fileReader->SetData("Graphics", "Windowed", Settings::Windowed ? "true" : "false"); }
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

		fileReader->SaveFile();
	}
	else
	{
		// Graphics Section.
		fileReader->SetData("Graphics", "Width",	std::to_string(Settings::WindowWidth));
		fileReader->SetData("Graphics", "Height",	std::to_string(Settings::WindowHeight));
		fileReader->SetData("Graphics", "Windowed", Settings::Windowed ? "true" : "false");
		fileReader->SetData("Graphics", "TileSize", std::to_string(Settings::TileSize)); 

		fileReader->SaveFile();

	}

	return true;
}