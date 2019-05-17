#pragma once
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include "defs.h"
#include "Address.h"
#include "Packet.h"
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
		Client();
		Client(string, unsigned, unsigned short, Address);  							// for a new client
		Client(string, unsigned, unsigned short, Address, vector<Packet>&, unsigned);  	// client read from file
		string getName() const;															//Getter for name
		unsigned getVATnumber() const;													//Getter for VAT number
		unsigned short getFamilySize() const;											//Getter for family
		Address getAddress() const;														//Getter for Address
		vector<Packet> getPacketList() const;											//Getter for packet list
		unsigned getTotalPurchased() const;												//Getter for total purchased
		bool hasPacket(Packet) const;													//Returns true if client has subscribed to given packet
		bool setName(string);															//Setter for name
		bool setVATnumber(unsigned);													//Setter for VAT number
		bool setFamilySize(unsigned short);												//Setter for family size
		bool setAddress(Address);														//Setter for Address
		bool setPacketList(vector<Packet>&);											//Setter for packet list
		bool setTotalPurchased(unsigned);												//Setter for total purchased
		friend ostream& operator<<(ostream&, const Client&);							//Overload of operator <<
		friend ofstream& operator<<(ofstream&, const Client&);							//Overload of operator <<
};
string str(Client client);																//Turns client into string