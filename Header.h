#pragma once
#include <random>
#include <algorithm>

constexpr int SIZE = 75;


//Enum to hold all colours of bunnies
enum BunnyColour
{
    white,   //0
    brown,
    grey,
    black,
    gold,
    silver
};



//Enum to hold bunny genders
enum BunnyGender
{
    male,    //0
    female
};




//Enum to hold all house types of bunnies
enum BunnyHouse
{
    stark,     //0
    baratheon,
    lanister,
    targaryen,
    whitewalker
};





//Struct to hold house information (name, sigil and saying) of a noble house
struct HouseInfo
{
    std::string house_name;
    std::string sigil;
    std::string saying;
};



//info constants of Noble house
static const std::string StarkName = "Stark";
static const std::string StarkSigil = "Wolf";
static const std::string StarkSaying = "Winter is Coming!";

static const std::string BaratheonName = "Baratheon";
static const std::string BaratheonSigil = "Stag";
static const std::string BaratheonSaying = "Ours is The Fury!";

static const std::string LannisterName = "Lannister";
static const std::string LannisterSigil = "Lion";
static const std::string LannisterSaying = "Hear me Roar!";

static const std::string TargaryenName = "Targaryen";
static const std::string TargaryenSigil = "Dragon";
static const std::string TargaryenSaying = "Fire And Blood!";

static const int MaxAge = 10;






//Purpose: Generate random numbers between from and to
static int generateRandomNumber(int from, int to)
{
    std::random_device rd;  //Will be used to obtain a seed for the random number engine
    std::mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()
    std::uniform_int_distribution<> distrib(from, to);

    return distrib(gen);
}






//Purpose: Get the next bunny type (of which house) according to the probability specified in the project
//white walker probability: 2% , noble house probability : 98% 
static BunnyHouse generateBunnyType()
{
    int probability = generateRandomNumber(1, 100);

    if (probability <= 2)
    {
        return BunnyHouse::whitewalker;
    }
    else
    {
        //If the bunny is of a noble house, randomly select which noble house it belongs to. Equi-probable
        int house_type = generateRandomNumber(0, 3);

        return (BunnyHouse)house_type;
    }
}






//Purpose: Randomly get next bunny gender. Male and Female bunnies are equi-probable
static BunnyGender generateBunnyGender()
{
    int gender = generateRandomNumber(0, 1);
    
    //considering getting 0 -> male, 1-> female
    return (gender == 0 ? BunnyGender::male : BunnyGender::female);
}






//Purpose: Randomly get next bunny colour. All colours are equi-probable
static BunnyColour generateBunnyColour()
{
    int colour = generateRandomNumber(0, 5);

    return (BunnyColour)colour;
}






//Purpose: Randomly generate next bunny name
static std::string generateBunnyName()
{
    std::string name("ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz");

    std::random_device rd;
    std::mt19937 generator(rd());

    std::shuffle(name.begin(), name.end(), generator);

    return name.substr(0, 10);    // assumes 10 < number of characters in str         
}


//Purpose: Randomly generate a place for initial bunnies
static void generateInitPlace(int& i, int& j){
    i = generateRandomNumber(0, SIZE - 1);
    j = generateRandomNumber(0, SIZE - 1);
}