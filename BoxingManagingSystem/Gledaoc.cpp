#include "Gledaoc.h"

Gledaoc::Gledaoc()
{
}

Gledaoc::Gledaoc(int idk)
{
	this->idKarte = idk;
}

Gledaoc::Gledaoc(const Gledaoc& g)
{
	this->idKarte = g.idKarte;
}

void Gledaoc::setIDkarte()
{
}

int Gledaoc::getIDkarte()
{
	return 0;
}
