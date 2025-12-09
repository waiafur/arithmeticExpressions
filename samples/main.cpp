
#include "MathEq.h"
void main() {
	try {
		string test = "33*2+1";
		MathEq test1(test);
		cout << test1.getRes();
	}
	catch (string a) {
		cout << a;
	}

	
	
	
	
	
}