#pragma once
#include "entity.h"
class Moby:public Entity
{
public:
	Moby(char ww, int xap, int yap) : Entity(ww, xap, yap) {};
	Pozycja getPozycja();
	void Ruch(Mapa&, bool&);
};

