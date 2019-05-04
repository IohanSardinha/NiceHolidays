#pragma once
#include <ctime>
#include <iostream>
#include <string>
#include "utils.h"
using namespace std;
int epoch = 2000;
class Date {														// Class that represents a date (day, month and year)
	private:														// Private methods and atributes
		unsigned short day, month;
		unsigned year;												// Parts of the date
	public:															// Public methods and atributes
		Date();														// Constructor that makes the date equal now
		Date(unsigned short);										// Constructor for a day in this month
		Date(unsigned short, unsigned short);						// Constructor for a day and month of this year
		Date(unsigned short, unsigned short, unsigned);				// Constructor for a date
		Date(string);												// Constructor for a date from a string in the form yyyy/mm/dd
		unsigned short getDay() const;								// Returns the day of the date
		unsigned short getMonth() const;							// Returns the month of the date
		unsigned getYear() const;									// Returns the year of the date
		bool setDay(unsigned short);								// Changes the day of the date, returns false if the date is not possible
		bool setMonth(unsigned short);								// Changes the month of the date, returns false if the date is not possible
		bool setYear(unsigned);										// Changes the year of the date, returns false if the date is not possible
		friend ostream& operator<<(ostream&, const Date&);			// 
		Date operator+(unsigned) const;								// Returns n days after the date
		Date operator-(unsigned) const;								// Returns n days before the date
		void operator+=(unsigned);									// Turns the date into the date after n days
		void operator-=(unsigned);									// Turns the date into the date before n days
		int operator-(const Date) const;							// Returns the difference of two dates in days
		bool operator==(const Date) const;							// Verifies if the date is igual to the parameter
		bool operator<(const Date) const;							// Verifies if the date is before the parameter
		bool operator>(const Date) const;							// Verifies if the date is after the parameter
		bool operator<=(const Date) const;							// Verifies if the date is before or equal the parameter
		bool operator>=(const Date) const;							// Verifies if the date is after or equal the parameter
		bool operator!=(const Date) const;							// Verifies if the date is different from the parameter
};
string str(Date date);												// Returns a date in the format dd/mm/yyyy
bool bissextile(unsigned year);										// Verify if the year is bissextile
bool validDate(unsigned short d, unsigned short m, unsigned y);		// Verify if it is a possible date on Gregorian Calendar
unsigned short daysMonth(unsigned short month);						// Returns the number of days of a month of a non leap year (Jan = 1 and Dec = 12)
unsigned daysYear(unsigned year);									// Returns the number of days of a year (365 or 366)
unsigned abs(const Date date);										// Returns the number of days from the epoch to the date
Date date(unsigned days);											// Calculates the date from the number of days from epoch
// ----------------------------------------------------------------------------------------
//                                       Constructors
// ----------------------------------------------------------------------------------------
Date::Date(){
	time_t t = time(0);
	year = localtime(&t) -> tm_year + 1900;
	month = localtime(&t) -> tm_mon + 1;
	day = localtime(&t) -> tm_mday;
}
Date::Date(unsigned short d){
	time_t t = time(0);
	year = localtime(&t) -> tm_year + 1900;
	month = localtime(&t) -> tm_mon + 1;
	day = d;
}
Date::Date(unsigned short d, unsigned short m){
	time_t t = time(0);
	year = localtime(&t) -> tm_year + 1900;
	month = m;
	day = d;
}
Date::Date(unsigned short d, unsigned short m, unsigned y){
	year = y;
	month = m;
	day = d;
}
Date::Date(string s){
	year = stoi(s.substr(0, 4));
	month = stoi(s.substr(5, 2));
	day = stoi(s.substr(8, 2));
}
// ----------------------------------------------------------------------------------------
//                                           Gets                                          
// ----------------------------------------------------------------------------------------
unsigned Date::getYear() const{
	return year;
}
unsigned short Date::getMonth() const{
	return month;
}
unsigned short Date::getDay() const{
	return day;
}
// ----------------------------------------------------------------------------------------
//                                           Sets                                          
// ----------------------------------------------------------------------------------------
bool Date::setDay(unsigned short d){
	if (!validDate(d, month, year))
		return false;
	day = d;
	return true;
}
bool Date::setMonth(unsigned short m){
	if (!validDate(day, m, year))
		return false;
	month = m;
	return true;
}
bool Date::setYear(unsigned y){
	if (!validDate(day, month, y))
		return false;
	year = y;
	return true;
}
// ----------------------------------------------------------------------------------------
//                                  Input Output Functions                                 
// ----------------------------------------------------------------------------------------
ostream& operator<<(ostream& out, const Date& date){
	out << str(date);
	return out;
}
// ----------------------------------------------------------------------------------------
//                                      Date Operators
// ----------------------------------------------------------------------------------------
Date Date::operator+(unsigned n) const{
	unsigned res = abs(* this);
	return date(res + n);
}
Date Date::operator-(unsigned n) const{
	unsigned res = abs(* this);
	return date(res - n);
}
void Date::operator+=(unsigned n){
	unsigned aux = abs(* this);
	Date res = date(aux + n);
	day = res.getDay();
	month = res.getMonth();
	year = res.getYear();
}
void Date::operator-=(unsigned n){
	*this += -n;
}
int Date::operator-(const Date param) const{
	Date x(day, month, year);
	unsigned actual = abs(x);
	int res = actual - abs(param);
	return res;
}
bool Date::operator==(const Date param) const{
	bool res = true;
	res = res && (year == param.getYear());
	res = res && (month == param.getMonth());
	res = res && (day == param.getDay());
	return res;
}
bool Date::operator<(const Date param) const{
	return abs(* this) < abs(param);
}
bool Date::operator>(const Date param) const{
	return abs(* this) > abs(param);
}
bool Date::operator<=(const Date param) const{
	return abs(* this) <= abs(param);
}
bool Date::operator>=(const Date param) const{
	return abs(* this) >= abs(param);
}
bool Date::operator!= (const Date param) const{
	return !(* this == param);
}
// ----------------------------------------------------------------------------------------
//                                      Date Functions
// ----------------------------------------------------------------------------------------
unsigned abs(const Date date){
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
Date date(unsigned days){
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
string str(Date date){
	string zero = "0";
	string aux = to_string(date.getDay());
	string d = zero * (2 - aux.size()) + aux;
	aux = to_string(date.getMonth());
	string m = zero * (2 - aux.size()) + aux;
	aux = to_string(date.getYear());
	string y = zero * (4 - aux.size()) + aux;
	return y + "/" + m + "/" + d;
}
bool bissextile(unsigned year){
	if (year % 4 == 0){
		if (year % 100 != 0 || year % 400 == 0) {
			return true;
		}
	}
	return false;
}
unsigned short daysMonth(unsigned short month){
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
unsigned daysYear(unsigned year){
	if (bissextile(year)){
		return 366;
	}else{
		return 365;
	}
}
bool validDate(unsigned short d, unsigned short m, unsigned y){
	if (d <= 0 || m <= 0 || y == 0){
		return false;
	}
	if (d == 29 && m == 2){
		return bissextile(y);
	}
	return d <= daysMonth(m);
}