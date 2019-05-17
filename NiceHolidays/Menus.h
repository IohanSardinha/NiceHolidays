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
unsigned mainMenu(Agency);								//Initial menu
unsigned exit(Agency);									//Exit menu
unsigned manageClients(Agency);							//Menu with actions about the client
unsigned managePackets(Agency);							//Menu with actions about the packets
unsigned packetIndications(Agency);						//Show the sugestion of packets for users, with the packets in the most visited that each user hasn't visited
unsigned viewInfo(Agency);								//Menu with actions tha show all kinds of data
unsigned viewClient(Agency,char);						//Show a specific client data
unsigned viewClients(Agency, char);						//Show all clients data
unsigned editClients(Agency);							//Let the user edit specific client data
unsigned newClient(Agency);								//Creates a new client with user input
unsigned deleteClient(Agency);							//Deletes an existing client
unsigned buyPacket(Agency);								//Subscribes a client to a packet if possible(packet is available, has available places, the user isn't subscribed yet)
unsigned viewPackets(Agency, char);						//Show all packets data
unsigned viewFilteredPackets(Agency);					//Show packets data filtered by given conditions
unsigned viewPacketsDestination(Agency);				//Show packets data that have a given destination
unsigned viewPacketsDate(Agency);						//Show packets data that have the begin and end date btween a given range of dates
unsigned viewPacketsDestinationDate(Agency);			//Show packets data filtered by both date and destination
unsigned packetSitesRanking(Agency);					//Show the N most visited sites, where N is a integer given by the user
unsigned editPackets(Agency);							//Let the user edit a specific packet data
unsigned newPacket(Agency);								//Creates a new packet with user input
unsigned deletePacket(Agency);							//Deletes an existing packet
unsigned packetsSoldToClient(Agency,char);				//Show all the packets a given client has subsribed to
unsigned soldPackets(Agency);							//Show the total value of all packets sold to all clients and how many packets were sold
