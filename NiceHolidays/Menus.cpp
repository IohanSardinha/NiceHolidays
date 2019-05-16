#pragma once
#include "Menus.h"
#include "defs.h"


// ----------------------------------------------------------------------------------------
//                                       Main
// ----------------------------------------------------------------------------------------
unsigned mainMenu(Agency agency){

	clear();
	Table table({ "Key", "Action" }, { { "C", "Manage clients" },{ "P", "Manage packets" },{ "I", "View info" },{ "E", "Exit" } });
	cout << table << endl;
	cout << "Choose an action:";
	string input;
	getline(cin, input);
	input = lower(input);
	while (input != "c" && input != "p" && input != "i" && input != "e")
	{
		clear();
		cout << table << endl;
		cout << input << " is not a valid action key, choose a valid action:";
		getline(cin, input);
		input = lower(input);
	}

	if (input == "c")
	{
		manageClients(agency);
	}
	else if (input == "p")
	{
		managePackets(agency);
	}
	else if (input == "i")
	{
		viewInfo(agency);
	}
	else if (input == "e")
	{
		exit();
	}

  return 0;
}

unsigned viewInfo(Agency agency)
{
	clear();
	Table table({ "Key", "Action" }, { { "C", "View clients" },{ "P", "View packets" },{ "S", "Packets sold to client" },{ "T", "Total sold packets" },{ "G", "Go back" } });
	cout << table << endl;
	cout << "Choose an action:";
	string input;
	getline(cin, input);
	input = lower(input);
	while (input != "c" && input != "p" && input != "s" && input != "t" && input != "g")
	{
		clear();
		cout << table << endl;
		cout << input << " is not a valid action key, choose a valid action:";
		getline(cin, input);
		input = lower(input);
	}

	if (input == "c")
	{
		viewClients(agency, 1);
	}
	else if (input == "p")
	{
		viewPackets(agency, 1);
	}
	else if (input == "s")
	{
		cout << "Client VAT:";
		getline(cin, input);
	}
	else if (input == "t")
	{

	}
	else if (input == "g")
	{
		mainMenu(agency);
	}

	return 0;
}

unsigned exit()
{
	clear();
	Table table({ "Thank you!" }, { { "Untill next time" } });
	cout << table;
	pause();
	return 0;
}

// ----------------------------------------------------------------------------------------
//                                       Clients
// ----------------------------------------------------------------------------------------
unsigned manageClients(Agency agency){
	clear();
	Table table({ "Key", "Action" }, { { "V", "View clients" },{ "E", "Edit clients" },{ "N", "New client" },{ "D", "Delete client" } ,{ "B", "Buy packet" },{ "G","Go Back" } });
	cout << table << endl;
	cout << "Choose an action: ";
	string input;
	getline(cin, input);
	input = lower(input);
	while (input != "v" && input != "e" && input != "n" && input != "d" && input != "b" && input != "g"){
		clear();
		cout << table << endl;
		cout << "'" << input << "' is not a valid action key, choose a valid action: ";
		getline(cin, input);
		input = lower(input);
	}
	if (input == "v"){
		viewClients(agency, 0);
	}
	else if (input == "e"){

	}
	else if (input == "n"){

	}
	else if (input == "d"){
		
	}
	else if (input == "b"){

	}
	else if (input == "g"){
		mainMenu(agency);
	}

	return 0;
}

unsigned viewClients(Agency agency, unsigned origin){
	clear();
	vector<string> header = { "Name","VAT","Family size","Address","Packets","Total purchased" };
	vector<vector<string>> clients;
	for (Client c : agency.getClients()){
		string packets = "";
		bool first = true;
		for (auto x : c.getPacketList()) {
			if (first)
				first = false;
			else
				packets += ", ";
			packets += x.getId();
		}
		clients.push_back(vector<string>({ c.getName(),to_string(c.getVATnumber()),to_string(c.getFamilySize()),str(c.getAddress()),packets,to_string(c.getTotalPurchased()) }));
	}
	cout << Table(header, clients) << endl;
	pause();
	if (origin == 0)
		manageClients(agency);
	else
		viewInfo(agency);
	return 0;
}

unsigned newClient(Agency agency){
	clear();
	return 0;
}

unsigned editClients(Agency agency)
{
	clear();
	return 0;
}

unsigned deleteClient(Agency agency)
{
	clear();
	return 0;
}

unsigned buyPacket(Agency agency)
{
	clear();
	return 0;
}

// ----------------------------------------------------------------------------------------
//                                       Packets
// ----------------------------------------------------------------------------------------/
unsigned managePackets(Agency agency){
	clear();
	Table table({ "Key", "Action" }, { { "V", "View packets" },{ "P", "Packets sold to client" },{ "E", "Edit packets" },{ "N", "New packet" },{ "D", "Delete packet" } ,{ "G","Go Back" } });
	cout << table << endl;
	cout << "Choose an action:";
	string input;
	getline(cin, input);
	input = lower(input);
	while (input != "v" && input != "e" && input != "n" && input != "d" && input != "b" && input != "g"){
		clear();
		cout << table << endl;
		cout << input << " is not a valid action key, choose a valid action:";
		getline(cin, input);
		input = lower(input);
	}
	if (input == "v"){
		viewPackets(agency, 0);
	}
	else if (input == "e"){

	}
	else if (input == "n"){
		newPacket(agency);
	}
	else if (input == "d"){

	}
	else if (input == "p"){

	}
	else if (input == "g"){
		mainMenu(agency);
	}

	return 0;
}

unsigned viewPackets(Agency agency, unsigned origin){
	clear();
	vector<string> header = { "ID","Sites","Start date","End date","Price per person","Sold places","Max places" };
	vector<vector<string>> packets;
	for (Packet p : agency.getPackets()){
		string sites;
		if (p.getSites().size() > 1){
			sites = p.getSites().at(0) + " - ";
			for (size_t i = 1; i < p.getSites().size(); i++){
				sites += p.getSites().at(i);
				if (i != p.getSites().size() - 1){
					sites += ", ";
				}
			}
		}
		else{
			sites = p.getSites().at(0);
		}
		ostringstream price;
		price << fixed << setprecision(2) << p.getPricePerPerson();
		packets.push_back(vector<string>({p.getId(),sites,str(p.getBeginDate()),str(p.getEndDate()),price.str(),to_string(p.getSoldPlaces()),to_string(p.getMaxPlaces())}));
	}
	cout << Table(header, packets) << endl;
	pause();
	if (origin == 0)
		managePackets(agency);
	else
		viewInfo(agency);
	return 0;
}

unsigned newPacket(Agency agency){
	string input;
	Packet p(false);
	clear();
	vector<string> header = { "ID","Sites","Start date","End date","Price per person","Sold places","Max places" };
	string sites = "";
	ostringstream price;
	price << fixed << setprecision(2) << p.getPricePerPerson();
	vector<string> packet = {p.getId(),sites,str(p.getBeginDate()),str(p.getEndDate()),price.str(),to_string(p.getSoldPlaces()),to_string(p.getMaxPlaces())};
	cout << Table(header, {packet}) << '\n';
	cout << "Packet Sites: ";
	getline(cin, input);
	vector<string> splitted = strip(split(input, "-"));
	if (splitted.size() > 1){
		vector<string> v = {splitted.at(0)};
		vector<string> v2 = strip(split(splitted.at(1), ","));
		v2.insert(v2.begin(), v.begin(), v.end());
		p.setSites(v2);
	}else{
		p.setSites({splitted.at(0)});
	}
	if (p.getSites().size() > 1){
		sites = p.getSites().at(0) + " - ";
		for (size_t i = 1; i < p.getSites().size(); i++){
			sites += p.getSites().at(i);
			if (i != p.getSites().size() - 1){
				sites += ", ";
			}
		}
	}else{
		sites = p.getSites().at(0);
	}
	packet = {p.getId(),sites,str(p.getBeginDate()),str(p.getEndDate()),price.str(),to_string(p.getSoldPlaces()),to_string(p.getMaxPlaces())};
	clear();
	cout << Table(header, {packet}) << '\n';
	cout << "Packet Start Date (dd/mm/yyyy): ";
	getline(cin, input);
	splitted = split(input, "/");
	vector<int> new_date = {stoi(splitted.at(0)), stoi(splitted.at(1)), stoi(splitted.at(2))};
	p.setBeginDate(Date(new_date.at(0), new_date.at(1), new_date.at(2)));	
	packet = {p.getId(),sites,str(p.getBeginDate()),str(p.getEndDate()),price.str(),to_string(p.getSoldPlaces()),to_string(p.getMaxPlaces())};
	clear();
	cout << Table(header, {packet}) << '\n';
	cout << "Packet End Date (dd/mm/yyyy): ";
	getline(cin, input);
	splitted = split(input, "/");
	new_date = {stoi(splitted.at(0)), stoi(splitted.at(1)), stoi(splitted.at(2))};
	p.setEndDate(Date(new_date.at(0), new_date.at(1), new_date.at(2)));
	packet = {p.getId(),sites,str(p.getBeginDate()),str(p.getEndDate()),price.str(),to_string(p.getSoldPlaces()),to_string(p.getMaxPlaces())};
	clear();
	cout << Table(header, {packet}) << '\n';
	cout << "Packet Price per Person: ";
	getline(cin, input);
	p.setPricePerPerson(stod(input));
	ostringstream new_price;
	new_price << fixed << setprecision(2) << p.getPricePerPerson();
	packet = {p.getId(),sites,str(p.getBeginDate()),str(p.getEndDate()),new_price.str(),to_string(p.getSoldPlaces()),to_string(p.getMaxPlaces())};
	clear();
	cout << Table(header, {packet}) << '\n';
	cout << "Packet Max Places: ";
	p.setMaxPlaces(stod(input));
	getline(cin, input);
	packet = {p.getId(),sites,str(p.getBeginDate()),str(p.getEndDate()),new_price.str(),to_string(p.getSoldPlaces()),to_string(p.getMaxPlaces())};
	clear();
	cout << Table(header, {packet}) << '\n';
	return 0;
}

unsigned editPackets(Agency agency)
{
	clear();
	return 0;
}

unsigned deletePacket(Agency agency)
{
	clear();
	return 0;
}

unsigned packetsSoldToClient(Agency)
{
	clear();
	return 0;
}

unsigned soldPackets(Agency)
{
	clear();
	return 0;
}