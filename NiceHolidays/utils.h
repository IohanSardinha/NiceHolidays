#pragma once
#include <iostream>
#include <string>
template<typename Char, typename Traits, typename Allocator>
std::basic_string<Char, Traits, Allocator> operator*(const std::basic_string<Char, Traits, Allocator> s, unsigned n){
	std::basic_string<Char, Traits, Allocator> tmp = "";
	for (size_t i = 0; i < n; ++i)
		tmp += s;
	return tmp;
}
template<typename Char, typename Traits, typename Allocator>
std::basic_string<Char, Traits, Allocator> operator*(unsigned n, const std::basic_string<Char, Traits, Allocator>& s){
   return s * n;
}
template<typename Char, typename Traits, typename Allocator>
std::basic_string<Char, Traits, Allocator> operator*=(std::basic_string<Char, Traits, Allocator>& s, unsigned n){
	std::basic_string<Char, Traits, Allocator> tmp = "";
	for (unsigned i = 0; i < n; ++i)
		tmp += s;
	s = tmp;
	return tmp;
}
template<typename Char, typename Traits, typename Allocator>
std::basic_string<Char, Traits, Allocator> operator*=(unsigned n, std::basic_string<Char, Traits, Allocator>& s){
   return s *= n;
}