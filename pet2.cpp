#include "pet.hpp"

VirtualPet::VirtualPet(const string& ime, const string& vrsta, int glad, int sreca, bool budnost) : ime(ime), vrsta(vrsta), glad(glad), sreca(sreca), budnost(budnost) {}

VirtualPet::~VirtualPet() {}
void VirtualPet::spava() {
	while (glad < 10) {
		if (sreca < 10) {
			sreca++;
		}
		glad++;
		budnost = false;
	}
	
	budnost = true;
}

void VirtualPet::igra() {
	while (glad <= 10) {
		glad++;
		budnost = true;
		sreca++;
	}
}

void VirtualPet::jede() {
	while (glad <= 10) {
		glad--;
		budnost = true;
		sreca++;
	}
}

ostream& operator<<(ostream &os, const VirtualPet &pet) {
	os << " pet " << pet.getIme() << " Vrsta" << pet.getVrsta() << " glad " << pet.getGlad() << " sreca " << pet.getSreca() << " budnost " << pet.getBudnost() << endl;
	return os;
}




