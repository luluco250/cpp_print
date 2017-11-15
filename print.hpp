// cpp_print

#ifndef LUCAS_CPP_PRINT_HEADER
#define LUCAS_CPP_PRINT_HEADER

#include <iostream>

#if __cplusplus >= 201703L
#define __CONSTEXPR constexpr
#else
#define __CONSTEXPR
#endif

namespace lucas {
	template<char end = '\n', char sep = ' '>
	inline void print() {
		if __CONSTEXPR (end != 0)
			std::cout << end;
	}

	template<char end = '\n', char sep = ' ', class T>
	inline void print(const T& arg) {
		std::cout << arg;
		if __CONSTEXPR (end != 0)
			std::cout << end;
	}

	template<char end = '\n', char sep = ' ', class T1, class... Tn>
	inline void print(const T1& first, const Tn&... others) {
		std::cout << first;
		if __CONSTEXPR (sep != 0)
			std::cout << sep;
		print<end, sep>(others...);
	}
}

#endif