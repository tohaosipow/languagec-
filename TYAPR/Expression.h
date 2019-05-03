#pragma once
enum ExpressionType {Binary, Number, Ident};
class Expression
{
public:
	Expression();
	~Expression();
	virtual int eval() = 0;
	virtual int print() = 0;
	static int ids;
	int id;
	virtual Expression* collapse() = 0;
	ExpressionType type;
	
};

