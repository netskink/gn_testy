#pragma once
#include <string>


class MyString {
    private:
        std::string line;

    public:

        MyString(std::string  aString);

        std::string dump(void) const;

        std::string add(std::string  aString);

        std::string subtract(std::string  aString);

};
