#include "moby.h"
Pozycja Moby::getPozycja() {
	return aktualnaPozycja;
}
void Moby::Ruch(Mapa& maps, bool& statusgry) {
	maps.MoveE(aktualnaPozycja, wyglad, nowaPozycja, statusgry);
}
