#ifndef _SETTINGS_H_
#define _SETTINGS_H_
//

#include "Includes.h"
#include <iostream>
#include <Windows.h>

#include "Utilities\FileReaders\IniFileReader.h"

class Settings
{
public:
	static std::string GameDirectoryPath;

	// Graphics
	static int WindowWidth;
	static int WindowHeight;
	static int TileSize;
	static bool Windowed;

	static bool LoadSettingsFile();
};

//
#endif // !_SETTINGS_H_
