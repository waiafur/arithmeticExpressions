#pragma once
#include "dataStruct.h"
#include <string>
class syntaxinator {
	queue<token> res;
	int cur=0;
	int curSost = 0;
	string err="";
	stack<int> brackets; 
	// ( - 1
	// ) - 2
	// 0...9 - 3
	// +- - 4
	// */ - 5
	// à-1: index of collumn, à/2 - nextSost, 0-(, 1-num, 2-+-*/.
	
	int getTokenSost(token a);
	void (syntaxinator::* func[3][5])(token a);
	//    | ( | ) | num | +- | */ |
	// 0  | 0 | 1 |  2  |  3 |  4 |
	// 1  | 5 | 6 |  7  |  2 |  2 |
	// 2  | 0 | 1 |  2  |  8 |  8 |
	
	
	void f0(token a); // ( push
	void f1(token a); // err ) push
	void f2(token a); // push
	void f3(token a); // unar push
	void f4(token a); // err unar push
	void f5(token a); // num( err
	void f6(token a); // ) push
	void f7(token a); // num after num
	void f8(token a); // znak posle znaka
public:
	syntaxinator(queue<token> _res): res(_res.getLen()), brackets(_res.getLen()) {
		func[0][0] = &syntaxinator::f0;
		func[0][1] = &syntaxinator::f1;
		func[0][2] = &syntaxinator::f2;
		func[0][3] = &syntaxinator::f3;
		func[0][4] = &syntaxinator::f4;
		func[1][0] = &syntaxinator::f5;
		func[1][1] = &syntaxinator::f6;
		func[1][2] = &syntaxinator::f7;
		func[1][3] = &syntaxinator::f2;
		func[1][4] = &syntaxinator::f2;
		func[2][0] = &syntaxinator::f0;
		func[2][1] = &syntaxinator::f1;
		func[2][2] = &syntaxinator::f2;
		func[2][3] = &syntaxinator::f8;
		func[2][4] = &syntaxinator::f8;
	}
	queue<token> syntaxinate(queue<token> a);
	string getErr() { return err; }
};