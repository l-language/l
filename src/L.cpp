#include <L.hpp>
#include <L/lexer.hpp>



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
	Lexer lexer(fin);
	Token token;
	while((token = lexer()) != Token(Operator::EndOfFile)){
		cout << token.get() << endl;
	}
	ShutdownGoogleLogging();
	return 0;
}