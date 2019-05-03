#include "pch.h"
#include "Lexer.h"
#include <string>
#include <fstream>
#include <streambuf>
#include <streambuf>




Lexer::Lexer()
{
}

char * Lexer::lexIdentify(char ** cont)
{
	char* content = *cont;
	if (isalpha(content[0]) && !isalpha(content[1]) && is8Digit(content[1]) && !is8Digit(content[2]) && !isalpha(content[2])) {
			
			char* r = new char[3] { content[0], content[1], '\0'};
			*cont += 2;
			return r;
	}
	else if (isalpha(content[0]) && isalpha(content[1]) && !is8Digit(content[2]) && !isalpha(content[2])) {
	
		char* r = new char[3]{ content[0], content[1], '\0' };
		*cont += 2;
		return r;
	}
	else if (isalpha(content[0]) && !is8Digit(content[1]) && !isalpha(content[1])) {
		
		char* r = new char[2]{ content[0], '\0' };
		*cont += 1;
		return r;
	}
	else if (isalpha(content[0]) && isalpha(content[1]) && is8Digit(content[2]) && !is8Digit(content[3]) && !isalpha(content[3])) {
		char* r =  new char[4]{ content[0], content[1], content[2], '\0' };
		*cont += 3;
		return r;
	}
	else throw "Expected identificator";
}

int Lexer::lexConstant(char**cont)
{
	char* content = *cont;
	if (!is8Digit(content[0])) throw "Expected 8-digit number in constant";
	char* p = content;
	int number = 0;
	while (is8Digit(*p)) {
		number = number * 8 + *p - '0';
		p++;
		*cont+=1;
	}
	return number;
}

bool Lexer::is8Digit(char ch)
{
	return ch >= '0' && ch <= '7';
}

Lexer::~Lexer()
{
}
