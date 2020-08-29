#include <L.hpp>
#include <L/lexer.hpp>
int main(int argc, char const* argv[]) {
	using namespace std;
	using namespace L;
	using namespace L::Base;
	ifstream fin(argv[1]);
	Lexer lexer(fin);
	for (auto&& i : lexer.get()) {
		cout << i << ",";
	}
	return 0;
}