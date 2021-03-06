#pragma once
#include "Menus.h"
#include "defs.h"

 Table clientsToTable(vector<Client> cs)
{
	vector<string> header = { "Name","VAT","Family size","Address","Packets","Total purchased" };
	vector<vector<string>> clients;
	for (Client c : cs)
	{
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
	return Table(header, clients);
}

 Table packetsToTable(vector<Packet> pckts)
{
	vector<string> header = { "ID","Sites","Start date","End date","Price per person","Sold places","Max places" };
	vector<vector<string>> packets;
	for (Packet p : pckts)
	{
		string sites;
		if (p.getSites().size() > 1)
		{
			sites = p.getSites().at(0) + " - ";
			for (size_t i = 1; i < p.getSites().size(); i++)
			{
				sites += p.getSites().at(i);
				if (i != p.getSites().size() - 1)
				{
					sites += ", ";
				}
			}
		}else{
			if (p.getSites().size() == 0)
				sites = "";
			else
				sites = p.getSites().at(0);
		}
		ostringstream price;
		price << fixed << setprecision(2) << p.getPricePerPerson();
		packets.push_back(vector<string>({ p.getId(),sites,str(p.getBeginDate()),str(p.getEndDate()),price.str(),to_string(p.getSoldPlaces()),to_string(p.getMaxPlaces()) }));
	}
	return Table(header, packets);
}

 vector<vector<string>> rankingSites(Agency agency, unsigned max) {
	 map<string, int> pairs;
	 map<string, int>::const_iterator mi;
	 pair<string, int> p;
	 multimap<int, string> ranking;
	 for (unsigned i = 0; i < agency.getPackets().size(); ++i) {
		 for (unsigned j = 0; j < agency.getPackets().at(i).getSites().size(); ++j) {
			 pairs[agency.getPackets().at(i).getSites().at(j)] += agency.getPackets().at(i).getSoldPlaces();
		 }
	 }
	 for (mi = pairs.begin(); mi != pairs.end(); mi++) {
		 p = *mi;
		 ranking.insert(pair<int, string>(-p.second, p.first));
	 }
	 vector<vector<string>> content;
	 clear();
	 int n = 0;
	 for (const auto& x : ranking) {
		 n++;
		 content.push_back({ to_string(n), x.second, to_string(-x.first) });
		 if (n == max) {
			 break;
		 }
	 }
	 return content;
 }

 bool yesOrNo(string question) {
	 string option;
	 cout << question << " (y/n) ";
	 getline(cin, option);
	 if (option == "y" || option == "Y")
		 return true;
	return false;
 }

 void save(Agency agency)
 {
	 ofstream clientsFile(agency.getClientsFile(), ofstream::out, ofstream::trunc), packetsFile(agency.getPacketsFile(), ofstream::out, ofstream::trunc);
	 packetsFile << Packet().getNumPackets() << endl;
	 for (size_t i = 0; i < agency.getPackets().size(); i++)
	 {
		 packetsFile << agency.getPackets().at(i);

		 if (i != agency.getPackets().size() - 1)
		 {
			 packetsFile << SEPARATOR << endl;
		 }
	 }
	 for (size_t i = 0; i < agency.getClients().size(); i++)
	 {
		 clientsFile << agency.getClients().at(i);

		 if (i != agency.getClients().size() - 1)
		 {
			 clientsFile << endl << SEPARATOR << endl;
		 }
	 }
	 clientsFile.close();
	 packetsFile.close();
 }

 bool stringInVector(vector<string> v, string s)
 {
	 for (string s2 : v)
	 {
		 if (s2 == s)
			 return true;
	 }
	 return false;
 }

 vector<Packet> getPacketsBySite(vector<Packet> ps, string site)
 {
	 vector<Packet> ret;
	 for (Packet p : ps)
	 {
		 if (stringInVector(p.getSites(), site))
			 ret.push_back(p);
	 }
	 return ret;
 }

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
		cout << "'" << input << "' is not a valid action key, choose a valid action: ";
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
		exit(agency);
	}

  return 0;
}

unsigned viewInfo(Agency agency)
{
	clear();
	Table table({ "Key", "Action" }, { { "C", "View clients" },{"O","View one specific client"},{ "P", "View packets" },{ "S", "Packets sold to client" },{ "T", "Total sold packets" },{ "G", "Go back" } });
	cout << table << endl;
	cout << "Choose an action:";
	string input;
	getline(cin, input);
	input = lower(input);
	while (input != "c" && input != "p" && input != "s" && input != "t" && input != "g" && input != "o")
	{
		clear();
		cout << table << endl;
		cout << "'" << input << "' is not a valid action key, choose a valid action: ";
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
	else if (input == "o")
	{
		viewClient(agency, 1);
	}
	else if (input == "s")
	{
		packetsSoldToClient(agency,0);
	}
	else if (input == "t")
	{
		soldPackets(agency);
	}
	else if (input == "g")
	{
		mainMenu(agency);
	}

	return 0;
}

unsigned exit(Agency agency)
{
	save(agency);
	clear();
	Table table({ "Thank you!" }, { { "Untill next time" } });
	cout << table;
	pause();
	return 0;
}

// ----------------------------------------------------------------------------------------
//                                       Clients
// ----------------------------------------------------------------------------------------
unsigned manageClients(Agency agency)
{
	clear();
	Table table({ "Key", "Action" }, { { "I", "Get sugested sites for clients to visit" }, { "V", "View clients" },{ "O","View one specific client" },{ "E", "Edit clients" },{ "N", "New client" },{ "D", "Delete client" } ,{ "B", "Buy packet" },{ "G","Go Back" } });
	cout << table << endl;
	cout << "Choose an action:";
	string input;
	getline(cin, input);
	input = lower(input);
	while (input != "i" && input != "v" && input != "e" && input != "n" && input != "d" && input != "b" && input != "g" && input != "o")
	{
		clear();
		cout << table << endl;
		cout << "'" << input << "' is not a valid action key, choose a valid action: ";
		getline(cin, input);
		input = lower(input);
	}

	if (input == "v")
	{
		viewClients(agency,0);
	}
	else if (input == "e")
	{
		editClients(agency);
	}
	else if (input == "i")
	{
		packetIndications(agency);
	}
	else if (input == "o")
	{
		viewClient(agency,0);
	}
	else if (input == "n")
	{
		newClient(agency);
	}
	else if (input == "d")
	{
		deleteClient(agency);
	}
	else if (input == "b")
	{
		buyPacket(agency);
	}
	else if (input == "g")
	{
		mainMenu(agency);
	}

	return 0;
}

unsigned viewClients(Agency agency, char origin)
{
	clear();
	cout << clientsToTable(agency.getClients()) << endl;
	pause();

	if (origin == 0)
		manageClients(agency);
	else
		viewInfo(agency);

	return 0;
}

unsigned newClient(Agency agency)
{
	string input;
	Client newClient = Client();

	//NAME
	clear();
	cout << clientsToTable({ newClient }) << endl;
	cout << "Client name(0 to exit):";
	getline(cin, input);
	if (input == "0")
	{
		manageClients(agency);
		return 0;
	}
	newClient.setName(input);

	//VAT
	clear();
	cout << clientsToTable({ newClient }) << endl;
	cout << "Client VAT number(0 to exit):";
	getline(cin, input);
	if (input == "0")
	{
		manageClients(agency);
		return 0;
	}
	while (true)
	{
		try
		{
			newClient.setVATnumber(stoi(input));
			break;
		}
		catch (exception)
		{
			cout <<"'" << input << "' is not a valid input. Insert a valid integer(0 to exit):";
			getline(cin, input);
			if (input == "0")
			{
				manageClients(agency);
				return 0;
			}
		}
	}

	//FAMILY SIZE
	clear();
	cout << clientsToTable({ newClient }) << endl;
	cout << "Client family size(0 to exit):";
	getline(cin, input);
	if (input == "0")
	{
		manageClients(agency);
		return 0;
	}
	while (true)
	{
		try
		{
			newClient.setFamilySize(stoi(input));
			break;
		}
		catch (exception)
		{
			cout << "'" << input << "' is not a valid input. Insert a valid integer(0 to exit):";
			getline(cin, input);
			if (input == "0")
			{
				manageClients(agency);
				return 0;
			}
		}
	}

	//ADDRESS
	clear();
	cout << clientsToTable({ newClient }) << endl;
	cout << "Client address(Street / floor / door / Postal-Code / Location)(0 to exit):";
	getline(cin, input);
	if (input == "0")
	{
		manageClients(agency);
		return 0;
	}
	while (true)
	{
		if (split(input, "/").size() > 4)
			break;
		cout << input << " is not a valid address. Insert a valid address (Street / floor / door / Postal-Code / Location)(0 to exit): ";
		getline(cin, input);
		if (input == "0")
		{
			manageClients(agency);
			return 0;
		}
	}
	newClient.setAddress(split(input,"/"));

	//PACKETS
	clear();
	cout << clientsToTable({ newClient }) << endl;
	cout << "Client packets(separated by ';')(0 to exit):";
	getline(cin, input);
	if (input == "0")
	{
		manageClients(agency);
		return 0;
	}
	vector<Packet> packets;
	vector<string> packsIds = split(input, ";");
	if (!(packsIds.size() == 1 && packsIds.at(0).empty()))
	{
		for (size_t i = 0; i < packsIds.size(); i++)
		{
			packets.push_back(getPacketById(agency.getPackets(), stoi(packsIds.at(i))));
		}
	}
	newClient.setPacketList(packets);

	//Total purchased
	clear();
	cout << clientsToTable({ newClient }) << endl;
	cout << "Client total purchased(-1 to exit):";
	getline(cin, input);
	if (input == "-1")
	{
		manageClients(agency);
		return 0;
	}
	while (true)
	{
		try
		{
			newClient.setTotalPurchased(stoi(input));
			break;
		}
		catch (exception)
		{
			cout << "'" << input << "' is not a valid input. Insert a valid integer(-1 to exit):";
			getline(cin, input);
			if (input == "-1")
			{
				manageClients(agency);
				return 0;
			}
		}
	}

	clear();
	cout << clientsToTable({ newClient }) << endl;
	pause();

	for (Packet p : newClient.getPacketList())
	{
		if (p.isAvailable())
		{
			p.setSoldPlaces(p.getSoldPlaces() + newClient.getFamilySize());
			agency.updatePacket(p);
		}
	}

	agency.addClient(newClient);

	save(agency);
	manageClients(agency);
	return 0;
}

unsigned viewClient(Agency agency, char origin)
{
	string input;
	cout << "Clients VAT number(0 to exit):";
	getline(cin, input);
	int vat;
	while (true)
	{
		try
		{
			vat = stoi(input);
			break;
		}
		catch (exception)
		{
			cout << "'" << input << "' is not a valid VAT number. Insert a valid integer (0 to exit):";
			getline(cin, input);
		}
	}

	if (vat == 0)
	{
		if (origin = 0)
			manageClients(agency);
		else
			viewInfo(agency);
		return 0;
	}
	for (unsigned i = 0; i < agency.getClients().size(); i++)
	{
		Client c = agency.getClients().at(i);
		if (vat == c.getVATnumber())
		{
			clear();
			cout << clientsToTable({ c });
			pause();
			if (origin = 0)
				manageClients(agency);
			else
				viewInfo(agency);
			return 0;
		}
	}
	cout << "Client '" << input << "' not found" << endl;
	viewClient(agency,origin);
	return 0;
}

unsigned editClients(Agency agency)
{
	string input;
	cout << "Clients VAT number(0 to exit):";
	getline(cin, input);
	int vat;
	while (true)
	{
		try
		{
			vat = stoi(input);
			break;
		}
		catch (exception)
		{
			cout << "'" << input << "' is not a valid VAT number. Insert a valid integer (0 to exit):";
			getline(cin, input);
		}
	}

	if (vat == 0)
	{
		manageClients(agency);
		return 0;
	}
	for (unsigned i = 0; i < agency.getClients().size(); i++)
	{
		Client c = agency.getClients().at(i);
		if (vat == c.getVATnumber())
		{
			bool another = false;
			do
			{
				clear();
				cout << clientsToTable({ c }) << endl << endl;
				Table table = Table({ "Key","Field" }, { { "N","Name" },{ "V","VAT number" },{ "F","Family size" },{ "A","Address" },{ "P","Packets" },{ "T","Total purschased" } });
				cout << table << endl << endl;
				cout << "Choose an action(0 to exit):";
				getline(cin, input);

				if (input == "0")
				{
					manageClients(agency);
					return 0;
				}

				input = lower(input);
				while (input != "n" && input != "v" && input != "f" && input != "a" && input != "p" && input != "t")
				{
					clear();
					cout << clientsToTable({ c }) << endl << endl;
					cout << table << endl;
					cout << "'" << input << "' is not a valid action key, choose a valid action: ";
					getline(cin, input);
					input = lower(input);
				}

				if (input == "n")
				{
					cout << c.getName() << "'s new name(0 to exit):";
					getline(cin, input);
					if (input == "0")
					{
						manageClients(agency);
						return 0;
					}
					c.setName(input);

				}
				else if (input == "v")
				{
					cout << c.getName() << "'s new VAT number(0 to exit):";
					getline(cin, input);
					if (input == "0")
					{
						manageClients(agency);
						return 0;
					}
					while (true)
					{
						try
						{
							c.setVATnumber(stoi(input));
							break;
						}
						catch (exception)
						{
							cout << "'" << input << "' is not a valid input. Insert a valid integer(0 to exit):";
							getline(cin, input);
							if (input == "0")
							{
								manageClients(agency);
								return 0;
							}
						}
					}
				}
				else if (input == "f")
				{
					cout << c.getName() << "'s new family size(0 to exit):";
					getline(cin, input);
					if (input == "0")
					{
						manageClients(agency);
						return 0;
					}
					while (true)
					{
						try
						{
							c.setFamilySize(stoi(input));
							break;
						}
						catch (exception)
						{
							cout << "'" << input << "' is not a valid input. Insert a valid integer(0 to exit):";
							getline(cin, input);
							if (input == "0")
							{
								manageClients(agency);
								return 0;
							}
						}
					}
				}
				else if (input == "a")
				{
					cout << c.getName() << "'s new address(0 to exit):";
					getline(cin, input);
					if (input == "0")
					{
						manageClients(agency);
						return 0;
					}
					while (true)
					{
						if (split(input, "/").size() > 4)
							break;
						cout << input << " is not a valid address. Insert a valid address (Street / floor / door / Postal-Code / Location)(0 to exit): ";
						getline(cin, input);
						if (input == "0")
						{
							manageClients(agency);
							return 0;
						}
					}
					c.setAddress(split(input, "/"));
				}
				else if (input == "p")
				{
					cout << c.getName() << "'s new packets(0 to exit):";
					getline(cin, input);
					if (input == "0")
					{
						manageClients(agency);
						return 0;
					}
					vector<Packet> packets;
					vector<string> packsIds = split(input, ";");
					if (!(packsIds.size() == 1 && packsIds.at(0).empty()))
					{
						for (size_t i = 0; i < packsIds.size(); i++)
						{
							packets.push_back(getPacketById(agency.getPackets(), stoi(packsIds.at(i))));
						}
					}
					c.setPacketList(packets);
				}
				else if (input == "t")
				{
					cout << c.getName() << "'s new total purchased :";
					getline(cin, input);
					if (input == "0")
					{
						manageClients(agency);
						return 0;
					}
					while (true)
					{
						try
						{
							c.setTotalPurchased(stoi(input));
							break;
						}
						catch (exception)
						{
							cout << "'" << input << "' is not a valid input. Insert a valid integer(0 to exit):";
							getline(cin, input);
							if (input == "0")
							{
								manageClients(agency);
								return 0;
							}
						}
					}
				}

				clear();

				cout << clientsToTable({ c });

				cout << "Change another field?(y/n): ";
				getline(cin, input);
				another = (input == "y");
			} while (another);

			vector<Client> cs = agency.getClients();
			cs.at(i) = c;
			agency.setClients(cs);

			save(agency);
			manageClients(agency);
			return 0;
		}
	}
	cout << "Client '" << input << "' not found" << endl;
	editClients(agency);
	return 0;
}

unsigned deleteClient(Agency agency)
{
	string input;
	cout << "Clients VAT number(0 to exit):";
	getline(cin, input);
	int vat;
	while (true)
	{
		try
		{
			vat = stoi(input);
			break;
		}
		catch (exception)
		{
			cout << "'" << input << "' is not a valid VAT number. Insert a valid integer (0 to exit):";
			getline(cin, input);
		}
	}

	if (vat == 0)
	{
		manageClients(agency);
		return 0;
	}
	for (unsigned i = 0; i < agency.getClients().size(); i++)
	{
		Client c = agency.getClients().at(i);
		if (vat == c.getVATnumber())
		{
			clear();
			cout << clientsToTable({c}) << endl;
			cout << "Are you sure you want to delete " << c.getName() << "?(y/n)" << endl;
			getline(cin, input);
			if (input == "y")
			{
				vector<Client> temp = agency.getClients();
				temp.erase(temp.begin() + i);
				agency.setClients(temp);
				for (Packet p : c.getPacketList())
				{
					if (p.isAvailable())
					{
						p.setSoldPlaces(p.getSoldPlaces() - c.getFamilySize());
						agency.updatePacket(p);
					}
				}
				save(agency);
			}
			manageClients(agency);
			return 0;
		}
	}
	cout << "Client '" << input << "' not found" << endl;
	deleteClient(agency);
	return 0;
}

unsigned buyPacket(Agency agency)
{
	string input;
	cout << "Clients VAT number(0 to exit):";
	getline(cin, input);
	int vat;
	while (true)
	{
		try
		{
			vat = stoi(input);
			break;
		}
		catch (exception)
		{
			cout << "'" << input << "' is not a valid VAT number. Insert a valid integer (0 to exit):";
			getline(cin, input);
		}
	}

	if (vat == 0)
	{
		manageClients(agency);
		return 0;
	}
	for (unsigned i = 0; i < agency.getClients().size(); i++)
	{
		Client c = agency.getClients().at(i);
		if (vat == c.getVATnumber())
		{
			cout << "Client " << c.getName() << " found" << endl;

			do
			{
				cout << "Package ID(0 to exit):";
				getline(cin, input);

				while (true)
				{
					if (input == "0")
					{
						manageClients(agency);
						return 0;
					}
					try
					{
						stoi(input);
						break;
					}
					catch (exception)
					{
						cout << input << " is not a valid ID. Insert a valid integer(0 to exit):";
						getline(cin, input);
					}
				}

				Packet packet = getPacketById(agency.getPackets(), stoi(input));
				
				if (!packet.isEmpty() && packet.isAvailable() && !c.hasPacket(packet) && (packet.getMaxPlaces() - packet.getSoldPlaces() >= c.getFamilySize()))
				{
					clear();
					cout << packetsToTable({ packet }) << endl;
					cout << "Should " << c.getName() << " buy packet " << packet.getId() << "? (y/n): ";
					getline(cin, input);
					if (input == "y")
					{
						vector<Client> cs = agency.getClients();
						vector<Packet> pckts = c.getPacketList();
						pckts.push_back(packet);
						packet.setSoldPlaces(packet.getSoldPlaces() + c.getFamilySize());
						cs.at(i).setPacketList(pckts);
						agency.setClients(cs);
						agency.updatePacket(packet);
						save(agency);


						cout << c.getName() << " bought packet " << packet.getId() << endl;
					}
					else
						cout << c.getName() << " did not buy packet" << endl;
					pause();
					manageClients(agency);
					return 0;
				}
				else if(!packet.isAvailable())
				{
					cout << "Packet " << input << " is not available" << endl;
				}
				else if (c.hasPacket(packet))
				{
					cout << c.getName() << " already bought packet " << packet.getId() << endl;
				}
				else if (!(packet.getMaxPlaces() - packet.getSoldPlaces() >= c.getFamilySize()))
				{
					cout << "Packet " << input << " is sold out" << endl;
				}
				else
					cout << "Packet " << input << " not found" << endl;

			} while (true);
			
			return 0;
		}
	}
	cout << "Client '" << input << "' not found" << endl;
	buyPacket(agency);
	return 0;
}

unsigned packetIndications(Agency agency) {
	cout << "How many of the first sites? ";
	string input;
	getline(cin, input);
	while (true) {
		try {
			if (stoi(input) < 1)
				stoi("erro");
			break;
		}
		catch (exception) {
			cout << "'" << input << "' is not a valid number. Insert a valid positive integer: ";
			getline(cin, input);
		}
	}
	vector<vector<string>> content = rankingSites(agency, stoi(input));
	vector<vector<string>> indications;
	for (unsigned i = 0; i < agency.getClients().size(); ++i){
		bool has_not_visited = false;
		for (unsigned j = 0; j < content.size(); ++j){
			bool visited = false;
			for (unsigned k = 0; k < agency.getClients().at(i).getPacketList().size(); ++k) {
				for (unsigned l = 0; l < agency.getClients().at(i).getPacketList().at(k).getSites().size(); ++l) {
					if (content.at(j).at(1) == agency.getClients().at(i).getPacketList().at(k).getSites().at(l)) {
						visited = true;
						break;
					}
				}
				if (visited) {
					break;
				}
			}
			if (!visited) {
				has_not_visited = true;
				indications.push_back({ to_string(agency.getClients().at(i).getVATnumber()), getPacketsBySite(agency.getPackets(),content.at(j).at(1)).at(0).getId()});
				break;
			}
		}
		if (!has_not_visited){ 
			vector<string> pair = {to_string(agency.getClients().at(i).getVATnumber()), string("Visited all of " + input + " most vited sites")};
			indications.push_back(pair);
		}
	}
	clear();
	cout << Table({ "Client","Sugested packet ID" }, indications) << endl;
	pause();
	manageClients(agency);
	return 0;
}

// ----------------------------------------------------------------------------------------
//                                       Packets
// ----------------------------------------------------------------------------------------/
unsigned managePackets(Agency agency)
{
	clear();
	Table table({ "Key", "Action" }, { { "V", "View packets" }, { "F","View filtered packets" }, {"R", "View packet sites ranked"}, { "P", "Packets sold to client" },{ "E", "Edit packets" },{ "N", "New packet" },{ "C", "Close packet" } ,{ "G","Go Back" } });
	cout << table << endl;
	cout << "Choose an action: ";
	string input;
	getline(cin, input);
	input = lower(input);
	while (input != "v" && input != "e" && input != "n" && input != "c" && input != "b" && input != "g" && input != "p" && input != "f" && input != "r")
	{
		clear();
		cout << table << endl;
		cout << "'" << input << "' is not a valid action key, choose a valid action: ";
		getline(cin, input);
		input = lower(input);
	}

	if (input == "v")
	{
		viewPackets(agency,0);
	}
	else if (input == "e")
	{
		editPackets(agency);
	}
	else if (input == "n")
	{
		newPacket(agency);
	}
	else if (input == "c")
	{
		deletePacket(agency);
	}
	else if (input == "p")
	{
		packetsSoldToClient(agency, 1);
	}
	else if (input == "g")
	{
		mainMenu(agency);
	}
	else if (input == "f") {
		viewFilteredPackets(agency);
	}else if (input == "r") {
		packetSitesRanking(agency);
	}

	return 0;
}

unsigned viewPackets(Agency agency, char origin)
{
	clear();
	cout << packetsToTable(agency.getPackets()) << endl;
	pause();

	if (origin == 0)
		managePackets(agency);
	else
		viewInfo(agency);
	return 0;
}

unsigned viewFilteredPackets(Agency agency) {
	clear();
	Table table({ "Key", "Filter" }, { { "D", "For a destination" }, { "B","Between two dates" }, { "DB", "For a destination and between two dates" }, { "G", "Go back" } });
	cout << table << endl;
	cout << "Choose an action: ";
	string input;
	getline(cin, input);
	input = lower(input);
	while (input != "d" && input != "b" && input != "db" && input != "g")
	{
		clear();
		cout << table << endl;
		cout << "'" << input << "' is not a valid action key, choose a valid action: ";
		getline(cin, input);
		input = lower(input);
	}
	if (input == "d")
	{
		viewPacketsDestination(agency);
	}
	else if (input == "b")
	{
		viewPacketsDate(agency);
	}
	else if (input == "db")
	{
		viewPacketsDestinationDate(agency);
	}
	else if (input == "g")
	{
		managePackets(agency);
	}
	return 0;
}

unsigned viewPacketsDestination(Agency agency) {
	cout << "Destination: ";
	string input;
	getline(cin, input);
	input = lower(input);
	vector<Packet> pckts;
	for (unsigned i = 0; i < agency.getPackets().size(); ++i) {
		for (unsigned j = 0; j < agency.getPackets().at(i).getSites().size(); ++j) {
			if (lower(agency.getPackets().at(i).getSites().at(j)) == input) {
				pckts.push_back(agency.getPackets().at(i));
				break;
			}
		}
	}
	clear();
	if (pckts.size() == 0)
		cout << "No packet matches this destination\n" << endl;
	else
		cout << packetsToTable(pckts) << endl;
	if (yesOrNo("Another destination?")) {
		viewPacketsDestination(agency);
		clear();
	} else {
		viewFilteredPackets(agency);
	}
	return 0;
}

unsigned viewPacketsDate(Agency agency) {
	string input;
	vector<string> splitted;
	vector<Packet> pckts;
	cout << "First date (dd/mm/yyyy): ";
	getline(cin, input);
	splitted = split(input, "/");
	while (true) {
		try {
			stoi(splitted.at(0));
			stoi(splitted.at(1));
			stoi(splitted.at(2));
			if (!validDate(stoi(splitted.at(0)), stoi(splitted.at(1)), stoi(splitted.at(2)))) {
				stoi("erro");
			}
			break;
		} catch (exception) {
			cout << "'" << input << "' is not a valid date. Insert a valid date: ";
			getline(cin, input);
			splitted = split(input, "/");
		}
	}
	Date date1(stoi(splitted.at(0)), stoi(splitted.at(1)), stoi(splitted.at(2)));
	cout << "Second date (dd/mm/yyyy): ";
	getline(cin, input);
	splitted = split(input, "/");
	while (true) {
		try {
			stoi(splitted.at(0));
			stoi(splitted.at(1));
			stoi(splitted.at(2));
			if (!validDate(stoi(splitted.at(0)), stoi(splitted.at(1)), stoi(splitted.at(2)))) {
				stoi("erro");
			}
			break;
		}
		catch (exception) {
			cout << "'" << input << "' is not a valid date. Insert a valid date: ";
			getline(cin, input);
			splitted = split(input, "/");
		}
	}
	Date date2(stoi(splitted.at(0)), stoi(splitted.at(1)), stoi(splitted.at(2)));
	if (date2 < date1) {
		Date aux = date1;
		date1 = date2;
		date2 = aux;
	}
	for (unsigned i = 0; i < agency.getPackets().size(); ++i) {
		for (unsigned j = 0; j < agency.getPackets().at(i).getSites().size(); ++j) {
			if (agency.getPackets().at(i).getBeginDate() >= date1 && agency.getPackets().at(i).getEndDate() <= date2) {
				pckts.push_back(agency.getPackets().at(i));
				break;
			}
		}
	}
	clear();
	if (pckts.size() == 0)
		cout << "No packet matches this interval\n" << endl;
	else
		cout << packetsToTable(pckts) << endl;
	if (yesOrNo("Another interval?")) {
		viewPacketsDate(agency);
		clear();
	}
	else {
		viewFilteredPackets(agency);
	}
	return 0;
}

unsigned viewPacketsDestinationDate(Agency agency) {
	string input, site;
	vector<string> splitted;
	vector<Packet> pckts;
	cout << "Destination: ";
	getline(cin, site);
	site = lower(site);
	cout << "First date (dd/mm/yyyy): ";
	getline(cin, input);
	splitted = split(input, "/");
	while (true) {
		try {
			stoi(splitted.at(0));
			stoi(splitted.at(1));
			stoi(splitted.at(2));
			if (!validDate(stoi(splitted.at(0)), stoi(splitted.at(1)), stoi(splitted.at(2)))) {
				stoi("erro");
			}
			break;
		}
		catch (exception) {
			cout << "'" << input << "' is not a valid date. Insert a valid date: ";
			getline(cin, input);
			splitted = split(input, "/");
		}
	}
	Date date1(stoi(splitted.at(0)), stoi(splitted.at(1)), stoi(splitted.at(2)));
	cout << "Second date (dd/mm/yyyy): ";
	getline(cin, input);
	splitted = split(input, "/");
	while (true) {
		try {
			stoi(splitted.at(0));
			stoi(splitted.at(1));
			stoi(splitted.at(2));
			if (!validDate(stoi(splitted.at(0)), stoi(splitted.at(1)), stoi(splitted.at(2)))) {
				stoi("erro");
			}
			break;
		}
		catch (exception) {
			cout << "'" << input << "' is not a valid date. Insert a valid date: ";
			getline(cin, input);
			splitted = split(input, "/");
		}
	}
	Date date2(stoi(splitted.at(0)), stoi(splitted.at(1)), stoi(splitted.at(2)));
	if (date2 < date1) {
		Date aux = date1;
		date1 = date2;
		date2 = aux;
	}
	for (unsigned i = 0; i < agency.getPackets().size(); ++i) {
		for (unsigned j = 0; j < agency.getPackets().at(i).getSites().size(); ++j) {
			if (agency.getPackets().at(i).getBeginDate() >= date1 && agency.getPackets().at(i).getEndDate() <= date2 && lower(agency.getPackets().at(i).getSites().at(j)) == site) {
				pckts.push_back(agency.getPackets().at(i));
				break;
			}
		}
	}
	clear();
	if (pckts.size() == 0)
		cout << "No packet matches this specification\n" << endl;
	else
		cout << packetsToTable(pckts) << endl;
	if (yesOrNo("Another destination and dates?")) {
		viewPacketsDestinationDate(agency);
		clear();
	}
	else {
		viewFilteredPackets(agency);
	}
	return 0;
}

unsigned packetSitesRanking(Agency agency) {
	cout << "How many of the first sites? ";
	string input;
	getline(cin, input);
	while (true) {
		try {
			if (stoi(input) < 1)
				stoi("erro");
			break;
		}
		catch (exception) {
			cout << "'" << input << "' is not a valid number. Insert a valid positive integer: ";
			getline(cin, input);
		}
	}
	cout << Table({"Place", "Site", "Visitors" }, rankingSites(agency, stoi(input))) << endl;
	pause();
	managePackets(agency);
	return 0;
}

unsigned newPacket(Agency agency) {
	string input, sites;
	Packet p(false, '?');
	clear();
	cout << packetsToTable({p}) << '\n';
	cout << "Packet Sites(0 to exit): ";
	getline(cin, input);
	if (input == "0")
	{
		managePackets(agency);
		return 0;
	}
	vector<string> splitted = strip(split(input, "-"));
	if (splitted.size() > 1) {
		vector<string> v = { splitted.at(0) };
		vector<string> v2 = strip(split(splitted.at(1), ","));
		v2.insert(v2.begin(), v.begin(), v.end());
		p.setSites(v2);
	} else {
		p.setSites({splitted.at(0)});
	}
	clear();
	cout << packetsToTable({p}) << '\n';
	cout << "Packet Start Date (dd/mm/yyyy)(0 to exit): ";
	getline(cin, input);
	if (input == "0")
	{
		managePackets(agency);
		return 0;
	}
	splitted = split(input, "/");
	vector<int> new_date = { stoi(splitted.at(0)), stoi(splitted.at(1)), stoi(splitted.at(2)) };
	p.setBeginDate(Date(new_date.at(0), new_date.at(1), new_date.at(2)));
	clear();
	cout << packetsToTable({ p }) << '\n';
	cout << "Packet End Date (dd/mm/yyyy)(0 to exit): ";
	getline(cin, input);
	if (input == "0")
	{
		managePackets(agency);
		return 0;
	}
	splitted = split(input, "/");
	new_date = { stoi(splitted.at(0)), stoi(splitted.at(1)), stoi(splitted.at(2)) };
	p.setEndDate(Date(new_date.at(0), new_date.at(1), new_date.at(2)));
	clear();
	cout << packetsToTable({ p }) << '\n';
	cout << "Packet Price per Person(0 to exit): ";
	getline(cin, input);
	if (input == "0")
	{
		managePackets(agency);
		return 0;
	}
	p.setPricePerPerson(stod(input));
	clear();
	cout << packetsToTable({ p }) << '\n';
	cout << "Packet Max Places(0 to exit): ";
	getline(cin, input);
	if (input == "0")
	{
		managePackets(agency);
		return 0;
	}
	p.setMaxPlaces(stoi(input));
	clear();
	cout << packetsToTable({ p }) << '\n';
	pause();

	agency.addPacket(p);

	save(agency);
	managePackets(agency);

	return 0;
}

unsigned editPackets(Agency agency){
	string input;
	cout << "Packet ID (0 to exit): ";
	getline(cin, input);
	int vat;
	while (true){
		try{
			vat = stoi(input);
			break;
		}catch (exception){
			cout << "'" << input << "' is not a valid ID. Insert a valid integer (0 to exit): ";
			getline(cin, input);
		}
	}
	if (vat == 0){
		managePackets(agency);
		return 0;
	}
	for (unsigned i = 0; i < agency.getPackets().size(); i++){
		if (vat == abs(stoi(agency.getPackets().at(i).getId()))){
			bool change = true;
			Table table({ "Key", "Change" }, { {"I", "ID"}, {"S", "Sites"}, {"ST", "Start date"}, {"ED", "End Date"}, {"P", "Price per person"} , {"SP", "Sold places"}, {"M", "Max places"}, {"G", "Go back"} });
			while (change) {
				clear();
				cout << packetsToTable({ agency.getPackets().at(i) }) << endl;
				cout << table << endl;
				cout << "Choose a field: ";
				getline(cin, input);
				if (input == "0")
				{
					managePackets(agency);
					return 0;
				}
				input = lower(input);
				while (input != "i" && input != "s" && input != "st" && input != "ed" && input != "p" && input != "sp" && input != "m" && input != "g") {
					clear();
					cout << packetsToTable({ agency.getPackets().at(i) }) << endl;
					cout << table << endl;
					cout << "'" << input << "' is not a valid field, choose a valid field(0 to exit): ";
					getline(cin, input);
					if (input == "0")
					{
						managePackets(agency);
						return 0;
					}
					input = lower(input);
				}
				string new_field;
				vector<Packet> pckts = agency.getPackets();
				if (input == "i") {
					if (stoi(pckts.at(i).getId()) > 0) {
						if(yesOrNo("Make it unavailable?"))
							pckts.at(i).setId(to_string(-stoi(pckts.at(i).getId())));
					} else {
						if (yesOrNo("Make it available?"))
							pckts.at(i).setId(to_string(-stoi(pckts.at(i).getId())));
					}
				}else if (input == "s") {
					cout << "New sites(0 to exit): ";
					getline(cin, new_field);
					if (new_field == "0")
					{
						managePackets(agency);
						return 0;
					}
					vector<string> splitted = strip(split(new_field, "-"));
					if (splitted.size() > 1) {
						vector<string> v = { splitted.at(0) };
						vector<string> v2 = strip(split(splitted.at(1), ","));
						v2.insert(v2.begin(), v.begin(), v.end());
						pckts.at(i).setSites(v2);
					} else {
						pckts.at(i).setSites({ splitted.at(0) });
					}
				}else if (input == "st") {
					cout << "New start date(0 to exit): ";
					getline(cin, new_field);
					if (new_field == "0")
					{
						managePackets(agency);
						return 0;
					}
					vector<string> splitted = split(new_field, "/");
					while (true){
						try{
							stoi(splitted.at(0));
							stoi(splitted.at(1));
							stoi(splitted.at(2));
							if (!validDate(stoi(splitted.at(0)), stoi(splitted.at(1)), stoi(splitted.at(2)))) {
								stoi("erro");
							}
							break;
						}catch (exception){
							cout << "'" << new_field << "' is not a valid date. Insert a valid date(0 to exit): ";
							getline(cin, new_field);
							if (new_field == "0")
							{
								managePackets(agency);
								return 0;
							}
							splitted = split(new_field, "/");
						}
					}
					vector<int> new_date = { stoi(splitted.at(0)), stoi(splitted.at(1)), stoi(splitted.at(2)) };
					pckts.at(i).setBeginDate(Date(new_date.at(0), new_date.at(1), new_date.at(2)));
				}else if (input == "ed") {
					cout << "New end date(0 to exit): ";
					getline(cin, new_field);
					if (new_field == "0")
					{
						managePackets(agency);
						return 0;
					}
					vector<string> splitted = split(new_field, "/");
					while (true) {
						try {
							stoi(splitted.at(0));
							stoi(splitted.at(1));
							stoi(splitted.at(2));
							if (!validDate(stoi(splitted.at(0)), stoi(splitted.at(1)), stoi(splitted.at(2)))) {
								stoi("erro");
							}
							break;
						}
						catch (exception) {
							cout << "'" << new_field << "' is not a valid date. Insert a valid date(0 to exit): ";
							getline(cin, new_field);
							if (new_field == "0")
							{
								managePackets(agency);
								return 0;
							}
							splitted = split(new_field, "/");
						}
					}
					vector<int> new_date = { stoi(splitted.at(0)), stoi(splitted.at(1)), stoi(splitted.at(2)) };
					pckts.at(i).setEndDate(Date(new_date.at(0), new_date.at(1), new_date.at(2)));
				}else if (input == "p") {
					cout << "New price per person(0 to exit): ";
					getline(cin, new_field);
					if (new_field == "0")
					{
						managePackets(agency);
						return 0;
					}
					while (true) {
						try {
							if (stof(new_field) < 0)
								stoi("erro");
							break;
						}
						catch (exception) {
							cout << "'" << new_field << "' is not a valid price. Insert a valid non-negative float(0 to exit): ";
							getline(cin, new_field);
							if (new_field == "0")
							{
								managePackets(agency);
								return 0;
							}
						}
					}
					pckts.at(i).setPricePerPerson(stod(new_field));
				}else if (input == "sp") {
					cout << "New sold places(0 to exit): ";
					getline(cin, new_field);
					if (new_field == "0")
					{
						managePackets(agency);
						return 0;
					}
					while (true) {
						try {
							if(stoi(new_field) < 0)
								stoi("erro");
							break;
						}
						catch (exception) {
							cout << "'" << new_field << "' is not a valid number. Insert a valid non-negative integer(0 to exit): ";
							getline(cin, new_field);
							if (new_field == "0")
							{
								managePackets(agency);
								return 0;
							}
						}
					}
					pckts.at(i).setSoldPlaces(stoi(new_field));
				}else if (input == "m") {
					cout << "New max places(0 to exit): ";
					getline(cin, new_field);
					if (new_field == "0")
					{
						managePackets(agency);
						return 0;
					}
					while (true) {
						try {
							if (stoi(new_field) < 0)
								stoi("erro");
							break;
						}
						catch (exception) {
							cout << "'" << new_field << "' is not a valid number. Insert a valid non-negative integer(0 to exit): ";
							getline(cin, new_field);
							if (new_field == "0")
							{
								managePackets(agency);
								return 0;
							}
						}
					}
					pckts.at(i).setMaxPlaces(stoi(new_field));
				}else if (input == "g") {
					break;
					return 0;
				}
				agency.setPackets(pckts);
				change = yesOrNo("Change another field?");
			}
			clear();
			cout << packetsToTable({ agency.getPackets().at(i) }) << endl;
			pause();
			managePackets(agency);
			return 0;
		}
	}
	cout << "Packet '" << input << "' not found" << endl;
	editPackets(agency);
	return 0;
}

unsigned deletePacket(Agency agency)
{
	string input;
	cout << "Packet ID (0 to exit): ";
	getline(cin, input);
	int vat;
	while (true)
	{
		try
		{
			vat = stoi(input);
			break;
		}
		catch (exception)
		{
			cout << "'" << input << "' is not a valid ID. Insert a valid integer (0 to exit):";
			getline(cin, input);
		}
	}

	if (vat == 0)
	{
		managePackets(agency);
		return 0;
	}

	for (unsigned i = 0; i < agency.getPackets().size(); i++)
	{
		if (vat == abs(stoi(agency.getPackets().at(i).getId())))
		{
			clear();
			cout << packetsToTable({ agency.getPackets().at(i) }) << endl;
			cout << "Are you sure you want to close packet " << agency.getPackets().at(i).getId() << "? (y/n) ";
			getline(cin, input);
			if (input == "y")
			{
				if (stoi(agency.getPackets().at(i).getId()) > 0) {
					string new_id = "-" + agency.getPackets().at(i).getId();
					vector<Packet> pckts = agency.getPackets();
					pckts.at(i).setId(new_id);
					agency.setPackets(pckts);
				}
			}
			managePackets(agency);
			return 0;
		}
	}
	cout << "Packet '" << input << "' not found" << endl;
	save(agency);
	deletePacket(agency);
	return 0;
}

unsigned packetsSoldToClient(Agency agency, char origin)
{

	string input;
	cout << "Clients VAT number(0 to exit):";
	getline(cin, input);
	int vat;
	while (true)
	{
		try
		{
			vat = stoi(input);
			break;
		}
		catch (exception)
		{
			cout << "'" << input << "' is not a valid VAT number. Insert a valid integer (0 to exit):";
			getline(cin, input);
		}
	}

	if (vat == 0)
	{
		if (origin == 0)
			viewInfo(agency);
		else
			managePackets(agency);
		return 0;
	}
	for (unsigned i = 0; i < agency.getClients().size(); i++)
	{
		Client c = agency.getClients().at(i);
		if (vat == c.getVATnumber())
		{
			clear();
			
			cout << packetsToTable(c.getPacketList());
			cout << "Packets sold to : " << c.getName() << endl << endl;
			pause();

			if (origin == 0)
				viewInfo(agency);
			else
				managePackets(agency);
			return 0;
		}
	}
	cout << "Client '" << input << "' not found" << endl;
	packetsSoldToClient(agency,origin);

	return 0;
}

unsigned soldPackets(Agency agency)
{
	clear();
	double price = 0;
	unsigned sold = 0;
	for (Packet pckt : agency.getPackets())
	{
		price += pckt.getSoldPlaces() * pckt.getPricePerPerson();
		sold += pckt.getSoldPlaces();
	}
	ostringstream p;
	p << fixed << setprecision(2) << price;
	cout << Table({"Total","Value"}, { {"Packets sold",to_string(sold) +" packets"},{"Price","$ "+p.str() } });
	pause();

	viewInfo(agency);

	return 0;
}