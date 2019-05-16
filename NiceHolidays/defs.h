#pragma once
#include <string>
#include <iostream>
#include "Packet.h"
#if defined(_WIN32)
    #define PLATFORM_NAME "windows" // Windows
#elif defined(_WIN64)
    #define PLATFORM_NAME "windows" // Windows
#elif defined(__CYGWIN__) && !defined(_WIN32)
    #define PLATFORM_NAME "windows" // Windows (Cygwin POSIX under Microsoft Window)
#elif defined(__linux__)
    #define PLATFORM_NAME "linux"
#else
	#define PLATFORM_NAME "other"
#endif
using namespace std;
const std::string AGENCY_FILE_NAME = "agency.txt";
const std::string SEPARATOR = "::::::::::";
const unsigned char TABLE_PADDING = 4;
inline bool clear(){
	if (PLATFORM_NAME == "linux"){
		cout << "\033[2J\033[1;1H";
	}else if (PLATFORM_NAME == "windows"){
		system("cls");
	}else{
		return false;
	}
	return true;
}

//Splits a string by a specific delimiter and puts it into a vector
inline vector<string> split(string str, string delimiter)
{
	vector<string> result;
	size_t pos = 0;
	string token;
	pos = str.find(delimiter);
	while (pos != str.npos)
	{
		token = str.substr(0, pos);
		result.push_back(token);
		str.erase(0, pos + delimiter.length());
		pos = str.find(delimiter);
	}
	result.push_back(str);
	return result;
}

inline string lower(string s)
{
	string ns;
	for (size_t i = 0; i < s.size(); i++)
	{
		if (s.at(i) >= 'A' && s.at(i) <= 'Z')
		{
			ns += s.at(i) + 32;
		}
		else
		{
			ns += s.at(i);
		}
	}

	return ns;
}

inline void pause()
{
	cout << "Press enter to continue...";
	cin.get();
}
string lstrip(string s){
	int i = 0;
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '	'){
		i++;
	}
	return s.substr(i);
}
string rstrip(string s){
	int i = s.length() - 1;
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '	'){
		i--;
	}
	return s.substr(0, i + 1);
}
string strip(string s){
	string result = lstrip(s);
	result = rstrip(result);
	return result;
}
vector<string> strip(vector<string> s){
	for (int i = 0; i < s.size(); ++i){
		s.at(i) = strip(s.at(i));
	}
	return s;
}