#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "defs.h"
#include "Address.cpp"
#include "Client.cpp"
#include "Packet.cpp"
using namespace std;
class Agency{
	private:
		string name; // name of the  agency
		unsigned int VATnumber; // VAT number of the agency
		Address address; // address of the agency
		string URL; // URL of the agency Web site
		vector<Client> clients; // vector to store the existing clients
		vector<Packet> packets; // vector to store the existing packets
		bool clientsInfoHasChanged; // flag that is set to "true" if at least one client has been changed/added/deleted
		bool packetsInfoHasChanged; // flag that is set to "true" if at least one packet has been changed/added/deleted
		unsigned int maxClientsId; // maximum value among all clients identifiers
		unsigned int maxPacketsId; // maximum value among all packets identifiers
	public:
		Agency(string fileName);
		string getName() const;
		unsigned getVATnumber() const;
		Address getAddress() const;
		string getURL() const;
		vector<Client> getClients() const;
		vector<Packet> getPackets() const;
		bool setName(string name);
		bool setVATnumber(unsigned VATnumber);
		bool setAddress(Address address);
		bool setURL(string url);
		bool setClients(vector<Client> & clients);
		bool setPackets(vector<Packet> & packets);
		friend ostream& operator<<(ostream& out, const Agency & agency);
};
