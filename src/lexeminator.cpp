#include "lexeminator.h"

int lexeminator::getCharSost(char a) {
	switch (a) {
	case '+': case '-': case '*': case '/': case '(': case ')':
		return 0;
		break;
	case '0': case '1': case '2': case '3': case '4': case '5': case '6': case '7': case '8': case '9': 
		return 1;
		break;
	default:
		err = err + to_string(i) + " - unknown char, ";
		return 2;
	}
}



void lexeminator::f0(char a) {
	temp = (int)a - 48;
}
void lexeminator::f1(char a) {
	res.push(token(a));
}
void lexeminator::f2(char a) {
	temp *= 10;
	temp += (int)a - 48;
}
void lexeminator::f3(char a) {
	res.push(token(temp));
	res.push(token(a));
}

queue<token> lexeminator::lexeminate(string eq) {

	while (i < eq.size()) {
		if (getCharSost(eq[i]) != 2) {
			(*this.*func[currState][getCharSost(eq[i])])(eq[i]);
			currState = getCharSost(eq[i]);
		}
		i++;
	}
	if (currState == 1) res.push(temp);
	if (err != "") throw err;
	queue<token> temp(res.getUsedLen());
	while (!res.IsEmpty()) {
		temp.push(res.pop());
	}
	return temp;
}

