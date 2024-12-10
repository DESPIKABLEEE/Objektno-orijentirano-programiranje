#include <iostream>
#include <string>

using namespace std;

class Food{
    static int counter;
    int oznaka;

public:
    Food(){
        counter++;
        oznaka = counter;
    }

    int getOznaka() const{return oznaka;}

    static int getCounter(){return counter;}

    static void setCounter(int value){counter = value;}

    static void printCounter(){cout << "Broj raspolozivih porcija hrane: " << counter << endl;}

    friend int getcounter();
};

int Food::counter = 0;

int getcounter(){return Food::getCounter();}

class VirtualPet{
    string ime;
    string vrsta;
    int bodovi;
    bool gladan;
    int brojPojedenihPorcija;

public:
    VirtualPet(const string& ime, const string& vrsta, int bodovi, bool gladan)
        : ime(ime), vrsta(vrsta), bodovi(bodovi), gladan(gladan), brojPojedenihPorcija(0) {}

    bool operator==(const VirtualPet& other) const{
        return ime == other.ime && vrsta == other.vrsta && bodovi == other.bodovi && gladan == other.gladan;
    }

    bool operator!=(const VirtualPet& other) const{
        return !(*this == other);
    }

    VirtualPet& operator=(const VirtualPet& other){
        if (this != &other){
            ime = other.ime;
            vrsta = other.vrsta;
            bodovi = other.bodovi;
            gladan = other.gladan;
            brojPojedenihPorcija = other.brojPojedenihPorcija;
        }
        return *this;
    }

    VirtualPet& operator++(){
        bodovi -= 1;
        brojPojedenihPorcija += 1;
        if (brojPojedenihPorcija > 0){
            gladan = false;
            brojPojedenihPorcija = 0;
        }
        return *this;
    }


    VirtualPet operator++(int){
        VirtualPet temp = *this;
        ++(*this);
        return temp;
    }

    bool operator<(const VirtualPet& other) const{
        return bodovi < other.bodovi;
    }

    bool operator>(const VirtualPet& other) const{
        return bodovi > other.bodovi;
    }

    bool operator<=(const VirtualPet& other) const{
        return bodovi <= other.bodovi;
    }

    bool operator>=(const VirtualPet& other) const{
        return bodovi >= other.bodovi;
    }

    friend ostream& operator<<(ostream& os, const VirtualPet& pet);

    
    int getBrojPojedenihPorcija() const{return brojPojedenihPorcija;}
};

ostream& operator<<(ostream& os, const VirtualPet& pet){
    os << "Ime : " << pet.ime << ", Vrsta : " << pet.vrsta << ", Bodovi : " << pet.bodovi << ", Gladan : " << pet.gladan;
    return os;
}

int main(){ // 10
    Food porcija1;
    Food porcija2;

    cout << "Porcija 1 Oznaka : " << porcija1.getOznaka() << endl;
    cout << "Porcija 2 Oznaka : " << porcija2.getOznaka() << endl;
    
    Food::printCounter();

    cout << "Broj raspolozivih porcija hrane : " << getcounter() << endl;

    VirtualPet ljubimac1("Kjara", "Papiga", 10, true);
    VirtualPet ljubimac2("Blinky", "Geckon", 12, false);

    cout << "Ljubimac 1 : " << ljubimac1 << endl;
    cout << "Ljubimac 2 : " << ljubimac2 << endl;

    ljubimac1++;

    cout << "Ljubimac 1 nakon radnje : " << ljubimac1 << endl;

    cout << "Broj pojedenih porcija Ljubimac 1 : " << ljubimac1.getBrojPojedenihPorcija() << endl;

    if (ljubimac1 < ljubimac2){
        cout << "Ljubimac 2 je sretniji od ljubimac 1" << endl;
    } else {
        cout << "Ljubimac 1 je sretniji od ljubimac 2" << endl;
    }

    return 0;
}
