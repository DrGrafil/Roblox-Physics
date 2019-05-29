/// @file Factor.hpp
///
/// @brief Defines Factor Functions 
///
/// @author Elliot M. Grafil 
/// @date 5/28/19

/// @defgroup ROBLOX-FACTOR Factor
/// @ingroup ROBLOX

//=================================
// header guards
#ifndef __FACTOR_HPP__ 
#define __FACTOR_HPP__
#pragma once
//=================================
// included dependencies
#include <cstdint>
#include "Number.hpp"
//=================================
// forward declared dependencies

//=================================
//

/// @addtogroup ROBLOX-FACTOR
/// @{

/**
*   @brief Finds number given the position in Factor Series.
*       
*       This algorithm is done by iterating over all numbers in order.
*       It then checks if the number can be factors into 2,3,5 and if so increments the counter.
*       Once counter has reached the required position it outputs it.
*          
*   @param position Poition of number wanting to be found in series
*	@return Number at position
*/
Number FindNumberInFactorSeries(uint64_t position);


/**
*   @brief Checks if number can be factored into a product of 2, 3 and 5
*
*   Since multiplication is a commutive property, once a number can no longer be divided by a factor any further divisions
*   will never generte a situation where you can pull out the same factor again.
*
*   Due to this one just needs to pull out the factors of interest from the number until further factors can no longer be pulled out.
*   The remainder if it is only a product of 2,3 and 5 will be 1 otherwise it will be some other number that is indivisable by 2,3 and 5.
*
*	@param num Number that is needed to be checked.
*	@return True if number can be factored into a product of 2, 3 and 5 only. Flase if not.
*/
bool FactoredIntoProductOfTwoThreeFive(Number num);


/// @}

#endif





