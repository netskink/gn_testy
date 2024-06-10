// 
// Demo's building a .a
// 

#include <stdio.h>

#include "MyMath.h"
#include "MyString.h"


int main(int argc, char* argv[]) {

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
