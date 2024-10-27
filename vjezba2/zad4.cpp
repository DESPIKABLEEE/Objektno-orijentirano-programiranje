// 4. Definirati strukturu koja opisuje matricu. Napisati program za osnovne
// operacije s matricama čiji su elementi decimalni brojevi (float). Program
// treba imati sljedeće funkcije:
// · funkciju za unos matricemxn,
// · funkciju za generiranje matricemxn s elementima u rasponu [a,b],
// · funkcije za zbarajanje, oduzimanje, množenje matrica,
// · funkciju za trasponiranje matrice,
// · funkciju za ispisivanje matrice. Elementi matrice se ispisuju na četiri
// decimale, poravnati udesno.
//Napomena: Koristitinew i delete. Ne koristiti funkcije malloc, free, ni std::vector.
#include <iostream>
using namespace std;
struct MATRICA{
    int red,stup;
    float** elementi;
};
void unos_matrice(MATRICA &m){
    cout << "Unesi broj redaka\n";
    cin >> m.red;
    cout << "Unesi broj stupaca\n";
    cin >> m.stup;
    m.elementi = new float*[m.red];
    int i,j;
    for(i = 0; i < m.red; i++){
        m.elementi[i] = new float[m.stup];
    }
    cout << "Unesite elemente matrice\n";
    for(i = 0; i < m.red; i++){
        for(j = 0; j < m.stup; j++){
            cin >> m.elementi[i][j];
        }
    }
}
void generiraj_matricu(MATRICA &m,float a, float b){
    cout << "Unesi broj redova\n";
    cin >> m.red;
    cout << "Unesi broj stupova\n";
    cin >> m.stup;
    m.elementi = new float*[m.red];
    int i,j;
    for(i = 0; i < m.red; i++){
        m.elementi[i] = new float[m.stup];
    }
    for(i = 0; i < m.red; i++){
        for(j = 0; j < m.stup; j++){
            m.elementi[i][j] = a + static_cast<float>((rand()) / (RAND_MAX * (b-a)));
        }
    }
}
MATRICA zbrajanje_matrice(MATRICA &m1, MATRICA &m2){
    MATRICA rez;
    rez.red = m1.red;
    rez.stup = m1.stup;
    int i,j;
    rez.elementi = new float*[rez.red];
    for(i = 0; i < rez.red; i++){
        rez.elementi[i] = new float[rez.stup];
        for(j = 0; j < rez.stup; j++){
            rez.elementi[i][j] = m1.elementi[i][j] + m2.elementi[i][j];
        }
    }
    return rez;
}
MATRICA oduzimanje_matrica(MATRICA &m1,MATRICA &m2){
    MATRICA rez;
    rez.red = m1.red;
    rez.stup = m1.stup;
    rez.elementi = new float*[rez.red];
    int i,j;
    for(i = 0; i < rez.red; i++){
        rez.elementi[i] = new float[rez.stup];
        for(j = 0; j < rez.stup; j++){
            rez.elementi[i][j] = m1.elementi[i][j] - m2.elementi[i][j];
        }
    }
    return rez;
}
MATRICA mnozenje_matrica(MATRICA &m1,MATRICA &m2){
    MATRICA rez;
    rez.red = m1.red;
    rez.stup = m1.stup;
    rez.elementi = new float*[rez.red];
    int i,j;
    for(i = 0; i < rez.red; i++){
        rez.elementi[i] = new float[rez.stup];
        for(j = 0; j < rez.stup; j++){
            rez.elementi[i][j] += m1.elementi[i][j] * m2.elementi[i][j];
        }
    }
    return rez;
}
MATRICA transpotiranje_matrica(MATRICA &m1){
    MATRICA rez;
    rez.red = m1.red;
    rez.stup = m1.stup;
    rez.elementi = new float*[rez.red];
    int i,j;
    for(i = 0; i < rez.red; i++){
        rez.elementi[i] = new float[rez.stup];
        for(j = 0; j < rez.stup; j++){
            rez.elementi[i][j] = m1.elementi[j][i];
        }
    }
    return rez;
}
void ispis_matrice(MATRICA &m){
    int i,j;
    for(i = 0; i < m.red; i++){
        for(j = 0; j < m.stup; j++){
            cout << m.elementi[i][j];
            cout << " ";
        }
        cout << "\n";
    }
}
void brisanje_matrice(MATRICA &m){
    int i;
    for(i = 0; i < m.red; i++){
        delete[] m.elementi[i];
    }
    delete[] m.elementi;
}


int main(){
    MATRICA m1,m2;
    cout << "Unos prve matrice\n"; 
    unos_matrice(m1);
    float a,b,c;
    cout << "Unesi donju granicu za brojeve\n";
    cin >> a;
    cout << "Unesi gornju granicu za brojeve\n";
    cin >> b;
    if (a > b){
        c = a;
        a = b;
        b = c;
    }
    cout << "Generiranje druge matrice\n";
    generiraj_matricu(m2,a,b);
    cout << "Prva matrica : \n";
    ispis_matrice(m1);
    cout << "\n";
    cout << "\n";
    cout << "Druga matrica : \n";
    ispis_matrice(m2);

    cout << "\n";
    cout << "\n";
    cout << "transpotiranje prve matrice: \n";
    MATRICA x = transpotiranje_matrica(m1);
    ispis_matrice(x);

    cout << "\n";
    cout << "\n";
    cout << "Zbroj\n";
    MATRICA y = zbrajanje_matrice(m1,m2);
    ispis_matrice(y);

    cout << "\n";
    cout << "\n";
    cout << "Oduzimanje\n";
    MATRICA z = oduzimanje_matrica(m1,m2);
    ispis_matrice(z);


    return 0;
}