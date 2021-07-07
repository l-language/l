#include <L.hpp>
#include <L/lexer.hpp>
#include <L/ast/ast.hpp>
#include <L/ast/parser.hpp>


int main(int argc, char const* argv[]) {
	using namespace std;
	using namespace L;
	using namespace L::Base;
	using namespace string_literals;
	using namespace google;
	InitGoogleLogging(argv[0]);
	ifstream fin(argv[1]);
	if(!fin.is_open()){
		LOG(FATAL) << "Cannot open the file";
	}
	AST::Parser parser(fin);
	while(!parser.isEnd()){
		parser();
	}
	ShutdownGoogleLogging();
	return 0;
}