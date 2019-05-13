#pragma once
#include <string>
#include <iostream>
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