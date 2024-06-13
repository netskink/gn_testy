
#include <iostream>

#include "MyMath.h"
#include "MyString.h"
#include "Testy.h"

using namespace std;

int main(int argc, char* argv[]) {

	cout << "Test Thing" << endl;

#ifdef VERBOSE
	cout << "== main() ===" << endl;
#endif

	testMyMath();
	testMyString();


	return 0;
}


void testMyMath(void) {

  MyMath myMath(5);

  myMath.add(5);
  myMath.dump();
  myMath.subtract(1);
  myMath.dump();
    
}


void testMyString(void) {

  MyString myString("John");

  myString.add(" Fred Fred Davis");
  myString.dump();
  myString.subtract(" Fred");
  myString.dump();

}
