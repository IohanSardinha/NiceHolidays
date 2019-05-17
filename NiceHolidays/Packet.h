#pragma once
#include <fstream>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include <vector>
#include "defs.h"
#include "Date.h"
using namespace std;
class Packet{
	private:
		bool empty = false;
		static unsigned long numPackets;							// Number of packets
		string id; 													// packet unique identifier
		vector<string> sites; 										// touristic sites to visit
		Date begin;  												// begin date
		Date end;  													// end date
		double pricePerPerson; 										// price per person
		unsigned soldPlaces; 										// number of sold places
		unsigned maxPlaces; 										// number of places still available in the packet (updated whenever the packet is sold to a new client)
	public:
		Packet();													// Empty constructor
		Packet(bool id,int nothing);								// Constructor of an empty packet that asks if the id should be zero or the next id after the greatest
		Packet(vector<string>, Date, Date, double, unsigned);		// Constructor with the attributes
		bool isEmpty() const;										// Returns true if the packet is empty
		bool isAvailable() const;									// Returns true if id is positive
		string getId() const;										// Returns ID
		unsigned long getNumPackets() const;						// Returns the total number of packets
		vector<string> getSites() const;							// Returns a vector with th sites
		Date getBeginDate() const;									// Returns begin date
		Date getEndDate() const;									// Returns end date
		double getPricePerPerson() const;							// Returns the cost of the packet
		bool setNumPacket(unsigned long);							// Sets the number of packets
		unsigned getSoldPlaces() const;								// Returns the number of sold places
		unsigned getMaxPlaces() const;								// Returns the maximum of places
		bool setId(string);  										// To set negative if "deprecated"
		bool setSites(vector<string>);								// Sets the sites
		bool setBeginDate(Date);									// Sets the begin date
		bool setEndDate(Date);										// Sets the end date
		bool setPricePerPerson(double);								// Sets the cost of the packet
		bool setMaxPlaces(unsigned);								// Sets the maximum of places
		bool setSoldPlaces(unsigned);								// Sets the number of sold packets
		friend ostream& operator<<(ostream&, const Packet&);		// Puts in ostream a formated packet
		friend ofstream& operator<<(ofstream&, const Packet&);		// Puts into a file a formated version of a packet
};
string str(Packet packet);											// Turns a packet into a string
Packet getPacketById(vector<Packet> pckts, unsigned id);			// Returns the packet that has the id, returns an empty one if not found