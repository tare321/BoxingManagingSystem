#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
//definicija klase Arena, njenih metoda i atributa

/*Klasa arena je bitna jer od nje imamo:
* 1) podatke za mjesta u areni, trebat ce za kartu, kad bude covjek kupovao i pregled arene
* 2) podatke o mjestu gradu itd, trebat ce za event, sto je bazna klasa klase karta
* ...
*	- Trebas ubaciti da kad unosis podatke o dijelovima arene, pita te za redove i kolonu, samo pomnozi redove i kolone tih mjesta
*	  i imas onda kapacitet, ugl kapacitet je najlakse, valja ovo skontat. """NOTE""" mozes si olaksati tako da stavis samo da jednom uneses red i kolonu i on
*	  ti onda to samo x 4 ( za svaku stranu ), i isto to za vip PUNO LAKSE i dobijes tako kapacitet i sto ti treba ;D,
*	  ___________ OPOMENA BIT CE ZA SVAKI OBJEKAT 4 TXT FILEA OD ARENE, kao sto si imranu rekao neka bude vip i obicna mjesta iste strane u istom txt file-u, a
*	  kad budes kupovao kartu i rekao necu vip, neka covjeku prikaze iz tog txt filea ali NE VIP MJESTA, manipulacija nizovima ??? samo redove oduzez (obic - vip)
*	  
*/ 

class Arena
{
protected:
	int brRed;
	int brKolona;
	int brVipRed;
	int brVipKolona;
	int idArene;
	std::string imeArene;
	std::string grad;
	int kapacitet;
	// mjesta
	int wMjesta;
	int eMjesta;
	int sMjesta;
	int nMjesta;
	int wVipMjesta;
	int eVipMjesta;
	int sVipMjesta;
	int nVipMjesta;
	//redovi i kolone
	// vektori
	std::vector<std::vector<int>> wVektorMjesta;
	std::vector<std::vector<int>> eVektorMjesta;
	std::vector<std::vector<int>> sVektorMjesta;
	std::vector<std::vector<int>> nVektorMjesta;
	std::vector<std::vector<int>> wVipVektorMjesta;
	std::vector<std::vector<int>> eVipVektorMjesta;
	std::vector<std::vector<int>> sVipVektorMjesta;
	std::vector<std::vector<int>> nVipVektorMjesta;
public:
	Arena();
	Arena(int ida, std::string arenaName, std::string city, int capacity, int wMjesta, int eMjesta, int sMjesta, int nMjesta, int wVipMjesta, int eVipMjesta,
	int sVipMjesta, int nVipMjesta, int brRed,int brKolona,int brVipRed, int brVipKolona,std::vector<std::vector<int>> wVM, std::vector<std::vector<int>> eVM,
	std::vector<std::vector<int>> sVM, std::vector<std::vector<int>> nVM, std::vector<std::vector<int>> wVVM, std::vector<std::vector<int>> eVVM, 
	std::vector<std::vector<int>> sVVM, std::vector<std::vector<int>> nVVM);
	Arena(int ida, std::string arenaName, std::string city, int brRed, int brKol, int brVipRed, int brVipKolona); // ovo cemo koristiti da ne moramo unositt
	//seteri																										 kad budemo prezentovali :D
	void setIDarene();
	void setIDareneSaParametrom(int* a);
	void setImeArene();
	void setGrad();
	void setKapacitet();
	void setwMjesta();
	void seteMjesta();
	void setsMjesta();
	void setnMjesta();
	void setwVipMjesta();
	void seteVipMjesta();
	void setsVipMjesta();
	void setnVipMjesta();
	void setbrRed();
	void setbrKolona();
	void setbrVipRed();
	void setbrVipKolona();
	//geteri
	int getIDarene();
	std::string getImeArene();
	std::string getGrad();
	int getKapacitet();
	int getwMjesta(Arena& a);
	int geteMjesta(Arena& a);
	int getsMjesta(Arena& a);
	int getnMjesta(Arena& a);
	int getwVipMjesta(Arena& a);
	int geteVipMjesta(Arena& a);
	int getsVipMjesta(Arena& a);
	int getnVipMjesta(Arena& a);
	int getbrRed();
	int getbrKolona();
	int getbrVipRed();
	int getbrVipKolona();

	void uFajl();

	friend std::istream& operator>>(std::istream& stream, Arena& a);
	friend std::ostream& operator<<(std::ostream& stream, Arena& a);
	~Arena() = default;
};

