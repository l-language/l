#pragma once
#include <L.hpp>
#define DEFINE_TOKEN_TYPE(tokenType, type) \
	template<> \
	struct GetType<TokenType::tokenType>{\
		using Type = type;\
	};
#define GET_TYPE(tokenType) GetType<TokenType::tokenType>::type

namespace L {
	enum class TokenType {
		Identifier,
		Keyword,
		Integer,
		Double,
		String,
		Operator,
	};
	template<TokenType>
	struct GetType{
		using Type = void*;
	};
	DEFINE_TOKEN_TYPE(Identifier, unsigned long long)
	DEFINE_TOKEN_TYPE(Keyword, std::string)
	DEFINE_TOKEN_TYPE(String, std::string)
	using Token = std::string;

	class Lexer {
	private:
		std::vector<Token> result{ "" };
		std::istream& fin;

	public:
		Lexer(std::istream&);
		~Lexer();
		std::vector<Token> operator()();

#define DEFINE_READER(name) void read##name();
		DEFINE_READER(Identifier)
		DEFINE_READER(String)
#undef DEFINE_READER
	};
}