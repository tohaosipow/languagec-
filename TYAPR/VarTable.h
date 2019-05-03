#pragma once
#include <map>
using namespace std;

class VarTable
{
public:
	static VarTable* getInstance();
	void setVar(char* iden, int value);
	bool isSetVar(char* iden);
	int getVar(char* iden);
	
private:
	VarTable() {};
	VarTable(const VarTable&);
	VarTable& operator=(VarTable&);
	static VarTable * instance;
	map<string, int> vars;
	~VarTable()
	{
	}


};

