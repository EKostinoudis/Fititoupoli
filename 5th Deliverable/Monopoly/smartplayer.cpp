#include "player.h"

SmartPlayer::SmartPlayer(int id) : Player(id)
{
    name = "Team 096";
}

bool SmartPlayer::decideBuy(Space* space)
{
    if(getLocation() >= 15 && getLocation() <= 25 && getMoney() >= 400)
        return true;
    else if(getLocation() >= 4 && getLocation() <= 29 && getMoney() >= 600)
        return true;
    else if(getMoney() >= 1000)
        return true;
    return false;
}

int SmartPlayer::decideUpgrade()
{
    int i;

    if(getMoney() >= 400 && spaces[opponent->getLocation() + 7]->typeIs(PropertyType) && canUpgrade((Property*)spaces[opponent->getLocation() + 7]))
        return opponent->getLocation() + 7;

    for(i=4; i<=9; i++) {
        if(getMoney() >= 600 && spaces[opponent->getLocation() + i]->typeIs(PropertyType) && canUpgrade((Property*)spaces[opponent->getLocation() + i]))
            return opponent->getLocation() + i;
    }

    for(i=2; i<=12; i++) {
        if(getMoney() >= 900 && spaces[opponent->getLocation() + i]->typeIs(PropertyType) && canUpgrade((Property*)spaces[opponent->getLocation() + i]))
            return opponent->getLocation() + i;
    }

    for(i=1; i<40; i++) {
        if(getMoney() >= 2000 && spaces[i]->typeIs(PropertyType) && canUpgrade((Property*)spaces[i]))
            return i;
    }

    return -1;
}
