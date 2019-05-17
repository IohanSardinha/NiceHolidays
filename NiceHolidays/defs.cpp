#pragma once
#include "defs.h"

using namespace std;

bool clear() {
	if (PLATFORM_NAME == "linux") {
		cout << "\033[2J\033[1;1H";
	}
	else if (PLATFORM_NAME == "windows") {
		system("cls");
	}
	else {
		return false;
	}
	return true;
}

//Splits a string by a specific delimiter and puts it into a vector
vector<string> split(string str, string delimiter)
{
	if (str.empty() || str.find(delimiter) == str.npos)
	{
		return { str };
	}
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

string lower(string s)
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

void pause()
{
	string s;
	cout << "Press enter to continue...";
	getline(cin, s);
}

string lstrip(string s) {
	int i = 0;
	if (s.length() == 0) {
		return "";
	}
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '	') {
		i++;
	}
	return s.substr(i);
}

string rstrip(string s) {
	int i = s.length() - 1;
	if (s.length() == 0) {
		return "";
	}
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '	') {
		i--;
	}
	return s.substr(0, i + 1);
}

string strip(string s) {
	string result = lstrip(s);
	result = rstrip(result);
	return result;
}

vector<string> strip(vector<string> s) {
	for (unsigned i = 0; i < s.size(); ++i) {
		s.at(i) = strip(s.at(i));
	}
	return s;
}