#pragma once
#include "Expression.h"
enum operationType {
	PLUS,
	MINUS,
	MULTY,
	DIV
};
class BinaryExpression :
	public Expression
{
public:
	BinaryExpression(Expression* expr1, Expression* expr2, operationType op);
	~BinaryExpression();
	int eval();
	int print();
	Expression* collapse();
private: 
	Expression* expr1;
	Expression* expr2;
	operationType operation;
	
};

