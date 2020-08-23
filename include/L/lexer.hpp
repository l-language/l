#pragma once
#include <L.hpp>
namespace L {
	typedef std::string Token;
	class Lexer {
	private:
		std::vector<Token> result{""};

	public:
		Lexer(std::ifstream&);
		~Lexer();
		std::vector<Token> get(){return result;}
	};
}