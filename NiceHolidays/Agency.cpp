#pragma once
#include "Agency.h"

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
			vector<string> date;
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
				//current.places = line;
				if (!start)
					start = true;
				break;

			case 2:
				date = split(line, "/");
				current.setBeginDate(Date(stoi(date.at(2)),stoi(date.at(1)),stoi(date.at(0))));
				break;

			case 3:
				date = split(line, "/");
				current.setEndDate(Date(stoi(date.at(2)), stoi(date.at(1)), stoi(date.at(0))));
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

	return travel_packs;
}

inline vector<Client> readClients(string clients_file)
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
				//current.setPacketList(split(line, ";"));
				break;
			}
			pos = (pos + 1) % 6;
		}
		clients.push_back(current);
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
		//clients = readClients(clientsFile,packets);

		file.close();
	}
	else
	{
		file.close();
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
