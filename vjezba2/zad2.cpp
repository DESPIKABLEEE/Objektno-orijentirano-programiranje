//2. Napisati funkciju koja vraća referencu na neki element niza.Koristeći po -
//vratnu vrijednost funkcije kao lvalue uvećajte i - ti element niza za jedan.
#include <iostream>
using namespace std;
int& funkcija(int *niz, int n, int indeks) {
	return niz[indeks];
}

int main() {
	int niz[] = { 1, 1, 3, 4, 5 };
	int n = sizeof(niz) / sizeof(niz[0]);
	int indeks = 1;

	funkcija(niz, n, indeks)++;

	cout << "Indeks povecan za jedan je broj: " << niz[indeks] << "\n";
	return 0;
}
