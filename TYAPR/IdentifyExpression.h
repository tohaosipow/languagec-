
#include "Expression.h"
class IdentifyExpression :
	public Expression
{
public:
	IdentifyExpression(char* ident);
	~IdentifyExpression();
	Expression* collapse();
	int eval();
	int print();
private:
	char* ident;

};
