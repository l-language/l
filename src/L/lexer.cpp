#include <L/lexer.hpp>
#include <L/helper.hpp>
using namespace std;
static std::vector<std::string> table{};

namespace L {
	Token::Token(string str, std::vector<std::string>& context = table) {
		auto& keywords = Lexer::keywords;
		if (Lexer::isKeyword(str)) {
			type = TokenType::Keyword;
			index = distance(begin(keywords), find(begin(keywords), end(keywords), str));
		} else {
			type = TokenType::Identifier;
			index = distance(begin(context), find(begin(context), end(context), str));
			if (index == distance(begin(context), end(context))) {
				table.push_back(str);
			}
		}
	}
	string Token::get(){
		switch(type){
			case TokenType::Keyword : {
				return Lexer::keywords[index];
			}
			case TokenType::Identifier : {
				return table[index];
			}
		}
		return "";
	}
	Lexer::Lexer(std::istream& fin_) :
		fin(fin_) {
	}
	Lexer::~Lexer() {
	}
	void Lexer::readString() {
		std::string result;
		bool escape = false;
		char quote = fin.get();
		result += quote;
		while ((current = fin.get()) != EOF) {
			result += current;
			if (escape || current == '\\')
				escape = !escape;
			else if (current == quote)
				break;
		}
	}
	Token Lexer::operator()() {
		while ((current = fin.get()) != EOF) {
			switch (current) {
			case ' ':
			case '\t':
			case '\n':
				return Token{ "" };
			default:
				std::string result;
				if (Helper::islalpha(current)) {
					while (Helper::islalnum(current))
						result += current;
				} else {
				}
				return Token{ "" };
				break;
			}
		}
	}

	const std::vector<std::string> Lexer::keywords = {
		"void",
		"bool",
		"short",
		"ushort",
		"int",
		"uint",
		"long",
		"ulong",
		"double",
		"udouble",
		"string",
		"cast",
		"const",
		"static",
		"mutable",
		"struct",
		"namespace",
		"using",
		"enum"
	};
	bool Lexer::isKeyword(std::string token) {
		return std::find(begin(keywords), end(keywords), token) != end(keywords);
	}
}