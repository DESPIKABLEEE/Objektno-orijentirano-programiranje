//3. Napišite funkciju koja stringove, koje korisnik unosi, sprema u vektor stin-
//gova, svaki string preokrene te sortira vektor po preokrenutim stringo-
//vima.
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
void funkcija(std::vector<std::string>& stringovi){
    for(std::string& s : stringovi){
        std::reverse(s.begin(), s.end());
    }
    std::sort(stringovi.begin(),stringovi.end());
}

int main3(){
    std::vector<std::string> svi_string;
    std::string string;
    std::cout << "Unesite stringove, prazni string za prestanak\n";
    
    while(true){
        std::getline(std::cin, string);
        if(string.empty())
            break;
        svi_string.push_back(string);
    }
    funkcija(svi_string);
    
    for(std::string& i : svi_string){
        std::cout << i << "\n";
    }
    
    return 0;
}
