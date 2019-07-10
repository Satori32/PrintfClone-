#pragma once
#include <iostream>
#include <string>
#include <string_view>
#include <cstdint>

//mit license.

/**/
std::uintmax_t PrintF_Show(const std::string_view& Fmt) {
	std::cout << Fmt;
	return 0;
}
/**/

std::string to_string(const std::string_view& In) {
	return In.data();
}

template<class T>
std::uintmax_t PrintF_Show(const std::string_view& Fmt, const T& In) {
		std::size_t N = 0;

	N = Fmt.find_first_of("%", 0);
	
	if (N == Fmt.npos) return 0;

	const std::string_view FMT = Fmt.substr(0, N);
	using std::to_string;
	std::string O = to_string(In);	
	std::cout << FMT<<O;

	PrintF_Show(Fmt.substr(N+1, Fmt.size()));

	return FMT.size()+O.size();
}

template<class T,class ... Args>
std::uintmax_t PrintF_Show(const std::string_view& Fmt, const T& In, const Args&... A) {
	std::size_t N = 0;

	N = Fmt.find_first_of("%", 0);


	if (N == Fmt.npos) return 0;

	const std::string_view FMT = Fmt.substr(0, N);
	using std::to_string;
	//std::string O = to_string( In );


	std::cout << FMT<<In;

	PrintF_Show(Fmt.substr(N+1, Fmt.size()) , A...);

	return FMT.size();// +O.size();
}


template<class ... Args>
std::uintmax_t PrintF(const std::string_view& Fmt, const Args&... In) {
	return PrintF_Show(Fmt, In...);
}