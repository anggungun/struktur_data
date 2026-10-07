#include <iostream>
#include <titik.h>

using namespace std;

int main() {
    Titik tA, tB;

    cout << "Input titik pertama " << endl;
    inputTitik(tA);

    cout << "Input titik kedua " << endl;
    inputTitik(tB);

    cout << "\nHasil rekap kordinat: " << endl;
    tampilTitik(tA);
    tampilTitik(tB);

    float jarak = hitungJarak(tA, tB);
    cout << "Jarak antara dua titik: " << jarak << endl;

    return 0;
}