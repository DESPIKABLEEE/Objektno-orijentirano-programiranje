////Koristeći STL funkcije sortirajte vektor, ubacite 0 ispred najmanjeg ele -
////menta, te sumu svih elemenata iza najvećeg elementa.
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	vector<int> v;
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);
	v.push_back(1);
	v.push_back(2);

	cout << "Vektor : ";
	for (int i : v) {
		cout << i << " ";
	}
	cout << "\n";

	sort(v.begin(), v.end());
	cout << "Sortirani vektor : ";
	for (int i : v) {
		cout << i << " ";
	}
	cout << "\n";

	cout << "Dodavanje nule ispred najmanjeg elementa : ";
	v.insert(v.begin(), 0);
	for (int i : v) {
		cout << i << " ";
	}
	cout << "\n";

	cout << "dodavanje sume iza najveceg elementa : ";
	int suma = 0;
	for (int i : v) {
		suma += i;
	}
	v.insert(v.end(), suma);
	for (int i : v) {
		cout << i << " ";
	}
	cout << "\n";
	return 0;
}
