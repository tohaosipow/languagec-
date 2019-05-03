#pragma once
#include "Expression.h"
class NumberExpression :
	public Expression
{
public:
	NumberExpression(int value);
	NumberExpression(Expression* base);
	~NumberExpression();
	Expression* collapse();
	int eval();
	int print();
private:
	int value;
};

