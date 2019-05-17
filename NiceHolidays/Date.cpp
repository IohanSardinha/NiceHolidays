#pragma once
#pragma warning(disable : 4996) //_CRT_SECURE_NO_WARNINGS
#include "Date.h"
// ----------------------------------------------------------------------------------------
//                                       Constructors
// ----------------------------------------------------------------------------------------
Date::Date() {
	time_t t = time(0);
	year = localtime(&t) -> tm_year + 1900;
	month = localtime(&t) -> tm_mon + 1;
	day = localtime(&t) -> tm_mday;
}
Date::Date(unsigned short d) {
	time_t t = time(0);
	unsigned y = localtime(&t) -> tm_year + 1900;
	unsigned short m = localtime(&t) -> tm_mon + 1;
	if (validDate(d, m, y)){
		year = y;
		month = m;
		day = d;
	}
}
Date::Date(unsigned short d, unsigned short m) {
	time_t t = time(0);
	unsigned y = localtime(&t) -> tm_year + 1900;
	if (validDate(d, m, y)){
		year = y;
		month = m;
		day = d;
	}
}
Date::Date(unsigned short d, unsigned short m, unsigned y) {
	if (validDate(d, m, y)){
		year = y;
		month = m;
		day = d;
	}
}
Date::Date(string s) {
	unsigned y = stoi(s.substr(0, 4));
	unsigned short m = stoi(s.substr(5, 2));
	unsigned short d = stoi(s.substr(8, 2));
	if (validDate(d, m, y)){
		year = y;
		month = m;
		day = d;
	}
}
// ----------------------------------------------------------------------------------------
//                                           Gets                                          
// ----------------------------------------------------------------------------------------
unsigned Date::getYear() const {
	return year;
}
unsigned short Date::getMonth() const {
	return month;
}
unsigned short Date::getDay() const {
	return day;
}
// ----------------------------------------------------------------------------------------
//                                           Sets                                          
// ----------------------------------------------------------------------------------------
bool Date::setDay(unsigned short d) {
	if (!validDate(d, month, year))
		return false;
	day = d;
	return true;
}
bool Date::setMonth(unsigned short m) {
	if (!validDate(day, m, year))
		return false;
	month = m;
	return true;
}
bool Date::setYear(unsigned y) {
	if (!validDate(day, month, y))
		return false;
	year = y;
	return true;
}
// ----------------------------------------------------------------------------------------
//                                  Input Output Functions                                 
// ----------------------------------------------------------------------------------------
ostream& operator<<(ostream& out, const Date& date) {
	out << str(date);
	return out;
}
// ----------------------------------------------------------------------------------------
//                                      Date Operators
// ----------------------------------------------------------------------------------------
Date Date::operator+(unsigned n) const {
	unsigned res = abs(* this);
	return date(res + n);
}
Date Date::operator-(unsigned n) const {
	unsigned res = abs(* this);
	return date(res - n);
}
void Date::operator+=(unsigned n) {
	unsigned aux = abs(* this);
	Date res = date(aux + n);
	day = res.getDay();
	month = res.getMonth();
	year = res.getYear();
}
void Date::operator-=(unsigned n) {
	*this += -(int)n;
}
int Date::operator-(const Date param) const {
	Date x(day, month, year);
	unsigned actual = abs(x);
	int res = actual - abs(param);
	return res;
}
bool Date::operator==(const Date param) const {
	bool res = true;
	res = res && (year == param.getYear());
	res = res && (month == param.getMonth());
	res = res && (day == param.getDay());
	return res;
}
bool Date::operator<(const Date param) const {
	return abs(* this) < abs(param);
}
bool Date::operator>(const Date param) const {
	return abs(* this) > abs(param);
}
bool Date::operator<=(const Date param) const {
	return abs(* this) <= abs(param);
}
bool Date::operator>=(const Date param) const {
	return abs(* this) >= abs(param);
}
bool Date::operator!= (const Date param) const {
	return !(* this == param);
}
// ----------------------------------------------------------------------------------------
//                                      Date Functions
// ----------------------------------------------------------------------------------------
unsigned abs(const Date date) {
	unsigned y = date.getYear();
	unsigned short m = date.getMonth();
	unsigned short d = date.getDay();
	unsigned total = 0;
	for (unsigned i = epoch; i < y; i++){
		total += daysYear(i);
	}
	for (unsigned i = 1; i < m; ++i){
		total += daysMonth(i);
	}
	if (bissextile(y)){
		total++;
	}
	total += d;
	return total;
}
Date date(unsigned days) {
	unsigned y = epoch;
	unsigned short m = 1;
	while (days > daysYear(y)){
		days -= daysYear(y++);
	}
	if (days > 31){
		days -= daysMonth(m++);
		if (days > 28){
			if (bissextile(y)){
				days -= daysMonth(m++) + 1;
			}else{
				days -= daysMonth(m++);
			}
			while(days > daysMonth(m)){
				days -= daysMonth(m++);
			}
		}else{
			if (bissextile(y)){
				days--;
			}
		}
	}else{
		if (bissextile(y)){
			days--;
		}
	}
	Date result(days, m, y);
	return result;
}
// ----------------------------------------------------------------------------------------
//                                    Auxiliary Functions
// ----------------------------------------------------------------------------------------
string str(Date date) {
	const char zero = '0';
	string aux = to_string(date.getDay());
	string d = string((2 - aux.size()),zero) + aux;
	aux = to_string(date.getMonth());
	string m = string((2 - aux.size()),zero) + aux;
	aux = to_string(date.getYear());
	string y = string((4 - aux.size()),zero) + aux;
	return y + "/" + m + "/" + d;
}
bool bissextile(unsigned year) {
	if (year % 4 == 0){
		if (year % 100 != 0 || year % 400 == 0) {
			return true;
		}
	}
	return false;
}
unsigned short daysMonth(unsigned short month) {
	if (month < 8){
		if (month % 2 == 1){
			return 31;
		}else if(month != 2){
			return 30;
		}else{
			return 28;
		}
	} else {
		if (month % 2 == 0){
			return 31;
		}else{
			return 30;
		}
	}
}
unsigned daysYear(unsigned year) {
	if (bissextile(year)){
		return 366;
	}else{
		return 365;
	}
}
bool validDate(unsigned short d, unsigned short m, unsigned y) {
	if (d <= 0 || m <= 0 || y == 0){
		return false;
	}
	if (d == 29 && m == 2){
		return bissextile(y);
	}
	return d <= daysMonth(m);
}