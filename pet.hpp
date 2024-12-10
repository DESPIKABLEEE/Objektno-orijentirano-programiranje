#ifndef PET_H
#define PET_H
#include <iostream>
#include <string>
using namespace std;

class VirtualPet{
	string ime;
	string vrsta;
	int glad;
	int sreca;
	bool budnost;
public:
	VirtualPet(const string& ime, const string& vrsta, int glad, int sreca, bool budnost);
	~VirtualPet();

	string getIme()const { return ime; }

	string getVrsta()const { return vrsta; }

	int getGlad()const { return glad; }

	int getSreca()const { return sreca; }

	bool getBudnost()const { return budnost; }

	void spava();

	void igra();

	void jede();

	friend ostream& operator<<(ostream &os, const VirtualPet &pet);

	VirtualPet(const VirtualPet& other) : ime(other.ime), vrsta(other.vrsta), glad(other.glad), sreca(other.sreca), budnost(other.budnost) {}

	void aktivnost() {
		int aktivnost = rand() % 3;

		if (aktivnost == 0) {
			cout << "Spava" << endl;
		}
		else if (aktivnost == 1) {
			cout << "Jede" << endl;
		}
		else if (aktivnost == 2) {
			cout << "Igra se" << endl;
		}

	}

};




#endif // !PET_H
