#include <iostream>

#include "actions.h"

using namespace std;

int makeMove(Bank &bank, Player players[], int playerTurn, int diceRoll)
{
    // Calculate new location
    int newLocation = players[playerTurn].getLocation() + diceRoll;

    // Check if player pass the last space (39th space)
    if(newLocation >= 40) {
        // Give player 200 from the bank
        players[playerTurn].giveMoneyToPlayer(200);
        bank.takeMoneyFromBank(200);
    }

    // Set players new location
    newLocation = newLocation % 40;
    players[playerTurn].setLocation(newLocation);

    return newLocation;
}

void makeAction(Bank &bank, Player players[], Space spaces[], int playerTurn, int newSpace)
{
    // Check the type of the space
    if(spaces[newSpace].getType() == "Property" ||
       spaces[newSpace].getType() == "RailRoad" ||
       spaces[newSpace].getType() == "Utility"
      ) {
        // Check who owns the space
        if(spaces[newSpace].getOwner() == -1) {
            // Bank owns the space
            // Check if player can buy the space
            if(players[playerTurn].getMoney() >= 5 * spaces[newSpace].getBuyingCost()) {
                // Player buys the space
                int spaceCost = spaces[newSpace].getBuyingCost();
                spaces[newSpace].setOwner(playerTurn);
                players[playerTurn].takeMoneyFromPlayer(spaceCost);
                bank.giveMoneyToBank(spaceCost);

                cout << players[playerTurn].getName() << " bought " << newSpace << " space." << endl;
            }
        }
        else if(spaces[newSpace].getOwner() == (1 - playerTurn)) {
            // Opponent owns the space
            // Pay the rent
            int rent = spaces[newSpace].getRent();
            players[playerTurn].takeMoneyFromPlayer(rent);
            players[1 - playerTurn].giveMoneyToPlayer(rent);

            cout << players[playerTurn].getName() << " pays " << rent << " for rent." << endl;
        }
    }
    else if(spaces[newSpace].getType() == "Tax") {
        // Player pays tax
        int tax = spaces[newSpace].getTax();
        players[playerTurn].takeMoneyFromPlayer(tax);
        bank.giveMoneyToFreePark(tax);

        cout << players[playerTurn].getName() << " pays " << tax << " for tax." << endl;
    }
    else if(spaces[newSpace].getType() == "FreeParking") {
        // Player take free parkings money
        int amount = bank.takeFreeParkMoney();
        players[playerTurn].giveMoneyToPlayer(amount);

        cout << players[playerTurn].getName() << " took " << amount << " from free parking." << endl;
    }
    else if(spaces[newSpace].getType() == "GoJail") {
        // Sent player to jail
        // Player pays 200 euros to free parking
        players[playerTurn].setLocation(10);
        players[playerTurn].takeMoneyFromPlayer(200);
        bank.giveMoneyToFreePark(200);

        cout << players[playerTurn].getName() << " pays " << 200 << " for jail." << endl;
    }
}
