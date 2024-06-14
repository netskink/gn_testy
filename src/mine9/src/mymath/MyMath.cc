



#ifdef __cplusplus

#include <string>
#include <iostream>

#include "MyMath.h"


using namespace std;


MyMath::MyMath(double value) 
    : total(value) {
#ifdef VERBOSE
  cout << "== MyMath::MyMath(double value) ===" << endl;
#endif
    cout << "Total: " << total << endl;

}

double MyMath::dump(void) const {
    cout << "Total: " << total << endl;
    return total;
}

double MyMath::add(double value) {
    total = total + value;
    return total;
}
double MyMath::subtract(double value) {
    total = total - value;
    return total;
}

//
// C wrappers
//

extern "C" void * call_MyMathConstructor(void *p, double value) {
    if (nullptr == p) {
        p = new MyMath(value);
    }
    return (void *) p;
}

extern "C" double call_MyMathDump(void *p) {
    if (nullptr == p) {
        return 0.0;
    }
    return ((MyMath *) p)->dump();
}

extern "C" double call_MyMathAdd(void *p, double value) {
    double result;

    if (nullptr == p) {
        p = new MyMath(0.0);
    }

    result = ((MyMath *) p)->add(value);

    return result;
}


extern "C" double call_MyMathSubtract(void *p, double value) {
    double result;

    if (nullptr == p) {
        p = new MyMath(0.0);
    }

    result = ((MyMath *) p)->subtract(value);

    return result;
}

#endif
