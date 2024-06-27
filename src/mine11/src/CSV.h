// CSV code is modeled after The Practice of Programming book
// sample code.
// 
// https://www.cs.princeton.edu/~bwk/tpop.webpage/csvgetlinec++.c
// 
/* Copyright (C) 1999 Lucent Technologies */
/* Excerpted from 'The Practice of Programming' */
/* by Brian W. Kernighan and Rob Pike */
#pragma once
#include <iostream>
#include <string>


class CSV {
	public:
		CSV(std::istream& fin = std::cin, std::string sep = ",");
		//CSV(std::istream& fin, std::string sep);

		int getline(std::string& str);
		std::string getfield(int n);
		int getnfield() const { return nfield;}
		int split();
		int endofline(char c);


	private:
		std::istream& fin; // input file pointer
		std::string fieldsep;  // separator characters
		std::vector<std::string> field; // field strings
		int nfield; // number of fields

		std::string line; // input line
		int advance_quoted(const std::string& line, std::string& fld, int i);
		int advance_plain(const std::string& line, std::string& fld, int i);
};