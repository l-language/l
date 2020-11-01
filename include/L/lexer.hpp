#pragma once
#include <L.hpp>
#define DEFINE_READER(name) void read##name();
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
	struct Token {
	private:
		unsigned long long index;
	public:
		TokenType type;
		Token(std::string,std::vector<std::string>&);
		std::string get();
	};
	class Lexer {
	private:
		std::istream& fin;
		char current;

	public:
		Lexer(std::istream&);
		~Lexer();
		Token operator()();

		DEFINE_READER(String)
		DEFINE_READER(Number)

		static bool isKeyword(std::string);
		static const std::vector<std::string> keywords;
	};
}

#undef DEFINE_READER