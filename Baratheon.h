#pragma once
#include "Header.h"
#include "BunnyClass.h"


//Class to hold info on bunny of house Baratheon
class BaratheonBunny : public BunnyClass
{
public:
    //constructor
    BaratheonBunny(BunnyGender gender, BunnyHouse house, BunnyColour colour, unsigned int age, std::string name) : BunnyClass(gender, house, colour, age, name)
    {
        house_info_ = { BaratheonName, BaratheonSigil, BaratheonSaying };
    }
    //default constructor
    BaratheonBunny() : BunnyClass()
    {
        house_info_ = { BaratheonName, BaratheonSigil, BaratheonSaying };
    }
};

