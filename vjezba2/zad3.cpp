// 3. Definirati strukturu koja opisuje vektor. Struktura se sastoji od niza int
// elemenata, logičke i fizičke veličine niza. Fizička veličina je inicijalno init, a
// kada se ta veličina napuni vrijednostima, alocira se duplo.
// Napisati funkcije vector_new, vector_delete, vector_push_back, vector_pop_back,
// vector_front, vector_back i vector_size. Funkcije su članovi strukture.
//Napomena: Koristitinew i delete. Ne koristiti funkcije malloc, free, ni std::vector
#include <iostream>
using namespace std;
struct VEKTOR{
    int *niz;
    int broj_elemenata;
    int kapacitet;

    void vektor_new(){
        broj_elemenata = 0;
        kapacitet = 2;
        niz = new int[kapacitet];
    }
    void vektor_delete(){
        delete[] niz;
        broj_elemenata = 0;
        kapacitet = 0;
    }
    void vektor_push_back(int vrijednost){
        if(broj_elemenata >= kapacitet){
            kapacitet *= 2;
            int* novi_niz = new int[kapacitet];
            int i;
            for (i = 0; i < broj_elemenata; i++) {
                novi_niz[i] = niz[i];
            }
            delete[] niz;
            niz = novi_niz;
        }
        niz[broj_elemenata++] = vrijednost;
        }
    void vektor_pop_back(){
        if(broj_elemenata > 0){
            broj_elemenata--;
        }
    }
    int vektor_front(){
        if(broj_elemenata > 0){
            return niz[0];
        }
        return -1;
    }
    int vektor_back(){
        if(broj_elemenata > 0){
            return niz[broj_elemenata - 1];
        }
        return -1;
    }
    int vektor_size(){
        return broj_elemenata;
    }
};

int main(){
    VEKTOR v;
    v.vektor_new();
    v.vektor_push_back(10);
    v.vektor_push_back(20);
    cout << "Velicina vektora je: " << v.vektor_size() << "\n";
    cout << "Zadnji element je: " << v.vektor_back() << "\n";
    cout << "Prvi element je: " << v.vektor_front() << "\n";
    v.vektor_pop_back();
    cout << "Velicina nakon popanja zadnjeg: " << v.vektor_size() << "\n";
    v.vektor_delete();
    cout << "Velicina nakon brisanja: " << v.vektor_size() << "\n";
    return 0;
}