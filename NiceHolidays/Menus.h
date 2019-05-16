#pragma once
#include <iostream>
#include "Agency.h"
#include "Table.cpp"
inline unsigned mainMenu(Agency);
inline unsigned exit();
inline unsigned manageClients(Agency);
inline unsigned managePackets(Agency);
inline unsigned viewInfo(Agency);
inline unsigned viewClients(Agency, unsigned);
inline unsigned editClients(Agency);
inline unsigned newClient(Agency);
inline unsigned deleteClient(Agency);
inline unsigned buyPacket(Agency);
inline unsigned viewPackets(Agency, unsigned);
inline unsigned editPackets(Agency);
inline unsigned newPacket(Agency);
inline unsigned deletePacket(Agency);
inline unsigned packetsSoldToClient(Agency);
inline unsigned soldPackets(Agency);