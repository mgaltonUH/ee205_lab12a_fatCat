///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205-lab12a-fatCat - EE 205 - Spr 2022
///
/// @file fatCat.h
/// @version 1.0
///
/// @author Mariko Galton <mgalton@hawaii.edu>
/// @date   12_Apr_2022
///////////////////////////////////////////////////////////////////////////////
#pragma once
#include <string>
#include <ostream>

enum UnitOfWeight{POUND, KILO, SLUG}; //public type

class Weight {
public:
    static const float UNKNOWN_WEIGHT;
    static const float KILOS_IN_A_POUND;
    static const float SLUGS_IN_A_POUND ;
private:
    bool  bIsKnown = false;
    bool  bHasMax = false;
    enum UnitOfWeight unitOfWeight = Pound;
    float weight{};
    float maxWeight{};

public: //static public member functions
    static float fromKilogramToPound( float kilogram ) noexcept;
    static float fromPoundToKilogram (float pound) noexcept;
    static float fromSlugToPound(float slug) noexcept;
    static float fromPoundToSlug (float pound) noexcept;
public: //public member functions
    bool isWeightKnown() const noexcept;
    bool hasMaxWeight() const noexcept;
    float getWeight() const noexcept;
    float getWeight(UnitOfWeight weightUnits) const noexcept;
    float getMaxWeight() const noexcept;

    UnitOfWeight getWeightUnit() const noexcept;

    void setWeight(float newWeight);
    void setWeight(float newWeight, UnitOfWeight weightUnits);
    bool isWeightValid(float checkWeight) const noexcept;
    bool validate() const noexcept;
    void dump() const noexcept;

    bool operator== (const Weight &rhs_Weight) const;
    bool operator< (const Weight &rhs_Weight) const;

    Weight & operator+= (float rhs_addToWeight);

    static float convertWeight (float fromWeight, UnitOfWeight fromUnit, UnitOfWeight toUnit) noexcept;
public: // public member functions
    Weight() noexcept;
    Weight(float newWeight);
    Weight(UnitOfWeight newUnitOfWeight) noexcept;
    Weight(float newWeight, UnitOfWeight newUnitOfWeight);
    Weight (float newWeight, float newMaxWeight);
    Weight (UnitOfWeight newUnitOfWeight, float newMaxWeight);
    Weight (float newWeight, UnitOfWeight newUnitOfWeight, float newMaxWeight);

private: //private member function
    void setMaxWeight (float newMaxWeight);

};

static const std::string POUND_LABEL = "Pound";
static const std::string KILO_LABEL = "Kilo" ;
static const std::string SLUG_LABEL = "Slug" ;
