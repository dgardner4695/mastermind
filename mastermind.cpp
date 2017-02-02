//
// Created by Dan on 2/2/2017.
//

#include "mastermind.h"
#include "code.h"

mastermind::mastermind() : sc(5, 10, false){
}

mastermind::mastermind(int numDigits, int maxDigit) : sc(numDigits, maxDigit, false){
}

code mastermind::getSecretCode() {
    return sc;
}

void mastermind::printSecretCode() {
    std::vector<int> codeData = sc.
}



