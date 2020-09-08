#include <L/lexer.hpp>
static void append(std::vector<std::string>& target, std::string str) {
	if (target.back() != "")
		target.push_back(str);
	else
		target.back() += str;
}
namespace L {
	Lexer::Lexer(std::istream& fin_) :
		fin(fin_) {
	}
	Lexer::~Lexer() {
	}
	void Lexer::readIdentifier() {
		char temp;
		while ((temp = fin.get()) != EOF) {
			result.back() += temp;
			char peek = fin.peek();
			if (!(isdigit(peek) || isalpha(peek) || peek == '_'))
				break;
		}
	}
	void Lexer::readString() {
		char temp;
		bool escape = false;
		char quote = result.back().back();
		while ((temp = fin.get()) != EOF) {
			result.back() += temp;
			if (escape || temp == '\\')
				escape = !escape;
			else if(temp == quote)
				break;
		}
	}
	std::vector<Token> Lexer::operator()() {
		char temp;
		while ((temp = fin.get()) != EOF) {
			if (isspace(temp) || temp == '\n') {
				append(result, "");
			} else if (isalpha(temp)) {
				append(result, std::string{ temp });
				readIdentifier();
			} else if (temp == '"' || temp == '\'') {
				append(result, std::string{ temp });
				readString();
			} else {
				append(result, std::string{ temp });
			}
		}
		return result;
	}
}