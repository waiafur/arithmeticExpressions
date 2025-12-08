#include "postfixinator.h"
queue<token> postfixinator::postfixinate(queue<token> eq) {
	stack<token> st(eq.getLen());
	queue<token> res(eq.getLen());
	map<char, int> priority = { {'+', 1}, {'-', 1}, {'*', 2}, {'/', 2}, {'(', 0} };
	token stackItem;
	while (!eq.IsEmpty()) {
		if (eq.top().getIsNum()) { // если число
			res.push(eq.pop());
		}
		else {
			switch (eq.top().getChar()) {
			case '(':
				st.push(eq.pop()); break;
			case ')':
				while (st.top().getChar() != '(') {
					res.push(st.pop());
				}
				st.pop();
				eq.pop();
				break;
			default: // operaTORS
				token eqToken = eq.pop();
				while (!st.IsEmpty()) {
					//token stacktemp = st.pop();
					if (eqToken.getIsUnar()) {
						token temp(0);
						res.push(temp);
					}
					if (priority[eqToken.getChar()] <= priority[st.top().getChar()]) res.push(st.pop());
					else { break; }
				}
				if (eqToken.getIsUnar() && st.IsEmpty()) {
					token temp(0);
					res.push(temp);
				}
				st.push(eqToken);
			}
		}
	}
	while (!st.IsEmpty()) {
		res.push(st.pop());
	}
	return res;
}