#include <iostream>
using namespace std;

int main() {
    float bil1, bil2;

    cout << "Masukkan bilangan pertama: ";
    cin >> bil1;
    cout << "Masukkan bilangan kedua: ";
    cin >> bil2;

    float hasilTambah = bil1 + bil2;
    float hasilKurang = bil1 - bil2;
    float hasilKali   = bil1 * bil2;
    float hasilBagi   = bil1 / bil2; 

    cout << bil1 << " + " << bil2 << " = " << hasilTambah << endl;
    cout << bil1 << " - " << bil2 << " = " << hasilKurang << endl;
    cout << bil1 << " * " << bil2 << " = " << hasilKali << endl;
    cout << bil1 << " / " << bil2 << " = " << hasilBagi << endl;

    return 0;
}