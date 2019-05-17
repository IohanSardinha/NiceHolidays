#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "defs.h"
#include "Address.h"
#include "Client.h"
#include "Packet.h"
using namespace std;
class Agency{
	private:
		string name;														// name of the  agency
		unsigned int VATnumber;												// VAT number of the agency
		string clientsFile;													// path to the clients file
		string packetsFile;													// path to the packets file
		Address address;													// address of the agency
		string URL;															// URL of the agency Web site
		vector<Client> clients;												// vector to store the existing clients
		vector<Packet> packets;												// vector to store the existing packets
		bool clientsInfoHasChanged;											// flag that is set to "true" if at least one client has been changed/added/deleted
		bool packetsInfoHasChanged;											// flag that is set to "true" if at least one packet has been changed/added/deleted
		unsigned int maxClientsId;											// maximum value among all clients identifiers
		unsigned int maxPacketsId;											// maximum value among all packets identifiers
	public:
		Agency(string fileName);											//Constructor of Agency with a given .txt file
		string getClientsFile() const;										//Getter for clients file
		string getPacketsFile() const;										//Getter for packets file
		string getName() const;												//Getter for name
		unsigned getVATnumber() const;										//Getter for VAT number
		Address getAddress() const;											//Getter for Address
		string getURL() const;												//Getter for URL
		vector<Client> getClients() const;									//Getter for clients
		vector<Packet> getPackets() const;									//Getter fot packets
		bool addClient(Client);												//Adds a given client to clients
		bool addPacket(Packet);												//Adds a given packet to packet
		bool updatePacket(Packet);											//Updates a given packet in packets
		bool setName(string name);											//Setter for name
		bool setVATnumber(unsigned VATnumber);								//Setter for VAT number
		bool setAddress(Address address);									//Setter for Address
		bool setURL(string url);											//Setter for URL
		bool setClients(vector<Client> & clients);							//Setter for clients
		bool setPackets(vector<Packet> & packets);							//Setter for packets
		friend ostream& operator<<(ostream& out, const Agency & agency);	//Prints an address in a nice way
};
