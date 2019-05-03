#include "pch.h"
#include "Parser.h"
#include "Lexer.h"
#include <iostream>
#include "NumberExpression.h"
#include "IdentifyExpression.h"
#include "BinaryExpression.h"
#include <cstdlib>


Parser::Parser(char* content)
{
	try {
		this->currentChar = content;
		while (*currentChar != '\0') {

			Statement* s = searchStatement();
			s->collapse();
			//s->print();
			s->execute();

		}
	}
	catch (const char* error)
	{
		cout << "ERROR: " << error << endl;
		exit(1);
	}
}

Statement * Parser::searchStatement()
{
	splice();
	char* ident = Lexer::lexIdentify(&currentChar);
	if (get() != '(') throw "Expected ( between identify and expression";
	Statement* s = new Statement(ident, searchExpression());
	if (get() != ')') throw "Expected ) after expression in statement";
	return s;
}

Expression * Parser::searchExpression()
{
	Expression* expr = searchPlusMinus();
	return expr;
}

Expression * Parser::searchPlusMinus()
{
	Expression* expr = searchMultyDiv();
	while (true) {
		if (*currentChar == '+') {
			get();
			expr = new BinaryExpression(expr, searchMultyDiv(), PLUS);
			continue;
		}
		if (*currentChar == '-') {
			get();
			expr = new BinaryExpression(expr, searchMultyDiv(), MINUS);
			continue;
		}
		break;
	}
	return expr;
}

Expression * Parser::searchMultyDiv()
{

	Expression* expr = searchNumber();
	while (true) {
		if (*currentChar == '*') {
			get();
			expr = new BinaryExpression(expr, searchNumber(), MULTY);
			continue;
		}
		if (*currentChar == '/') {
			get();
			expr = new BinaryExpression(expr, searchNumber(), DIV);
			continue;
		}
		break;
	}
	return expr;
}

Expression * Parser::searchNumber()
{
	
		Expression* expr = nullptr;
		if (Lexer::is8Digit(*currentChar)) expr = new NumberExpression(Lexer::lexConstant(&currentChar));
		else if (isalpha(*currentChar)) expr = new IdentifyExpression(Lexer::lexIdentify(&currentChar));
		else if (get() == '(') {
			expr = searchExpression();
			if (get() != ')') throw "Expected ) in expression";
		}
		else {
			
				throw "Expected constant or identificator, but not found.";
			
		}
		return expr;
	
}

char Parser::get()
{
	return *(currentChar++);
}

void Parser::splice()
{
	while (*currentChar == '\r' || *currentChar == '\n') {
		++currentChar;
	}
}


Parser::~Parser()
{
}
