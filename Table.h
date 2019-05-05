#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "defs.h"
#include "utils.h"
using namespace std;
class Table{
	private:
		vector<string> header;										//
		vector<vector<string>> content;								//
	public:
		Table();													// 
		Table(vector<string>, vector<vector<string>>);				// 
		vector<string> getHeader() const;
		vector<vector<string>> getContent() const;
		bool setHeader(vector<string>);
		bool setContent(vector<vector<string>>);
		friend ostream& operator<<(ostream&, const Table&);			// 
};
string normalize(string s, unsigned n);								//
string str(Table table);