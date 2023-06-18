#pragma once

#include <iostream>
#include <list>
#include <iterator>
#include <string>
#include "Header.h"
#include "BunnyClass.h"
#include "Stark.h"
#include "Baratheon.h"
#include "Lannister.h"
#include "Targaryen.h"
#include "WhiteWalker.h"


BunnyClass *grid[SIZE][SIZE];
bool occupancyGrid[SIZE][SIZE];
int bunnyCounter = 0;

//Purpose: Create bunny instance randomly as per conditions and return the pointer to a BunnyClass instance
BunnyClass *createBunnyInstance()
{
  BunnyClass *bunny;

  //generate bunny info randomly
  BunnyHouse house_type = generateBunnyType();
  BunnyGender gender = generateBunnyGender();
  std::string name = generateBunnyName();
  int age = 0;
  BunnyColour colour;

  //If a white walker bunny, set colour to white and pass other data to constructor
  if (house_type == BunnyHouse::whitewalker)
  {
    bunny = new WhitewalkerBunny(gender, BunnyHouse::whitewalker, BunnyColour::white, age,
                                 name);
    std::cout << "white Walker bunny " << bunny->name_ << " was born!" << std::endl;
  }
  else
  {
    colour = generateBunnyColour();
    //If a noble house bunny, create an instance of respective noble class and print message
    switch (house_type)
    {
      case stark:
        bunny = new StarkBunny(gender, house_type, colour, age, name);
        break;
      case baratheon:
        bunny = new BaratheonBunny(gender, house_type, colour, age, name);
        break;
      case lanister:
        bunny = new LannisterBunny(gender, house_type, colour, age, name);
        break;
      case targaryen:
        bunny = new TargaryenBunny(gender, house_type, colour, age, name);
        break;
      default:
        bunny = new StarkBunny(gender, house_type, colour, age, name);
        break;
    }
    bunny->gender_ == BunnyGender::female ? std::cout << "Lady " : std::cout << "Lord ";
    std::cout << bunny->name_ << " of bunny house " << bunny->house_info_.house_name
              << " of color " << bunny->colour_name_ << " was born!" << std::endl;
  }

  int i, j;
  do
  {
    generateInitPlace(i, j);
  } while (occupancyGrid[i][j]);
  occupancyGrid[i][j] = true;

  bunnyCounter++;
  bunny->i_ = i;
  bunny->j_ = j;
  grid[i][j] = bunny;
  return bunny;
}


//Purpose: Create a bunny instance when parent info is given. Other information is randomly generated as per rules.
BunnyClass *createBunnyInstance(BunnyColour mother_colour, BunnyHouse father_house_type, int i,
                                int j)
{
  BunnyClass *bunny;
  BunnyHouse house_type = generateBunnyType();
  BunnyGender gender = generateBunnyGender();
  std::string name = generateBunnyName();
  int age = 0;
  BunnyColour colour;

  //If a white walker bunny, set colour to white and pass other data to constructor
  if (house_type == BunnyHouse::whitewalker)
  {
    bunny = new WhitewalkerBunny(gender, BunnyHouse::whitewalker, BunnyColour::white, age,
                                 name);
    std::cout << "white Walker bunny " << bunny->name_ << " was born!" << std::endl;
  }
  else
  {
    colour = mother_colour;
    house_type = father_house_type;

    //If a noble house bunny, create an instance of respective noble class and print message
    switch (house_type)
    {
      case stark:
        bunny = new StarkBunny(gender, house_type, colour, age, name);
        break;
      case baratheon:
        bunny = new BaratheonBunny(gender, house_type, colour, age, name);
        break;
      case lanister:
        bunny = new LannisterBunny(gender, house_type, colour, age, name);
        break;
      case targaryen:
        bunny = new TargaryenBunny(gender, house_type, colour, age, name);
        break;
      default:
        bunny = new StarkBunny(gender, house_type, colour, age, name);
        break;
    }

    bunny->gender_ == BunnyGender::female ? std::cout << "Lady " : std::cout << "Lord ";
    std::cout << bunny->name_ << " of bunny house " << bunny->house_info_.house_name
              << " of color " << bunny->colour_name_ << " was born!" << std::endl;
  }

  bunny->i_ = i;
  bunny->j_ = j;

  bunnyCounter++;
  grid[i][j] = bunny;
  occupancyGrid[i][j] = true;
  return bunny;
}


//Purpose: kill half of the bunny population
void killHalfPopulation(){
  std::list<std::pair<int, int>> options;
  for (int i = 0; i < SIZE; ++i)
  {
    for (int j = 0; j < SIZE; ++j)
    {
      if(grid[i][j] != nullptr){
        options.emplace_back(std::make_pair(i,j));
      }
    }
  }
  int population = bunnyCounter;
  for(int it=0; it < population / 2 ; it++){
    std::_List_iterator<std::pair<int, int>> killAt = options.begin();
    std::advance(killAt, (rand() % options.size()));
    delete grid[killAt->first][killAt->second];
    grid[killAt->first][killAt->second] = nullptr;
    occupancyGrid[killAt->first][killAt->second] = false;
    bunnyCounter--;
  }
}



//Purpose: To determine if a bunny is age > 2 (adult), female and of a nobel house
bool isAdultNobelFemaleBunnyPtr(BunnyClass *bunny_it)
{
  if (bunny_it->age_ >= 2 && bunny_it->gender_ == BunnyGender::female &&
      bunny_it->house_ != BunnyHouse::whitewalker)
  {
    return true;
  }

  return false;
}


//Purpose: To randomly pick a male bunny of age > 2 (adult), of a noble house. if exists. otherwise return nullptr
BunnyClass *getRandomAdultNobelMaleBunnyPtr()
{
  bool is_found = false;
  std::list<BunnyClass *> male_list;
  for (int i = 0; i < SIZE; ++i)
  {
    for (int j = 0; j < SIZE; ++j)
    {
      if (grid[i][j] != nullptr && grid[i][j]->gender_ == BunnyGender::male)
      {
        male_list.emplace_back(grid[i][j]);
      }
    }
  }
  if (male_list.empty())
  {
    return nullptr;
  }

  else
  {
    int position = generateRandomNumber(1, male_list.size());
    auto bunny_it = std::next(male_list.begin(), position - 1);

    if ((*bunny_it)->age_ >= 2 && (*bunny_it)->gender_ == BunnyGender::male &&
        (*bunny_it)->house_ !=
        BunnyHouse::whitewalker)
    {
      return *bunny_it;
    }
  }
}

// Purpose: moves specific bunny on the grid to new location, frees old location
void moveBunny(int iOld, int jOld, int iNew, int jNew)
{
  BunnyClass *bunny = grid[iOld][jOld];
  bunny->moveBunny(iNew, jNew);
  grid[iOld][jOld] = nullptr;
  occupancyGrid[iOld][jOld] = false;
  grid[iNew][jNew] = bunny;
  occupancyGrid[iNew][jNew] = true;
}

//Purpose: Iterate the grid to find dying bunnies and incremnt their age by one
void checkBunnyGridAge()
{
  BunnyClass *bunny;
  for (int i = 0; i < SIZE; ++i)
  {
    for (int j = 0; j < SIZE; ++j)
    {
      bunny = grid[i][j];
      if (bunny != nullptr)
      {
        bunny->incrementAge();
        if (bunny->willDie())
        {
          delete grid[i][j];
          grid[i][j] = nullptr;
          bunny = nullptr;
          occupancyGrid[i][j] = false;
          bunnyCounter--;
        }
      }
    }
  }
}

// Purpose: move all the bunnies (if they can move) to random adjacent square
void moveBunnies()
{
  std::list<std::pair<int, int>> options;
  BunnyClass *bunny;
  for (int i = 0; i < SIZE; ++i)
  {
    for (int j = 0; j < SIZE; ++j)
    {
      bunny = grid[i][j];
      if (bunny != nullptr && bunny->canMove(occupancyGrid, options))
      {
        std::_List_iterator<std::pair<int, int>> moveTo = options.begin();
        std::advance(moveTo, (rand() % options.size()));
//                std::cout << "moved " << bunny->i_ << "," << bunny->j_ << " TO " <<
//                          moveTo->first << "," << moveTo->second << std::endl;
        moveBunny(bunny->i_, bunny->j_, moveTo->first, moveTo->second);

      }
      options.clear();
    }
  }
}

// Purpose: prints the grid for visual representation
void print_grid()
{
  std::cout << " printing grid " << std::endl;
  std::cout << " ------------- TOTAL BUNNIES " << bunnyCounter << " -------------- " << std::endl;
  for (int i = 0; i < SIZE; ++i)
  {
    for (int j = 0; j < SIZE; ++j)
    {
      BunnyClass *currentBunny = grid[i][j];
      if (currentBunny == nullptr || currentBunny->i_ == -1 || currentBunny->j_ == -1)
      {
        std::cout << "_";
      }
      else
      {
        switch (currentBunny->house_)
        {
          case stark:
            std::cout << (currentBunny->age_ < 2 ? "s" : "S");
            break;
          case baratheon:
            std::cout << (currentBunny->age_ < 2 ? "b" : "B");
            break;
          case lanister:
            std::cout << (currentBunny->age_ < 2 ? "l" : "L");
            break;
          case targaryen:
            std::cout << (currentBunny->age_ < 2 ? "t" : "T");
            break;
          case whitewalker:
            std::cout << "W";
          default:
            std::cout << "_";
            break;
        }
      }
    }
    std::cout << std::endl;
  }
}

// Purpose: make sure grid is initialized properly at the beginning
void initGrid()
{
  for (int i = 0; i < SIZE; ++i)
  {
    for (int j = 0; j < SIZE; ++j)
    {
      grid[i][j] = nullptr;
    }
  }
  bunnyCounter = 0;
}

// Purpose: Breed the bunnies, according to the rules
void breedBunnies()
{
  BunnyClass *bunny;
  std::list<std::pair<int, int>> options;
  for (int i = 0; i < SIZE; ++i)
  {
    for (int j = 0; j < SIZE; ++j)
    {
      bunny = grid[i][j];
      // if its adult female check for space near the mother
      if (bunny != nullptr && isAdultNobelFemaleBunnyPtr(bunny) && bunny->canMove(occupancyGrid, options))
      {
        BunnyClass *baby_bunny;
        BunnyClass *male_bunny = getRandomAdultNobelMaleBunnyPtr();
        if (male_bunny != nullptr)
        {
          std::_List_iterator<std::pair<int, int>> bornAt = options.begin();
          std::advance(bornAt, (rand() % options.size()));
//                    std::cout << "born from " << bunny->i_ << "," << bunny->j_ << " AT " <<
//                              bornAt->first << "," << bornAt->second << std::endl;

          baby_bunny = createBunnyInstance(bunny->colour_, male_bunny->house_,
                                           bornAt->first, bornAt->second);
        }
      }
      options.clear();
    }
  }
}

//Purpose: Convert a randomly picked noble house bunny neighbor into a white walker
void whiteWalkerConvertion()
{
  BunnyClass *bunny;
  std::list<std::pair<int, int>> options;
  for (int i = 0; i < SIZE; ++i)
  {
    for (int j = 0; j < SIZE; ++j)
    {
      bunny = grid[i][j];
      if (bunny != nullptr && bunny->house_ == BunnyHouse::whitewalker)
      {
        options.clear();
        bool hasNeighbours = bunny->findAdjacent(grid, options);
        if (hasNeighbours)
        {
          std::cout << "ww at " << i << " " << j << std::endl;
          for(auto &it : options){
            std::cout << it.first << " " << it.second << std::endl;
          }
          std::_List_iterator<std::pair<int, int>> convertAt = options.begin();
          std::advance(convertAt, (rand() % options.size()));
          BunnyClass *beforeConvertion = grid[convertAt->first][convertAt->second];
          BunnyClass *convertedBunny = new WhitewalkerBunny(beforeConvertion->gender_, BunnyHouse::whitewalker,BunnyColour::white, beforeConvertion->age_,beforeConvertion->name_);
          convertedBunny->i_ = convertAt->first;
          convertedBunny->j_ = convertAt->second;
          delete beforeConvertion;
          grid[convertAt->first][convertAt->second] = convertedBunny;
        }
      }
    }
  }
}


long long countNumber = 1;
const int itNumber = 5;

int main()
{
  initGrid();
  BunnyClass *bunny_inst;

  //create 5 bunnies in the beginning
  for (size_t i = 0; i < itNumber; i++)
  {
    bunny_inst = createBunnyInstance();
  }
  print_grid();

  while (bunnyCounter)
  {
    std::cout << "----------------------------------" << countNumber
              << "-------------------------------------" << std::endl;
    countNumber++;

//  Modified Gameplay
    moveBunnies();
    whiteWalkerConvertion();
    breedBunnies();
    checkBunnyGridAge();
    if(bunnyCounter > 1000){
      killHalfPopulation();
    }
    print_grid();
  }
}