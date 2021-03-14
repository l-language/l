#pragma once
#include <L.hpp>
#include <map>
#include <iterator>
#define DEFINE_READER(name) L::Token read##name();
namespace L {
	enum class TokenKind {
		Identifier,
		Keyword,
		Integer,
		Double,
		String,
		Operator,
		Unknown,
	};
	enum class Reversed {
		TK_void,
		TK_bool,
		TK_short,
		TK_ushort,
		TK_int,
		TK_uint,
		TK_long,
		TK_ulong,
		TK_double,
		TK_udouble,
		TK_string,
		TK_cast,
		TK_const,
		TK_static,
		TK_mutable,
		TK_struct,
		TK_namespace,
		TK_using,
		TK_enum
	};
	enum class Operator{
		Not = 1,
		NotEquals, EqualsEquals,
		OpenBrace, CloseBrace,
		OpenParen, CloseParen,
		OpenBracket, CloseBracket,
		Plus, Minus, Asterisk, Slash,
		MinusMinus, PlusPlus,
		Equals, PlusEquals, MinusEquals, AsteriskEquals, SlashEquals,
		LessThan, GreaterThan,
		Colon,
		Comment, EndLine, EndOfFile, Unknown,
	};
	class Token {
	public:
		static std::vector<std::string> table;
		unsigned long long index;
		TokenKind type;
		Token(std::string);
		Token(Operator);
		Token(): type(TokenKind::Unknown){}
		std::string get();
		bool operator==(Token other){
			return other.type == type && other.index == index;
		}
		bool operator!=(Token other){
			return other.type != type || other.index != index;
		}
	};
	class Lexer {
	private:
		std::istream& fin;
		char current;
		std::size_t line = 1;
		char next(){return current = fin.get();}
		void unget(){fin.unget();}
		char peek(){return fin.peek();}
	public:
		Lexer(std::istream&);
		~Lexer();
		Token operator()();
		DEFINE_READER(String)
		DEFINE_READER(Number)
		DEFINE_READER(Operator)
		static bool isKeyword(std::string);
		static const std::vector<std::string> keywords;
	};
}

#undef DEFINE_READER