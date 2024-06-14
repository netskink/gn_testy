// 
// Demo's building with a config directive
// 

#include <stdlib.h>
#include <stdio.h>

#include "MyMath.h"
#include "MyString.h"


int main(int argc, char* argv[]) {

#ifdef VERBOSE
  printf("== main() ===\n");
#endif

  printf("Demo a static library.\n");
  void *pMyMath = NULL;
  double dTotal;

  pMyMath =  call_MyMathConstructor(pMyMath, 33.3);
  printf("main{Total}: %.2f\n", dTotal);
  dTotal = call_MyMathAdd(pMyMath, 22.2);  // will print the result and return result
  printf("main{Total}: %.2f\n", dTotal);
  dTotal = call_MyMathDump(pMyMath);  // will print the result and return result
  printf("main{Total}: %.2f\n", dTotal);
  dTotal = call_MyMathSubtract(pMyMath, 11.1);  // will print the result and return result
  dTotal = call_MyMathDump(pMyMath);  // will print the result and return result
  printf("main{Total}: %.2f\n", dTotal);

  if (NULL != pMyMath) {
    free(pMyMath);
    pMyMath = NULL;
  }


  printf("Demo a dynamic library.\n");
  void *pMyString = NULL;
  //char *pLine = NULL;

  pMyString =  call_MyStringConstructor(pMyString, "John");
  call_MyStringDump(pMyString);  // will print the result and return result
  call_MyStringAdd(pMyString, " Fred");  
  call_MyStringDump(pMyString);  // will print the result and return result
  call_MyStringSubtract(pMyString, " Fred");  
  call_MyStringDump(pMyString);  // will print the result and return result

  return 0;
}
