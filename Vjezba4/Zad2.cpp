//2. Učitati string koji predstavlja rečenicu. Napisati funkciju koja iz stringa
//izbacuje sve praznine koje se nalaze ispred znakova interpunkcije i dodaje
//praznine nakon znaka interpunkcije ako nedostaju.
//Primjer:
//”Ja bih ,ako ikako mogu , ovu recenicu napisala ispravno.”
//”Ja bih, ako ikako mogu, ovu recenicu napisala ispravno.”.
#include <iostream>
#include <string>
#include <cctype>
void ispravi_string(std::string& string){
    std::string ispravljeni;
    int prethodni_razmak = 0;
    for(int i = 0; i < string.length(); i++){
        if(string[i] == ' '){
            if(prethodni_razmak == 0){
                ispravljeni.push_back(' ');
                prethodni_razmak = 1;
            }
        }
        else if(ispunct(string[i])){
            if(ispravljeni.back() == ' '){
                ispravljeni.pop_back();
            }
            
            ispravljeni.push_back(string[i]);
            
            if(i + 1 < string.length() && string[i + 1] != ' '){
                ispravljeni.push_back(' ');
            }
            prethodni_razmak = 0;
        } else {
            ispravljeni.push_back(string[i]);
            prethodni_razmak = 0;
        }
        
    }
    
    string = ispravljeni;
}

int main2(){
    std::string string = "Ja bih   ,   ako ikako mogu , ovu recenicu napisala ispravno.";
    std::cout << string << "\n";
    ispravi_string(string);
    std::cout << string << "\n";
    
    return 0;
}
