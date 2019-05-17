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

bool clear();																//Clear the screen taking account the correct command for both linux and windos systems
std::vector<std::string> split(std::string str, std::string delimiter);		//Divides a given string by a delimitter and putting in a vector
std::string lower(std::string s);											//Turns a string in all lower case
void pause();																//Pauses the execution of the program untill the user presses enter
std::string lstrip(std::string s);											//Remove blank spaces on the left of a string
std::string rstrip(std::string s);											//Remove blank spaces on the right of a string
std::string strip(std::string s);											//Remove blank spaces on both left and right of a string
std::vector<std::string> strip(std::vector<std::string> s);					//Remove blank spaces on both left and right in all elements of a list of strings