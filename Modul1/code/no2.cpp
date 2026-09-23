#include <iostream>
using namespace std;

int main() {
    int angka;

    string nama[] = {
        "nol", "satu", "dua", "tiga", "empat",
        "lima", "enam", "tujuh", "delapan", "sembilan",
        "sepuluh", "sebelas"
    };

    cout << "Masukkan angka: ";
    cin >> angka;

    cout << angka << " : ";

    if (angka == 100) {
        cout << "seratus";
    }
    else if (angka <= 11) {
        cout << nama[angka];
    }
    else if (angka >= 12 && angka <= 19) {
        int satuan = angka - 10;
        cout << nama[satuan] << " belas";
    }
    else {
        int puluhan = angka / 10; 
        int satuan  = angka % 10; 

        cout << nama[puluhan] << " puluh";

        if (satuan != 0) {
            cout << " " << nama[satuan];
        }
    }
    cout << endl;
    return 0;
}