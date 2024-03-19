#pragma once
#include "Osoba.h"

class Gledaoc :
    public Osoba
{
public:
    int idKarte;
    Gledaoc();
    Gledaoc(int idk);
    Gledaoc(const Gledaoc& g);
    void setIDkarte();
    int getIDkarte();
    ~Gledaoc();
};
