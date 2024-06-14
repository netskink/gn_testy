

#ifdef __cplusplus

#pragma once

class MyMath {
    private:
        double total;

    public:

        MyMath(double value);

        double dump(void) const;

        double add(double value);

        double subtract(double value);

};

#else

    // TODO: add some ifdef define stuff to prevent multiple includes in c

    void * call_MyMathConstructor(void *p, double value);
    double call_MyMathDump(void *p);
    double call_MyMathAdd(void *p, double value);
    double call_MyMathSubtract(void *p, double value);


#endif
