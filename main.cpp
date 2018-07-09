//
// Created by PC on 6/15/2018.
//

#include "duel.h"

/* generates each type of card */
void generateCards(card cards[]) {
    unique_ptr<card>temp(new card);
    for (unsigned int i = 0; i < CARD_TYPES; i++) {
        // numbered cards 1-7
        if (i < 7) {
            temp->setValue(i+1);
            temp->setName(to_string(i+1));
        }
            // special cards
        else {
            temp->setValue(1); // can be used to check if a card is numbered or special
            switch(i) {
                case 7: {
                    temp->setName("bolt");
                    temp->setCardType(1);
                    break;
                }
                case 8: {
                    temp->setName("mirror");
                    temp->setCardType(2);
                    break;
                }
                case 9: {
                    temp->setName("blast");
                    temp->setCardType(3);
                    break;
                }
                case 10: {
                    temp->setName("force");
                    temp->setCardType(4);
                    break;
                }
                default: {
                    cout << "An error has occurred. " << "cards cannot be generated";
                }
            }
        }
        cards[i] = *temp;
    }
}

int main() {
    card cards[CARD_TYPES];
    generateCards(cards);
    duel d(cards);
    return 0;
}