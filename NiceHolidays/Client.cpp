#pragma once
#include "Client.h"
// ----------------------------------------------------------------------------------------
//                                       Constructors
// ----------------------------------------------------------------------------------------

Client::Client(){}

Client::Client(string name, unsigned VATnumber, unsigned short familySize, Address address) {
	this -> name = name;
	this -> VATnumber = VATnumber;
	this -> familySize = familySize;
	this -> address = address;
	this -> packets = {};
	this -> totalPurchased = 0;
}
Client::Client(string name, unsigned VATnumber, unsigned short familySize, Address address, vector<Packet>& packets, unsigned totalPurchased) {
	this -> name = name;
	this -> VATnumber = VATnumber;
	this -> familySize = familySize;
	this -> address = address;
	this -> packets = packets;
	this -> totalPurchased = totalPurchased;
}
// ----------------------------------------------------------------------------------------
//                                           Gets                                          
// ----------------------------------------------------------------------------------------
string Client::getName() const {
	return name;
}
unsigned Client::getVATnumber() const {
	return VATnumber;
}
unsigned short Client::getFamilySize() const {
	return familySize;
}
Address Client::getAddress() const {
	return address;
}
vector<Packet> Client::getPacketList() const {
	return packets;
}
unsigned Client::getTotalPurchased() const {
	return totalPurchased;
}
// ----------------------------------------------------------------------------------------
//                                           Sets                                          
// ----------------------------------------------------------------------------------------
bool Client::setName(string name) {
	this -> name = name;
	return true;
}
bool Client::setVATnumber(unsigned VATnumber) {
	this -> VATnumber = VATnumber;
	return true;
}
bool Client::setFamilySize(unsigned short familySize) {
	this -> familySize = familySize;
	return true;
}
bool Client::setAddress(Address address) {
	this -> address = address;
	return true;
}
bool Client::setPacketList(vector<Packet>& packets) {
	this -> packets = packets;
	return true;
}
bool Client::setTotalPurchased(unsigned totalPurchased) {
	this -> totalPurchased = totalPurchased;
	return true;
}
// ----------------------------------------------------------------------------------------
//                                  Input Output Functions                                 
// ----------------------------------------------------------------------------------------
ostream& operator<<(ostream& out, const Client& client) {
	out << str(client);
	return out;
}
ofstream& operator<<(ofstream& out, const Client& client) {
	out << client.getName() << '\n';
	out << client.getVATnumber() << '\n';
	out << client.getFamilySize() << '\n';
	out << client.getAddress() << '\n';
	bool first = true;
	double packetsValue = 0;
	for (auto x : client.getPacketList()){
		if (first)
			first = false;
		else
			out << " ; ";
		out << x.getId();
		packetsValue += x.getPricePerPerson() * client.getFamilySize();
	}
	out << '\n';
	out << packetsValue;
	return out;
}
// ----------------------------------------------------------------------------------------
//                                    Auxiliary Functions
// ----------------------------------------------------------------------------------------
string str(Client client) {
	ostringstream res;
	res << "Name       : " << client.getName() << '\n';
	res << "VAT Number : " << client.getVATnumber() << '\n';
	res << "Family size: " << client.getFamilySize() << '\n';
	res << "Address    : " << client.getAddress() << '\n';
	res << "Packets    : ";
	bool first = true;
	for (auto x : client.getPacketList()){
		if (first)
			first = false;
		else
			res << ", ";
		res << x.getId();
	}
	return res.str();
}