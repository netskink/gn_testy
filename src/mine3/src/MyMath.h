#pragma once
#include <string>


class MyMath {
    private:
        double total;

    public:

        MyMath(double value);

        double dump(void) const;

        double add(double value);

        double subtract(double value);

};
