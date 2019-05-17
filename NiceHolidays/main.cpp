#include "Agency.h"
#include "Menus.h"
using namespace std;
unsigned long Packet::numPackets = 0;

int main() {
	Agency agency(AGENCY_FILE_NAME);   					// create the agency
	mainMenu(agency); 									// initial menu inicial with the major options of the application
	return 0;
}
