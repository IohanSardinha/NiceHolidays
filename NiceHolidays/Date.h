#pragma once
#include <ctime>
#include <iostream>
#include <stdexcept>
#include <string>
#include "utils.h"
using namespace std;
int epoch = 2000;
class Date {														// Class that represents a date (day, month and year)
	private:														// Private methods and atributes
		unsigned short day, month;
		unsigned year;												// Parts of the date
	public:															// Public methods and atributes
		inline Date();														// Constructor that makes the date equal now
		inline Date(unsigned short);										// Constructor for a day in this month
		inline Date(unsigned short, unsigned short);						// Constructor for a day and month of this year
		inline Date(unsigned short, unsigned short, unsigned);				// Constructor for a date
		inline Date(string);												// Constructor for a date from a string in the form yyyy/mm/dd
		inline unsigned short getDay() const;								// Returns the day of the date
		inline unsigned short getMonth() const;							// Returns the month of the date
		inline unsigned getYear() const;									// Returns the year of the date
		inline bool setDay(unsigned short);								// Changes the day of the date, returns false if the date is not possible
		inline bool setMonth(unsigned short);								// Changes the month of the date, returns false if the date is not possible
		inline bool setYear(unsigned);										// Changes the year of the date, returns false if the date is not possible
		inline friend ostream& operator<<(ostream&, const Date&);			// 
		inline Date operator+(unsigned) const;								// Returns n days after the date
		inline Date operator-(unsigned) const;								// Returns n days before the date
		inline void operator+=(unsigned);									// Turns the date into the date after n days
		inline void operator-=(unsigned);									// Turns the date into the date before n days
		inline int operator-(const Date) const;							// Returns the difference of two dates in days
		inline bool operator==(const Date) const;							// Verifies if the date is igual to the parameter
		inline bool operator<(const Date) const;							// Verifies if the date is before the parameter
		inline bool operator>(const Date) const;							// Verifies if the date is after the parameter
		inline bool operator<=(const Date) const;							// Verifies if the date is before or equal the parameter
		inline bool operator>=(const Date) const;							// Verifies if the date is after or equal the parameter
		inline bool operator!=(const Date) const;							// Verifies if the date is different from the parameter
};
inline string str(Date date);												// Returns a date in the format dd/mm/yyyy
inline bool bissextile(unsigned year);										// Verify if the year is bissextile
inline bool validDate(unsigned short d, unsigned short m, unsigned y);		// Verify if it is a possible date on Gregorian Calendar
inline unsigned short daysMonth(unsigned short month);						// Returns the number of days of a month of a non leap year (Jan = 1 and Dec = 12)
unsigned daysYear(unsigned year);									// Returns the number of days of a year (365 or 366)
unsigned abs(const Date date);										// Returns the number of days from the epoch to the date
Date date(unsigned days);											// Calculates the date from the number of days from epoch