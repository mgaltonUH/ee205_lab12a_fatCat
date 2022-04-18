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
    return true;
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
    setWeight(newWeight);
    setMaxWeight(newMaxWeight);
}
Weight::Weight (UnitOfWeight newUnitOfWeight, float newMaxWeight) {
    setMaxWeight(newMaxWeight);
    unitOfWeight = newUnitOfWeight;
}
Weight::Weight (float newWeight, UnitOfWeight newUnitOfWeight, float newMaxWeight){
    setWeight(newWeight);
    unitOfWeight = newUnitOfWeight;
    setMaxWeight(newMaxWeight);
}

void Weight::setMaxWeight(float newMaxWeight){
    if(bHasMax == false){
        if(isWeightValid(newMaxWeight) == false ){
            exit(0);
        }
        else {
            bHasMax = true;
            maxWeight = newMaxWeight;
        }
    }
}

bool Weight::isWeightKnown() const noexcept {
    if(bIsKnown == true){
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
        cout << "Input weight [ " << checkWeight << " ] cannot be less that zero" << endl;
    }
    if(bHasMax == true) {
        if(checkWeight <= maxWeight){
            return true;
        }
        else {
            cout << "Error: The inputted " << checkWeight << "cannot be greater than " << maxWeight << endl;
        }
    }
    return true;
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
        return  UNKNOWN_WEIGHT;
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
        bIsKnown = true;
    }
}

void Weight::setWeight (float newWeight, UnitOfWeight weightUnits) {
    setWeight(convertWeight(newWeight, weightUnits,unitOfWeight));
}

std::ostream& operator<<( ostream& lhs_stream,const UnitOfWeight rhs_UnitOfWeight ) {
    switch( rhs_UnitOfWeight ) {
        case POUND: return lhs_stream << POUND_LABEL ;
        case KILO:  return lhs_stream << KILO_LABEL ;
        case SLUG:  return lhs_stream << SLUG_LABEL ;
        default:
            throw out_of_range( "The unit can’t be mapped to a string" );
    }
}

#define FORMAT_LINE( className, member ) cout << setw(8) << (className) << setw(20) << (member) << setw(52)

void Weight::dump() const noexcept {
    //assert(validate());
        cout << setw(80) << setfill( '=' ) << "" << endl ;
        cout << setfill( ' ' ) ;
        cout << left ;
        cout << boolalpha ;
        FORMAT_LINE( "Weight", "this" )           << &weight << endl;
        FORMAT_LINE( "Weight", "isKnown" )        << bIsKnown << endl ;
        FORMAT_LINE( "Weight", "weight" )         <<  getWeight() << endl;
        FORMAT_LINE( "Weight", "unitOfWeight" )   << unitOfWeight << endl;
        FORMAT_LINE( "Weight", "hasMax" )         << bHasMax << endl;
        FORMAT_LINE( "Weight", "maxWeight" )      << getMaxWeight() << endl;
    }
