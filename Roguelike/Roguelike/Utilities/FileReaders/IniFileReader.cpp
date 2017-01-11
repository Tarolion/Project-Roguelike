#ifndef _INI_FILEREADER_H_
//
#include "IniFileReader.h"

IniFileReader::IniFileReader()
{
	_lines.clear();
	_sections.clear();
}

IniFileReader::~IniFileReader()
{
	_lines.clear();
	_sections.clear();
}

void IniFileReader::Initialize()
{
	_lines.clear();
	_sections.clear();
}
bool IniFileReader::ParseLines()
{
	IniSection lastSection;
	lastSection.name = "#unnamed#";
	lastSection.keys.clear();

	std::size_t pos = 0;

	for (std::string line : _lines)
	{
		// Remove any comments
		pos = line.find("#", 0);
		if (!(pos > line.length()))
		{
			line = line.substr(0, pos);
		}

		// Check if section.
		pos = line.find("[", 0);
		if (!(pos > line.length()))
		{
			// Add last Section to sections.
			if (lastSection.name != "#unnamed#")
			{
				_sections.push_back(lastSection);
			}

			// Create new temp section
			IniSection section;
			section.name = line.substr(pos+1, line.length() - 2);
			section.keys.clear();

			lastSection = section;
		}

		// Check if Key
		pos = line.find(":", 0);
		if (!(pos > line.length()))
		{
			// Create Key
			IniKey key;

			// Get Name and value
			key.name	= line.substr(0, pos);
			key.value	= line.substr(pos + 1);
			
			// Add key to last Section
			if (lastSection.name != "#unnamed#")
			{
				lastSection.keys.push_back(key);
			}
		}
	}

	if (lastSection.name != "#unnamed#")
	{
		_sections.push_back(lastSection);
	}

	if (_sections.size() > 0)
		return true;

	return false;
}

bool IniFileReader::ReadFile(const char* p)
{
	path = p;

	Initialize();

	std::ifstream stream(path);

	if (stream.is_open())
	{
		std::string line;

		while (std::getline(stream, line))
		{
			_lines.push_back(line);
		}

		stream.close();
	}
	else return false;

	return ParseLines();
}

bool IniFileReader::SaveFile()
{
	// TODO
	return false;
}

std::string IniFileReader::GetData(std::string sectionName, std::string keyName)
{
	for (IniSection s : _sections)
	{
		if (s.name == sectionName)
		{
			for (IniKey k : s.keys)
			{
				if (k.name == keyName)
				{
					return k.value;
				}
			}
		}
	}

	return "";
}

bool IniFileReader::SetData(std::string sectionName, std::string keyName, std::string value)
{
	for (IniSection s : _sections)
	{
		if (s.name == sectionName)
		{
			for (IniKey k : s.keys)
			{
				if (k.name == keyName)
				{
					k.value = value;
					return true;
				}
			}
		}
	}

	return false;
}

//
#endif // !_INI_FILEREADER_H_
