#include "Address.h"


Address::Address() {
}

Address::Address(string street, unsigned short doorNumber, string floor, string postalCode, string location) {

	// REQUIRES IMPLEMENTATION
}

// metodos GET


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


// metodos SET

void Address::setStreet(string street) {

	this->street = street;
}

void Address::setDoorNumber(unsigned short doorNumber) {

	this->doorNumber = doorNumber;
}

void Address::setFloor(string floor) {

	this->floor = floor;
}

void Address::setPostalCode(string postalCode) {

	this->postalCode = postalCode;
}

void Address::setLocation(string  location) {

	this->location = location;
}


/*********************************
* Mostrar Address
********************************/

// discplyes an address in a nice format
ostream& operator<<(ostream& out, const Address & address) {

	// REQUIRES IMPLEMENTATION

}
