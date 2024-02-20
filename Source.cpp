#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

//Start of Game Variables
int firstCard1;
int firstCard2;
int newCard;
int total;
char userChoice = 'y';

int cardGenerator() {
    return rand() % 10 + 1;
}

void dealCard() {

    newCard = cardGenerator();
    cout << "Card: " << newCard << endl;
    total += newCard;
    cout << "Total: " << total << endl;
}

void askForCard() {
    cout << "Do you want another card (y/n)? ";
    cin >> userChoice;

    if (userChoice == 'y') {
        dealCard();
    }
    else if (userChoice == 'n') {
        return;
    }

}



void playGame() {
    //START THE GAME
    //Deal cards
    firstCard1 = cardGenerator();
    firstCard2 = cardGenerator();

    cout << "First cards: " << firstCard1 << ", " << firstCard2 << endl;

    //Add the cards
    total = firstCard1 + firstCard2;

    cout << "Total: " << total << endl;

    while (userChoice == 'y') {

        //Conditional to stop dealing when over 30
        if (total == 21) {
            break;
        }

        //Conditional to stop askForCard if player gets 21
        if (total > 21) {
            break;
    }
}

void calculateResult() {
    if (total == 21) {
        cout << "Congratulations!" << endl;
    }
    else if (total > 21) {
        cout << "Bust." << endl;
    }
    else {
        return;
    }
}

void askToPlayAgain() {
    calculateResult();
    cout << "Would you like to play again (y/n)? ";

    cin >> userChoice;
    if (userChoice == 'y') {
        playGame();
        askToPlayAgain();
    }
}

int main() {
    /* Commented out for submission.
    //Random Seed Generator based on time
    srand(time(0));
    */

    playGame();
    askToPlayAgain();

}
