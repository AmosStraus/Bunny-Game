#pragma once
#include "Header.h"
#include "BunnyClass.h"


//Class to hold info on bunny of house Lannister
class LannisterBunny : public BunnyClass
{
public:
    //constructor
    LannisterBunny(BunnyGender gender, BunnyHouse house, BunnyColour colour, unsigned int age, std::string name) : BunnyClass(gender, house, colour, age, name)
    {
        house_info_ = { LannisterName, LannisterSigil, LannisterSaying };
    }
    //default constructor
    LannisterBunny() : BunnyClass()
    {
        house_info_ = { LannisterName, LannisterSigil, LannisterSaying };
    }
};

