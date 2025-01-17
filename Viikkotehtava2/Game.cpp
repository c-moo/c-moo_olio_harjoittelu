#include <iostream>
#include <ctime>
using namespace std;

#include "Game.h"
#define DEBUG true

void Game::play() {

    srand(time(0));

    randomNumber = 1 + (rand() % (maxNumber));

    cout << endl << "Arvaa 1-" << maxNumber <<" valilta numero." << endl;

    #if DEBUG
    cout << "Random numero on " << randomNumber << endl; // Kertoo luvun jos DEBUG = true
    #endif

    while(true)  {
        while(!(cin >> playerGuess) or (playerGuess < 1) or (playerGuess > maxNumber)) {
            cout << "Anna sopiva numero, " << playerGuess << " ei ole sopiva numero" << endl;
            cin.clear();
            cin.ignore(10000, '\n');
        }

        if (playerGuess < randomNumber) {
            cout << endl << "Luku on suurempi kuin " << playerGuess << endl;
        }

        else if (playerGuess > randomNumber) {
            cout << endl << "Luku on pienempi kuin " << playerGuess << endl;
        }

        else {
            numOfGuesses += 1;
            break;
        }
    numOfGuesses += 1;
    }
    printGameResult();
};

void Game::printGameResult() {

    cout << playerGuess << " On oikein!" << " Arvausten maara on " << numOfGuesses << endl;
    numOfGuesses = 0;
};

