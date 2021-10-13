#include "mapa.h"

Mapa::~Mapa() {

}

void Mapa::Ustaw(Pozycja pozycja, char wyglad) {
	map[pozycja.x][pozycja.y] = wyglad;
}

void Mapa::MoveP(Pozycja& aktualna, const char wyglad, Pozycja nowa, bool& statusgry) {
	nowa.x += aktualna.x;
	nowa.y += aktualna.y;
	if (map[nowa.x][nowa.y] == ' ') {
		map[nowa.x][nowa.y] = wyglad;
		map[aktualna.x][aktualna.y] = ' ';
		aktualna.x = nowa.x;
		aktualna.y = nowa.y;
	}
	else if (map[nowa.x][nowa.y] == '$') {
		map[nowa.x][nowa.y] = wyglad;
		map[aktualna.x][aktualna.y] = ' ';
		aktualna.x = nowa.x;
		aktualna.y = nowa.y;
		punkty++;
	}
	else if (map[nowa.x][nowa.y] == 'O') {
		statusgry = false;
		winlose = true;
	}
}

void Mapa::MoveE(Pozycja& aktualna, const char wyglad, Pozycja &nowa, bool& statusgry) {
	int saveX=nowa.x, saveY=nowa.y;
	nowa.x += aktualna.x;
	nowa.y += aktualna.y;
	if (map[nowa.x][nowa.y] == ' ') {
		map[nowa.x][nowa.y] = wyglad;
		map[aktualna.x][aktualna.y] = ' ';
		aktualna.x = nowa.x;
		aktualna.y = nowa.y;
		nowa.x = saveX;
		nowa.y = saveY;
	}
	else if (map[nowa.x][nowa.y] == '$') {
		map[nowa.x][nowa.y] = wyglad;
		map[aktualna.x][aktualna.y] = '$';
		aktualna.x = nowa.x;
		aktualna.y = nowa.y;
		nowa.x = saveX;
		nowa.y = saveY;
	}
	else if (map[nowa.x][nowa.y] == '#' || map[nowa.x][nowa.y] == '0') {
		map[aktualna.x][aktualna.y] = wyglad;
		if (saveX == 0 && saveY == -1) {
			nowa.Nowapozycja(0, 1);
		}
		else if (saveX == 0 && saveY == 1) {
			nowa.Nowapozycja(0, -1);
		}
	}
	else {
		statusgry = false;
		winlose = false;
	}
}

void Mapa::WyswietlMape(int dlugosc) {
	int licznik = 0;
	int dlugoscmin = dlugosc;
	int dlugoscmax = dlugosc + 12;
	for (int i = 0; i < 10; i++) {
		licznik++;
		for (dlugosc=-3 + dlugoscmin; dlugosc < dlugoscmax; dlugosc++) {
			cout << map[i][dlugosc];
		}
		cout << endl;
		if (licznik == 10) {
			break;
		}
	}
	

}

int Mapa::Score() {
	return punkty;
}

bool Mapa::getWinlose() {
	return winlose;
}
