#include <iostream>
using namespace std;

int main(){
    int n;
    cin >> n;

    int nilai[100];
    int total = 0;

    for (int i = 0; i < n; i++)
    {
        cin >> nilai[i];
        total = total + nilai[i];
    }

    int rataRata = total / n;

    int jumlahAtas = 0;
    for (int i = 0; i < n; i++)
    {
        if (nilai[i] > rataRata)
        {
            jumlahAtas++;
        }
    }

    cout << "Rata-rata: " << rataRata << endl;
    cout << "Di atas rata-rata: " << jumlahAtas << endl;

    return 0;
}