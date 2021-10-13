#include <iostream>
#include <conio.h>
#include <cstdlib>
#include <Windows.h>
#include "mapa.h"
#include "gracz.h"
#include "moby.h"
#include "ranking.h"
#include "plikiRanking.h"

void napisyKoncowe(string annocment,string winlose, Mapa mapa) {
    vector<Ranking> RankingLista;
    Plik Lista("ranking.txt");
    system("cls");
    cout << annocment << endl << "Zdobyte punkty: " << mapa.Score() << endl;
    string nick;
    cout << "Podaj nick zeby wpisac sie do rankingu" << endl;
    cin >> nick;
    Ranking wpis(mapa.Score(), nick, "Wygrana");
    Lista.Zapis(wpis);
    Lista.Odczyt(RankingLista);
    Lista.View(RankingLista);
}

int main()
{
    Pozycja kierunek;
    Pozycja kierunekmob1;
    Pozycja kierunekmob2;
    Gracz kesoyu('@', 8, 3);
    Moby mob1('^', 8, 26);
    Moby mob2('^', 8, 49);
    Mapa mapa;
    mob1.printAvatar(mapa);
    mob2.printAvatar(mapa);
    mob1.setPozycjaKierunku(kierunekmob1, 0, -1);
    mob2.setPozycjaKierunku(kierunekmob2, 0, -1);
    kesoyu.printAvatar(mapa);
    int dlugoscmapy=kesoyu.getPozycjaY();
    mapa.WyswietlMape(dlugoscmapy);
    bool gamerunning=true;
    while (gamerunning == true) {
        dlugoscmapy = kesoyu.getPozycjaY();
        if (_kbhit())
        {
            switch (_getch())
            {
            case 'a':
                kesoyu.setPozycjaKierunku(kierunek, 0, -1);
                break;
            case 'w':
                if (kesoyu.getskokCD() == 0) {
                    kesoyu.setPozycjaKierunku(kierunek, -3, 0);
                    kesoyu.setskokCD(3);
                }
                break;
            case 'd':
                kesoyu.setPozycjaKierunku(kierunek, 0, 1);
                break;
            case 's':
                kesoyu.setPozycjaKierunku(kierunek, 1, 0);
                break;
            default:
                break;
            }
        }
        kesoyu.Ruch(mapa, gamerunning);
        mob1.Ruch(mapa, gamerunning);
        mob2.Ruch(mapa, gamerunning);
        if (kesoyu.getskokCD() != 0 && kesoyu.getNowaPozycjaX()==-3) {
            kesoyu.setPozycjaKierunku(kierunek, 0, 0);
            kesoyu.czasCD();
        }
        else {
            kesoyu.czasCD();
        }
        system("cls");
        mapa.WyswietlMape(dlugoscmapy);
        Sleep(300);        
    }
    if (bool wynik=mapa.getWinlose() == true) {
        napisyKoncowe("Gratulacje wygrales","Wygrana", mapa);
    }
    else {
        napisyKoncowe("Przegrales", "Przegrana", mapa);
    }
}

