//
// Created by Dan on 2/2/2017.
//

#include <iostream>
#include "mastermind.h"
#include <sstream>
#include <cstdlib>


mastermind::mastermind() : sc(5, 10, false){
    //default constructor
    numDigits = 5;
    maxDigit = 10;

}

mastermind::mastermind(int num, int max) : sc(num, max, false){
    //constructor
    numDigits = num;
    maxDigit = max;
}

code mastermind::getSecretCode() {
    //return secret code
    return sc;
}

void mastermind::printSecretCode() {
    std::vector<int> codeData = sc.getCodeData();

    std::cout << "secret code: ";
    for(int i: codeData){
        std::cout << codeData[i] << " "; //output each number in the secret code
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
    //calls the code constructor using the secret code parameters
    return code(numDigits,maxDigit, true);
}

response mastermind::getResponse(code sc, code gc){
    int numCorrect = sc.checkCorrect(gc);
    int numIncorrect = sc.checkIncorrect(gc);
    //creates a response
    return response(numCorrect, numIncorrect);
}

bool mastermind::isSolved(response r){
    response solved(numDigits, 0); //hypothetical "perfect score" response
    return solved == r; //overloaded operator checks if they are equal
}

void mastermind::playGame(){
    bool gameWon = false;

    while(!gameWon){
        if(isSolved(getResponse(sc, humanGuess()))){ //gets user input -> creates a response -> checks if the response is "solved"
            gameWon = true;
        }
    }

    std::cout << std::endl << "You win";
}






