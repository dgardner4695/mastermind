#ifndef RESPONSE_H
#define RESPONSE_H

#include <ostream>
class response
{
	//Initialize public member functions
	public:
		response(int correct, int incorrect);
		int getCorrect() const;
		int getIncorrect() const;
		void setCorrect(int correct);
		void setIncorrect(int incorrect);
		bool operator== (const response &r1);
		//Friend function overloading the << operator
		friend std::ostream& operator<< (std::ostream& ostr, const response& r);
	private:
		//Two private data members for storing the response to a guess
		int numCorrect;
		int numIncorrect;
};
#endif
