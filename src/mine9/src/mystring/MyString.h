

#ifdef __cplusplus

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

#else

    // TODO: add some ifdef define stuff to prevent multiple includes in c

    void * call_MyStringConstructor(void *p, char * pValue);
    void call_MyStringDump(void *p);
    void call_MyStringAdd(void *p, const char * pValue);
    void call_MyStringSubtract(void *p, const char * pValue);
#endif