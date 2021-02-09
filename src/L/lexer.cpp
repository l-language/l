#include <L/lexer.hpp>
#include <L/helper.hpp>
using namespace std;

namespace L {
	Token::Token(string str) {
		auto& keywords = Lexer::keywords;
		auto iter = find(begin(keywords), end(keywords), str);
		if (iter != end(keywords)) {
			type = TokenType::Keyword;
			index = distance(begin(keywords), iter);
		} else {
			type = TokenType::Identifier;
			index = distance(begin(table), find(begin(table), end(table), str));
			if (index == distance(begin(table), end(table))) {
				table.push_back(str);
			}
		}
	}
	Token::Token(Operator op){
		type = TokenType::Operator;
		index = static_cast<std::size_t>(op);
	}
	string Token::get(){
		switch(type){
			case TokenType::Keyword : {
				return Lexer::keywords[index];
			}
			case TokenType::Identifier : {
				return table[index];
			}
			case TokenType::Operator: {
				return to_string(index);
			}
		}
		return "";
	}
	Lexer::Lexer(std::istream& fin_) :
		fin(fin_) {
	}
	Lexer::~Lexer() {
	}
	Token Lexer::readString() {
		std::string result;
		bool escape = false;
		char quote = fin.get();
		while ((current = fin.get()) != EOF) {
			if (escape){
				escape = !escape;
                switch(current){
                    case 'a': current = '\a';break;
                    case 'b': current = '\b';break;
                    case 'f': current = '\f';break;
                    case 'n': current = '\n';break;
                    case 'r': current = '\r';break;
                    case 't': current = '\t';break;
                    case 'v': current = '\v';break;
                    case '\\': current = '\\';break;
                    case '?': current = '\?';break;
                    case '\'': current = '\'';break;
                    case '"': current = '\"';break;
                    case '0': current = '\0';break;
                    default: {}
                }
			}else{
				if(current == '"')
					break;
				result += current;
			}
		}
		return Token(result);
	}
	Token Lexer::readOperator(){
		switch(current){
			case '!': {
				if(peek() == '='){
					next();
					return Operator::NotEquals;
				}
				return Operator::Not;
			}
			case '+': {
				if(peek() == '='){
					next();
					return Operator::PlusEquals;
				}
				if(peek() == '+'){
					next();
					return Operator::PlusPlus;
				}
				return Operator::Plus;
			}
			case '-': {
				if(peek() == '='){
					next();
					return Operator::MinusEquals;
				}
				if(peek() == '-'){
					next();
					return Operator::MinusMinus;
				}
				return Operator::Minus;
			}
			case '*': {
				if(peek() == '='){
					next();
					return Operator::AsteriskEquals;
				}
				return Operator::Asterisk;
			}
			case '/': {
				if(peek() == '*'){
					next();
					while((current = next()) != '*'&&peek() != '/' ){
						if(current = '\n') line++;
					}
					next();
					return Operator::Comment;
				}
				if(peek() == '='){
					next();
					return Operator::SlashEquals;
				}
				if(peek() == '/'){
					next();
					while (peek() != '\n'&&peek() != EOF){
						fin.get();
					}
					++line;
					return Operator::Comment;
				}
				return Operator::Slash;
			}
			case '=': {
				if(peek() == '='){
					next();
					return Operator::EqualsEquals;
				}
				return Operator::Equals;
			}
			case '(':
				return Operator::OpenParen;
			case ')':
				return Operator::CloseParen;
			case '[':
				return Operator::OpenBracket;
			case ']':
				return Operator::CloseBracket;
			case '{':
				return Operator::OpenBrace;
			case '}':
				return Operator::CloseBrace;
			case ';':
				return Operator::EndLine;
		}
		return Operator::Unknown;
	};
	Token Lexer::operator()() {
		while (next() != EOF) {
			switch (current) {
			case '\n':
				++line;
			case ' ':
			case '\t':
				continue;
			case '"':
				unget();
				return readString();
			default:
				std::string result {current};
				if (Helper::islalpha(current)) {
					while (Helper::islalnum(peek())){
						result += next();
					}
					return Token(result);
				} else if(Helper::islpunct(current)){
					return readOperator();
				}
				return Token("");
				break;
			}
		}
		return Token(Operator::EndOfFile);
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
	std::vector<std::string> Token::table{};
}