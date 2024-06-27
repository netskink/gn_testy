
// CSV code is modeled after The Practice of Programming book
// sample code.
// 
// https://www.cs.princeton.edu/~bwk/tpop.webpage/csvgetlinec++.c
// 
/* Copyright (C) 1999 Lucent Technologies */
/* Excerpted from 'The Practice of Programming' */
/* by Brian W. Kernighan and Rob Pike */

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include "CSV.h"

using namespace std;


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

	//cout << "getline()::line: " << line << endl;

	split();
	str = line;

	return !fin.eof();

}

// advance_quoted: quoted filed; return index of next separator
int CSV::advance_quoted(const string& line, string& fld, int i) {

	int j;

	fld = "";
	for (j = i; j < line.length(); j++) {
		if (line[j] == '"' && line[++j] != '"') {
			int k = line.find_first_of(fieldsep,j);
			if (k > line.length()) {
				// no separator found
				k = line.length();
			}
			for (k -= j; k-- > 0; /* no iterator*/) {
				fld += line[j++];
			}
			break;
		}
		fld += line[j];
	}
	return j;
}

// advance_plain: unquoted field; return index of next separator
int CSV::advance_plain(const string& line, string& fld, int i) {

	int j;

	j = line.find_first_of(fieldsep, i); // look for separator
	if (j > line.length()) {
		j = line.length();
	}
	fld = string(line, i, j-1);
	return j;
}

// split: split line into fields
int CSV::split() {

	string fld;
	int i, j;

	nfield = 0;
	if (line.length() == 0) {
		return 0;
	}

	i = 0;

	do {
		if ( i < line.length() && line[i] == '"') {
			// skip quote
			j = advance_quoted(line, fld, ++i);
		} else {
			j = advance_plain(line, fld, i);
		}

		if (nfield >= field.size()) {
			field.push_back(fld);
		}

		nfield++;
		i = j + 1;

	} while (j < line.length());
	

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

// getfield: return n-th field
string CSV::getfield(int n) {
	if (n < 0 || n >= nfield) {
		return "";
	} else {
		return field[n];
	}
}