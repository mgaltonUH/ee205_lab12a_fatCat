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
#include <cassert>
#include <iostream>
#include <stdexcept>
#include <iomanip>
#include "Weight.h"

using namespace std;

const float Weight::UNKNOWN_WEIGHT = -1 ;
const float Weight::KILOS_IN_A_POUND = 0.453592 ;
const float Weight::SLUGS_IN_A_POUND = 0.031081 ;




//Kilo, Slug, and Pound conversion (static members)
float Weight::fromKilogramToPound( const float kilogram ) noexcept {
    return kilogram / KILOS_IN_A_POUND;
}
float Weight::fromPoundToKilogram(float pound) noexcept {
    return pound * KILOS_IN_A_POUND;
}
float Weight::fromSlugToPound(const float slug) noexcept {
    return slug / SLUGS_IN_A_POUND;
}
float Weight::fromPoundToSlug(float pound) noexcept {
    return pound * SLUGS_IN_A_POUND;
}
float Weight::convertWeight (float fromWeight, UnitOfWeight fromUnit, UnitOfWeight toUnit) noexcept {
    switch( fromUnit ) {
        case POUND         : return fromWeight; // No conversion necessary
            break;
        case KILO          : return fromKilogramToPound( fromWeight );
           break;
        case SLUG          : return fromSlugToPound(fromWeight);
            break;
    }

    switch(toUnit) {
        case POUND         : return fromWeight;
            break;
        case KILO          : return fromPoundToKilogram(fromWeight);
            break;
        case SLUG          : return fromPoundToSlug(fromWeight);
            break;
    }
}

bool Weight::isWeightKnown() const noexcept {
    if(weight == true){
        return true;
    }
    else {
        return false;
    }
}

bool Weight::isWeightValid (float checkWeight) const noexcept {
    if(checkWeight > 0){
        return true;
    }
    else {
        cout << checkWeight << " cannot be less that zero" << endl;
    }
    if(bHasMax == true) {
        if(checkWeight <= maxWeight){
            return true;
        }
        else {
            cout << "Error: The inputted " << checkWeight << "cannot be greater than " <<maxWeight << endl;
        }
    }
}

bool Weight::validate() const noexcept {
    if (bIsKnown == true) {
        if(isWeightValid(weight) == true){
            return true;
        }
    }
    if(bHasMax == true){
        if(isWeightValid(weight) == true ){
            return true;
        }
    }
    return false;
}


bool Weight::hasMaxWeight() const noexcept {
    if(bHasMax == true){
        return true;
    }
    else {
        return false;
    }
}

float Weight::getWeight() const noexcept{
    if(bIsKnown == false){
        return UNKNOWN_WEIGHT;
    }
    else {
        return weight;
    }
}

float Weight::getMaxWeight() const noexcept {
    if (bHasMax == false) {
        return UNKNOWN_WEIGHT;
    }
    else {
        return maxWeight;
    }
}

void Weight::setWeight (float newWeight) {
    if(isWeightValid(newWeight) == true){
        weight = newWeight;
    }
}

void Weight::setWeight (float newWeight, UnitOfWeight weightUnits) {
    setWeight(convertWeight(newWeight, weightUnits,unitOfWeight));
}

void Weight::dump() const noexcept {

}

//Public Member Functions
Weight::Weight() noexcept {
}

Weight::Weight(float newWeight) {
    setWeight(newWeight);
}
Weight::Weight(UnitOfWeight newUnitOfWeight) noexcept {
    unitOfWeight = newUnitOfWeight; // since enum UnitOfWeight unitOfWeight, so unitOfWeight is equal to the newUnitOfWeight
}
Weight::Weight(float newWeight, UnitOfWeight newUnitOfWeight) {
    setWeight(newWeight,newUnitOfWeight);
}
Weight::Weight(float newWeight, float newMaxWeight) {
    
}



