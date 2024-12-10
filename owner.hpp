#ifndef OWNER_H
#define OWNER_H
#include "pet.hpp"
#include <vector>
#include <ctime>
class Owner{
	string ime;
	vector<VirtualPet> ljubimci;
public:
	Owner(const string& ime) : ime(ime) {}
	//~Owner();

	void dodaj(VirtualPet& ljubimac) {
		ljubimci.emplace_back(ljubimac);
	}

	void ispisi_ljubimac() {
		cout << ime << " ima : " << endl;
		for (auto& i : ljubimci) {
			cout << i << endl;
		}
	}
};


#endif // !OWNER_HPP
