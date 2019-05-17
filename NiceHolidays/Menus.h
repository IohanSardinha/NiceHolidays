#pragma once
#include <iostream>
#include <iomanip>
#include <sstream>
#include "Agency.h"
#include "Table.h"
#include "Agency.h"
unsigned mainMenu(Agency);
unsigned exit(Agency);
unsigned manageClients(Agency);
unsigned managePackets(Agency);
unsigned viewInfo(Agency);
unsigned viewClients(Agency, unsigned);
unsigned editClients(Agency);
unsigned newClient(Agency);
unsigned deleteClient(Agency);
unsigned buyPacket(Agency);
unsigned viewPackets(Agency, unsigned);
unsigned editPackets(Agency);
unsigned newPacket(Agency);
unsigned deletePacket(Agency);
unsigned packetsSoldToClient(Agency);
unsigned soldPackets(Agency);