/// @file Number.hpp
///
/// @brief Defines Number class which will hold any sized number 
///
/// @author Elliot M. Grafil 
/// @date 5/28/19

/// @defgroup ROBLOX-Number Number
/// @ingroup ROBLOX

//=================================
// header guards
#ifndef __NUMBER_HPP__ 
#define __NUMBER_HPP__
#pragma once
//=================================
// included dependencies
#include <cstdint>
//=================================
// forward declared dependencies

//=================================
//

/// @addtogroup ROBLOX-Number
/// @{

constexpr unsigned int maxNumberSizeIn64uints = 1;

/// WARNING THE FOLLOWING CODE IS NOT CROSS PLATFORM 
/// IT MAKES AN ASSUMPTION THAT THE SYSTEM IS LITTLE ENDIAN
/// THIS AFFECTS BOTH THE CHECKS DONE, DIVISIONS AND DISPLAY
/// NEED TO CHANGE THE BELOW CONSTANTS IF MOVING TO BIG ENDIAN SYSTEM

constexpr unsigned int first64unit = 0;
constexpr unsigned int last64unit = maxNumberSizeIn64uints - 1;
constexpr unsigned int first32unit = 0;
constexpr unsigned int last32unit = maxNumberSizeIn64uints * 2 - 1;
constexpr unsigned int first16unit = 0;
constexpr unsigned int last16unit = maxNumberSizeIn64uints * 4 - 1;




///This might seem odd at first but this can theoretically allow any size number to be passed to the function
///However I would need to write proper X-length bit shifts for maxNumberSize > 1.
///     Example of how to do is found in page 39 if Hackers delight 2nd eddition
class Number
{
protected:
    union NumberData {
        uint64_t    quad[maxNumberSizeIn64uints];  
        uint32_t    dbl[maxNumberSizeIn64uints * 2];
        uint16_t    word[maxNumberSizeIn64uints * 4];
    };

    NumberData      data;
public:
	//Constructors
    Number();
    Number(uint32_t num);
    Number(uint64_t num);
    //Number(uint64_t* num, unsigned int size);

	//Get Functions
    NumberData GetData() {return data;}

	//Set Function
	
	//Other Functions

    /**
    *   @brief Checks if number is equal to one.
    *
    *	@return True if equal to one. False if not.
    */
    bool IsOne();

    /**
    *   @brief Checks if number is divisable by two.
    *
    *          Check is performed by shifting bit to the left then right and seeing if it equals the original number.
    *          If the least significant bit was initially zero the number remains unchanged and this returns true.
    *          A Binary number is divisible by two if it ends in zero
    *
    *	@return True if divisable by two. False if not.
    */
    bool IsDivisableByTwo();


    /**
    *   @brief Checks if number is divisable by three.
    *
    *           Check is performed by summing alternating bits and seeing if it is divisible by 3
    *
    *   See https://stackoverflow.com/questions/844867/check-if-a-number-is-divisible-by-3
    *	@return True if divisable by three. False if not.
    */
    bool IsDivisableByThree();

    /**
    *   @brief Checks if number is divisable by five.
    *           Currently using modulous operator. Didnt have time to look for a nice bit check
    *   
    *	@return True if divisable by three. False if not.
    */
    bool IsDivisableByFive();




    /**
    *   @brief Divides number by two.
    *   
    *   Performs bit shift to do division.
    */
    void DivideByTwo();


    /**
    *   @brief Divides number by three.
    *          Using simple division would impliment one that covers any size number but time issues.
    *   See Hackers delight 2nd eddition page 254
    */
    void DivideByThree();

    /**
    *   @brief Divides number by five.
    *           Using simple division would impliment one that covers any size number but time issues.
    *   See Hackers delight 2nd eddition page 254
    */
    void DivideByFive();

    /**
    *   @brief Sets Number to default value (0). Is called by all constructors
    */
    void SetDefaults();



    Number& operator++(){
        data.quad[0] += 1;
        return *this;
    }

    // Overloading(++) operator to perform increment 
    Number operator++(int)
    {
        Number tmp(*this);
        operator++(); // prefix-increment this instance
        return tmp;   // return value before increment
    }

};



#endif





