// 
// Demo's building a .a
// 

#include <stdio.h>

#include "MyMath.h"


int main(int argc, char* argv[]) {
  printf("Hello from the tutorial.\n");

  MyMath myMath(5);

  myMath.add(5);
  myMath.dump();
  myMath.subtract(1);
  myMath.dump();

  return 0;
}
