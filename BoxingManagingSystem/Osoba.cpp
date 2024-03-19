#include <iostream>
#include <string>
#include "Osoba.h"



std::string Osoba::getIme() {
	return this->ime;
}

void Osoba::setIme() {
	std::cout << "Unesite ime: ";
	std::getline(std::cin, this->ime);
}

std::string Osoba::getPrezime() {
	return this->prezime;
}

void Osoba::setPrezime() {
	std::cout << "Unesite prezime: ";
	std::getline(std::cin, this->prezime);
}

Osoba::Osoba() 
{

}

Osoba::Osoba(std::string i, std::string prezi)
{
	this->ime = i;
	this->prezime = prezi;
}

Osoba::Osoba(const Osoba& o)
{
	this->ime = o.ime;
	this->prezime = o.prezime;
}
