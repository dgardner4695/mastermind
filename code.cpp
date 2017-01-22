#include <iostream>
#include <algorithm>
#include <stdlib.h>
#include <time.h>
#include "code.h"

using namespace std;

code::code(int n, int m, bool guess = false)
{
	/* Call init_code to generate a new secret code
	for the code object */
	if (guess)
	{
		int digit;
		for (int i = 0; i < n; i++)
		{
			cout << "Enter the next digit in your guess: ";
			cin >> digit;
			while (!(cin) || digit < 0 || digit > m)
			{
				cin.clear();
				cin.ignore();
				cout << "Incorrect parameter, try again: ";
				cin >> digit;
			}
			codeData.push_back(digit);
		}
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
	cout << "Secret code: ";
	for (int i = 0; i < codeData.size(); i++)
	{
		//Each element is created randomly with a range [0, range-1]
		codeData.at(i) = rand() % range;
		cout << codeData.at(i);
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
	vector<int> checkedNums;
	for (int i = 0; i < codeData.size(); i++)
	{
		//Check if the current value had already been checked
		if (find(checkedNums.begin(), checkedNums.end(), codeData.at(i)) == checkedNums.end())
		{
			//If not, add it to the list of checked values
			checkedNums.push_back(codeData.at(i));
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

int main()
{
	//Initialize length and range integers
	int n, m;
	//User input and error handling
	cout << "Enter the desired code length: ";
	while (!(cin >> n) || n <= 0)
	{
		cin.clear();
		cin.ignore();
		cout << "Input must be an integer, try again: ";
	}
	cout << "Enter the maximum value for the random number generator: ";
	while (!(cin >> m) || m <= 0)
	{
		cin.clear();
		cin.ignore();
		cout << "Input must be an integer, try again: ";
	}
	/*Create the secret code and guess code objects using
	the parameters n and m*/
	code sc(n, m);
	code gc(n, m, true);
	/*First is # of numbers in correct position
	Second is # of correct numbers in incorrect position*/
	int first = sc.checkCorrect(gc);
	int second = sc.checkIncorrect(gc);
	cout << first << second << endl;
	if (first == n)
	{
		cout << "You win!" << endl;
	}
	else
	{
		cout << "Too bad, try again" << endl;
	}
	system("pause");
	return 0;
}
