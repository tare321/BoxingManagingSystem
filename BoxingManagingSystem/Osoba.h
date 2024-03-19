#pragma once
#include <string>
//definicija klase Osoba, njenih metoda i atributa

/* 
* :::::::::::::::: OVDJE NEMA NISTA ::::::::::::::::::::
*/

class Osoba
{
private: 
	std::string ime;
	std::string prezime;
public:
	void setIme();
	std::string getIme();
	void setPrezime();
	std::string getPrezime();
	Osoba();
	Osoba(std::string ime, std::string prezime);
	Osoba(const Osoba& o);
	~Osoba() = default;
	friend class Borac;
};

