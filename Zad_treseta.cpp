//Definirajte klase za kartasku igru Treseta. Modelirajte klase za kartu, igraca i mac (deck).
//Karta se sastoji od broja i zoga. Mac ima 40 karata koji se moraju moci promijesati i podijeliti
//igracima (po 10 karata). Igrac ima ime, kombinaciju karata, broj bodova i moze akuzati ako
//ima odgovarajucu kombinaciju karata (napolitana tj. 1, 2, 3 iste boje nose 3 boda, a po
//(barem) tri jedinice, dvojke ili trojke nose tri ili cetiri boda).
//Napisati program u kojem korisnik odreduje broj igraca (2 ili 4) i imena igraca, potom se
//promijesane karte podijele igracima, te se ispisuje koliko bodova iz akuze ima koji igrac.
#include <iostream>
#include <string>
using namespace std;
class Karta{
public:
    string broj;
    string zog;
    Karta(string broj, string zog) : broj(broj), zog(zog){}
    string getBroj(){   return broj;   }
    string getZog(){    return zog;   }
};

class Igrac{
public:
    string ime_igraca;
    vector<Karta> karte_igraca;
    int bodovi;
    Igrac(string ime_igraca) : ime_igraca(ime_igraca), bodovi(0){}
    string getIme(){return ime_igraca;}
    void uzmi_karte(vector<Karta>& karte){
        karte_igraca = karte;
    }
    int akuza(){
        int bodovi = 0;
        int brojac_1 = 0, brojac_2 = 0, brojac_3 = 0;
        string zog_1, zog_2, zog_3;
        for(Karta i : karte_igraca){
            if(i.getBroj() == "3"){
                brojac_3++;
                zog_3 = i.getZog();
            }
            else if(i.getBroj() == "2"){
                brojac_2++;
                zog_2 = i.getZog();
            }
            else if(i.getBroj() == "1"){
                brojac_1++;
                zog_3 = i.getZog();
            }
        }
        if(brojac_3 >= 1 && brojac_2 >= 1 && brojac_1 >= 1 && zog_1 == zog_2 && zog_2 == zog_3){
            cout << "Igrac " << getIme() << " ima asa,duju i tricu istog zoga, dobija 3 boda" << endl;
            bodovi += 3;
        }
        if(brojac_3 == 3){
            cout << "Igrac " << getIme() << " ima 3 trice, dobiva 3 boda" << endl;
            bodovi += 3;
        }
        if(brojac_3 == 4){
            cout << "Igrac " << getIme() << " ima 4 trice, dobiva 4 boda" << endl;
            bodovi += 4;
        }
        if(brojac_2 == 3){
            cout << "Igrac " << getIme() << " ima 3 duje, dobiva 3 boda" << endl;
            bodovi += 3;
        }
        if(brojac_2 == 4){
            cout << "Igrac " << getIme() << " ima 4 duje, dobiva 4 boda" << endl;
            bodovi += 4;
        }
        if(brojac_1 == 3){
            cout << "Igrac " << getIme() << " ima 3 asa, dobiva 3 boda" << endl;
            bodovi += 3;
        }
        if(brojac_1 == 4){
            cout << "Igrac " << getIme() << " ima 4 asa, dobiva 4 boda" << endl;
            bodovi += 4;
        }
        return bodovi;
    }
    void ispisi_ruku_igraca(){
        for(Karta i : karte_igraca){
            cout << i.getBroj() << " " << i.getZog() << endl;
        }
    }
};


class Mac{
public:
    vector<Karta> spil_karata;
    Mac(){
        napravi_spil_karata();
        promjesaj_spil_karata();
    }
    
    void napravi_spil_karata(){
        vector<string> brojevi = {"1","2","3","4","5","6","7","11","12","13"};
        vector<string> zogovi = {"Dinari","Kupe","Spadi","Bate"};
        for(string i : brojevi){
            for(string j : zogovi){
                Karta novaKarta(i,j);
                spil_karata.push_back(novaKarta);
            }
        }
    }
    void promjesaj_spil_karata(){
        srand(static_cast<unsigned>(time(0)));
        size_t n = spil_karata.size();
        for(int i = n - 1; i > 0; i--){
            int j = rand() % i;
            swap(spil_karata[i],spil_karata[j]);
        }
    }
    vector<vector<Karta>> podijeli_spil_karata(int broj_igraca){
        vector<vector<Karta>> ruke(broj_igraca); // sto ovo znaci???
        int ruka_igraca;
        for(int i = 0; i < broj_igraca * 10; i++){
            ruka_igraca = i % broj_igraca;
            ruke[ruka_igraca].push_back(spil_karata[i]);
        }
        return ruke;
    }
};


int main6(){
    cout << "Unesite broj igraca : (2 ili 4)" << endl;
    int broj_igraca = 0;
    cin >> broj_igraca;
    cout << endl;
    vector<string> imena_igraca;
    string ime_igraca;
    if(broj_igraca != 2 && broj_igraca != 4){
        cout << "Pogresan broj igraca" << endl;
        return 1;
    }
    for(int i = 0; i < broj_igraca; i++){
        cout << "Unesite ime " << i + 1 << " igraca" << endl;
        cin >> ime_igraca;
        imena_igraca.push_back(ime_igraca);
    }
    Mac mac;
    vector<vector<Karta>> podijeljene_karte = mac.podijeli_spil_karata(broj_igraca);
    vector<Igrac> igraci;
    for(int j = 0; j < broj_igraca; j++){
        Igrac noviIgrac = imena_igraca[j];
        noviIgrac.uzmi_karte(podijeljene_karte[j]);
        igraci.push_back(noviIgrac);
    }
    int bodovi;
    for(auto f : igraci){
        bodovi = f.akuza();
        cout << "Igrac " << f.getIme() << " ima : " << bodovi << " bodova\n";
        f.ispisi_ruku_igraca();
    }
    
    
    return 0;
}
