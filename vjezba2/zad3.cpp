//3. Definirati strukturu koja opisuje vektor.Struktura se sastoji od niza int
//elemenata, logičke i fizičke veličine niza.Fizička veličina je inicijalno init, a
//kada se ta veličina napuni vrijednostima, alocira se duplo.
//Napisati funkcije vector_new, vector_delete, vector_push_back, vector_pop_back,
//vector_front, vector_back i vector_size.Funkcije su članovi strukture.
#include <iostream>
#include <memory>
using namespace std;
struct Vektor {
	int *niz;
	int broj_elemenata;
	int kapacitet;

	Vektor(int init = 2) : broj_elemenata(0), kapacitet(init) {
		int *niz = new int[kapacitet];
	}
	void vektor_delete() {
		delete[] niz;
		*niz = 0;
		broj_elemenata = 0;
		kapacitet = 0;
	}
	void vektor_new(int value) {
		if (broj_elemenata == kapacitet) {
			kapacitet *= 2;
			int *novi_niz = new int[kapacitet];
			int i;
			for (i = 0; i < broj_elemenata; i++) {
				novi_niz[i] = niz[i];
			}
			delete[] niz;
			niz = novi_niz;
		}
		niz[broj_elemenata++];
	}
	int vektor_size() {
		if(broj_elemenata > 0)
			return broj_elemenata;
	}
	int& vektor_front() {
		return niz[0];
	}
	int& vektor_back() {
		return niz[broj_elemenata - 1];
	}
	void vector_pop_back() {
		broj_elemenata--;
	}


};

int main() {
	Vektor p;
	p.vektor_new(1);
	p.vektor_new(2);
	p.vektor_new(3);

	cout << "Velicina " << p.vektor_size() << "\n";
	cout << "Prvi vektor " << p.vektor_front() << "\n";
	cout << "Zadnji vektor " << p.vektor_back() << "\n";

	p.vector_pop_back();
	cout << "Velicina nakon popanja zadnjeg: " << p.vektor_size() << "\n";
	cout << "Velicina zadnjeg " << p.vektor_back() << "\n";
	p.vektor_delete();
	cout << "Vektor nakon brisanja: " << p.vektor_size() << "\n";

	return 0;
}