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
		inline Agency(string fileName);
		inline string getName() const;
		inline unsigned getVATnumber() const;
		inline Address getAddress() const;
		inline string getURL() const;
		inline vector<Client> getClients() const;
		inline vector<Packet> getPackets() const;
		inline bool setName(string name);
		inline bool setVATnumber(unsigned VATnumber);
		inline bool setAddress(Address address);
		inline bool setURL(string url);
		inline bool setClients(vector<Client> & clients);
		inline bool setPackets(vector<Packet> & packets);
		inline friend ostream& operator<<(ostream& out, const Agency & agency);
};
