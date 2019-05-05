#include <iostream>
#include "space.h"

/* Space class */
// Space constructor
Space::Space(int id, string name, SpaceType type, string actionText) {
    this->id = id;
    this->name = name;
    this->type = type;
    this->actionText = actionText;

    owner = NULL;
}

// Setter for owner
void Space::setOwner(Player* owner) {
    this->owner = owner;
}

// Getters
int Space::getId() {
    return id;
}

string Space::getName() {
    return name;
}

string Space::getActionText() {
    return actionText;
}
// End of getters

bool Space::typeIs(SpaceType type) {
    return type == this->type;
}

bool Space::ownerIs(Player* player) {
    return player->getName() == owner->getName();
}
/* End of Space class */


/* Property class */
// Property constructor
Property::Property(int id, string name, SpaceType type, string actionText, int buyCost, int upgradeCost, PropertyCategory category)
  : Space(id, name, type, actionText) {
    this->buyCost = buyCost;
    this->upgradeCost = upgradeCost;
    this->category = category;

    numberOfHouses = 0;
}

// Rent setter
void Property::setRent(int numberOfHouses, int inputRent) {
    rent[numberOfHouses] = inputRent;
}

// Getters
int Property::getBuyingCost() {
    return buyCost;
}

int Property::getUpgradeCost() {
    return upgradeCost;
}

int Property::getNumberOfHouses() {
    return numberOfHouses;
}

PropertyCategory Property::getCategory() {
    return category;
}
// End of getters ??

int Property::getRent() {
    return rent[numberOfHouses];
}

void Property::addHouse() {
    if(numberOfHouses < 5) {
        numberOfHouses++;
    }
    else {
        std::cout << "Can't have more that 5 houses." << std::endl;
    }
}
/* End of Property class */


/* RailRoad class */
// Constructor of RailRoad
RailRoad::RailRoad(int id, string name, SpaceType type, string actionText, int buyCost) : Space(id, name, type, actionText) {
    this->buyCost = buyCost;
}

// rent setter
void RailRoad::setRent(int numberOfRailRoads, int inputRent) {
    rent[numberOfRailRoads - 1] = inputRent;
}

// buyCost getter
int RailRoad::getBuyingCost() {
    return buyCost;
}

int RailRoad::getRent() {
    return rent[owner->getNumberOfRailRoadsOwned() - 1];
}
/* End of RailRoad class */


/* Utility class */
// Constructor of Utility
Utility::Utility(int id, string name, SpaceType type, string actionText, int buyCost, Dice* dice)
  : Space(id, name, type, actionText) {
    this->buyCost = buyCost;
    this->dice = dice;
}

// rentMultiplier setter
void Utility::setRentMultiplier(int numberOfUtilities, int inputRentMultiplier) {
   rentMultiplier[numberOfUtilities - 1] = inputRentMultiplier;
}

// buyCost getter
int Utility::getBuyingCost() {
    return buyCost;
}

int Utility::getRent() {
    return rentMultiplier[owner->getNumberOfUtilitiesOwned() - 1] * (dice->getFirstDice() + dice->getSecondDice());
}
/* End of Utility class */


/* Tax class */

/* End of Tax class */
