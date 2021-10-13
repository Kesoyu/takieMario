#pragma once
#include "entity.h"
class Gracz :public Entity{
public:
	int skokCD=0;
	Gracz(char ww, int xap, int yap) : Entity(ww, xap, yap) {
		skokCD = 0;
	}
	Pozycja getPozycja();
	void Ruch(Mapa&, bool&);
	int getskokCD();
	void setskokCD(int);
	void czasCD();
};

