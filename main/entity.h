#pragma once
#include "pozycja.h"
#include "mapa.h"
#include <iostream>
using namespace std;

class Entity{
public:
	char wyglad;
	Pozycja aktualnaPozycja;
	Pozycja nowaPozycja;
	Entity(char ww, int xap, int yap) : wyglad(ww){
		setPozycja(xap, yap);
	};
	int getPozycjaX();
	int getPozycjaY();
	int getNowaPozycjaX();
	int getNowaPozycjaY();
	void setKierunek(Pozycja);
	void setPozycja(int, int);
	void printAvatar(Mapa&);
	virtual Pozycja getPozycja() = 0;
	void setPozycjaKierunku(Pozycja, int, int);
};

