//Napisati funkcije za unos i ispis vektora brojeva.Prototipove funkcija sta -
//viti u.hpp datoteke, a implementaciju u.cpp datoteke.
//Za unos vektora napisati dvije funkcije :
//· funkcija čiji su parametri referenca na vektor i broj elemenata vektora,
//· funkcija čiji su parametri referenca na vektor i granice intervala u ko -
//jem trebaju biti elementi vektora.Elementi vektora se unose u funkciji,
//sve dok se ne unese broj koji nije u danom intervalu
#include <iostream>
#include <vector>
using namespace std;
void unesi_broj_el(vector<int>& v, int broj_el) {
	for (int i = 0; i < broj_el; i++) {
		//cout << "Unesite elemente vektora : ";
		v.push_back(i + 1);
	}
	cout << "\n";
}

void unesi_intervale(vector<int>& v, int donji, int gornji) {
	int x;
	if (donji > gornji) {
		int temp = donji;
		donji = gornji;
		gornji = temp;
	}

	while (1) {
		cout << "Unesite broj vektora unutar granica : ";
		cin >> x;
		if (x < donji || x > gornji) {
			break;
		}
		v.push_back(x);
		cout << "\n";
	}
	cout << "\n";
}

void ispis(vector<int>& v) {
	for (int i : v) {
		cout << i << " ";
	}
	cout << "\n";
}