#include <iostream>
#include <string>
using namespace std;

struct Mahasiswa {
    string nama;
    string nim;
    float uts;
    float uas;
    float tugas;
    float nilaiAkhir;
};

float hitungNilaiAkhir(float uts, float uas, float tugas) {
    return (0.3 * uts) + (0.4 * uas) + (0.3 * tugas);
}

int main() {
    Mahasiswa mhs[10];
    int jumlah;

    cout << "Masukkan jumlah mahasiswa (max 10): ";
    cin >> jumlah;

    for (int i = 0; i < jumlah; i++) {
        cout << "\nData mahasiswa ke-" << i + 1 << endl;

        cout << "Nama : ";
        cin >> mhs[i].nama;

        cout << "NIM  : ";
        cin >> mhs[i].nim;

        cout << "UTS  : ";
        cin >> mhs[i].uts;

        cout << "UAS  : ";
        cin >> mhs[i].uas;

        cout << "Tugas: ";
        cin >> mhs[i].tugas;

        mhs[i].nilaiAkhir = hitungNilaiAkhir(
            mhs[i].uts,
            mhs[i].uas,
            mhs[i].tugas
        );
    }

    cout << "\nDATA MAHASISWA" << endl;

    for (int i = 0; i < jumlah; i++) {
        cout << "\nMahasiswa ke-" << i + 1 << endl;
        cout << "Nama       : " << mhs[i].nama << endl;
        cout << "NIM        : " << mhs[i].nim << endl;
        cout << "UTS        : " << mhs[i].uts << endl;
        cout << "UAS        : " << mhs[i].uas << endl;
        cout << "Tugas      : " << mhs[i].tugas << endl;
        cout << "Nilai Akhir: " << mhs[i].nilaiAkhir << endl;
    }
    return 0;
}