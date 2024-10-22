//1. Napisati funkciju koja računa najveći i najmanji broj u nizu od n prirodnih
//brojeva.Funkcija vraća tražene brojeve pomoću referenci.
#include <iostream>
using namespace std;
void funkcija(int *niz,int n,int& min, int& max) {
	int i;
	min = niz[0];
	max = niz[0];
	for (i = 0; i < n; i++) {
		if (niz[i] > max)
			max = niz[i];
		if (niz[i] < min)
			min = niz[i];
	}

}

int main() {
	int niz[] = { 1, 2, 3, 4, 5 };
	int n = sizeof(niz) / sizeof(niz[0]);
	int min, max;
	funkcija(niz, n, min, max);
	cout << "Najmanji broj je " << min << ",a najveci je " << max << "\n";
	return 0;
}
