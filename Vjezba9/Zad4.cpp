//4. Napisati funkciju koja cita rijeci iz datoteke words.txt i izvrsava sljedece operacije:
//• Napuni vektor stringova rijecima iz datoteke koristeci istream iterator.
//• Izbaci sve stringove koji sadrze odredeni podstring koristeci remove if i erase.
//• Koristeci transform, promijeni sva slova u stringovima u velika slova.
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>
#include <cctype>
#include <iterator>

using namespace std;

void obradiRijeci(const string& filename, const string& podstring) {
    ifstream file(filename);
    
    if (!file) {
        cerr << "Ne mogu otvoriti datoteku " << filename << endl;
        return;
    }

    vector<string> rijeci((istream_iterator<string>(file)), istream_iterator<string>());
    
    rijeci.erase(remove_if(rijeci.begin(), rijeci.end(), [&podstring](const string& rijec) {
        return rijec.find(podstring) != string::npos;
    }), rijeci.end());
    
    for (auto& rijec : rijeci) {
        transform(rijec.begin(), rijec.end(), rijec.begin(), ::toupper);
    }
    
    for (const auto& rijec : rijeci) {
        cout << rijec << " ";
    }
    cout << endl;
}

int main15() { //
    string filename = "/Users/gabrielmilunovic/Desktop/smece/OOP_VJEZBE/Vjezba9/words.txt";
    string podstring = "test";

    obradiRijeci(filename, podstring);

    return 0;
}
