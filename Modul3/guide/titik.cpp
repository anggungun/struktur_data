#include <iostream>
#include <cmath>
#include <titik.h>

using namespace std;

void inputTitik(Titik &t) {
    cout << " Masukkan kordinat X: ";
    cin >> t.x;
    cout << " Masukkan kordinat Y: ";
    cin >> t.y;
}

void tampilTitik(Titik t) {
    cout << "Posisi Titik: ( " << t.x << " , " << t.y << " ) " << endl;
}

float hitungJarak(Titik t1, Titik t2) {
    return sqrt(pow(t2.x - t1.x, 2) + pow(t2.y - t1.y, 2));
}