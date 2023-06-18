#pragma once
#include "Header.h"
#include "BunnyClass.h"



//Class to hold info of a bunny of house Stark
class StarkBunny : public BunnyClass
{
public:
    //constructor
    StarkBunny(BunnyGender gender, BunnyHouse house, BunnyColour colour, unsigned int age, std::string name) : BunnyClass(gender, house, colour, age, name)
    {
        house_info_ = { StarkName, StarkSigil, StarkSaying };
    }
    //default constructor
    StarkBunny() : BunnyClass()
    {
        house_info_ = { StarkName, StarkSigil, StarkSaying };
    }
};

