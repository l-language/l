#include <L.hpp>
#include <L/lexer.hpp>
int main(int argc, char const* argv[]) {
	using namespace std;
	using namespace L;
	using namespace L::Base;
	ifstream fin(argv[1]);
	Lexer lexer(fin);
	for (auto&& i : lexer()) {
		cout << i << ",";
	}
	cout << endl << boolalpha << Lexer::isKeyword("static");
	return 0;
}