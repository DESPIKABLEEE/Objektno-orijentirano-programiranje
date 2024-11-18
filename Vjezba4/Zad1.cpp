//1. Napisati funkciju koja broji koliko pojavljivanja danog podstringa ima u stringu
//koristeći funkcije standardne biblioteke.

#include <iostream>
#include <string>
//using namespace std;
int brojac_stringa(std::string recenica, std::string rijec){
    int brojac = 0;
    std::string::size_type pozicija = 0;
    while((pozicija = recenica.find(rijec,pozicija)) != std::string::npos){
        pozicija += rijec.length();
        brojac++;
    }
    
    return brojac;
}

int main1() {
    std::string string = "duje je kralj, duje je as, duje je car";
    std::string s = "duje";
    std::cout << "Ponavljanja rijeci " << s << " ima " << brojac_stringa(string, s) << " puta\n";
    
    return 0;
}
