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
// ----------------------------------------------------------------------------------------
//                                       Constructors
// ----------------------------------------------------------------------------------------
Address::Address(string s, unsigned short n, string f, string c, string l){
	street = s;
	doorNumber = n;
	floor = f;
	postalCode = c;
	location = l;
}
// ----------------------------------------------------------------------------------------
//                                           Gets                                          
// ----------------------------------------------------------------------------------------
string Address::getStreet() const{
	return street;
}
unsigned short Address::getDoorNumber() const{
	return doorNumber;
}
string Address::getFloor() const{
	return floor;
}
string Address::getPostalCode() const{
	return postalCode;
}
string Address::getLocation() const{
	return location;
}
// ----------------------------------------------------------------------------------------
//                                           Sets                                          
// ----------------------------------------------------------------------------------------
bool Address::setStreet(string street){
	this -> street = street;
	return true;
}
bool Address::setDoorNumber(unsigned short doorNumber){
	this -> doorNumber = doorNumber;
	return true;
}
bool Address::setFloor(string floor){
	this -> floor = floor;
	return true;
}
bool Address::setPostalCode(string postalCode){
	this -> postalCode = postalCode;
	return true;
}
bool Address::setLocation(string location){
	this -> location = location;
	return true;
}
// ----------------------------------------------------------------------------------------
//                                  Input Output Functions                                 
// ----------------------------------------------------------------------------------------
ostream& operator<<(ostream& out, const Address& address){
	out << str(address);
	return out;
}
ofstream& operator<<(ofstream& out, const Address& address){
	out << address.getStreet() << " / ";
	out << address.getDoorNumber() << " / ";
	out << address.getFloor() << " / ";
	out << address.getPostalCode() << " / ";
	out << address.getLocation();
	return out;
}
string str(Address address){
	ostringstream res;
	res << address.getStreet() << ", ";
	res << address.getDoorNumber();
	if (address.getFloor() != "-"){
		res << " " << address.getFloor();
	}
	res << ", ";
	res << address.getLocation() << ", ";
	res << address.getPostalCode();
	return res.str();
}