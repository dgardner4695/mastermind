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
public:
    mastermind(int numDigits, int maxDigit);
    mastermind();
    void printSecretCode();
    code humanGuess();
    response getResponse();
    void playGame();
    code getSecretCode();
};


#endif //MASTERMIND_MASTERMIND_H
