#pragma once

#include "BunnyClass.h"
#include <iostream>


//Purpose: To determine if a bunny has reached the age at which it dies
bool BunnyClass::willDie()
{
  if (age_ >= 10)
  {
    gender_ == BunnyGender::female ?
    std::cout << "Lady " << name_ << " of bunny house " << house_info_.house_name
              << " died at age " << age_ << "! " << "She was a fierce " << house_info_.sigil
              << "! " << house_info_.saying << std::endl :
    std::cout << "Lord " << name_ << " of bunny house " << house_info_.house_name
              << " died at age " << age_ << "! " << "He was a fierce " << house_info_.sigil
              << "! " << house_info_.saying << std::endl;

    return true;
  }
  return false;
}


//Purpose: To increase the age of a bunny by 1
unsigned int BunnyClass::incrementAge()
{
  return this->age_++;
}


//Purpose: Function returns the colour of the bunny when the BunnyColour enum value is given
std::string BunnyClass::getColourName(BunnyColour colour)
{
  std::string colour_name;

  switch (colour)
  {
    case white:
      colour_name = "White";
      break;
    case brown:
      colour_name = "Brown";
      break;
    case grey:
      colour_name = "Grey";
      break;
    case black:
      colour_name = "Black";
      break;
    case gold:
      colour_name = "Gold";
      break;
    case silver:
      colour_name = "Silver";
      break;
    default:
      colour_name = "White";
      break;
  }

  return colour_name;
}

std::string BunnyClass::getHouseName(BunnyHouse house)
{
  switch (house)
  {
    case stark:
      return "stark";
    case baratheon:
      return "baratheon";
    case lanister:
      return "lannister";
      break;
    case targaryen:
      return "targaryen";
      break;
    case whitewalker:
      return "whitewalker";
    default:
      return "_";
  }
}

bool BunnyClass::canMove(bool occupancyGrid[SIZE][SIZE], std::list<std::pair<int, int>> &options) const
{
  bool res = false;
  if (i_ - 1 >= 0 && !occupancyGrid[i_ - 1][j_])
  {
    res = true;
    options.emplace_back(std::make_pair(i_ - 1, j_));
  }
  if (i_ + 1 < SIZE && !occupancyGrid[i_ + 1][j_])
  {
    res = true;
    options.emplace_back(std::make_pair(i_ + 1, j_));
  }
  if (j_ - 1 >= 0 && !occupancyGrid[i_][j_ - 1])
  {
    res = true;
    options.emplace_back(std::make_pair(i_, j_ - 1));
  }
  if (j_ + 1 < SIZE && !occupancyGrid[i_][j_ + 1])
  {
    res = true;
    options.emplace_back(std::make_pair(i_, j_ + 1));
  }
  return res;
}

bool BunnyClass::findAdjacent(BunnyClass *grid[SIZE][SIZE], std::list<std::pair<int, int>> &options) const
{
  bool res = false;
  if (i_ - 1 >= 0 && grid[i_ - 1][j_] != nullptr && grid[i_ - 1][j_]->house_ != BunnyHouse::whitewalker)
  {
    res = true;
    options.emplace_back(std::make_pair(i_ - 1, j_));
  }
  if (i_ + 1 < SIZE && grid[i_ + 1][j_] != nullptr && grid[i_ + 1][j_]->house_ != BunnyHouse::whitewalker)
  {
    res = true;
    options.emplace_back(std::make_pair(i_ + 1, j_));
  }
  if (j_ - 1 >= 0 && grid[i_][j_ - 1] != nullptr && grid[i_][j_ - 1]->house_ != BunnyHouse::whitewalker)
  {
    res = true;
    options.emplace_back(std::make_pair(i_, j_ - 1));
  }
  if (j_ + 1 < SIZE && grid[i_][j_ + 1] != nullptr && grid[i_][j_ + 1]->house_ != BunnyHouse::whitewalker)
  {
    res = true;
    options.emplace_back(std::make_pair(i_, j_ + 1));
  }
  return res;
}


