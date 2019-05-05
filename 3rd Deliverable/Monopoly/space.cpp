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


// TODO: Implement here the methods of RailRoad, Utility, and Tax
