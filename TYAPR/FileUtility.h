#include <string>
#pragma once
using namespace std;
class FileUtility
{
public:
	FileUtility();
	static char* readFileToChar(string file);
	~FileUtility();
};

