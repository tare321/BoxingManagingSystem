#include <iostream>
#include <vector>
#include "Osoba.h"
#include "Event.h"
#include "Arena.h"
#include "Gledaoc.h"
#include "Borac.h"
#include <sstream>
#include <stdio.h>
#include <stdlib.h>
#include <cctype>
#include <memory>
#include <string>
#include <iomanip>

int id1;

std::vector<Arena> Arene;
std::vector<Borac> Borci;
std::vector<Event> Eventi;
std::vector<int> Karte;

int kolone = 0;
int redovi = 0;

int brEvenata = 0;

int ListaBorbi[6][13] = { {0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0} };

int redoviListaBorbi = 0; // borbe za eventa
int koloneListaBorbi = 0;

// ::::::::::::::::::::::::: DODATNE POGODNOSTI :::::::::::::::::::::::::::::::::::::::::::::

std::string dodijeliKategoriju(int br)
{
    for (auto& i : Borci) {
        if (i.getId() == br)
        {
            return i.getKategorija();
        }
    }
}

void ispisBoracaUEventu(int red)
{
    int nizOnihKojihNemaKojeSmoIspisali[10] = { 0,0,0,0,0,0,0,0,0,0 }, nizonihkojesmounijeliuborbe[10] = {0,0,0,0,0,0,0,0,0,0};
    int zaNiz = 0;
    int zaniz2 = 0;
    for (int x = 0; x < 10; x++)
    {
        for (auto& i : Borci)
        {
            if (ListaBorbi[red][x] == i.getId())
            {
                nizonihkojesmounijeliuborbe[zaniz2] = i.getId();
                x++;
                break;
            }
            else if (ListaBorbi[red][x] != i.getId())
            {
                nizOnihKojihNemaKojeSmoIspisali[zaNiz] = i.getId();
                x++;
                break;
            }
        }
    }
    std::cout << "niz onih koje smo unijeli u borbe: ";
    for (int x = 0; x < 10; x++) {
        std::cout<< nizonihkojesmounijeliuborbe[x];
    }
    std::cout << "\nniz onih koje nismo unijeli u borbe: ";
    for (int x = 0; x < 10; x++) {
        std::cout << nizOnihKojihNemaKojeSmoIspisali[x];
    }
    std::cout << ":::::::::::::::::::::::::::::::::::::::::\n";
    for (int x = 0; x < 10; x++)
    {
            for (auto& i : Borci)
            {
                if (ListaBorbi[red][x] == 0)
                {

                }
                else if (ListaBorbi[red][x] == i.getId())
                {

                }
                else if (ListaBorbi[red][x] != i.getId())
                {
                    std::cout << i;
                    std::cout << "\n" << red << ".\n" << x;
                    std::cout << ":::::::::::::::::::::::::::::::::::::::::\n";
                }
                
            }
    }
}

bool NizPrazan()
{
    for (int i = 0; i < 7; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            if (ListaBorbi[i][j] != 0)
            {
                return false;
            }
        }
    }
    return true;
}

void unesiUListaBorbi(int redovi, int kolone, int br) {
    ListaBorbi[redovi][kolone] = br; // postavlja na tu i tu poziciju u listama borib
}

int dajMuVrijednostBorcevogIDa(int intId)
{
    for (auto& i : Borci)
    {
        if (i.getId() == intId)
        {
            return i.getId();
        }
    }
}

void getListaBorbi(int br)
{
    if (NizPrazan() == true) {
        std::cout << "Nema unesenih borbi.\n";
    }
    else {
        std::string imeBorca;
        std::string prezimeBorca;
        for (int broj = br; broj < 7; broj++)
        {
            if (ListaBorbi[br] == 0) {
                break;
            }
            for (int x = 0; x < 10; x++)
            {
                ajmoNazad:
                if (x % 2 == 0)
                {
                    for (auto i : Borci)
                    {
                        if (i.getId() == ListaBorbi[broj][x])
                        {
                            imeBorca = i.getIme();
                            prezimeBorca = i.getPrezime();
                            std::cout<< "\n\t" << imeBorca << " " << prezimeBorca << "   ";
                            x = x + 1;
                            goto ajmoNazad;
                        }
                    }
                }
                else if (x % 2 == 1)
                {
                    for (auto i : Borci)
                    {
                        if (i.getId() == ListaBorbi[broj][x])
                        {
                            imeBorca = i.getIme();
                            prezimeBorca = i.getPrezime();
                            std::cout << "vs   " << imeBorca << " " << prezimeBorca << "";
                            x = x + 1;
                            goto ajmoNazad;
                        }
                    }
                }
            }
        }
    }
}

// :::::::::::::::::::::::::: PROVJERE ::::::::::::::::::::::::::::

bool JeLiInt(std::string id)
{
    int  brr = id.length();
    char cunt[20];
    for (int y = 0; y < brr; y++) {
        cunt[y] = id[y];
    }
    int br = 0;
    for (int i = 0; i < brr; i++)
    {
        if (isdigit(cunt[i]) == false)
        {
            br++;
        }
    }
    if (br == 0)
    {
        return true;
    }
    else 
    {
        return false;
    }
}

bool provjera_ID_Borac(int x) {
    std::cout << "\n" << __FUNCTION__ << "...  ";
    for (auto& i : Borci)
    {
        if (i.getId() == x)
        {
            return true;
        }
    }
    return false;
}
bool provjera_ID_Borac_za_Borbe(int x, int r) { // x = int borca, r  = red,
   std::cout << "\n" << __FUNCTION__ << "...  "; // provjera_ID_Borac_za_Borbe
   
           for (koloneListaBorbi = 1; koloneListaBorbi < 13; koloneListaBorbi++)
           {
               if (ListaBorbi[r][koloneListaBorbi] == x)
               {
                   return true; // ako je borac vec u listi za borbu vrati false, ne moze se u jednom eventu jedan borac dva puta boriti
               }
           }
           return false;
}

bool provjera_Champ_Borac_za_Borbe(int x, Borac& b) {
    std::cout << "\n" << __FUNCTION__ << "...  "; // Da li se borac nalazi u ListeBorbi
    for (auto& i : Borci)
    {
        if (i.getChamp() == x && i.getKategorija() == "1")
        {
            return true; // ako je borac vec u listi za borbu vrati false, ne moze se u jednom eventu jedan borac dva puta boriti
        }
    }
    return false;
}

bool provjera_ID_Event(double x) {
    std::cout << "\n" << __FUNCTION__ << "...  ";
    for (auto& i : Eventi)
    {
        if (i.getId() == x)
        {
            return true;
        }
    }
    return false;
}

bool provjera_ID_Arena(int x) {
    std::cout << "\n" << __FUNCTION__ << "...  ";
    for (auto& i : Arene) 
    {
        if (i.getIDarene() == x)
        {
            return true;
        }
    }
    return false;
}


// ::::::::::::::::::::: UNOSI I ISPISI :::::::::::::::::::::

/*void kupiKartau() // OVO CE BITI ISPIS KARTE
{
    if (Karte.empty()) {
        std::cout << "Nema kupljenih karti.\n";
    }
    else
    {
        int t = 0;
        std::string id;
        std::cout << "Unesite ID karte: ";
        std::getline(std::cin, id);
        if (JeLiInt(id) == true) 
        {
            std::stringstream ss;
            ss << id;
            ss >> id1;
            for (int i = 0; i < Karte.size(); i++) {

            }
        }
    }
}
*/

void unosBorca() { // unos boraca case 3:
    Borac temp;
    std::cin >> temp;
ovdjeborac :
    std::string stringID;
    std::cout << "Unesite ID borca: ";
    std::getline(std::cin, stringID);

    if (JeLiInt(stringID) == true)
    {
        std::stringstream ss;
        ss << stringID;
        ss >> id1;
        temp.setIdSaParametrom(&id1);
        while (provjera_ID_Borac(temp.getId()) == true)
        {
            std::cout << "ID vec postoji\n";
            goto ovdjeborac;
        }
        Borci.emplace_back(temp);
        std::cout << "Borac je unesen.\n\n";
        system("PAUSE");
    }
    else
    {
        std::cout << "\nMolimo vas unesite vrijednost tipa int.\n";
        goto ovdjeborac;
    }
}

void ispisBoraca() { // ispis boraca case 4:
    if (Borci.empty()) {
        std::cout << "Nema unesenih boraca.\n";
    }
    else {
        for (auto i : Borci) {
            std::cout << ":::::::::::::::::::::::::::::::::::::::::\n";
            std::cout << i;
        }
    }
}

void unosArene() { // obicni unos arene case 1:
    Arena temp;
    std::cin >> temp;
ovdjearena:
    std::string stringID;
    std::cout << "Unesite ID arene: ";
    std::getline(std::cin, stringID);
    
    if (JeLiInt(stringID) == true)
    {
        std::stringstream ss;
        ss << stringID;
        ss >> id1;
        temp.setIDareneSaParametrom(&id1);
        while (provjera_ID_Arena(temp.getIDarene()) == true)
        {
            std::cout << "ID vec postoji\n";
            goto ovdjearena;
        }
        Arene.emplace_back(temp);
        std::cout << "Arena je unesena.\n\n";
        system("PAUSE");
    }
    else
    {
        std::cout << "\nMolimo vas unesite vrijednost tipa int.\n";
        goto ovdjearena;
    }
}

void unosArene1() { // automatski se dodjeljuje ID, kad idemo 2.Pregled Arena, i unesemo id koji ne postoji kliknemo DA i on automatski postavi uneseni pokusaj
    Arena temp;
    std::cin >> temp;
    temp.setIDareneSaParametrom(&id1);
    while (provjera_ID_Arena(temp.getIDarene()) == true)
    {
        std::cout << "ID vec postoji\n";
        temp.setIDarene();
    }
    Arene.emplace_back(temp);
    std::cout << "Arena je unesena.\n\n";
}

void ispisArene() // obicni ispis arene case 2:
{
    if (Arene.empty()) {
        std::cout << "Nema unesenih arena.\n";
    }
    else {
        int t = 0;
    ovdje:
        std::string id;
        std::cout << "Unesite ID arene: ";
        std::getline(std::cin,id);

        if (JeLiInt(id) == true)
        {
            std::stringstream ss;
            ss << id;
            ss >> id1;
            for (auto i : Arene)
            {
                if (id1 == i.getIDarene())
                {
                    system("cls");
                    t = 1;
                    std::cout << i;
                    break;
                }
            }
            if (t == 0)
            {
                enum DaNe
                {
                    N = 0, D = 1
                };
                std::cout << "ID arene koji ste unijeli ne postoji!\nDa li biste zeljeli unijeti arenu i automatski joj dodijeliti ovaj ID?\n Da - D\n Ne - N\n";
                char sl;
                std::cin >> sl;
                DaNe odabir = static_cast<DaNe>(sl);
                if (odabir == 'd' || odabir == 'D')
                {
                    system("cls");
                    unosArene1();
                }
                else
                {
                    system("cls");
                    std::cin.ignore();
                    goto ovdje;
                }
            }
        }
        else
        {
            std::cout << "\nMolimo vas unesite vrijednost tipa int.\n";
            goto ovdje;
        }
        
    }
    system("PAUSE");
}

void ispisArenaZaEvente() // bukvalno samo se kaze
{
    if (Arene.empty()) {
        std::cout << "Nema unesenih arena.\n";
    }
    else {
        for (auto i : Arene) {
            std::cout << ":::::::::::::::::::::::::::::::::::::::::\n";
            std::cout << "ID Arene: " << i.getIDarene() << "\nIme arene: " << i.getImeArene() << "\nLokacija arene: " << i.getGrad() << "\nKapacitet arene: " << i.getKapacitet() * 4 << std::endl;
        }
    }
}

void unosEventa() // self explanatory, koristimo u case 5:
{
    Event temp;
    Borac temp1;
    // :::::::::::::::::::::::::: UNOS DATUMA ZA EVENT ::::::::::::::::::::::::::::::::::::::::
    std::cout << "Unos eventa:\n";
ponovoUnosIdEventa:
    try {
        temp.setGodina();
        if (temp.getGodina() > 2023 || temp.getGodina() < 2022)
        {
            throw 1;
        }
    }
    catch (int x) {
        std::cout << "Godina odrzavanja eventa ne moze biti 2021. i prosle ili poslije 2023 :: GRESKA br. " << x << std::endl;
        system("PAUSE");
        goto ponovoUnosIdEventa;
    }
    temp.setMjesec();
    temp.setDan();
ovdjeEvent:
    std::string stringID;

    // :::::::::::::::::::::::::: UNOS ID-a ZA EVENT::::::::::::::::::::::::::::::::::::::::

    std::cout << "Unesite ID Eventa: ";
    std::getline(std::cin, stringID);

    if (JeLiInt(stringID) == true)
    {
        std::stringstream ss;
        ss << stringID;
        ss >> id1;
        temp.setIdEventaSaParametrom(&id1);
        while (provjera_ID_Event(temp.getId()) == true)
        {
            std::cout << "ID vec postoji\n";
            goto ovdjeEvent;
        }
        int id;
        std::cout << std::endl;

    // :::::::::::::::::::::::::: UNOS ARENE ZA EVENT ::::::::::::::::::::::::::::::::::::::::

        system("cls");
    ponovniUnosArene:
        ispisArenaZaEvente();
        std::cout << "\nUnesite ID arene u kojoj ce se odrzati event: ";
        std::cin >> id;
        temp.setIdArene(&id);
        int br = 0;
        for (auto i : Arene) {

            if (i.getIDarene() == id)
            {
                br = 1;
                std::string grad, arena;
                arena = i.getImeArene();
                grad = i.getGrad();
                temp.setImeArene(&arena);
                temp.setGrad(&grad);
            }
        }
        if (br != 1)
        {
            system("cls");
            std::cout << "Unijeli ste id arene koji ne postoji.\nMolim vas unesite ponovo\n\n";
            system("PAUSE");
            goto ponovniUnosArene;
        }
        
        // :::::::::::::::::::::::::: UNOSI BORBI ::::::::::::::::::::::::::::::::::::::::
        ListaBorbi[brEvenata][0] = temp.getId();
        system("cls");
        ispisBoraca();
        std::cout << "\nUnesite koliko borbi zelite unijeti za event:\n";
        int brojBorbi, brBoraca = 1, intId;
        std::string stringId, kategorija;
        std::cin >> brojBorbi;
        std::cin.ignore();
        std::cout << "\n>>> [ Unosite ID boraca ] <<<\n";
        for (int i = 0; i < brojBorbi; i++)
        {
            std::cout << "\t\tBorba " << i + 1 << " : \n"; // ima logike
        ponovniUnosIDa:
            std::cout << "Borac " << brBoraca << " [ID]: ";
            std::getline(std::cin, stringId);
            if (JeLiInt(stringId) == true)
            {
                std::stringstream ss;
                ss << stringId;
                ss >> intId; // konvertuje string u id
                if (provjera_ID_Borac(intId) == true)
                {
                    std::cout << "<Borac postoji>";
                    while (provjera_ID_Borac_za_Borbe(intId, brEvenata) == true) // brEvenata - red treba radi id-a
                    {
                        std::cout << "Borac je vec dodijeljen za borbu.\n";
                        goto ponovniUnosIDa;
                    }
                    int br = dajMuVrijednostBorcevogIDa(intId);

                    kategorija = dodijeliKategoriju(ListaBorbi[brEvenata][brBoraca-1]);
                    //std::cout << "\n" << kategorija << "\n";
                    if (brBoraca % 2 == 0)
                    {
                        int x = 0;
                        for (auto& b : Borci)
                        {
                            if (b.getId() == br) 
                            {
                                if (b.getKategorija() == kategorija)
                                {
                                    ListaBorbi[brEvenata][brBoraca] = br;
                                    std::cout << "Borac " << brBoraca << " je unesen.\n\n";
                                    brBoraca++;
                                    x = 1;
                                }
                            }
                        }
                        if (x == 0) {
                            std::cout << "Borac kojeg ste unijeli je razlicite kategorije od prvog unesenog u borbi.\nMolim vas unesite iste kategorije.\n";
                            goto ponovniUnosIDa;
                        }
                    }
                    else
                    {
                        ListaBorbi[brEvenata][brBoraca] = br;
                        std::cout << "Borac " << brBoraca << " je unesen.\n\n";
                        brBoraca++;
                    }
                    //ListaBorbi[temp.getListaBorbiRed()][temp.getListaBorbiKolone()] = br;
                    if (brBoraca % 2 != 1)
                    {
                        goto ponovniUnosIDa;
                    }
                }
                else 
                {
                    std::cout << "<ID koji ste unijeli ne pripada ni jednom borcu!>\n";
                }
            }
            else
            {
                std::cout << "Molim vas unesite vrijednost tipa int.\n";
                goto ponovniUnosIDa;
            }
        }
        Eventi.emplace_back(temp);
        std::cout << "Event je unesen.\n\n";
        brEvenata++;
        system("PAUSE");
        
    }
    else
    {
        std::cout << "\nMolimo vas unesite vrijednost tipa int.\n";
        goto ovdjeEvent;
    }
}

void ispisEventa()
{
    redoviListaBorbi = 0;
    Event temp;
    Borac temp1;
    if (Eventi.empty()) {
        std::cout << "Nema unesenih event-a.\n";
    }
    else {
        for (auto i : Eventi) 
        {
            std::cout << "::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n";
            std::cout << i;
            for (int x = 0; x < Eventi.size(); x++)
            {
                if (i.getId() == ListaBorbi[x][0])
                {
                    for (int y = 1; y < 13; y++)
                    {
                        int brBorca = 0;
                    boracdva:
                        if (ListaBorbi[x][y] == 0)
                        {
                            break;
                        }
                        for (auto j : Borci)
                        {
                            if (j.getId() == ListaBorbi[x][y])
                            {
                                if (y % 2 == 1)
                                {
                                    int brime, brprezime;
                                    brime = j.getIme().size();
                                    brprezime = j.getPrezime().size();
                                    if (j.getChamp() == 1) {
                                        std::cout.width(27-(brime+brprezime+3)); std::cout << std::right << std::fixed << "*C*" << j.getIme() << " " << j.getPrezime();
                                    }
                                    else {
                                        std::cout.width(27-(brime+brprezime+3)); std::cout << std::right << std::fixed << "   " << j.getIme() << " " << j.getPrezime();
                                    }
                                }
                                if (y % 2 == 0)
                                {
                                    if (j.getChamp() == 1) {
                                        std::cout << " vs "<< j.getIme() << " " << j.getPrezime() << "*C*\n";
                                    }
                                    else {
                                        std::cout << " vs "  << j.getIme() << " " << j.getPrezime() << "\n";
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    std::cout << "\n\n\n";
    system("PAUSE");
}

int main()
{
    int izbor;
    Arena arena1(1, "Arctic Oval", "Brooklyn, NYC", 90, 70, 40, 50);
    Arena arena2(2, "MGM Grand Garden", "Las Vegas", 70, 70, 50, 40);
    Arena arena3(3, "York Hall", "London", 80, 60, 60, 40);
    Arene.emplace_back(arena1);
    Arene.emplace_back(arena2);
    Arene.emplace_back(arena3);
    Borac borac1("Tyson", "Fury", 1, "Heavyweight", 1, 33, 206, 126, 31, 1, 0); // wins ties losses
    Borac borac2("Oleksandr", "Usyk", 0, "Heavyweight", 2, 34, 191, 100, 19, 0, 0);
    Borac borac3("Anthony", "Joshua", 0, "Heavyweight", 3, 32, 198, 109, 24, 0, 2);
    Borac borac8("Muhammad", "Ali", 0, "Heavyweight", 8, 36, 191, 107, 56, 2, 5);
    Borac borac4("Gennady", "Golovkin", 1, "Middleweight", 4, 39, 179, 72, 41, 0, 1);
    Borac borac5("Ryoto", "Murata", 0, "Middleweight", 5, 36, 182, 72, 16, 0, 2);
    Borac borac6("Vasyl", "Lomachenko", 1, "Lightweight", 6, 33, 170, 61, 16, 0, 2);
    Borac borac7("Isaac", "Cruz", 0, "Lightweight", 7, 23, 163, 60, 22, 0, 2);
    Borci.emplace_back(borac1);
    Borci.emplace_back(borac2);
    Borci.emplace_back(borac3);
    Borci.emplace_back(borac4);
    Borci.emplace_back(borac5);
    Borci.emplace_back(borac6);
    Borci.emplace_back(borac7);
    Borci.emplace_back(borac8);
    std::string StrIzbor;
    do 
    {
        pocetak:
        system("cls");
        std::cout << "1. Unos arene\n";
        std::cout << "2. Pregled arene\n";
        std::cout << "3. Unos borca\n";
        std::cout << "4. Pregled boraca\n";
        std::cout << "5. Unos eventa\n";
        std::cout << "6. Pregled eventa\n";
        std::cout << "7. Kraj\n";
        std::cout << "\tIzbor: "; 
        std::getline(std::cin, StrIzbor);
        if (JeLiInt(StrIzbor) == true) 
        {
            system("cls");
            std::stringstream ss;
            ss << StrIzbor;
            ss >> izbor;
            switch (izbor) 
            {
            case 1:
                unosArene();
                break;
            case 2:
                ispisArene();
                break;
            case 3:
                unosBorca(); 
                break;
            case 4:
                ispisBoraca();
                system("PAUSE");
                break;
            case 5:
                unosEventa();
                break;
            case 6:
                ispisEventa();
                break;
            }
        }
        else 
        {
            std::cout << "\nMolimo vas unesite vrijednost tipa int.\n";
            system("PAUSE");
            goto pocetak;
        }
    } while (izbor != 7);
    return 0;
}