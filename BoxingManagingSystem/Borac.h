#pragma once
#include "Osoba.h"
//definicija klase Borac, njenih metoda i atributa

/* Borac: https://stackoverflow.com/questions/37670500/global-array-in-a-c-object 
* evo link za globalne varijable da mozes pozivati, OPET NEKAKO BORBE SKOTNAJ
* BORBE RIJESI ZADNJE
* RIJESI PRVO KUPOVINU KARTE
* KARTU
* FUNCKOINISANJE KARTE
* TEK ONDA NEKAKO SMRLJAVI PREGLED ONOGA STO SI KUPIOI
* TO CEMO POSENO DAN IZDVOJIT
*  sto se tice borca, samo jos skontaj pravi unos i eto ajmo rec ispis nekog borca testa radi
* sutra ako stignes isto testaj neke stvari
* tako to nekako mislim da nema oko borca TOLIOK JOS POSLA
*/


class Borac : public Osoba
{
private:
    int champ;
    std::string kategorija;
    int id;
    int godine;
    int visina; // cm
    int kg; // kg
    int wins; // wins
    int ties; // ties
    int ls; // loses
    friend class Event;
public:
    Borac();
    Borac(std::string ime, std::string prezime, int champ, std::string kategorija, int id, int god, int cm, int kgs, int wins, int ties, int l) : Osoba(ime, prezime), champ(champ), kategorija(kategorija), id(id), godine(god)
        ,visina(cm),kg(kgs),wins(wins),ties(ties),ls(l)
    {
        
    }
    Borac(const Borac& b);
    void setChamp();
    void setId();
    void setIdSaParametrom(int* id1);
    void setKategorija();
    void setGodine();
    void setVisina();
    void setKg();
    void setWins();
    void setTies();
    void setLs();
    int getChamp();
    int getId();
    std::string getKategorija();
    int getGodine();
    int getVisina();
    int getKg();
    int getWins();
    int getTies();
    int getLs();
    friend std::istream& operator>>(std::istream& stream, Borac& b);
    friend std::ostream& operator<<(std::ostream& stream, Borac& b);
    ~Borac() = default;
};

