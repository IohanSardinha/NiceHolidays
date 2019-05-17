#pragma once
#include "Table.h"
// ----------------------------------------------------------------------------------------
//                                       Constructors
// ----------------------------------------------------------------------------------------
Table::Table(vector<string> h, vector<vector<string>> c) {
	header = h;
	content = c;
}
// ----------------------------------------------------------------------------------------
//                                           Gets                                          
// ----------------------------------------------------------------------------------------
vector<string> Table::getHeader() const {
	return header;
}
vector<vector<string>> Table::getContent() const {
	return content;
}
// ----------------------------------------------------------------------------------------
//                                           Sets                                          
// ----------------------------------------------------------------------------------------
bool Table::setHeader(vector<string> h) {
	header = h;
	return true;
}
bool Table::setContent(vector<vector<string>> c) {
	content = c;
	return true;
}
// ----------------------------------------------------------------------------------------
//                                  Input Output Functions                                 
// ----------------------------------------------------------------------------------------
ostream& operator<<(ostream& out, const Table& table) {
	out << str(table);
	return out;
}
// ----------------------------------------------------------------------------------------
//                                    Auxiliary Functions
// ----------------------------------------------------------------------------------------
string normalize(string s, unsigned n) {
	unsigned diff = n - s.length();
	string result;
	const char space = ' ';
	if (diff % 2 == 0){
		diff /= 2;
		result += string(diff,space);
		result += s;
		result += string(diff, space);
	}else{
		diff /= 2;
		result += string(diff+1, space);
		result += s;
		result += string(diff, space);
	}
	return result;
}
string str(Table table) {
	string res = "";
	string padding = string(TABLE_PADDING,' ');
	unsigned rows = table.getContent().size();
	unsigned cols = table.getContent().at(0).size();
	vector<unsigned> sizes(cols);
	for(unsigned i = 0; i < rows; ++i){
		for(unsigned j = 0; j < cols; ++j){
			if (table.getContent().at(i).at(j).length() > sizes.at(j)){
				sizes.at(j) = table.getContent().at(i).at(j).length();
			}
		}
	}
	for(unsigned i = 0; i < cols; ++i){
		if (table.getHeader().at(i).length() > sizes.at(i)){
			sizes.at(i) = table.getHeader().at(i).length();
		}
	}
	string line = "+";
	for (unsigned i = 0; i < sizes.size(); ++i){
		line += string((sizes.at(i) + padding.size() * 2),'-') + "+";
	}
	res += line + '\n';
	for(unsigned j = 0; j < cols; ++j){
		res += "|" + padding + normalize(table.getHeader().at(j), sizes.at(j)) + padding;
	}
	res += "|\n" + line + "\n";
	for(unsigned i = 0; i < rows; ++i){
		for(unsigned j = 0; j < cols; ++j){
			res += "|" + padding + normalize(table.getContent().at(i).at(j), sizes.at(j)) + padding;
		}
		res += "|\n";
	}
	res += line + '\n';
	return res;
}