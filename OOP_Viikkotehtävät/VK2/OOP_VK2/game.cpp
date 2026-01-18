#include "game.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

Game::Game(int i) {
    maxNumber = i;
    playerGuess = 0;
    numOfGuesses = 0;
    srand(time(0));
    randomNumber = rand() % maxNumber;

    cout << "GAME CONSTRUCTOR: object initialized with "<< maxNumber << " as maximum value" << endl;

}

Game::~Game()
{
    cout << "GAME DESTRUCTOR: object cleared from stack memory" << endl;
}

void Game::play() {
    cout << "Arvaa numero: ";

    while(true){
        cin >> playerGuess;
        numOfGuesses++;

        if (playerGuess < randomNumber) {
            cout << "Luku on suurempi kuin " << playerGuess << endl;
        }

        else if (playerGuess > randomNumber) {
            cout << "Luku on pienempi kuin " << playerGuess << endl;
        }
        else {
            break;
        }
    }
    printGameResults();
}

void Game::printGameResults() {

    cout << "Oikein! Vastaus oli " << randomNumber << endl;
    cout << numOfGuesses << " arvausta" << endl;
}
