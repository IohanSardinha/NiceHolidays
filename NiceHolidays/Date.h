#pragma once
#include <ctime>
#include <iostream>
#include <stdexcept>
#include <string>
#define epoch 1900
using namespace std;
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