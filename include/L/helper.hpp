#pragma once
#include <L.hpp>
namespace L {
	namespace Helper {
		extern bool islalnum(char);
		extern bool islalpha(char);
		extern bool islpunct(char);
		template<typename T,typename F>
		T cast(F f){
			return *reinterpret_cast<double*>(&f);
		}
	}
}