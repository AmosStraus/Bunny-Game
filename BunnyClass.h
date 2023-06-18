#pragma once
#include <string>
#include <list>
#include "Header.h"

//Class to hold common bunny info irrespective of the house
class BunnyClass
{

public:
    BunnyGender gender_;
    BunnyHouse house_;
    BunnyColour colour_;
    unsigned int age_;
    std::string name_;
    std::string colour_name_;
    HouseInfo house_info_{};
    unsigned int max_age_ = MaxAge;
    int i_ = -1;
    int j_ = -1;


    //Constructor
    BunnyClass(BunnyGender gender, BunnyHouse house, BunnyColour colour, unsigned int age, std::string name) : 
        gender_(gender),
        house_(house),
        colour_(colour),
        age_(age),
        name_(name),
        max_age_(MaxAge)
    {
        house_info_ = { "", "", "" };

        colour_name_ = getColourName(colour);
    }

    //default constructor
    BunnyClass() = default;
    
    //destructor
    virtual ~BunnyClass() = default;


    bool findAdjacent(BunnyClass *grid[SIZE][SIZE], std::list<std::pair<int, int>> &options) const;

public:
    virtual bool willDie();

    virtual unsigned incrementAge();

    bool canMove(bool occupancyGrid[SIZE][SIZE], std::list<std::pair<int,int>> &options) const;
    void moveBunny(int iNew, int jNew) {i_ = iNew; j_ = jNew; }

private:
    std::string getColourName(BunnyColour colour);
    std::string getHouseName(BunnyHouse house);
};

