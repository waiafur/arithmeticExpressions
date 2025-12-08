#pragma once
#include "dataStruct.h"
#include <string>
using namespace std;

// автомат, делящий поступающий string в очередь
class lexeminator {
	int currState;
	int temp;
	int i = 0;
	void (lexeminator::* func[2][2])(char a);
	string err = "";
	queue<token> res; 
	int getCharSost(char a); // возвращает следующее состояние автомата и столбец для функции, приватный ибо пользователю не надо
	void f0(char a); // начало написания числа
	void f1(char a); // пушим знак
	void f2(char a); // прибавляем цифру к имеющемуся
	void f3(char a); // пушим число и знак
	//    | znak | chislo
	// 0  | f1   | f0
	// 1  | f3   | f2   
	// -----------------
	//    | znak | chislo
	// 0  |  0   |  1
	// 1  |  0   |  1
public:
	lexeminator(int len): res(queue<token>(len)) {
		currState = 0;
		func[0][0] = &lexeminator::f1;
		func[0][1] = &lexeminator::f0;
		func[1][0] = &lexeminator::f3;
		func[1][1] = &lexeminator::f2;
	}

	queue<token> lexeminate(string eq);
	
	
};