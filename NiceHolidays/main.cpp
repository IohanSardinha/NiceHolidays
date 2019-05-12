#include <iostream>
#include <string>
#include <vector>
#include "utils.h"
#include "Date.cpp"
//#include "Agency.cpp"
#include "Packet.cpp"
#include "Client.cpp"
//#include "Menus.cpp"
#include "Table.cpp"
#include "Address.cpp"
using namespace std;
int main() {
	//Agency agency(AGENCY_FILE_NAME);   					// create the agency
	//mainMenu(agency); 									// initial menu inicial with the major options of the application
	Table table({"Key", "Change"}, {{"N", "Name"}, {"F", "Family Size"}, {"A", "Address"}, {"P", "Packs"}});
	Packet packet({"Madeira", "Funchal", "Porto Santo"}, Date(1, 8, 2019), Date(5, 8, 2019), 300, 50);
	Address address("Rua Sem Fim", 200, "5Esq", "1200-001", "Lisboa");
	Client client("Antonio Jose Silva", 1232894, 4, address);
	cout << table << '\n' << packet << '\n';
	cout << client << '\n';
	ofstream f;
	f.open("test.txt");
	f << packet << '\n' << SEPARATOR << '\n';
	f << client << '\n' << SEPARATOR << '\n';
	f.close();
	return 0;
}
