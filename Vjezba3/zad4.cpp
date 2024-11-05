//Napisati funkciju u za uklanjanje elementa iz vektora sa što manje operacija.
//Poredak elemenata u vektoru nije bitan
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void funkcija(vector<int>& vector, int indeks) {
	if (indeks < 0 || indeks > vector.size()) {
		cout << "Greska";
		return;
	}
	vector[indeks] = vector.back();
	vector.pop_back();
}

int main() {
	vector<int> vektor = { 1, 2, 3, 4, 5 };
	int indeks = 2;
	cout << "Vektor je : ";
	funkcija(vektor, indeks);
	for (int b : vektor) {
		cout << b << " ";
	}

	return 0;
}