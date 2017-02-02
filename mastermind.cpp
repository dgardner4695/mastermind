//
// Created by Dan on 2/2/2017.
//

#include <iostream>
#include "mastermind.h"
#include <sstream>
#include <cstdlib>
#include "response.cpp"


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
    for(int i = 0; i < numDigits; i++){
        std::cout << codeData.at(i);//output each number in the secret code
        if(i < numDigits - 1){
            std::cout << ",";
        }
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
    response r = response(numCorrect, numIncorrect);
    return r;
}

bool mastermind::isSolved(response r){
    response solved(numDigits, 0); //hypothetical "perfect score" response
    return solved == r; //overloaded operator checks if they are equal
}

void mastermind::playGame(){
    bool gameWon = false;
    bool gameLost = false;
    int roundsPlayed = 0;
    response r(0,0);

    while(!gameWon && roundsPlayed < 10){
        r = getResponse(sc, humanGuess());//gets user input -> creates a response
        if(isSolved(r)){ //checks if the response is "solved"
            gameWon = true;
        }else {
            std:: cout << r;
            roundsPlayed++;
        }
    }
    if(roundsPlayed >= 10){
        std::cout << std::endl << "You lose";
    }
    else{
        std::cout << std::endl << "You win";
    }

}

int main(){
    int n, m;
    //User input and error handling
    std::cout << "Enter the desired code length: ";
    while (!(std::cin >> n) || n <= 0)
    {
        std::cin.clear();
        std::cin.ignore();
        std::cout << "Input must be an integer, try again: " << std::endl;
    }
    std::cout << "Enter the maximum value for the random number generator: ";
    while (!(std::cin >> m) || m <= 0)
    {
        std::cin.clear();
        std::cin.ignore();
        std::cout << "Input must be an integer, try again: " << std::endl;
    }
    mastermind mm = mastermind(n,m);
    mm.printSecretCode();

    mm.playGame();

    return 0;
}






