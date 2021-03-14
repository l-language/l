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
	auto result = parser();
	cout << to_string((int)(*result).kind) << endl;
	ShutdownGoogleLogging();
	return 0;
}