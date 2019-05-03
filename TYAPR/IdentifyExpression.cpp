#include "pch.h"
#include "IdentifyExpression.h"
#include "VarTable.h"
#include <iostream>
using namespace std;

IdentifyExpression::IdentifyExpression(char * ident)
{
	this->id = Expression::ids++;
	this->ident = ident;
	type = Ident;
}

IdentifyExpression::~IdentifyExpression()
{
}

Expression * IdentifyExpression::collapse()
{
	return nullptr;
}

int IdentifyExpression::eval()
{
	return  VarTable::getInstance()->isSetVar(ident) ? VarTable::getInstance()->getVar(ident) : throw "Identificator not defined";
}

int IdentifyExpression::print()
{
	cout << this->id << ": " << ident << endl;
	return this->id;
}
