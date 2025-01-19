//1. Napisati template funkciju min koja vraca manji od dva elementa. Elementi mogu biti
//brojevi i stringovi.
#include <iostream>
#include <string>
using namespace std;

template <typename type>
type manji(type& a, type& b){
    return (a < b ? a : b);
}

int main12(){
    int x = 5, y = 10;
    string str1 = "Pozdrav";
    string str2 = "Dujkan";
    
    cout << "Manji broj je: " << manji(x,y) << endl;
    
    cout << "Kraci string je: " << manji(str1, str2) << endl;
    
    return 0;
}
