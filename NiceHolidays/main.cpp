#include <iostream>
#include <string>
#include <vector>
#include "utils.h"
#include "Date.h"
//#include "Agency.h"
#include "Packet.h"
//#include "Menus.h"
#include "Table.h"
using namespace std;
int main() {
	//Agency agency(AGENCY_FILE_NAME);   					// create the agency
	//mainMenu(agency); 									// initial menu inicial with the major options of the application
	Date d1(20, 7, 1999);
	Date d2;
	cout << d2 << '\n';
	cout << d2 - d1 << '\n';
	Table t({"Key", "Change"}, {{"N", "Name"}, {"F", "Family Size"}, {"A", "Address"}, {"P", "Packs"}});
	cout << t;
	Date b(1, 8, 2019);
	Date e(5, 8, 2019);
	Packet p({"Madeira", "Funchal", "Porto Santo"}, b, e, 300, 50);
	cout << p << '\n';
	ofstream f;
	f.open("test.txt");
	f << p << '\n' << SEPARATOR << '\n';
	f.close();
	return 0;
}
