#pragma once
class Lexer
{
public:
	Lexer();
	static char* lexIdentify(char** cont);
	static int lexConstant(char** cont);
	static bool is8Digit(char ch);
	~Lexer();
};

