#include "syntaxinator.h"
int syntaxinator::getTokenSost(token a) {
	if (a.getIsNum()) return 3;
	switch (a.getChar()) {
	case '(': return 1;
	case ')': return 2;
	case '+': case '-': return 4;
	case '*': case '/': return 5;
	}
}

void syntaxinator::f0(token a) {
	res.push(a);
	brackets.push(cur);
	cur++;
}
void syntaxinator::f1(token a) {
	res.push(a);
	err = err + to_string(cur) + " strange ')',  ";
	try {
		brackets.pop();
	}
	catch (...) {
		err = err + to_string(cur) + " no pair for ')',  ";
	}
	cur++;
}
void syntaxinator::f2(token a) {
	res.push(a);
	cur++;
}
void syntaxinator::f3(token a) {
	a.setUnarTrue();
	res.push(a);
	cur++;
}
void syntaxinator::f4(token a) {
	err = err + to_string(cur) + " can't be unar,  ";
	res.push(a);
	cur++;
}
void syntaxinator::f5(token a) {
	err = err + to_string(cur) + " netu znaka before '(',  ";
	brackets.push(cur);
	res.push(a);
	cur++;
}
void syntaxinator::f6(token a) {
	try {
		brackets.pop();
	}
	catch (...) {
		err = err + to_string(cur) + " no pair for ')',  ";
	}
	res.push(a);
	cur++;
}
void syntaxinator::f7(token a) {
	err = err + to_string(cur) + " num after num,  ";
	res.push(a);
	cur++;
}
void syntaxinator::f8(token a) {
	err = err + to_string(cur) + " znak posle znaka,  ";
	res.push(a);
	cur++;
}
queue<token> syntaxinator::syntaxinate(queue<token> a) {
	int newSost;
	while (!a.IsEmpty()) {
		newSost = getTokenSost(a.top());
		(*this.*func[curSost][newSost - 1])(a.pop());
		curSost = newSost / 2;
	}
	while (!brackets.IsEmpty()) err = err + to_string(brackets.pop()) + " '(' without pair,  ";
	if (err != "") throw err;
	return res;
}