//5. Definirati strukturu Point koja predstavlja tocku s x i y koordinatama. Napisati funkciju
//koja cita tocke iz datoteke points.txt i izvrsava sljedece operacije:
//• Napuni vektor tocaka koristeci istream iterator.
//• Sortira tocke prema udaljenosti od ishodsta koristeci sort
//• Zamijeni sve tocke koje su tocno na odredenoj udaljenosti od ishodista s novom
//tockom koristeci replace if.
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iterator>

using namespace std;

struct Point {
    int x, y;

    Point(int x = 0, int y = 0) : x(x), y(y) {}

    int udaljenost() const {
        return sqrt(x * x + y * y);
    }
};

void obradiTocke(const string& filename, int udaljenostZaZamjenu, const Point& novaTocka) {
    ifstream file(filename);

    if (!file) {
        cerr << "Ne mogu otvoriti datoteku " << filename << endl;
        return;
    }

    vector<Point> tocke((istream_iterator<Point>(file)), istream_iterator<Point>());

    sort(tocke.begin(), tocke.end(), [](const Point& a, const Point& b) {
        return a.udaljenost() < b.udaljenost();
    });

    replace_if(tocke.begin(), tocke.end(), [&udaljenostZaZamjenu](const Point& p) {
        return abs(p.udaljenost() - udaljenostZaZamjenu);
    }, novaTocka);

    for (const auto& tocka : tocke) {
        cout << "(" << tocka.x << ", " << tocka.y << ") ";
    }
    cout << endl;
}

istream& operator>>(istream& in, Point& p) {
    in >> p.x >> p.y;
    return in;
}

int main() {
    string filename = "/Users/gabrielmilunovic/Desktop/smece/OOP_VJEZBE/Vjezba9/points.txt";
    int udaljenostZaZamjenu = 5;
    Point novaTocka(10, 10);

    obradiTocke(filename, udaljenostZaZamjenu, novaTocka);

    return 0;
}
