#pragma once
#include "Packet.h"
// ----------------------------------------------------------------------------------------
//                                       Constructors
// ----------------------------------------------------------------------------------------
Packet::Packet(vector<string> s, Date b, Date e, double p, unsigned m){
	numPackets++;
	id = to_string(numPackets);
	sites = s;
	begin = b;
	end = e;
	pricePerPerson = p;
	soldPlaces = 0;
	maxPlaces = m;
}
// ----------------------------------------------------------------------------------------
//                                           Gets                                          
// ----------------------------------------------------------------------------------------
string Packet::getId() const {
	return id;
}
vector<string> Packet::getSites() const {
	return sites;
}
Date Packet::getBeginDate() const {
	return begin;
}
Date Packet::getEndDate() const {
	return end;
}
double Packet::getPricePerPerson() const {
	return pricePerPerson;
}
unsigned Packet::getSoldPlaces() const {
	return soldPlaces;
}
unsigned Packet::getMaxPlaces() const {
	return maxPlaces;
}
// ----------------------------------------------------------------------------------------
//                                           Sets                                          
// ----------------------------------------------------------------------------------------
bool Packet::setId(string i) {
	id = i;
	return true;
}
bool Packet::setSites(vector<string> s) {
	sites = s;
	return true;
}
bool Packet::setBeginDate(Date b) {
	begin = b;
	return true;
}
bool Packet::setEndDate(Date e) {
	end = e;
	return true;
}
bool Packet::setPricePerPerson(double p) {
	pricePerPerson = p;
	return true;
}
bool Packet::setMaxPlaces(unsigned m) {
	maxPlaces = m;
	return true;
}
// ----------------------------------------------------------------------------------------
//                                  Input Output Functions                                 
// ----------------------------------------------------------------------------------------
ostream& operator<<(ostream& out, const Packet& packet) {
	out << str(packet);
	return out;
}
ofstream& operator<<(ofstream& out, const Packet& packet) {
	out << packet.getId() << '\n';
	out << packet.getSites().at(0);
	if (packet.getSites().size() > 1){
		out << " - ";
		bool first = true;
		for (unsigned i = 1; i < packet.getSites().size(); ++i){
			if (!first)
				out << ", ";
			else
				first = false;
			out << packet.getSites().at(i);
		}
	}
	out << '\n';
	out << packet.getBeginDate() << '\n';
	out << packet.getEndDate() << '\n';
	out << packet.getPricePerPerson() << '\n';
	out << packet.getSoldPlaces() + packet.getMaxPlaces() << '\n';
	out << packet.getMaxPlaces();
	return out;
}
// ----------------------------------------------------------------------------------------
//                                    Auxiliary Functions
// ----------------------------------------------------------------------------------------
string str(Packet packet) {
	ostringstream res;
	res << "ID    : " << packet.getId() << "\n";
	res << "Sites : ";
	bool first = true;
	for (const auto& site : packet.getSites()){
		if (!first)
			res << ", ";
		else
			first = false;
		res << site;
	}
	res << '\n';
	res << "Begin : " << packet.getBeginDate() << '\n';
	res << "End   : " << packet.getEndDate() << '\n';
	res << "Price : " << fixed << setprecision(2) << packet.getPricePerPerson() << '\n';
	res << "Places: " << packet.getMaxPlaces();
	return res.str();
}