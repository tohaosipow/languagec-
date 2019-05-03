#include "pch.h"
#include "VarTable.h"

VarTable* VarTable::instance = 0;

VarTable * VarTable::getInstance()
{
	if (instance == nullptr) instance = new VarTable();
	return instance;
}

void VarTable::setVar(char * iden, int value)
{
	this->vars[iden] = value;
}

bool VarTable::isSetVar(char * iden)
{
	return this->vars.count(iden) != 0;
}

int VarTable::getVar(char * iden)
{
	return this->vars[iden];
}
