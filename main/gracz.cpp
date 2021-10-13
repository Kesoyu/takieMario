#include "gracz.h"
Pozycja Gracz::getPozycja() {
	return aktualnaPozycja;
}

int Gracz::getskokCD(){
	return skokCD;
}
void Gracz::setskokCD(int cd) {
	skokCD = cd;
}
void Gracz::czasCD() {
	if (skokCD > 0) {
		skokCD--;
	}
}
void Gracz::Ruch(Mapa& maps, bool& statusgry) {
	Pozycja dol(1, 0);
	maps.MoveP(aktualnaPozycja, wyglad, nowaPozycja, statusgry);
	maps.MoveP(aktualnaPozycja, wyglad, dol, statusgry);
}
