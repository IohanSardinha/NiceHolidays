#pragma once
#include "Agency.h"
Agency::Agency(string fileName){

	ifstream file(fileName);
	if (file.is_open())
	{
		string line;
		getline(file, name);
		getline(file, line);
		VATnumber = stoi(line);
		getline(file, URL);
		getline(file, line);
		address = Address(line);

	}
	else
	{
		throw exception("Could not open agency file");
	}
}
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

/*********************************
 * Mostrar Loja
 ********************************/  

// mostra o conteudo de uma agencia
ostream& operator<<(ostream& out, const Agency & agency){
	out << agency.name;
	return out;
}
