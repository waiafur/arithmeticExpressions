#pragma once
#include <iostream>
// структуры что используются в коде: стек, очередь и токены для очереди
using namespace std;
template <class T>
class stack {
	T* mem;
	int curr, len;
public:
	stack(int n) :curr(-1), len(n) {mem = new T[n];}
	bool IsFull() { return curr == len - 1; }
	bool IsEmpty() { return curr == -1; }
	void push(T a) { 
		if (!IsFull()) { curr++; mem[curr] = a; }
		else { throw "push - full stack"; }
	}
	T top() { 
		if (!IsEmpty()) return mem[curr];
		else { throw "stack top - no el"; }
	}
	T pop() { 
		if (!IsEmpty()) return mem[curr--];
		else { throw "stack pop - no el"; }
	}
	int getLen() { return len; }
	stack(const stack& other) : len(other.len), curr(other.curr) {
		mem = new T[len];
		for (int i = 0; i < len; i++) {
			mem[i] = other.mem[i];
		}
	}
	stack& operator=(const stack& other) {
		if (this == other) return *this;
		delete[] mem;
		len = other.len;
		curr = other.curr;
		mem = new T[len];
		for (int i = 0; i < len; i++) {
			mem[i] = other.mem[i];
		}
		return *this;
	}
	~stack() {
		delete[] mem;
	}
};
template <class T>
class queue {
	T* mem;
	int len, fp, lp;
	int next(int i) { return (i + 1) % len; }
public:
	queue(int n=1) :len(n+1), fp(0), lp(-1) { mem = new T[len]; }
	bool IsFull() { return next(next(lp)) == fp; }
	bool IsEmpty() { return next(lp) == fp; }
	void push(T a) {
		if (!IsFull()) { lp=next(lp); mem[lp] = a; }
		else { throw "push - full queue"; }
	}
	T top() {
		if (!IsEmpty()) return mem[fp];
		else { throw "queue top - no el"; }
	}
	T pop() {
		if (!IsEmpty()) {
			T temp = mem[fp];
			fp = next(fp);
			return temp; 
		}
		else { throw "queue pop - no el"; }
	}
	int getUsedLen() { 
		if (!IsEmpty()) {
			if (lp >= fp) {
				return lp - fp + 1;
			}
			else{
				return len - (fp - lp) + 1;
			}
		}
		else {
			return 0;
		}
	}
	int getLen() {
		return len;
	}
	~queue() {
		delete[] mem;
	}
//	queue(const queue& other) {
//		len = other.len;
//		lp = -1;
//		fp = 0;
//		mem = new T[len];
//		for (int i = other.fp; i != next(other.lp); i = next(i)) {
//			push(other.mem[i]);
//		}
//		
//	}
//	queue& operator=(const queue& other) {
//		if (other == this) return *this;
//		delete[] mem;
//		mem = new T[len];
//		len = other.len;
//		lp = -1;
//		fp = 0;
//		for (int i = other.fp; i != next(other.lp); i = next(i)) {
//			push(other.mem[i]);
//		}
//		return *this;
//	}
	queue(const queue& other) : len(other.len), fp(other.fp), lp(other.lp) {
		mem = new T[len];
		for (int i = 0; i < len; i++) {
			mem[i] = other.mem[i];
		}
	}

	queue& operator=(const queue& other) {
		if (this == &other) return *this;
		delete[] mem;
		len = other.len;
		fp = other.fp;
		lp = other.lp;
		mem = new T[len];
		for (int i = 0; i < len; i++) {
			mem[i] = other.mem[i];
		}
		return *this;
	}
};
class token {
	int val;
	bool IsNum, IsUnar;
public:
	token(char a) {
		IsNum = false;
		IsUnar = false;
		val = (int)a;
	}
	token(int a=0) {
		IsNum = true;
		val = a;
	}
	int getNum() { return val; }
	char getChar() { return (char)val; }
	bool getIsNum() { return IsNum; }
	bool getIsUnar() { return IsUnar; }
	void setUnarTrue() { IsUnar = true; }
	friend ostream& operator<<(ostream& os, token a) {
		if (a.getIsNum()) { cout << a.getNum(); }
		else { cout << a.getChar(); }
		return os;
	}

};