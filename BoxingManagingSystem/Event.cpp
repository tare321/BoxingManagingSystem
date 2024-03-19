#include <iostream>
#include "Event.h"
#include "Arena.h"

/*for (int i = 0; i < eVipVektorMjesta.size(); i++) {
	for (int j = 0; j < eVipVektorMjesta[i].size(); j++) {
		this->eVipVektorMjesta[i][j] = 0;
	}
}
*/


Event::Event(int niz[6][2])
{
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 2; j++) {
			ListaBorbi[i][j] = niz[i][j];
		}
	}
}

Event::Event(std::string imeArene, std::string grad, int idArene, int id, int dan, int mjesec, int godina)
{
	this->imeArene = imeArene;
	this->grad = grad;
	this->idArene = idArene;
	this->id = id;
	this->dan = dan;
	this->mjesec = mjesec;
	this->godina = godina;
}

Event::Event(const Event& e)
{
	this->imeArene = e.imeArene;
	this->grad = e.grad;
	this->idArene = e.idArene;
	this->id = e.id;
	this->dan = e.dan;
	this->mjesec = e.mjesec;
	this->godina = e.godina;
}

void Event::setIdEventaSaParametrom(int* id)
{
	this->id = *id;
}

void Event::setId()
{
	this->id = id;
}

std::string Event::getImeArene()
{
	return this->imeArene;
}

void Event::setImeArene(std::string* ime)
{
	this->imeArene = *ime;
}

std::string Event::getGrad()
{
	return this->grad;
}

void Event::setGrad(std::string* grad)
{
	this->grad = *grad;
}

int Event::getListaBorbi(int x, int y)
{
	return this->ListaBorbi[x][y];
}

void Event::setListaBorbi(int x, int y, int vrijednost) // x pozicija, y id
{
	this->ListaBorbi[x][y] = vrijednost;
}

int Event::getIdArene()
{
	return this->idArene;
}

void Event::setIdArene(int* a)
{
	this->idArene = *a;
}

int Event::getId()
{
	return this->id;
}

// OVO TREBAS SREDITI IZNAD

void Event::setDan()
{
	int day, mj = 31;
noviDan:
	std::cout << "Unesite dan: ";
	std::cin >> day;
	if (day < 1 || day > mj)
	{
		std::cout << "Unijeli ste nepravilan dan\n";
		goto noviDan;
	}
	else
	{
		if (mjesec == 4 || mjesec == 6 || mjesec == 9 || mjesec == 11)
		{
			if (dan > 30) {
				std::cout << "Uneseni mjesec ima 30 dana\n";
				mj = 30;
				goto noviDan;
			}
			else
			{
				this->dan = day;
			}
		}
		else if (mjesec == 2)
		{
			if (jePrestupna(godina))
			{
				if (day > 29)
				{
					mj = 29;
					std::cout << "Februar u ovoj godini ima 29 dana\n";
					goto noviDan;
				}
				else
				{
					this->dan = day;
				}
			}
			else
			{
				if (day > 28)
				{
					mj = 28;
					std::cout << "Februar u ovoj godini ima 28 dana\n";
					goto noviDan;
				}
				else
				{
					this->dan = day;
				}
			}
		}
		else
		{
			this->dan = day;
		}
	}
	std::cin.ignore();
}

int Event::getDan()
{
	return this->dan;
}

void Event::setMjesec()
{
	int mj;
noviMjesec:
	std::cout << "Unesite mjesec: ";
	std::cin >> mj;
	if (mj < 1 || mj > 12)
	{
		std::cout << "Unijeli ste nepravilan mjesec\n";
		goto noviMjesec;
	}
	else
	{
		this->mjesec = mj;
	}
}

int Event::getMjesec()
{
	return this->mjesec;
}

void Event::setGodina()
{
	int god;
	std::cout << "Unesite godinu: ";
	std::cin >> god;
	this->godina = god;
}

int Event::getGodina()
{
	return this->godina;
}

void Event::getDatum()
{
	std::cout << Event::getDan() << "/" << Event::getMjesec()
		<< "/" << Event::getGodina();
}

bool Event::jePrestupna(int god)
{
	return (((god % 4 == 0) && (god % 100 != 0)) || (god % 400 == 0));
}

std::istream& operator>>(std::istream& stream, Event& e)
{
	std::cout << "Unos evetna:\n";
	e.setGodina();
	e.setMjesec();
	e.setDan();
	return stream;
}

std::ostream& operator<<(std::ostream& stream, Event& e)
{
	stream << "\n\t\t    BOXING NIGHT " << e.getId() << "\n\t    Datum odrzavanja: " << e.getDan() << "." << e.getMjesec() << "." << e.getGodina() << ". godine\n" << "\t    Mjesto: Arena " << e.getImeArene()
			<< ", " << e.getGrad() << "\n\n\t\t\tBORBE\n";
	return stream;
}
