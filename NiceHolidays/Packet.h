#pragma once
#include <fstream>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include <vector>
#include "defs.h"
#include "Date.cpp"
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
		inline Packet();
		inline Packet(vector<string>, Date, Date, double, unsigned);		// 
		inline string getId() const;										// 
		inline unsigned long getNumPackets() const;
		inline vector<string> getSites() const;							// 
		inline Date getBeginDate() const;									// 
		inline Date getEndDate() const;									// 
		inline double getPricePerPerson() const;							// 
		inline bool setNumPacket(unsigned long);
		inline unsigned getSoldPlaces() const;								// 
		inline unsigned getMaxPlaces() const;								// 
		inline bool setId(string);  										// to set negatve if "deprecated"
		inline bool setSites(vector<string>);								// 
		inline bool setBeginDate(Date);									// 
		inline bool setEndDate(Date);										// 
		inline bool setPricePerPerson(double);								// 
		inline bool setMaxPlaces(unsigned);	
		inline bool setSoldPlaces(unsigned);
		inline friend ostream& operator<<(ostream&, const Packet&);		// 
		inline friend ofstream& operator<<(ofstream&, const Packet&);		// 
};
inline string str(Packet packet);											// 