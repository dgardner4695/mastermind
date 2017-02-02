//
// Created by Dan on 2/2/2017.
//

#ifndef MASTERMIND_MASTERMIND_H
#define MASTERMIND_MASTERMIND_H


#include "code.h"
#include "response.h"

class mastermind {
private:
    code sc;
    int numDigits;
    int maxDigit;
public:
    mastermind(int numDigits, int maxDigit);
    mastermind();
    void printSecretCode();
    code humanGuess();
    response getResponse(code sc, code gc);
    void playGame();
    code getSecretCode();
    int getMax();
    int getNumDigits();
    bool isSolved(response r);
};


#endif //MASTERMIND_MASTERMIND_H
