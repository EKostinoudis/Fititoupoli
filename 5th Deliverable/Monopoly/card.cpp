#include "card.h"

// Card class
Card::Card(int id, string text) {
    this->id = id;
    this->text = text;
}

// id getter
int Card::getId() {
    return id;
}

// text getter
string Card::getText() {
    return text;
}
// End of Card class


// CardMove class
CardMove::CardMove(int id, string text, int location) : Card(id, text) {
    this->location = location;
}

void CardMove::cardAction(Bank* bank, Player* player) {
    player->setLocation(this->location);
}
// End of MoveCard class


// CardMoney class
CardMoney::CardMoney(int id, string text, int amount) : Card(id, text) {
    this->amount = amount;
}

void CardMoney::cardAction(Bank* bank, Player* player) {
    bank->takeMoneyFromBank(this->amount);
    player->giveMoneyToPlayer(this->amount);
}
// End of CardMoney class
