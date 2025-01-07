//Napisite program koji modelira sustav za obradu razlicitih oblika neprijatelja u igri. Baza
//hijerarhije klasa je klasa Enemy koja sadrzi sljedece atribute:
//    • string name - ime neprijatelja
//    • int health - zdravlje neprijatelja
//    • int damage - steta koju neprijatelj moze nanijeti
//Klasa Enemy ima sljedece funkcije:
//    • konstruktor s parametrima, baca iznimku ako argument nije ispravan (npr. health ili
//                damage negativan broj)
//    • attack() - cisto virtualna funkcija koja opisuje napad neprijatelja
//    • displayInfo() - cisto virtualna funkcija za ispis informacija o neprijatelju
//Implementirajte dvije klase Boss i Monster koje nasljeduju klasu Enemy, Boss ima dodatno
//oruzje, a Monster posebne sposobnosti. Oruzje i sposobnosti su stringovi, te konstruktori
//bacaju iznimke u slucaju da su stringovi prazni.
//U glavnom dijelu programa, dodajte nekoliko neprijatelja u vektor pointera na baznu klasu,
//te za sve izvrsite napad i ispisite informacije.
//Koristire standardnu iznimku std::invalid_argument te testirajte hvatanje iznimke za pro-
//blematicne slucajeve.
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Enemy{
protected:
    string name;
    int health;
    int damage;
public:
    Enemy(const string& name, int health, int damage){
        if(health < 0 || damage < 0){
            throw invalid_argument("Nepravilan argument");
        }
        this->name = name;
        this->health = health;
        this->damage = damage;
    }
    
    virtual void attack() const = 0;
    virtual void displayInfo() const = 0;
    
    virtual ~Enemy() {}
};

class Boss : public Enemy{
private:
    string oruzje;
    
public:
    Boss(const string& ime, int health, int damage, string oruzje) : Enemy(ime, health, damage) {
        if(oruzje.empty()){
            throw invalid_argument("Nepravilan argument");
        }
        this->oruzje = oruzje;
    }
    void attack() const override{
        cout << name << " napada s " << oruzje << " i pravi " << damage << " stete" << endl;
    }
    void displayInfo() const override{
        cout << "Ime: " << name << " Zivot: " << health << " Steta: " << damage << " Oruzje: " << oruzje << endl;
    }
    //virtual ~Boss();
    
};

class Monster : public Enemy{
private:
    string sposobnosti;
    
public:
    Monster(const string& ime, int health, int damage,const string& sposobnosti) : Enemy(ime, health, damage) {
        if(sposobnosti.empty()){
            throw invalid_argument("Nepravilan argument");
        }
        this->sposobnosti = sposobnosti;
    }
    void attack() const override{
        cout << name << " koristi sposobnost " << sposobnosti << " i pravi " << damage << " stete" << endl;
    }
    void displayInfo() const override{
        cout << "Ime: " << name << " Zivot: " << health << " Steta: " << damage << " Sposobnosti: " << sposobnosti << endl;
    }
    
};

int main11(){
    vector<Enemy*> enemies;
    try {
        enemies.push_back(new Boss("Dark Overlord", 200, 50, "Flaming Sword"));
        enemies.push_back(new Monster("Goblin", 50, 10, "Stealth Attack"));
        enemies.push_back(new Monster("Dragon", 300, 100, "Fire Breath"));
    } catch (const invalid_argument& e) {
        cerr << "Greska kod neprijatelja " << e.what() << endl;
    }

    try {
        enemies.push_back(new Boss("Shadow King", 150, 40, ""));
    } catch (const invalid_argument& e) {
        cerr << "Greska kod neprijatelja " << e.what() << endl;
    }

    for (Enemy* enemy : enemies) {
        try {
            enemy->attack();
            enemy->displayInfo();
        } catch (const exception& e) {
            cerr << "Greska kod neprijatelja  " << e.what() << endl;
        }
    }

        for (Enemy* enemy : enemies) {
            delete enemy;
        }

        return 0;
}
