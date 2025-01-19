//3. Napisite template funkciju za sortiranje niza. Napisite specijalizaciju te funkcije za niz
//charova u kojoj nece biti razlike izmedu malih i velikih slova.
#include <iostream>
#include <algorithm>
#include <cctype>
#include <string>

using namespace std;

template <typename t>
void sortiraj(vector<t>& niz){
    sort(niz.begin(), niz.end());
}

template <>
void sortiraj(vector<char>& niz){
    sort(niz.begin(), niz.end(), [](char x, char y){
        return tolower(x) < tolower(y);
    });
}


int main14(){ // 14
    vector<int> niz = {1, 2, 5, 4, 3};
    sortiraj(niz);
    for(auto i : niz){
        cout << i << " ";
    }
    cout << endl;
    vector<char> nizCharova = {'a', 'c', 'b', 'e', 'd'};
    sortiraj(nizCharova);
    for(auto j : nizCharova){
        cout << j << " ";
    }
    
    return 0;
}
