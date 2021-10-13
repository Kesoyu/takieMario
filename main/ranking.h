#pragma once
#include <string>
using namespace std;

struct Ranking {
	Ranking(int x=0, string y="Brak",string z="None") : Score(x), Nazwa(y),WinLose(z) {}
	int Score;
	string Nazwa;
	string WinLose;
	void Dane(string, int);
};