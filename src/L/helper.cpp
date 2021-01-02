#include <L/helper.hpp>
namespace L {
	namespace Helper {
		bool islalnum(char c) {
			return std::isalnum(c) || c == '_';
		}
		bool islalpha(char c) {
			return std::isalpha(c) || c == '_';
		}
		bool islpunct(char c) {
			return std::ispunct(c) && c != '_';
		}
	}
}