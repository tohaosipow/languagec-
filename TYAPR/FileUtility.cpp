#include "pch.h"
#include "FileUtility.h"
#include <iostream>;
#include <iostream>;
#include <fstream>

FileUtility::FileUtility()
{
}

char * FileUtility::readFileToChar(string file)
{
	int length;
	char* buffer;

	ifstream is;
	is.open(file, ios::in | ios::binary);

	is.seekg(0, ios::end);
	length = is.tellg();
	is.seekg(0, ios::beg);

	buffer = new char[length+1];

	is.read(buffer, length);
	buffer[length] = '\0';
	is.close();

	//cout.write(buffer, length);
	return buffer;
}


FileUtility::~FileUtility()
{
}
