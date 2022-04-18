///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205-lab12a-fatCat - EE 205 - Spr 2022
///
/// @file fatCat.cpp
/// @version 1.0
///
/// @author Mariko Galton <mgalton@hawaii.edu>
/// @date   12_Apr_2022
///////////////////////////////////////////////////////////////////////////////

#include "Weight.h"

int main() {
    Weight testWeight1( 0, POUND, 0); //Sample Output 1
    testWeight1.Weight::dump();

    Weight testWeight2(3.14, KILO, 20); //Sample Output 2
    testWeight2.Weight::dump();
    return 0;
}
