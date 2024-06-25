#pragma once
#include <iostream>
#include <string>

int some_func(void);


class CSV {
	public:
		CSV(std::istream& fin = std::cin, std::string sep = ",");
		//CSV(std::istream& fin, std::string sep);

		int getline(std::string& str);
		int split();
		int endofline(char c);

	private:
		std::istream& fin; // input file pointer
		std::string fieldsep;  // separator characters

		std::string line; // input line
		int nfield; // number of fields
};