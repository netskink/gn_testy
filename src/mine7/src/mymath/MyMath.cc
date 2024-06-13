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
    total = total + value;
    return total;
}