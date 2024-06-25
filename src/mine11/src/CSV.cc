#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include "CSV.h"

using namespace std;

int some_func(void) {

#ifdef VERBOSE
	cout << "== some_func() ===" << endl;
#endif

	cout << "do something here" << endl;

	return 0;

}


CSV::CSV(istream& fin, string sep) 
	: fin(fin), fieldsep(sep) {

}

// getline: get one line, grow as needed
int CSV::getline(string& str) {

	char c;

	// This reads character by character 
	// until EOL.
	// The result is put in the private line variable.
	for (line = ""; fin.get(c) && !endofline(c); /* no iteration */) {
		line += c;
	}

	cout << "getline()::line: " << line << endl;

	split();
	str = line;

	return !fin.eof();

}

// split: split line into fields
int CSV::split() {

	return nfield;

}

// endofline: check for and consume \r, \n, \r\n or EOF
int CSV::endofline(char c) {
	int eol; // a flag

	// set flag if carriage return \r or 
	// line feed \n
	eol = ( c=='\r' || c=='\n' );

	// on windows, line ending is \r\n
	if ( c=='\r' ) {
		fin.get(c);
		// get next character
		if ( !fin.eof() && c!='\n') {
			// the next character is neither
			// \n or eof so putback in the queue
			fin.putback(c); // read to far
		}
	}

	// returns non zero when \r, \n or \r\n
	return eol;
}