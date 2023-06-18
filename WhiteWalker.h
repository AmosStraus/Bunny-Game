#pragma once
#include "Header.h"
#include "BunnyClass.h"
#include <iostream>


//Class to hold info on White walker bunny
class WhitewalkerBunny : public BunnyClass
{
public:
    //constructor
    WhitewalkerBunny(BunnyGender gender, BunnyHouse house, BunnyColour colour, unsigned int age, std::string name) : BunnyClass(gender, house, BunnyColour::white, age, name)
    {
        house_info_ = { "", "", "" };
        max_age_ = 50;  // set the max age for white walker bunnies, to 50.
    }

    //default constructor
    WhitewalkerBunny() : BunnyClass()
    {
        house_info_ = { "", "", "" };
        max_age_ = 50; // set the max age for white walker bunnies, to 50.
    }

    //White walker bunnies live longer than other noble house bunnies, so the function is overridden. 
    virtual bool willDie()
    {
        if (age_ >= max_age_)
        {
            std::cout << "White Walker " << name_ << " died at age " << age_ << "!" << std::endl;
            return true;
        }
        return false;
    }
};
