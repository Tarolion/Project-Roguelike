#ifndef _INI_FILEREADER_H_
#define _INI_FILEREADER_H_
//
	#ifndef _IOSTREAM_
	//
		#include <iostream>
	//
	#endif // !_IOSTREAM_

	#ifndef _FSTREAM_
	//
		#include <fstream>
	//
	#endif // !_FSTREAM_

	#ifndef _SSTREAM_
	//
		#include <sstream>
	//
	#endif // !_SSTREAM_

	#ifndef _STRING_
	//
		#include <string>
	//
	#endif // !_STRING_

	#ifndef _VECTOR_
	//
		#include <vector>
	//
	#endif // !_VECTOR_

class IniFileReader
{
private:
	struct IniKey
	{
	public:
		std::string name;
		std::string value;
	};

	struct IniSection
	{
	public:
		std::string name;
		std::vector<IniKey*> keys;
	};
	
	const char* path;

	std::vector<IniSection*> _sections;
	std::vector<std::string> _lines;

	void Initialize();		// Clears all sections and lines vectors.
	bool ParseLines();		// Takes data in _lines and converts it into INI Data.

public:
	IniFileReader();
	~IniFileReader();

	bool ReadFile(const char* p);		// Returns true if successful, false if not.	// Saves file data to _lines.
	bool SaveFile();		// Returns true if successful, false if not.	// Saves file and updates _lines and _sections.

	// Returns the value pointed to.
	std::string GetData(std::string sectionName, std::string keyName);	

	// Sets the value pointed to, then saves the file.
	bool SetData(std::string sectionName, std::string keyName, std::string value);
};


//
#endif // !_INI_FILEREADER_H_