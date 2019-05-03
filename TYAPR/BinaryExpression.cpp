#include "pch.h"
#include "BinaryExpression.h"
#include "NumberExpression.h"
#include <iostream>
using namespace std;


BinaryExpression::BinaryExpression(Expression * expr1, Expression * expr2, operationType op)
{
	this->expr1 = expr1;
	this->expr2 = expr2;
	this->operation = op;
	this->id = Expression::ids++;
	type = Binary;
}

BinaryExpression::~BinaryExpression()
{
}

int BinaryExpression::eval()
{
	switch (operation) {
		case MINUS: {
			return expr1->eval() - expr2->eval();
			break;
		}
		case MULTY: {
			return expr1->eval() * expr2->eval();
			break;
		}
		case DIV: {
			return expr1->eval() / expr2->eval();
			break;
		}
		case PLUS: {
			return expr1->eval() + expr2->eval();
			break;
		}
		default: {
			return expr1->eval() + expr2->eval();
		}

	}
}

Expression* BinaryExpression::collapse() {
	Expression* ex1 = expr1->collapse();
	Expression* ex2 = expr2->collapse();
	if (ex1 != nullptr) expr1 = ex1;
	if (ex2 != nullptr) expr2 = ex2;
	Expression* e = nullptr;
	if (expr1->type == Number && expr2->type == Number) return new NumberExpression(this);

}

int BinaryExpression::print()
{
	expr1->print();
	expr2->print();
	switch (operation) {
	case MINUS: {
		cout << this->id << ": " << "^" <<expr1->id << "-" << " ^" << expr2->id << endl;
		break;
	}
	case MULTY: {
		cout << this->id << ": " << "^" << expr1->id << "*" << " ^" << expr2->id << endl;
		break;
	}
	case DIV: {
		cout << this->id << ": " << "^" << expr1->id << "/" << " ^" << expr2->id << endl;
		break;
	}
	case PLUS: {
		cout << this->id << ": " << "^" << expr1->id << "+" << " ^" << expr2->id << endl;
		break;
	}
	default: {
		cout << expr1->print() << "DEFAULT" << expr2->print() << endl;
	}
	

	}
	return this->id;
}
