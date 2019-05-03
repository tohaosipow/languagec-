#include "pch.h"
#include "NumberExpression.h"
#include <iostream>
using namespace std;


NumberExpression::NumberExpression(int value)
{
	this->value = value;
	this->id = Expression::ids++;
	type = Number;
}

NumberExpression::NumberExpression(Expression * base)
{
	type = Number;
	this->id = base->id;
	this->value = base->eval();
}


NumberExpression::~NumberExpression()
{
}

Expression * NumberExpression::collapse()
{
	return nullptr;
}

int NumberExpression::eval()
{
	return value;
}

int NumberExpression::print()
{
	cout << this->id << ": " << " C " << value << endl;
	return  this->id;
}
