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
	public:															// 
		Address();													// 
		Address(string, unsigned short, string, string, string);	// 
		string getStreet() const;									// 
		unsigned short getDoorNumber() const;						// 
		string getFloor() const;									// 
		string getPostalCode() const;								// 
		string getLocation() const;									// 
		bool setStreet(string);										// 
		bool setDoorNumber(unsigned short);							// 
		bool setFloor(string);										// 
		bool setPostalCode(string);									// 
		bool setLocation(string);									// 
		friend ostream& operator<<(ostream&, const Address&);		// 
		friend ofstream& operator<<(ofstream&, const Address&);		// 
};
string str(Address address);