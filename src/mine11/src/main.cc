// 
// Demo's building with reading data from a file
// and including that file in the gn config files.
//
// CSV code is modeled after The Practice of Programming book
// sample code.
// 

#include <iostream>  // if you want to use stdin like original example
#include <fstream>  // if you want to read from a file
#include <string>
#include <vector>
#include <algorithm>  // 

#include "CSV.h"

using namespace std;


int main(int argc, char* argv[]) {

  string line;

 
 

#ifdef VERBOSE
  cout << "== main() ===" << endl;
#endif

  // no need for elaborate checks, this is just a hack demo
  cout << "argc: " << argc << endl;
  cout << "argv[0]: " << argv[0] << endl;  // ./out/main
  cout << "argv[1]: " << argv[1] << endl;  // data/data.csv

  ifstream file(argv[1]);
   if (!file.is_open()) {
    cerr << "Failed to open the input file."  << endl;
    return 1;
   }
  CSV csv(file);


  // read from the file handle, line by line
  int line_num = 0;
  while(csv.getline(line) != 0) {
    //cout << "line: " << line << endl;
    for (int i = 0; i < csv.getnfield(); i++) {
      cout << "line[" << line_num << "]: ";
      cout << "filed[" << i << "]: '" << csv.getfield(i) << "'\n";
    }
    line_num++;
  }

  return 0;
}
