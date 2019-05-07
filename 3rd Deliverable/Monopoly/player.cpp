#include <sstream>
#include <iostream>
#include "player.h"

using namespace std;

Player::Player(int id)
{
    this->id = id;
    money = 1500;
    location = 0;

    if (id == 0)
        name = "Player 1";
    else if (id == 1)
        name = "Player 2";
}

void Player::setSpaces(Space** spaces)
{
    this->spaces = spaces;
}

void Player::setLocation(int spaceNum)
{
    location = spaceNum;
}

string Player::getName()
{
    return name;
}

void Player::giveMoneyToPlayer(int amount)
{
    money = money + amount;
}

int Player::getMoney()
{
    return money;
}

void Player::takeMoneyFromPlayer(int amount)
{
    money = money - amount;
}

int Player::getLocation()
{
    return location;
}

bool Player::ownsProperty(int inputIndex)
{
    return spaces[inputIndex]->ownerIs(this);
}

bool Player::ownsProperty(Space* space)
{
    return space->ownerIs(this);
}

int Player::getNumberOfRailRoadsOwned()
{
    int numberOfRailRoads = 0;
    for(int i = 0; i < 40; i++)
    {
        if (spaces[i]->typeIs(RailRoadType) && ownsProperty(spaces[i]))
            numberOfRailRoads++;
    }
    return numberOfRailRoads;
}

int Player::getNumberOfUtilitiesOwned()
{
    int numberOfUtilities = 0;
    for(int i = 0; i < 40; i++)
    {
        if (spaces[i]->typeIs(UtilityType) && ownsProperty(spaces[i]))
            numberOfUtilities++;
    }
    return numberOfUtilities;
}

bool Player::decideBuy(Space* space)
{
    if (space->typeIs(PropertyType) && getMoney() > 5 * ((Property*)space)->getBuyingCost())
        return true;
    else if (space->typeIs(RailRoadType) && getMoney() > 5 * ((RailRoad*)space)->getBuyingCost())
        return true;
    else if (space->typeIs(UtilityType) && getMoney() > 5 * ((Utility*)space)->getBuyingCost())
        return true;
    else
        return false;
}

int Player::decideUpgrade()
{
    for(int i = 0; i < 40; i++)
    {
        if (spaces[i]->typeIs(PropertyType) && canUpgrade((Property*)spaces[i]) &&
                getMoney() > 5 * ((Property*)spaces[i])->getUpgradeCost())
        {
            return i;
        }
    }
    return -1;
}

bool Player::canBuy(Property* property)
{
    if(property->ownerIs(NULL)) {
        if(property->getBuyingCost() <= money) {
            return true;
        }
    }
    return false;
}

bool Player::canBuy(RailRoad* railroad)
{
    if(railroad->ownerIs(NULL)) {
        if(railroad->getBuyingCost() <= money) {
            return true;
        }
    }
    return false;
}

bool Player::canBuy(Utility* utility)
{
    if(utility->ownerIs(NULL)) {
        if(utility->getBuyingCost() <= money) {
            return true;
        }
    }
    return false;
}

bool Player::canUpgrade(Property* property)
{
    if(property->ownerIs(this) && money >= property->getUpgradeCost() && property->getNumberOfHouses() < 5) {
        // Check if player owns all properties with the same color
        bool ownsAll = true;
        PropertyCategory category = property->getCategory();

        for(int i = 0; i < 40; i++) {
            if(spaces[i]->typeIs(PropertyType)) {
                if(((Property*)spaces[i])->getCategory() == category) {
                    if(!ownsProperty(spaces[i])) {
                        ownsAll = false;
                        break;
                    }
                }
            }
        }
        return ownsAll;
    }

    return false;
}

void Player::buy(Space* space)
{
    space->setOwner(this);
}

void Player::upgrade(Property* space)
{
    space->addHouse();
}
