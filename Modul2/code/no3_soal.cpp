#include <iostream>
#include <string>
using namespace std;

int hitungKarakter(string kata, char cari){
    int jumlah = 0;

    // Cek satu per satu huruf dalam kata
    for (int i = 0; i < kata.length(); i++)
    {
        if (kata[i] == cari)
        {
            jumlah++;
        }
    }

    return jumlah;
}

int main()
{
    string kata;
    char karakter;

    cin >> kata;
    cin >> karakter;

    int hasil = hitungKarakter(kata, karakter);

    cout << hasil << endl;

    return 0;
}