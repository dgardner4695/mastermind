#include <iostream>
#include <algorithm>
#include <stdlib.h>
#include <time.h>
#include "code.h"

code::code(int n, int m)
{
	/* Call init_code to generate a new secret code
	for the code object */
	secret.resize(n);
	guess.resize(n);
	init_code(m);
}

void code::init_code(int range)
{
	//Seed for random num
	srand(time(NULL));

	//Loop over the secret vector
	std::cout << "Secret code: ";
	for (int i = 0; i < secret.size(); i++)
	{
		//Each element is created randomly with a range [0, range-1]
		secret[i] = rand() % range;
		std::cout << secret[i];
	}
	std::cout << std::endl;
}

int code::checkCorrect(const code& c)
{
	//Initial num of correct positions
	int numCorrect = 0;
	//Loop through the guess
	for (int i = 0; i < c.guess.size(); i++)
	{
		//Check if each element matches the element at the same position
		if (c.guess[i] == secret[i])
		{
			//Increment if true
			numCorrect++;
		}
	}
	return numCorrect;
}

int code::checkIncorrect(const code& c)
{
	int numIncorrect = 0;
	std::vector<int> checkedNums;
	for (int i = 0; i < c.guess.size(); i++)
	{
		//First make sure that the current elements value does not match a previously checked value
		if (std::find(checkedNums.begin(), checkedNums.end(), c.guess[i]) == checkedNums.end())
		{
			//If it does not, add it to the vector of checked values
			checkedNums.push_back(c.guess[i]);
			//Check if the value matches any values in the secret vector
			if (std::find(c.secret.begin(), c.secret.end(), c.guess[i]) != c.secret.end())
			{
				//If so, increment numIncorrect
				numIncorrect++;
			}
		}
	}
	return numIncorrect;
}

void code::setGuess(std::vector<int> g)
{
	guess = g;
}

void print_vect(std::vector<int> v)
{
	for (int i = 0; i < v.size(); i++)
	{
		std::cout << v[i];
	}
	std::cout << std::endl;
}

int main()
{
	code ex1 = code(5, 7);
	int guess1[] = {5, 0, 3, 2, 6};
	int guess2[] = {2, 1, 2, 2, 2};
	int guess3[] = {1, 3, 3, 4, 5};
	std::vector<int> g1(guess1, guess1 + (sizeof(guess1)/sizeof(guess1[0])));
	ex1.setGuess(g1);
	int first = ex1.checkCorrect(ex1);
	int second  = ex1.checkIncorrect(ex1);
	std::cout << "Guess 1: ";
	print_vect(g1);
	std::cout << first << ' ' << second << std::endl;

	std::vector<int> g2(guess2, guess2 + (sizeof(guess2)/sizeof(guess2[0])));
	ex1.setGuess(g2);
	first = ex1.checkCorrect(ex1);
	second = ex1.checkIncorrect(ex1);
	std::cout << "Guess 2: ";
	print_vect(g2);
	std::cout << first << ' ' << second << std::endl;

	std::vector<int> g3(guess3, guess3 + (sizeof(guess3)/sizeof(guess3[0])));
	ex1.setGuess(g3);
	first = ex1.checkCorrect(ex1);
	second = ex1.checkIncorrect(ex1);
	std::cout << "Guess 3: ";
	print_vect(g3);
	std::cout << first << ' ' << second << std::endl;
	system("pause");
	return 0;
}
