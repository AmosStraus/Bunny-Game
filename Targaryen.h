#pragma once
#include "Header.h"
#include "BunnyClass.h"



//Class to hold info on bunny of house Targareon
class TargaryenBunny : public BunnyClass
{
public:
    //constructor
    TargaryenBunny(BunnyGender gender, BunnyHouse house, BunnyColour colour, unsigned int age, std::string name) : BunnyClass(gender, house, colour, age, name)
    {
        house_info_ = { TargaryenName, TargaryenSigil, TargaryenSaying };
    }
    //default constructor
    TargaryenBunny() : BunnyClass()
    {
        house_info_ = { TargaryenName, TargaryenSigil, TargaryenSaying };
    }
};


