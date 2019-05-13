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
		inline Table();												// 
		inline Table(vector<string>, vector<vector<string>>);		// 
		inline vector<string> getHeader() const;					//
		inline vector<vector<string>> getContent() const;			//
		inline bool setHeader(vector<string>);						//
		inline bool setContent(vector<vector<string>>);				//
		inline friend ostream& operator<<(ostream&, const Table&);	// 
};
inline string normalize(string s, unsigned n);								//
inline string str(Table table);