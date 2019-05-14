#pragma once
#include "Agency.h"
// ----------------------------------------------------------------------------------------
//                                       Constructors
// ----------------------------------------------------------------------------------------
Agency::Agency(string fileName){

  //  IMPLEMENTATION REQUIRED 
}
// ----------------------------------------------------------------------------------------
//                                           Gets                                          
// ----------------------------------------------------------------------------------------
string Agency::getName() const{
	return name;
}
unsigned Agency::getVATnumber() const{
	return VATnumber;
}
Address Agency::getAddress() const{
	return address;
}
string Agency::getURL() const{
	return URL;
}
vector<Client> Agency::getClients() const{
	return clients;
}
vector<Packet> Agency::getPackets() const{
	return packets;
}
// ----------------------------------------------------------------------------------------
//                                           Sets                                          
// ----------------------------------------------------------------------------------------
bool Agency::setName(string name){
	this->name = name;
	return true;
}
bool Agency::setVATnumber(unsigned VATnumber){
	this->VATnumber = VATnumber;
	return true;
}
bool Agency::setAddress(Address address){
	this -> address = address;
	return true;
}
bool Agency::setURL(string url){
	this -> URL = url;
	return true;
}
bool Agency::setClients(vector<Client> & clients){
	this -> clients = clients;
	return true;
}
bool Agency::setPackets(vector<Packet> & packets){
  	this -> packets = packets;
  	return true;
}
// ----------------------------------------------------------------------------------------
//                                  Input Output Functions                                 
// ----------------------------------------------------------------------------------------
ostream& operator<<(ostream& out, const Agency & agency){
	out << agency.name;
	return out;
}
