#pragma once
#include <string>
#include "dataStruct.h"
#include "lexeminator.h"
#include "syntaxinator.h"
#include "postfixinator.h"
#include "reshatinator.h"
using namespace std;
// сам класс, содержащий математическое выражение
class MathEq {
	string TextIn; // текст инфиксного
	queue<token> lexEq; // разделённый на лексемы текст
	queue<token> postEq; // постфикс
	int res;
public:
	MathEq(string eq) {
		if (eq == "") throw "no el in MathEq";
		TextIn = eq;
		lexeminator temp(TextIn.size());
		
		postfixinator temp2;
		reshatinator temp3;
		lexEq = temp.lexeminate(TextIn);
		syntaxinator temp1(lexEq);
		lexEq = temp1.syntaxinate(lexEq);
		postEq = temp2.postfixinate(lexEq);
		res = temp3.res(postEq);
	}
	MathEq(const MathEq& other) {
		TextIn = other.TextIn;
		lexEq = other.lexEq;
		postEq = other.postEq;
		res = other.res;
	}
	MathEq& operator=(const MathEq& other) {
		TextIn = other.TextIn;
		lexEq = other.lexEq;
		postEq = other.postEq;
		res = other.res;
		return *this;
	}
	string getTextInf() { return TextIn; }
	queue<token> getQueueIn() { return lexEq; }
	queue<token> getQueuePost() { return postEq; }
	int getRes() { return res; }
	
};