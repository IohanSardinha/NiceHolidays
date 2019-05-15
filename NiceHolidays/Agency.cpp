#pragma once
#include <iostream>
#include "Agency.h"

inline Packet getPacketById(vector<Packet> pckts, unsigned id)
{
	for (Packet pckt : pckts)
	{
		if (abs(stoi(pckt.getId())) == id)
		{
			return pckt;
		}
	}
    return Packet();
}

inline vector<Packet> readPackets(string packets_file)
{
	string line;
	ifstream file(packets_file);
	int pos = 0;
	vector<Packet> travel_packs;
	Packet current = Packet();
	bool start = false;

	if (file.is_open())
	{
		getline(file, line);


		while (getline(file, line))
		{
			vector<string> splittedLine;
			switch (pos)
			{
			case 0:
				if (start)
				{
					travel_packs.push_back(current);
				}
				current.setId(line);
				break;

			case 1:
				splittedLine = split(line, "-");
				if (splittedLine.size() > 1)
				{
					vector<string> v = { splittedLine.at(0) };
					vector<string> v2 = split(splittedLine.at(1), ",");
					v.insert(v.begin(), v2.begin(), v2.end());
					current.setSites(v);
				}
				else
				{
					current.setSites(vector<string>({ splittedLine.at(0)}));
				}
				
				if (!start)
					start = true;
				break;

			case 2:
				splittedLine = split(line, "/");
				current.setBeginDate(Date(stoi(splittedLine.at(2)),stoi(splittedLine.at(1)),stoi(splittedLine.at(0))));
				break;

			case 3:
				splittedLine = split(line, "/");
				current.setEndDate(Date(stoi(splittedLine.at(2)), stoi(splittedLine.at(1)), stoi(splittedLine.at(0))));
				break;

			case 4:
				current.setPricePerPerson(stod(line));
				break;

			case 5:
				current.setMaxPlaces(stoi(line));
				break;

			case 6:
				current.setSoldPlaces(stoi(line));
				break;
			}
			pos = (pos + 1) % 8;
		}
		travel_packs.push_back(current);
	}
	else
	{
		cout << "Could not open file " << packets_file << endl;
	}

	return travel_packs;
}

inline vector<Client> readClients(string clients_file, vector<Packet> packets)
{
	string line;
	ifstream file(clients_file);
	int pos = 0;
	vector<Client> clients;
	Client current = Client();
	bool start = false;

	if (file.is_open())
	{
		while (getline(file, line))
		{
			vector<string> packsIds;
			vector<Packet> currentPackets;
			switch (pos)
			{
			case 0:
				if (start)
				{
					clients.push_back(current);
				}
				current.setName(line);
				break;
			case 1:
				current.setVATnumber(stoi(line));
				if (!start)
					start = true;
				break;
			case 2:
				current.setFamilySize(stoi(line));
				break;
			case 3:
				current.setAddress(split(line,"/"));
				break;
			case 4:
				packsIds = split(line, ";");
				for (size_t i = 0; i < packsIds.size(); i++)
				{
					currentPackets.push_back(getPacketById(packets, stoi(packsIds.at(i))));
				}
				current.setPacketList(currentPackets);
				currentPackets.clear();
				break;
			case 5:
				current.setTotalPurchased(stoi(line));
				break;
			}
			pos = (pos + 1) % 7;
		}
		clients.push_back(current);
	}
	else
	{
		cout << "Could not open file " << clients_file << endl;
	}

	return clients;
}

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
		address = Address(split(line,"/"));
		string clientsFile;
		getline(file, clientsFile);
		getline(file, line);
		packets = readPackets(line);
		clients = readClients(clientsFile,packets);
		file.close();
	}
	else
	{
		file.close();
		cout << "Could not open agency file";
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
	out << agency.name << endl;
	out << agency.VATnumber << endl;
	out << agency.URL << endl;
	out << agency.address << endl;
	out << agency.clients.size() << " Clients" << endl;
	out << agency.packets.size() << " Packets" << endl;
	return out;
}
