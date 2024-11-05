//Napisati funkcije za unos i ispis vektora brojeva.Prototipove funkcija sta -
//viti u.hpp datoteke, a implementaciju u.cpp datoteke.
//Za unos vektora napisati dvije funkcije :
//· funkcija čiji su parametri referenca na vektor i broj elemenata vektora,
//· funkcija čiji su parametri referenca na vektor i granice intervala u ko -
//jem trebaju biti elementi vektora.Elementi vektora se unose u funkciji,
//sve dok se ne unese broj koji nije u danom intervalu
#include <iostream>
#include <vector>
#include "zadatak1.hpp"
using namespace std;
int main() {
	vector<int> v1;
	vector<int> v2;
	cout << "Vektor s brojem elemenata : ";
	unesi_broj_el(v1, 5);
	ispis(v1);
	cout << "\n\n";

	cout << "Vektor s intervalima : ";
	unesi_intervale(v2, 0, 10);
	ispis(v2);
	cout << "\n\n";

}