//2. Koristeći funkcije iz prvog zadatka unijeti dva vektora i formirati novi vek-
//tor koji se sastoji od elemenata iz prvog vektora koji nisu u drugom vektoru.
#include <iostream>
#include <vector>
#include <algorithm>
#include "zadatak1.hpp"
using namespace std;

vector<int> funkcija(vector<int>& v1, vector<int>& v2) {
	vector<int> v3;
	// for (int i : v1) {
	// 	for (int j : v2) {
	// 		if (i == j) {
	// 			break;	
	// 		}
	// 		v3.push_back(i);
	// 	}
	// }
	for (int i : v1) {
	        int count = 0;
	        for (int j : v2) {
	            if (i == j) {
	                count++;
	                break;
	            }
	        }
	        if (count == 0) {
	            v3.push_back(i);
	        }
    	}
	return v3;
}
// 1 2 3 4 5
// 4 5 6 7 8 11
// 1 2 3
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
	cout << "Novi vektor je : ";
	vector<int> rez = funkcija(v1, v2);
	ispis(rez);

}
