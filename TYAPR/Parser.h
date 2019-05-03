#pragma once
#include "Statement.h";
using namespace std;
class Parser
{
public:
	Parser(char* content);
	Statement* searchStatement();
	Expression* searchExpression();
	Expression* searchPlusMinus();
	Expression* searchMultyDiv();
	Expression* searchNumber();
	char get();
	void splice();
	~Parser();
private:
	char* currentChar;
};

