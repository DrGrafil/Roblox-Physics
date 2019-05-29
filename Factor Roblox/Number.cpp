#include "stdafx.h"
#include "Number.hpp"
#include "BitManipulators.hpp"

Number::Number() {
    SetDefaults();
}

Number::Number(uint32_t num) {
    SetDefaults();
    data.dbl[first32unit] = num;
}

Number::Number(uint64_t num) {
    SetDefaults();
    data.quad[first64unit] = num;
}
/*
Number::Number(uint64_t* num, unsigned int size) {

}*/

bool Number::IsOne() {
    //Check if last 64 uint is equal to one
    if (data.quad[last64unit] != 1) {
        return false;
    }

    //Check if the remaining 64 uints are zero
    for (unsigned int i = last64unit; i >= 1; i--) {
        if (data.quad[i] != 0) {
            return false;
        }
    }
    return true;
}

bool Number::IsDivisableByTwo() {
    return (((data.dbl[first32unit] >> 1) << 1) == data.dbl[first32unit]);
}

bool Number::IsDivisableByThree() {
    uint16_t evenMask = 0b1010101010101010;
    uint16_t oddMask = ~evenMask;

    //Stores th
    int sumOfAlternatingBits = 0;
    for (size_t element = 0; element <= last16unit; element++) {
        sumOfAlternatingBits += CountOfOneBits(data.word[element] & evenMask) - CountOfOneBits(data.word[element] & oddMask);
    }

    //Checks if the sum of alternating bits is divisable by 3
    if (sumOfAlternatingBits % 3 == 0) {
        return true;
    }
    return false;
}

bool Number::IsDivisableByFive() {
    if (data.quad[0] % 5 == 0) {
        return true;
    }
    return false;
}



void Number::DivideByTwo() {
    //Divide by two via binary shift
    data.quad[last64unit] = data.quad[last64unit] >> 1;

    //Shift rest of data
    if constexpr(last64unit != 0){
        for (size_t element = last64unit - 1; element >= 0; element--) {
        
            //Shifting last bit of the more significant element then putting it in the MSB of the least significant element
            data.quad[element + 1] |= data.quad[element] << 63;

            data.quad[element] = data.quad[element] >> 1;
        }
    }
}


void Number::DivideByThree() {
    data.quad[0] /= 3;
    /*
    would need to modify below to span across all words
    uint16_t q;
    uint16_t n = data.word[0];
    q = ( n >> 2) + (n >> 4);
    q = q + (q>>4);
    q = q + (q>>8);
    q = q + (q>>16);
    */
}


void Number::DivideByFive() {
    data.quad[0] /= 5;
    /*
    would need to modify below to span across all words
    uint16_t q;
    uint16_t n = data.word[0];
    q = ( n >> 3) + (n >> 4);
    q = q + (q>>4);
    q = q + (q>>8);
    q = q + (q>>16);
    */
    
}

void Number::SetDefaults() {
    for (size_t element = 0; element <= last64unit; element++) {
        data.quad[element] = 0;
    }
}