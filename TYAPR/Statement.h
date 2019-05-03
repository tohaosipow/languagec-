#pragma once
#include "Expression.h"
class Statement
{
public:
	Statement(char* identify, Expression* expression);
	~Statement();
	void execute();
	void collapse();
	void print();
	
private:
	char* identify;
	int id;
	Expression* expression;
};

