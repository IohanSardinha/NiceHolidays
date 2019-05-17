#pragma once
#include <cassert>
#include <iostream>
#include <iomanip>
#include <map>
#include <sstream>
#include <utility>
#include "Agency.h"
#include "Table.h"
#include "Agency.h"
unsigned mainMenu(Agency);								//
unsigned exit(Agency);									//
unsigned manageClients(Agency);							//
unsigned managePackets(Agency);							//
unsigned packetIndications(Agency);						//
unsigned viewInfo(Agency);								//
unsigned viewClient(Agency,char);						// 
unsigned viewClients(Agency, char);						//
unsigned editClients(Agency);							//	
unsigned newClient(Agency);								//
unsigned deleteClient(Agency);							//	
unsigned buyPacket(Agency);								//
unsigned viewPackets(Agency, char);						//
unsigned viewFilteredPackets(Agency);					//
unsigned viewPacketsDestination(Agency);				//
unsigned viewPacketsDate(Agency);						//
unsigned viewPacketsDestinationDate(Agency);			//
unsigned packetSitesRanking(Agency);					//
unsigned editPackets(Agency);							//
unsigned newPacket(Agency);								//
unsigned deletePacket(Agency);							//
unsigned packetsSoldToClient(Agency,char);				//
unsigned soldPackets(Agency);							//
