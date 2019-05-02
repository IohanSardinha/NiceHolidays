#include <iostream>
#include <string>
#include <ctime>
int epoch = 2000;
class Date {								// Class that represents a date (day, month and year)
	public:									// Public methods and atributes
		Date();								// Constructor that makes the date equal now
		Date(int);							// Constructor for a day in this month
		Date(int, int);						// Constructor for a day and month of this year
		Date(int, int, int);				// Constructor for a date
		Date(std::string);					// Constructor for a date from a string in the form yyyy/mm/dd
		int getDay() const;					// Returns the day of the date
		int getMonth() const;				// Returns the month of the date
		int getYear() const;				// Returns the year of the date
		void show() const;					// Procedure that prints the date
		Date operator+(int) const;			// Returns n days after the date
		Date operator-(int) const;			// Returns n days before the date
		void operator+=(int);				// Turns the date into the date after n days
		void operator-=(int);				// Turns the date into the date before n days
		int operator-(const Date) const;	// Returns the difference of two dates in days
		bool operator==(const Date) const;	// Verifies if the date is igual to the parameter
		bool operator<(const Date) const;	// Verifies if the date is before the parameter
		bool operator>(const Date) const;	// Verifies if the date is after the parameter
		bool operator<=(const Date) const;	// Verifies if the date is before or equal the parameter
		bool operator>=(const Date) const;	// Verifies if the date is after or equal the parameter
		bool operator!=(const Date) const;	// Verifies if the date is different from the parameter
	private:								// Private methods and atributes
		int day, month, year;				// Parts of the date
};
bool bissextile(int year);					// Verify if the year is bissextile
bool validDate(int d, int m, int y);		// Verify if it is a possible date on Gregorian Calendar
int daysMonth(int month);					// Returns the number of days of a month of a non leap year (Jan = 1 and Dec = 12)
int daysYear(int year);						// Returns the number of days of a year (365 or 366)
int abs(const Date date);					// Returns the number of days from the epoch to the date
Date date(int days);						// Calculates the date from the number of days from epoch
std::string str(Date date);					// Returns a date in the format dd/mm/yyyy
std::string multiplyChar(char c, int n);	// Returns a string formed by n times the char c
// ----------------------------------------------------------------------------------------
//                                      Date Functions                                     
// ----------------------------------------------------------------------------------------
int abs(const Date date){
	int y = date.getYear();
	int m = date.getMonth();
	int d = date.getDay();
	int total = 0;
	for (int i = epoch; i < y; i++){
		total += daysYear(i);
	}
	for (int i = 1; i < m; ++i){
		total += daysMonth(i);
	}
	if (bissextile(y)){
		total++;
	}
	total += d;
	return total;
}
Date date(int days){
	int y = epoch, m = 1;
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
//                                      Date Operators                                     
// ----------------------------------------------------------------------------------------
Date Date::operator+(int n) const{
	int res = abs(* this);
	return date(res + n);
}
Date Date::operator-(int n) const{
	int res = abs(* this);
	return date(res - n);
}
void Date::operator+=(int n){
	int aux = abs(* this);
	Date res = date(aux + n);
	day = res.getDay();
	month = res.getMonth();
	year = res.getYear();
}
void Date::operator-=(int n){
	*this += -n;
}
int Date::operator-(const Date param) const{
	Date x(day, month, year);
	int actual = abs(x);
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
//                                      Gets and Shows                                     
// ----------------------------------------------------------------------------------------
std::string str(Date date){
	std::string aux = std::to_string(date.getDay());
	std::string res = multiplyChar('0', 2 - aux.size()) + aux + "/";
	aux = std::to_string(date.getMonth());
	res += multiplyChar('0', 2 - aux.size()) + aux + "/";
	aux = std::to_string(date.getYear());
	res += multiplyChar('0', 4 - aux.size()) + aux;
	return res;
}
int Date::getYear() const{
	return year;
}
int Date::getMonth() const{
	return month;
}
int Date::getDay() const{
	return day;
}
void Date::show() const{
	std::cout << str(*this);
}
// ----------------------------------------------------------------------------------------
//                                       Constructors                                      
// ----------------------------------------------------------------------------------------
Date::Date(){
	std::time_t t = std::time(0);
	year = std::localtime(&t) -> tm_year + 1900;
	month = std::localtime(&t) -> tm_mon + 1;
	day = std::localtime(&t) -> tm_mday;
}
Date::Date(int d){
	std::time_t t = std::time(0);
	year = std::localtime(&t) -> tm_year + 1900;
	month = std::localtime(&t) -> tm_mon + 1;
	day = d;
}
Date::Date(int d, int m){
	std::time_t t = std::time(0);
	year = std::localtime(&t) -> tm_year + 1900;
	month = m;
	day = d;
}
Date::Date(int d, int m, int y){
	year = y;
	month = m;
	day = d;
}
Date::Date(std::string s){
	year = std::stoi(s.substr(0, 4));
	month = std::stoi(s.substr(5, 2));
	day = std::stoi(s.substr(8, 2));
}
// ----------------------------------------------------------------------------------------
//                                    Auxiliary Functions                                  
// ----------------------------------------------------------------------------------------
bool bissextile(int year){
	if (year % 4 == 0){
		if (year % 100 != 0 || year % 400 == 0) {
			return true;
		}
	}
	return false;
}
int daysMonth(int month){
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
int daysYear(int year){
	if (bissextile(year)){
		return 366;
	}else{
		return 365;
	}
}
bool validDate(int d, int m, int y){
	if (d <= 0 || m <= 0 || y == 0){
		return false;
	}
	if (d == 29 && m == 2){
		return bissextile(y);
	}
	return d <= daysMonth(m);
}
std::string multiplyChar(char c, int n){
	std::string result = "";
	for (int i = 0; i < n; ++i){
		result.push_back(c);
	}
	return result;
}