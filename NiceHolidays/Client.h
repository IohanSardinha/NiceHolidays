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
		inline Client();
		inline Client(string, unsigned, unsigned short, Address);  							// for a new client
		inline Client(string, unsigned, unsigned short, Address, vector<Packet>&, unsigned);  	// client read from file
		inline string getName() const;
		inline unsigned getVATnumber() const;
		inline unsigned short getFamilySize() const;
		inline Address getAddress() const;
		inline vector<Packet> getPacketList() const;
		inline unsigned getTotalPurchased() const;
		inline bool setName(string);
		inline bool setVATnumber(unsigned);
		inline bool setFamilySize(unsigned short);
		inline bool setAddress(Address);
		inline bool setPacketList(vector<Packet>&);
		inline bool setTotalPurchased(unsigned);
		inline friend ostream& operator<<(ostream&, const Client&);
		inline friend ofstream& operator<<(ofstream&, const Client&);
};
inline string str(Client client);