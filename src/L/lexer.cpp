#include <L/lexer.hpp>
static bool isToken(std::string str) {
	using namespace std;
	int i = 0;
	for (auto&& c : str) {
		if (isdigit(c) && i == 0)
			return false;
		if (ispunct(c) || !isalpha(c))
			return false;
	}
	return true;
}
namespace L {
	Lexer::Lexer(std::ifstream& fin) {
		char temp;
		while ((temp = fin.get()) != EOF) {
			if (isspace(temp) || temp == '\n') {
				if (result.back() != "")
					result.push_back("");
				continue;
			}
			if (isToken(result.back() + temp) && result.back() != "") {
				result.back() += temp;
				continue;
			}
			if (result.back() != "")
				result.push_back(Token{ temp });
			else
				result.back() += Token{ temp };
		}
	}
	Lexer::~Lexer() {
	}
}