/// @file BitManipulators.hpp
///
/// @brief Defines bit manipulator helper functions
///
/// @author Elliot M. Grafil 
/// @date 5/28/19

/// @defgroup ROBLOX-BITMANIPULATORS Bit Manipulators
/// @ingroup ROBLOX

//=================================
// header guards
#ifndef __BITMANIPULATORS_HPP__ 
#define __BITMANIPULATORS_HPP__
#pragma once
//=================================
// included dependencies
#include <cstdint>
//=================================
// forward declared dependencies

//=================================
//


/// @addtogroup ROBLOX-BITMANIPULATORS
/// @{


/**
*   @brief Counts the number of one digits the binary representation of a number has.
*
*          See page 82 of Hackers Delight Second Edition.
*
*   @param num Number that needs to be checked.
*	@return Number of one digits the binary representation num has.
*/
unsigned int CountOfOneBits(uint16_t num);

/// @}


#endif





