#include <string>
#include <iostream>

#include "MyString.h"


using namespace std;


MyString::MyString(string aString) 
    : line(aString) {

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