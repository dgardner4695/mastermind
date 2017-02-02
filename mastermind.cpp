//
// Created by Dan on 2/2/2017.
//

#include <iostream>
#include "mastermind.h"
#include <sstream>
#include <cstdlib>
#include "code.h"


mastermind::mastermind() : sc(5, 10, false){
    numDigits = 5;
    maxDigit = 10;

}

mastermind::mastermind(int num, int max) : sc(num, max, false){
    numDigits = num;
    maxDigit = max;
}

code mastermind::getSecretCode() {
    return sc;
}

void mastermind::printSecretCode() {
    std::vector<int> codeData = sc.getCodeData();

    std::cout << "secret code: ";
    for(int i: codeData){
        std::cout << codeData[i] << " ";
    }
    std::cout << std::endl;
}

int mastermind::getMax() {
    return this->maxDigit;
}

int mastermind::getNumDigits() {
    return this->numDigits;
}

code mastermind::humanGuess(){
    return code(numDigits,maxDigit, true);
}

response mastermind::getResponse(code sc, code gc){
    int numCorrect = sc.checkCorrect(gc);
    int numIncorrect = sc.checkIncorrect(gc);

    return response(numCorrect, numIncorrect);
}

bool mastermind::isSolved(response r){
    response solved(numDigits, 0);
    return solved == r;
}

void mastermind::playGame(){
    this->printSecretCode();
    bool gameWon = false;


    while(!gameWon){
        if(isSolved(getResponse(sc, humanGuess()))){
            gameWon = true;
        }
    }

    std::cout << std::endl << "You win";
}






