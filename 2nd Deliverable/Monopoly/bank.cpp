#include "bank.h"

// Constructor of Bank
Bank::Bank() {
    money = 20580;
    freeParkMoney = 0;
}

// Getters
int Bank::getMoney() {
    return money;
}

int Bank::getFreeParkMoney() {
    return freeParkMoney;
}
// End of getters

void Bank::giveMoneyToBank(int amount) {
    money += amount;
}

void Bank::takeMoneyFromBank(int amount) {
    money -= amount;
}

void Bank::giveMoneyToFreePark(int amount) {
    freeParkMoney += amount;
}

int Bank::takeFreeParkMoney() {
    int temp = freeParkMoney;
    freeParkMoney = 0;
    return temp;
}
