#ifndef CODE_H
#define CODE_H

#include <vector>
class code
{
	public:
		code(int n, int m, bool human);
		void init_code(int range);
		void setGuess(std::vector<int> g);
		int checkCorrect(const code& c);
		int checkIncorrect(const code& c);
        std::vector<int> getCodeData();
	private:
		std::vector<int> codeData;
		int numCorrect = 0;
		int numIncorrect = 0;
};
#endif
