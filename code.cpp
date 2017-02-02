#include <iostream>
#include <algorithm>
#include <time.h>
#include <sstream>
#include <locale>
#include "code.h"

using namespace std;

vector<int> split(string &s, char delim, int max){
    //function to split a string seperated by commas into integers and stores them in a vector
    vector<int> nums;
    string digit;
    int n;
    stringstream ss;
    ss.str(s);
    while(getline(ss,digit,delim)){
        n = atoi(digit.c_str());
        if(n > max){
            cout << endl << "One of your digits is greater than the maximum value" << endl;
        }
        nums.push_back(n);
    }

    return nums;
}

code::code(int n, int m, bool guess)
{
	string str;
    bool isValid = true;
    int numCommas = 0;
    locale loc;
	/* Call init_code to generate a new secret code
	for the code object */
    if (guess)
    {
        cout << "Enter code with digits seperated by commas";
        cin >> str;
        //check for input length
        for(char c : str){
            if(!isdigit(c, loc) && c != ','){
                isValid = false;
            }
            if(c == ','){
                numCommas++;
            }
        }
        while(numCommas != n-1 || !isValid){
            isValid = true;
            numCommas = 0;
            cout << "Invalid input" << endl;
            cout << "Enter code with digits separated by commas";
            cin >> str;
            for(char c : str){       //checks for non number or delimiter characters
                if(!isdigit(c, loc) && c != ','){
                    isValid = false;
                }
                if(c == ','){
                    numCommas++;
                }
            }
        }
       codeData = split(str, ',', m);

    }
    else
    {
        codeData.resize(n);
        init_code(m);
    }
}

void code::init_code(int range)
{
	//Seed for random num
	srand(time(NULL));

	//Loop over the secret vector
	//cout << "Secret code: ";
	for (int i = 0; i < codeData.size(); i++)
	{
		//Each element is created randomly with a range [0, range-1]
		codeData.at(i) = rand() % range;
		//cout << codeData.at(i);
        if(i < codeData.size() - 1){
            //cout << ",";
        }
	}
	cout << endl;
}

int code::checkCorrect(const code& c)
{
	//Loop through the guess
	for (int i = 0; i < c.codeData.size(); i++)
	{
		//Check if each element matches the element at the same position
		if (c.codeData.at(i) == codeData.at(i))
		{
			//Increment if true
			numCorrect++;
			//Add index to list to prevent counting twice
		}
	}
	return numCorrect;
}

int code::checkIncorrect(const code& c)
{
	//Vector to hold history of already checked values
    int digit;
	vector<int> checkedNums;
	for (int i = 0; i < codeData.size(); i++)
	{
		//Check if the current value had already been checked
		if (find(checkedNums.begin(), checkedNums.end(), codeData.at(i)) == checkedNums.end())
		{
			//If not, add it to the list of checked values
            digit = codeData.at(i);
			checkedNums.push_back(digit);
			//Find number of occurrences of value in both the secret and guess codes
			int numInSecret = count(codeData.begin(), codeData.end(), codeData.at(i));
			int numInGuess = count(c.codeData.begin(), c.codeData.end(), codeData.at(i));
			//Smallest # of occurrences is equal to the amount of occurrences in common
			numIncorrect += min(numInSecret, numInGuess);
		}
	}
	//Adjust the # of incorrect values to account for values at identical indexes
	numIncorrect -= numCorrect;
	return numIncorrect;
}

vector<int> code::getCodeData(){
    return this->codeData;
}


