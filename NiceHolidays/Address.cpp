#pragma once
#include "Address.h"


// ----------------------------------------------------------------------------------------
//                                       Constructors
// ----------------------------------------------------------------------------------------
Address::Address() {
	street = "Unnamed Street";
	doorNumber = 0;
	floor = "";
	postalCode = "0000-000";
	location = "Unnamed Location";
}

Address::Address(vector<string> aux)
{
	street = aux.at(0);
	doorNumber = stoi(aux.at(1));
	if (strip(aux.at(2)) == "-")
		floor = "";
	else
		floor = aux.at(2);
	postalCode = aux.at(3);
	location = aux.at(4);
}

Address::Address(string s, unsigned short n, string f, string c, string l) {
	street = s;
	doorNumber = n;
	if (f == "-")
		floor = "";
	else
		floor = f;
	postalCode = c;
	location = l;
}
// ----------------------------------------------------------------------------------------
//                                           Gets                                          
// ----------------------------------------------------------------------------------------
string Address::getStreet() const {
	return street;
}
unsigned short Address::getDoorNumber() const {
	return doorNumber;
}
string Address::getFloor() const {
	return floor;
}
string Address::getPostalCode() const {
	return postalCode;
}
string Address::getLocation() const {
	return location;
}
// ----------------------------------------------------------------------------------------
//                                           Sets                                          
// ----------------------------------------------------------------------------------------
bool Address::setStreet(string street) {
	this -> street = street;
	return true;
}
bool Address::setDoorNumber(unsigned short doorNumber) {
	this -> doorNumber = doorNumber;
	return true;
}
bool Address::setFloor(string floor) {
	if (floor == "-")
		this -> floor = "";
	else
		this -> floor = floor;
	return true;
}
bool Address::setPostalCode(string postalCode) {
	this -> postalCode = postalCode;
	return true;
}
bool Address::setLocation(string location) {
	this -> location = location;
	return true;
}
// ----------------------------------------------------------------------------------------
//                                  Input Output Functions                                 
// ----------------------------------------------------------------------------------------
ostream& operator<<(ostream& out, const Address& address) {
	out << str(address);
	return out;
}
ofstream& operator<<(ofstream& out, const Address& address) {
	out << address.getStreet();
	out << address.getDoorNumber() << " / ";
	out << address.getFloor() << " / ";
	out << address.getPostalCode() << " / ";
	out << address.getLocation();
	return out;
}
string str(Address address) {
	ostringstream res;
	res << address.getStreet() << ", ";
	res << address.getDoorNumber();
	if (address.getFloor() != "-"){
		res << "" << address.getFloor();
	}
	res << ", ";
	res << address.getLocation() << ", ";
	res << address.getPostalCode();
	return res.str();
}