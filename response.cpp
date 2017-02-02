#include <ostream>
#include "response.h"

//Constructor initializing a response
response::response(int correct, int incorrect)
{
	numCorrect = correct;
	numIncorrect = incorrect;
}

//Getters and setters
int response::getCorrect() const
{
	return numCorrect;
}

int response::getIncorrect() const
{
	return numIncorrect;
}

void response::setCorrect(int correct)
{
	numCorrect = correct;
}

void response::setIncorrect(int incorrect)
{
	numIncorrect = incorrect;
}

//== Operator overloaded, returns true if both
//correct and incorrect are equal
bool operator == (const response& r2)
{
	if (getCorrect() == r2.getCorrect() && getIncorrect() == r2.getIncorrect())
	{
		return true;
	}
	return false;
}

//<< Operator overloaded, prints correct and incorrect
//separated by a space.
std::ostream& operator<< (std::ostream& ostr, const response& r)
{
	ostr << r.numCorrect << " " << r.numIncorrect << std::endl;
	return ostr;
}
