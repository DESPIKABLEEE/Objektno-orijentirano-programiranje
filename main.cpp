#include "pet.hpp"
#include "owner.hpp"
using namespace std;

int main() {
	VirtualPet ljubimac1("lala", "pas", 5, 20, true);
	VirtualPet ljubimac2("Kjara", "Papiga", 15, 10, true);
	VirtualPet ljubimac3("Suza", "macka", 10, 30, false);
	Owner vlasnik("Duje");
	Owner vlasnik1("Kralj");
	vlasnik.dodaj(ljubimac1);
	vlasnik.dodaj(ljubimac2);
	vlasnik1.dodaj(ljubimac3);


	vlasnik.ispisi_ljubimac();
	vlasnik1.ispisi_ljubimac();

	ljubimac1.aktivnost();
	ljubimac2.aktivnost();
	ljubimac3.aktivnost();

	vlasnik.ispisi_ljubimac();
	vlasnik1.ispisi_ljubimac();

	//cout << ljubimac1;
	return 0;
}