#include "stdafx.h"
#include <iostream>

#include "BitManipulators.hpp"



unsigned int CountOfOneBits(uint16_t num) {
    num = num - ((num >> 1) & 0x55555555);
    num = (num & 0x33333333) + ((num >> 2) & 0x33333333);
    num = (num + (num >> 4)) & 0x0F0F0F0F;
    num = num + (num >> 8);
    num = num + (num >> 16);
    return num & 0x0000003F;
}