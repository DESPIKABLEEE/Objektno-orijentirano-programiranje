//4. Napisati funkciju koji prevodi engleske rečenice na pig latin jezik. Pravila su
//sljedeća:
//(a) ako riječ počinje samoglasnikom dopisuje se hay na kraj riječi,
//(b) inače, svi suglasnici s početka riječi prebacuju se na kraj te se na kraju
//riječi dopisuje ay.
//Rečenice treba spremiti u vector, a zatim prevesti slučajno odabranu re-
//čenicu iz vektora.
//Primjer: ”What time is it?” prevodi se kao ”atwhay imetay ishay ithay?”
#include <iostream>
#include <vector>
#include <algorithm>
#include <cctype>

#include <ctime>
#include <sstream>

bool je_samoglasnik(char i){
    i = std::tolower(i);
    return i == 'a' || i == 'e' || i == 'i' || i == 'o' || i == 'u';
}

std::string prevedi_u_pig(std::string& string){
    std::string pocetak,kraj;
    std::size_t n = string.size(), i = 0;
    while((i < n) && std::isalpha(string[i])){
        pocetak += string[i];
        i++;
    }
    while(i < n){
        kraj += string[i];
        i++;
    }
    if(je_samoglasnik(pocetak[0])){
        return pocetak + "hay" + kraj;
    } else {
        size_t samoglasnik = 0;
        while(samoglasnik < pocetak.size() && (!je_samoglasnik(pocetak[samoglasnik]))){
            samoglasnik++;
        }
        std::string novi = pocetak.substr(samoglasnik) + pocetak.substr(0,samoglasnik) + "ay";
        return novi + kraj;
    }
}

std::string prevedi2(std::string& string){
    std::istringstream stream(string);
    std::ostringstream rezultat;
    std::string rijec;
    while(stream >> rijec){
        rezultat << prevedi_u_pig(rijec) << " ";
    }
    
    std::string prevedena = rezultat.str();
    if(!prevedena.empty()){
        prevedena.pop_back();
    }
    return prevedena;
    
}



int main(){
    std::srand(std::time(0));
    
    std::vector<std::string> recenice = {
            "What time is it?",
            "How do you do?",
            "blabla budabo lola",
            "Hello world!"
    };
    
    int nasumicna = std::rand() % recenice.size();
    std::string meta = recenice[nasumicna];
    
    std::cout << "Engleska : " << meta << "\n";
    
    std::string prevedena_rijec = prevedi2(meta);
    
    std::cout << "Pig latin : " << prevedena_rijec << "\n";
    
    
    return 0;
}
