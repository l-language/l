#pragma once
#include <L.hpp>
#define DEFINE_TOKEN_TYPE(tokenType, type)    \
	template<>                                \
	struct GetType<L::TokenType::tokenType> { \
		using Type = type;                    \
	};
#define GET_TYPE(tokenType) GetType<L::TokenType::tokenType>::Type
#define DEFINE_READER(name) void read##name();
#define DEFINE_GETTER(tokenType) std::shared_ptr<GET_TYPE(tokenType)> tokenType;
#define DEFINE_CONSTRUCTOR()

namespace L {
	enum class TokenType {
		Identifier,
		Keyword,
		Integer,
		Double,
		String,
		Operator,
		Unknown,
	};
	template<TokenType>
	struct GetType {
		using Type = void;
	};

	DEFINE_TOKEN_TYPE(Identifier, unsigned long long)
	DEFINE_TOKEN_TYPE(Keyword, unsigned)
	DEFINE_TOKEN_TYPE(Integer, int)
	DEFINE_TOKEN_TYPE(Double, double)
	DEFINE_TOKEN_TYPE(String, std::string)

	class Token_ {
	private:
		static std::vector<std::string> findTable;
		union {
			DEFINE_GETTER(Identifier)
			DEFINE_GETTER(Keyword)
			DEFINE_GETTER(Integer)
			DEFINE_GETTER(Double)
			DEFINE_GETTER(String)
		} token;

	public:
		Token_();
	};
	class Token : public std::string {
	public:
		Token(std::initializer_list<char> c, TokenType type_ = TokenType::Unknown) :
			std::string(c), type(type_) {}
		Token(const char* const pc, TokenType type_ = TokenType::Unknown) :
			std::string(pc), type(type_) {}
		Token(TokenType type_ = TokenType::Unknown) :
			std::string(), type(type_) {}
		bool operator==(Token& lhs) {
		}
		TokenType type;
	};
	class Lexer {
	private:
		std::vector<Token> result{ "" };
		std::istream& fin;

	public:
		Lexer(std::istream&);
		~Lexer();
		std::vector<Token> operator()();



		DEFINE_READER(Identifier)
		DEFINE_READER(String)
		DEFINE_READER(Number)

		static bool isKeyword(Token);
		static const std::vector<Token> keywords;
	};
}

#undef DEFINE_READER
#undef DEFINE_TOKEN_TYPE
#undef DEFINE_GETTER
#undef GET_TYPE