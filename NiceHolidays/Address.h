#pragma once
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include "defs.h"
using namespace std;
class Address{
	private:
		string street; 												// street name
		unsigned short doorNumber; 									// door number
		string floor; 												// floor number ("-" is not applicable)
		string postalCode; 											// postal code
		string location; 											// site
	public:
		Address();													// Empty Constructor 
		Address(vector<string>);									// Constructor from a vector
		Address(string, unsigned short, string, string, string);	// Constructor from filtered data
		string getStreet() const;									// Returns the street
		unsigned short getDoorNumber() const;						// Returns the number
		string getFloor() const;									// Returns the floor
		string getPostalCode() const;								// Returns the postal code
		string getLocation() const;									// Returns location
		bool setStreet(string);										// Sets street
		bool setDoorNumber(unsigned short);							// Sets number
		bool setFloor(string);										// Sets floor
		bool setPostalCode(string);									// Sets postal code
		bool setLocation(string);									// Sets location
		friend ostream& operator<<(ostream&, const Address&);		// Prints an address in a nice way
		friend ofstream& operator<<(ofstream&, const Address&);		// Puts a formated address in a file
};
string str(Address address);