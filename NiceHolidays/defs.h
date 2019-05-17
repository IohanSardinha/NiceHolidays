#pragma once
#include <string>
#include <vector>
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
const std::string AGENCY_FILE_NAME = "agency.txt";
const std::string SEPARATOR = "::::::::::";
const unsigned char TABLE_PADDING = 1;

bool clear();
std::vector<std::string> split(std::string str, std::string delimiter);
std::string lower(std::string s);
void pause();
std::string lstrip(std::string s);
std::string rstrip(std::string s);
std::string strip(std::string s);
std::vector<std::string> strip(std::vector<std::string> s);