#include "entity.h"

void Entity::setPozycja(int xap, int yap) {
	aktualnaPozycja.Nowapozycja(xap, yap);
}
void Entity::printAvatar(Mapa& maps) {
	maps.Ustaw(aktualnaPozycja, wyglad);
}
void Entity::setKierunek(Pozycja kierunek) {
	nowaPozycja.Nowapozycja(kierunek.x, kierunek.y);
}
int Entity::getPozycjaX() {
	return aktualnaPozycja.x;
}
int Entity::getPozycjaY() {
	return aktualnaPozycja.y;
}
int Entity::getNowaPozycjaX() {
	return nowaPozycja.x;
}
int Entity::getNowaPozycjaY() {
	return nowaPozycja.y;
}
void Entity::setPozycjaKierunku(Pozycja kierunek, int a, int b) {
	kierunek.Nowapozycja(a, b);
	setKierunek(kierunek);
}
