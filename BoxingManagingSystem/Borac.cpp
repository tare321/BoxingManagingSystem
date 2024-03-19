#include <iostream>
#include "Borac.h"
#include "Osoba.h"
//definicija klase Borac, njenih metoda i atributa



Borac::Borac()
{
}

Borac::Borac(const Borac& b)
{
    this->champ = b.champ;
    this->ime = b.ime;
    this->prezime = b.prezime;
    this->kategorija = b.kategorija;
    this->id = b.id;
    this->godine = b.godine;
    this->visina = b.visina;
    this->kg = b.kg;
    this->wins = b.wins;
    this->ties = b.ties;
    this->ls = b.ls;
}

void Borac::setChamp()
{
}


void Borac::setId()
{
    std::cout << "Unesite id: ";
    std::cin >> this->id;
}

void Borac::setIdSaParametrom(int* a)
{
    this->id = *a;
}

void Borac::setKategorija()
{
    if (kg >= 86)
    {
        this->kategorija = "Heavyweight";
    }
    else if (kg >= 62)
    {
        this->kategorija = "Middleweight";
    }
    else
    {
        this->kategorija = "Lightweight";
    }
}

void Borac::setGodine()
{
    std::cout << "Unesite godine: ";
    std::cin >> this->godine;
    std::cin.ignore();
}

void Borac::setVisina()
{
    std::cout << "Unesite visinu: ";
    std::cin >> this->visina;
    std::cin.ignore();
}

void Borac::setKg()
{
    std::cout << "Unesite kg: ";
    std::cin >> this->kg;
    std::cin.ignore();
}

void Borac::setWins()
{
    std::cout << "Wins: ";
    std::cin >> this->wins;
    std::cin.ignore();
}

void Borac::setTies()
{
    std::cout << "Ties: ";
    std::cin >> this->ties;
    std::cin.ignore();
}

void Borac::setLs()
{
    std::cout << "Losses: ";
    std::cin >> this->ls;
    std::cin.ignore();
}

int Borac::getChamp()
{
    return this->champ;
}

int Borac::getId()
{
    return this->id;
}

std::string Borac::getKategorija()
{
    return this->kategorija;
}

int Borac::getGodine()
{
    return this->godine;
}

int Borac::getVisina()
{
    return this->visina;
}

int Borac::getKg()
{
    return this->kg;
}

int Borac::getWins()
{
    return this->wins;
}

int Borac::getTies()
{
    return this->ties;
}

int Borac::getLs()
{
    return this->ls;
}

std::istream& operator>>(std::istream& stream, Borac& b)
{
    std::cout << "Unos borca:\n";
    b.setIme();
    b.setPrezime();
    b.setGodine();
    b.setKg();
    b.setKategorija();
    b.setVisina();
    std::cout << "\tRezultat:\n";
    b.setWins();
    b.setTies();
    b.setLs();
    return stream;
}

std::ostream& operator<<(std::ostream& stream, Borac& b)
{
    if (b.getChamp() == 1) {
        stream << "ID: \t\t" << b.getId() << "\nIme: \t\t" << b.getIme() << " " << b.getPrezime() << "|CHAMP|\nGod: \t\t" << b.getGodine() << "\nTezina: \t" << b.getKg() << "kg - " << b.getKategorija() << "\nVisina: \t"
            << b.getVisina() << "cm\nW-T-L:\t\t(" << b.getWins() << " - " << b.getTies() << " - " << b.getLs() << ")\n";
    }
    else {
        stream << "ID: \t\t" << b.getId() << "\nIme: \t\t" << b.getIme() << " " << b.getPrezime() << "\nGod: \t\t" << b.getGodine() << "\nTezina: \t" << b.getKg() << "kg - " << b.getKategorija() << "\nVisina: \t"
            << b.getVisina() << "cm\nW-T-L:\t\t(" << b.getWins() << " - " << b.getTies() << " - " << b.getLs() << ")\n";
    }
	return stream;
}
