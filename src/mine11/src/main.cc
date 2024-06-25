// 
// Demo's building with reading data from a file
// and including that file in the gn config files.
//
// CSV code is modeled after The Practice of Programming book
// sample code.
// 

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>  // 

#include "CSV.h"

using namespace std;


int main(int argc, char* argv[]) {

  string line;
  CSV csv;

#ifdef VERBOSE

  cout << "== main() ===" << endl;
#endif

  some_func();

  while(csv.getline(line) != 0) {
    cout << "line: " << line << endl;
  }

  return 0;
}
