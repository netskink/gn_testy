// 
// Demo's building with a config directive
// 

#include <iostream>

#include "MyMath.h"
#include "MyString.h"

using namespace std;

int main(int argc, char* argv[]) {

#ifdef VERBOSE
  cout << "== main() ===" << endl;
#endif


  printf("Demo a static library.\n");
  MyMath myMath(5);

  myMath.add(5);
  myMath.dump();
  myMath.subtract(1);
  myMath.dump();

  printf("Demo a dynamic library.\n");
  MyString myString("John");

  myString.add(" Fred Fred Davis");
  myString.dump();
  myString.subtract(" Fred");
  myString.dump();

  return 0;
}
