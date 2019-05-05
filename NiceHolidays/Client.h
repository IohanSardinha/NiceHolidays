#pragma once
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include "defs.h"
#include "Address.cpp"
#include "Packet.cpp"
using namespace std;
class Client{
	private:
		string name; 																	// name of the client
		unsigned VATnumber; 															// VAT number of client
		unsigned short familySize;  													// number of family members
		Address address; 																// client's address
		vector<Packet> packets; 														// vector to store client's packets bought
		unsigned totalPurchased; 														// total value spent by the client
	public:
		Client(string, unsigned, unsigned short, Address);  							// for a new client
		Client(string, unsigned, unsigned short, Address, vector<Packet>&, unsigned);  	// client read from file
		string getName() const;
		unsigned getVATnumber() const;
		unsigned short getFamilySize() const;
		Address getAddress() const;
		vector<Packet> getPacketList() const;
		unsigned getTotalPurchased() const;
		bool setName(string);
		bool setVATnumber(unsigned);
		bool setFamilySize(unsigned short);
		bool setAddress(Address);
		bool setPacketList(vector<Packet>&);
		bool setTotalPurchased(unsigned);
		friend ostream& operator<<(ostream&, const Client&);
		friend ofstream& operator<<(ofstream&, const Client&);
};
string str(Client client);