#include <L/lexer.hpp>

static void append(std::vector<L::Token>& target, L::Token str) {
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
		char quote = fin.get();
		append(result, Token{ quote });
		while ((temp = fin.get()) != EOF) {
			result.back() += temp;
			if (escape || temp == '\\')
				escape = !escape;
			else if (temp == quote)
				break;
		}
		result.back().type = TokenType::String;
	}
	std::vector<Token> Lexer::operator()() {
		char temp;
		while ((temp = fin.get()) != EOF) {
			if (isspace(temp) || iscntrl(temp) || temp == '\n') {
				append(result, "");
			} else if (isalpha(temp)) {
				fin.unget();
				readIdentifier();
			} else if (temp == '"' || temp == '\'') {
				fin.unget();
				readString();
			} else {
				append(result, Token{ temp });
			}
		}
		return result;
	}

	const std::vector<Token> Lexer::keywords = {
		"void",
		"bool",
		"char",
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
	bool Lexer::isKeyword(Token token) {
		return std::find(begin(keywords), end(keywords), token) != end(keywords);
	}
}