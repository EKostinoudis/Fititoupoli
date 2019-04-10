#include <iostream>
#include <sstream>

#include "player.h"

using namespace std;

// Constructor of Player
Player::Player(int playerId) {
    id = playerId;
    location = 0;
    money = 1500;

    if(id == 0) {
        name = "Player 1";
    }
    else if(id == 1) {
        name = "Player 2";
    }
    else {
        cout << "id must be 0 or 1. name set to \"Unknown\"" << endl;
        name = "Unknown";
    }
}

// Getter functions
int Player::getId() {
    return id;
}

int Player::getLocation() {
    return location;
}

int Player::getMoney() {
    return money;
}

string Player::getName() {
    return name;
}
// End of getters

// Setter function for location
void Player::setLocation(int spaceNum) {
    location = spaceNum;
}

void Player::giveMoneyToPlayer(int amount) {
    money += amount;
}

void Player::takeMoneyFromPlayer(int amount) {
    money -= amount;
}
