//Napisati funkcije za unos i ispis vektora brojeva.Prototipove funkcija sta -
//viti u.hpp datoteke, a implementaciju u.cpp datoteke.
//Za unos vektora napisati dvije funkcije :
//· funkcija čiji su parametri referenca na vektor i broj elemenata vektora,
//· funkcija čiji su parametri referenca na vektor i granice intervala u ko -
//jem trebaju biti elementi vektora.Elementi vektora se unose u funkciji,
//sve dok se ne unese broj koji nije u danom intervalu
#ifndef ZADATAK1_HPP
#define ZADATAK1_HPP
#include <iostream>
#include <vector>
using namespace std;
void unesi_broj_el(vector<int>& v,int broj_el);

void unesi_intervale(vector<int>& v, int donji, int gornji);

void ispis(vector<int>& v);
#endif 