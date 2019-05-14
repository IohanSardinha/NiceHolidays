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
		inline Address();													// 
		inline Address(string);
		inline Address(string, unsigned short, string, string, string);	// 
		inline string getStreet() const;									// 
		inline unsigned short getDoorNumber() const;						// 
		inline string getFloor() const;									// 
		inline string getPostalCode() const;								// 
		inline string getLocation() const;									// 
		inline bool setStreet(string);										// 
		inline bool setDoorNumber(unsigned short);							// 
		inline bool setFloor(string);										// 
		inline bool setPostalCode(string);									// 
		inline bool setLocation(string);									// 
		inline friend ostream& operator<<(ostream&, const Address&);		// 
		inline friend ofstream& operator<<(ofstream&, const Address&);		// 
};
inline string str(Address address);