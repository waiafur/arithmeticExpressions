
#include "MathEq.h"
void main() {
	try {
		string test = "1+26*3";
		MathEq test1(test);
		cout << test1.getRes();
	}
	catch (string a) {
		cout << a;
	}

	
	
	
	
	
}