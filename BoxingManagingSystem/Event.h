#pragma once
#include <vector>
#include <iostream>
#include <string>
#include "Borac.h"
//definicija klase Event, njenih metoda i atributa

/* 
* Event, ugl treba jos skontati kartu event je zadnji
* jest karta kupuje event, ali bez karte nema ni eventa
* pogotovo zbog tog ispisa eventa, kako spakovati borbe i sve to, najvjerovatnije klasa ali vidjet cemo, datum hajd, id same, doable, id eventa je bitan
* mozda bude i ovdje txt file ali vidjet cemo. to samo ako skontam globalni niz/vektor i uspijem ga kao klasu napraviti. Ako i bude txt borbe bit ce samo indeksi 
* od raznih id-eova da mogu ispisati sve fino u pregledu evetna. skontat sve ostalo :D 
*/

class Event
{
private:
	std::string imeArene;
	std::string grad;
	int idArene;
	int id;
	int dan;
	int mjesec;
	int godina;

public:
	Event() = default;
	int ListaBorbi[6][2] = { {0,0}, {0,0}, {0,0}, {0,0}, {0,0}, {0,0} };
	Event(int niz[6][2]);
	Event(std::string imeArene, std::string grad, int idArene, int id, int dan, int mjesec, int godina);
	Event(const Event& e);
	void setIdEventaSaParametrom(int* id);
	void setId();//sto se ovog tice to sutra uradit i pobrini
	// se da imas vektor u koji ces stavljati od 0-x id-eve
	// i kad ga dadne varijabli neka vidi ima li ga u vektoru
	// je li dodijeljen prije ako nije daj ga njemu, ugl sutr
	// detalji

	std::string getImeArene();
	void setImeArene(std::string *ime);
	std::string getGrad();
	void setGrad(std::string *grad);
	int getIdArene();
	void setIdArene(int* a);
	// :::::::::::: ARENA IZNAD _::::::::::::::::::::::

	int getListaBorbi(int x, int y);
	void setListaBorbi(int x, int y, int vrijednost);

	int getId();
	void setDan();
	int getDan();
	void setMjesec();
	int getMjesec();
	void setGodina();
	int getGodina();
	void getDatum();

	// :::::::::::: DATUM I OSTALO IZNAD

	friend std::istream& operator>>(std::istream& stream, Event& e);
	friend std::ostream& operator<<(std::ostream& stream, Event& e);
	~Event() = default;
	bool jePrestupna(int god);
};

