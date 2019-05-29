#include "stdafx.h"
#include "Factor.hpp"


Number FindNumberInFactorSeries(uint64_t position) {
    uint64_t count = 0;
    Number number = Number();

    while (count < position) {
        number++;

        if (FactoredIntoProductOfTwoThreeFive(number)) {
            count++;
        }
    }
    return number;
}

bool FactoredIntoProductOfTwoThreeFive(Number num) {

    //Divide by Two
    while (num.IsDivisableByTwo()) {
        num.DivideByTwo();
    }
    //Three
    while (num.IsDivisableByThree()) {
        num.DivideByThree();
    }
    //Five
    while (num.IsDivisableByFive()) {
        num.DivideByFive();
    }

    return num.IsOne();
}