#include "reshatinator.h"
int reshatinator::res(queue<token> postf) {
	int temp1, temp2;
	stack<int> temp(postf.getLen());
	while (!postf.IsEmpty()) {
		if (postf.top().getIsNum()) {
			temp.push(postf.pop().getNum());
		}
		else {
			temp2 = temp.pop();
			temp1 = temp.pop();
			switch (postf.pop().getChar()) {
			case '+':
				temp.push(temp1 + temp2); break;
			case '-':
				temp.push(temp1 - temp2); break;
			case '*':
				temp.push(temp1 * temp2); break;
			case '/':
				temp.push(temp1 / temp2); break;
			}
		}
	}
	return temp.pop();
}