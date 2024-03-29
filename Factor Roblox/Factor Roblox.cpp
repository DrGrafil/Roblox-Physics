// Factor Roblox.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Number.hpp"
#include "Factor.hpp"
#include <iostream>
#include <cstdint> // For defined integers

int main(){

    
    for (uint64_t i = 1; i <= 18; i++) {
        std::cout << i << " " << FindNumberInFactorSeries(i).GetData().quad[0] << std::endl;
    }
    std::cout << "---------" << std::endl;

    std::cout << 1500 << " " << FindNumberInFactorSeries(1500).GetData().quad[0] << std::endl;
    std::cout << 100000 << " " << FindNumberInFactorSeries(100000).GetData().quad[0] << std::endl;

    system("pause");
    return 0;
}
