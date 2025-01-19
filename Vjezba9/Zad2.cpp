//2. Definirajte template klasu za skup. U skup se mogu dodavati elementi, izbacivati ele-
//menti i moze se provjeriti je li neki element u skupu ili ne.
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

template <typename type>
class Skup{
private:
    vector<type> niz;
    
public:
    void add(const type& x){
        niz.push_back(x);
    }
    void remove(const type& x){
        auto makni = find(niz.begin(),niz.end(),x);
        niz.erase(makni);
    }
    int postoji(const type& x){
        for(auto i : niz){
            if (i == x){
                return 1;
            }
        }
        return 0;
    }
    void print(){
        cout << "Niz je : { ";
        for(auto i : niz){
            cout << i << " ";
        }
        cout << "}" << endl;
    }
    
};

int main13(){ // 13
    Skup<int> intSkup;
    intSkup.add(5);
    intSkup.add(1);
    intSkup.add(4);
    intSkup.add(99);
    intSkup.print();
    
    intSkup.remove(99);
    intSkup.print();
    
    if(intSkup.postoji(1)){
        cout << "element 1 postoji u skupu" << endl;
    } else {
        cout << "element 1 ne postoji u skupu" << endl;
    }
    
    return 0;
}
