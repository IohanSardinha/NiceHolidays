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
		static unsigned long numPackets;							// 
		string id; 													// packet unique identifier
		vector<string> sites; 										// touristic sites to visit
		Date begin;  												// begin date
		Date end;  													// end date
		double pricePerPerson; 										// price per person
		unsigned soldPlaces; 										// number of sold places
		unsigned maxPlaces; 										// number of places still available in the packet (updated whenever the packet is sold to a new client)
	public:
		Packet();
		Packet(bool id,int nothing);
		Packet(vector<string>, Date, Date, double, unsigned);		// 
		string getId() const;										// 
		unsigned long getNumPackets() const;
		vector<string> getSites() const;							// 
		Date getBeginDate() const;									// 
		Date getEndDate() const;									// 
		double getPricePerPerson() const;							// 
		bool setNumPacket(unsigned long);
		unsigned getSoldPlaces() const;								// 
		unsigned getMaxPlaces() const;								// 
		bool setId(string);  										// to set negatve if "deprecated"
		bool setSites(vector<string>);								// 
		bool setBeginDate(Date);									// 
		bool setEndDate(Date);										// 
		bool setPricePerPerson(double);								// 
		bool setMaxPlaces(unsigned);	
		bool setSoldPlaces(unsigned);
		friend ostream& operator<<(ostream&, const Packet&);		// 
		friend ofstream& operator<<(ofstream&, const Packet&);		// 
};
string str(Packet packet);											// 
Packet getPacketById(vector<Packet> pckts, unsigned id);