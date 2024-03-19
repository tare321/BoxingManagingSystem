#include "Arena.h"
#include <limits>
#include <fstream>

Arena::Arena()
{
}

Arena::Arena(int ida, std::string arenaName, std::string city, int capacity, int wMjesta, int eMjesta, int sMjesta, int nMjesta, int wVipMjesta, int eVipMjesta, int sVipMjesta, int nVipMjesta,
	int brRed, int brKolona, int brVipRed, int brVipKolona, std::vector<std::vector<int>> wVM, std::vector<std::vector<int>> eVM, std::vector<std::vector<int>> sVM, std::vector<std::vector<int>> nVM,
	std::vector<std::vector<int>> wVVM, std::vector<std::vector<int>> eVVM, std::vector<std::vector<int>> sVVM, std::vector<std::vector<int>> nVVM)
{
	this->idArene = ida;
	this->imeArene = arenaName;
	this->grad = city;
	this->kapacitet = capacity;
	this->wMjesta = wMjesta;
	this->eMjesta = eMjesta;
	this->sMjesta = sMjesta;
	this->nMjesta = nMjesta;
	this->wVipMjesta = wVipMjesta;
	this->eVipMjesta = eVipMjesta;
	this->sVipMjesta = sVipMjesta;
	this->nVipMjesta = nVipMjesta;
	this->wVektorMjesta = wVM;
	this->eVektorMjesta = eVM;
	this->sVektorMjesta = sVM;
	this->nVektorMjesta = nVM;
	this->wVipVektorMjesta = wVVM;
	this->eVipVektorMjesta = eVVM;
	this->sVipVektorMjesta = sVVM;
	this->nVipVektorMjesta = nVVM;
	this->brRed = brRed;
	this->brKolona = brKolona;
	this->brVipRed = brVipRed;
	this->brVipKolona = brVipKolona;
}

Arena::Arena(int ida, std::string arenaName, std::string city, int brRed, int brKol, int brVipRed, int brVipKolona) {
	this->idArene = ida;
	this->imeArene = arenaName;
	this->grad = city;
	this->brRed = brRed;
	this->brKolona = brKol;
	this->brVipRed = brVipRed;
	this->brVipKolona = brVipKolona;
	// mnozi ono
	setwMjesta();
	setwVipMjesta();
	seteMjesta();
	seteVipMjesta();
	setsMjesta();
	setsVipMjesta();
	setnMjesta();
	setnVipMjesta();
	//postavlja vektore
	setKapacitet();
}
//SETERI

void Arena::setIDarene()
{
	std::cout << "ID arene: ";
	std::cin >> this->idArene;
}

void Arena::setIDareneSaParametrom(int* a)
{
	this->idArene = *a;
}

void Arena::setImeArene()
{
	std::cin.ignore();
	std::string iimeArene;
	std::cout << "Ime arene: ";
	std::getline(std::cin, iimeArene);
	this->imeArene = iimeArene;
}

void Arena::setGrad()
{
	std::string gradd;
	std::cout << "Naziv grada: ";
	std::getline(std::cin, gradd);
	this->grad = gradd;
}

void Arena::setKapacitet()
{
	this->kapacitet = (this->brRed * this->brKolona) + (this->brVipRed * this->brVipKolona);
}

void Arena::setwMjesta()
{
	this->wMjesta = this->getbrKolona()* this->getbrRed();
}

void Arena::seteMjesta()
{
	this->eMjesta = this->getbrKolona() * this->getbrRed();
}

void Arena::setsMjesta()
{
	this->sMjesta = this->getbrKolona() * this->getbrRed();
}

void Arena::setnMjesta()
{
	this->nMjesta = this->getbrKolona() * this->getbrRed();
}

void Arena::setwVipMjesta()
{
	this->wVipMjesta = this->getbrVipKolona() * this->getbrVipRed();
}

void Arena::seteVipMjesta()
{
	this->eVipMjesta = this->getbrVipKolona() * this->getbrVipRed();
}

void Arena::setsVipMjesta()
{
	this->sVipMjesta = this->getbrVipKolona() * this->getbrVipRed();
}

void Arena::setnVipMjesta()
{
	this->nVipMjesta = this->getbrVipKolona() * this->getbrVipRed();
}

void Arena::setbrRed()
{
	std::cin >> this->brRed;
}

void Arena::setbrKolona()
{
	std::cin >> this->brKolona;
}

void Arena::setbrVipRed()
{
	std::cin >> this->brVipRed;
}

void Arena::setbrVipKolona()
{
	std::cin >> this->brVipKolona;
}

//GETERI

int Arena::getIDarene()
{
	return this->idArene;
}

std::string Arena::getImeArene()
{

	return this->imeArene;
}

std::string Arena::getGrad()
{
	return this->grad;
}

int Arena::getKapacitet()
{
	return this->kapacitet;
}

int Arena::getwMjesta(Arena& a)
{
	return this->wMjesta;
}

int Arena::geteMjesta(Arena& a)
{
	return this->eMjesta;
}

int Arena::getsMjesta(Arena& a)
{
	return this->sMjesta;
}

int Arena::getnMjesta(Arena& a)
{
	return this->nMjesta;
}

int Arena::getwVipMjesta(Arena& a)
{
	return this->wVipMjesta;
}

int Arena::geteVipMjesta(Arena& a)
{
	return this->eVipMjesta;
}

int Arena::getsVipMjesta(Arena& a)
{
	return this->sVipMjesta;
}

int Arena::getnVipMjesta(Arena& a)
{
	return this->nVipMjesta;
}

int Arena::getbrRed()
{
	return this->brRed;
}

int Arena::getbrKolona()
{
	return this->brKolona;
}

int Arena::getbrVipRed()
{
	return this->brVipRed;
}

int Arena::getbrVipKolona()
{
	return this->brVipKolona;
}

void Arena::uFajl()
{
	std::fstream myFile;
	myFile.open("Arene.txt", std::ios::app);
	if (myFile.is_open())
	{
		myFile << "Naziv arene [" << idArene << "] = " << imeArene << "\n";
		myFile << "Grad arene [" << idArene << "] = " << grad << "\n";
		myFile << "Kapacitet arene [" << idArene << "] = " << kapacitet << "\n";
		myFile.close();
	}
}

std::istream& operator>>(std::istream& stream, Arena& a) // ime grad 
{
	std::cout << "Unos nove arene: \n";
	std::cout << "Arena ima cetiri dijela (Zapad, Istok, Jug, Sjever) i Vip dio\nUnesite broj redova obicnog dijela: \n";
	a.setbrRed();
	std::cout << "Unesite broj kolona obicnog dijela: \n";
	a.setbrKolona();
	std::cout << "Unesite broj redova VIP dijela: \n";
	a.setbrVipRed();
	std::cout << "Unesite broj kolona VIP dijela: \n";
	a.setbrVipKolona();
	// mnozi ono
	a.setwMjesta();
	a.setwVipMjesta();
	a.seteMjesta();
	a.seteVipMjesta();
	a.setsMjesta();
	a.setsVipMjesta();
	a.setnMjesta();
	a.setnVipMjesta();
	//postavlja vektore
	a.setKapacitet();
	a.setImeArene();
	a.setGrad();
	a.uFajl();
	return stream;
}

std::ostream& operator<<(std::ostream& stream, Arena& a) 
{
	stream << "Ime arene: " << a.getImeArene() << "\nLokacija arene: " << a.getGrad() << "\nKapacitet arene: " << a.getKapacitet()*4 << std::endl;
	return stream;
}