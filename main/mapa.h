#pragma once
#include <iostream>
#include <cstdlib>
#include "pozycja.h"
using namespace std;

class Mapa {
public:
	Mapa() : punkty(0) {};
	~Mapa();
	int punkty;
	bool winlose=true;
	char map[10][91] = {
	"##########################################################################################",
	"###                                                                                    ###",
	"###                                                                                    ###",
	"###                           $$$$$$                 $$$$$$                            ###",
	"###                           ######                 ###### $$$$$$                     ###",
	"###     $$$           $$$$$$$$$                             ######  $                  ###",
	"###     ###           #########        $$                $$$#########  $               ###",
	"###            ###                   ######              ###############  $            ###",
	"###   $$$   #########             ############        $$$##################           O###",
	"##########################################################################################",
	};
	bool getWinlose();
	void MoveE(Pozycja&, const char, Pozycja&, bool&);
	void MoveP(Pozycja&, const char, Pozycja, bool&);
	void Ustaw(Pozycja, const char);
	void WyswietlMape(int);
	int Score();
};