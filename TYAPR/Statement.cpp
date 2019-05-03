#include "pch.h"
#include "Statement.h"
#include <iostream>
#include "VarTable.h"
using namespace std;


Statement::Statement(char * identify, Expression * expression)
{
	this->id = Expression::ids++;
	this->identify = identify;
	this->expression = expression;
}

Statement::~Statement()
{
}

void Statement::execute()
{
	int n = expression->eval();
	int c = 0;
	int k = 1;
	int b = 0;
	while (n > 0)
	{
		b = n % 8;
		n /= 8; 
		c += b * pow(10, k - 1); 
		b = 0;  
		k++;
	}
	cout << identify << " = " << c << endl;
	VarTable::getInstance()->setVar(identify, expression->eval());
}

void Statement::collapse()
{
	Expression* e = this->expression->collapse();
	if (e != nullptr) this->expression = e;
}
void Statement::print()
{
	cout << this->id << ":  " << identify << " = ^" << expression->print() << endl;
}
