

#ifdef __cplusplus

#include <string>
#include <iostream>
#include <sstream>

#include "MyString.h"


using namespace std;


MyString::MyString(string aString) 
    : line(aString) {

#ifdef VERBOSE
  cout << "== MyString::MyString(string aString) ===" << endl;
#endif
    cout << "Line: " << line << endl;

}

string MyString::dump(void) const {
    cout << "Total: " << line << endl;
    return line;
}

string MyString::add(string aString) {
    line = line + aString;
    return line;
}


string MyString::subtract(string aString) {
    size_t pos;

    pos = line.find(aString);

    cout << "pos: " << pos << endl;
    cout << "std::string::npos: " << std::string::npos << endl;

    while (pos != std::string::npos) {
        line.erase(pos, aString.length());
        pos = line.find(aString);
    }

    return line;
}

//
// C wrappers
//

extern "C" void * call_MyStringConstructor(void *p, char *pValue) {

    std::ostringstream buffer; // requires #include <sstream>
    std::string result;

    if (nullptr == pValue) {
        result = "";
    } else {
        int i=0;
        while(pValue[i] != 0) {
            buffer << pValue[i++];
        }
        result = buffer.str();

    }

    if (nullptr == p) {
        p = new MyString(result);
    }

    return (void *) p;
}

extern "C" void call_MyStringDump(void *p) {

    if (nullptr == p) {
        return;
    }

    ((MyString *) p)->dump();

    // result.c_str() returns const char *
    // result.data() returns char *
    //return (char *) result.data();  // TODO: add mod for c++17+
    //return result.c_str();
}

extern "C" void call_MyStringAdd(void *p, const char * pValue) {

    if (nullptr == p) {
        p = new MyString("");
    }

    ((MyString *) p)->add(pValue);

}


extern "C" void call_MyStringSubtract(void *p, const char * pValue) {

    if (nullptr == p) {
        p = new MyString("");
    }

    ((MyString *) p)->subtract(pValue);

}

#endif