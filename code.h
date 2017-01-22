#include <vector>
class code
{
	public:
		code(int n, int m, bool human);
		void init_code(int range);
		void setGuess(std::vector<int> g);
		int checkCorrect(const code& c);
		int checkIncorrect(const code& c);
	private:
		std::vector<int> codeData;
		int numCorrect = 0;
		int numIncorrect = 0;
};
