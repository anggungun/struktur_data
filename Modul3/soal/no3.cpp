#include <iostream>
using namespace std;

void tampilArray(int array[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << array[i][j] << " ";
        }
        cout << endl;
    }
}

void tukarArray(int array1[3][3], int array2[3][3], int baris, int kolom) {
    int temp;

    temp = array1[baris][kolom];
    array1[baris][kolom] = array2[baris][kolom];
    array2[baris][kolom] = temp;
}

void tukarPointer(int *p1, int *p2) {
    int temp;

    temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}

int main() {
    int array1[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    int array2[3][3] = {
        {10, 11, 12},
        {13, 14, 15},
        {16, 17, 18}
    };

    int *p1;
    int *p2;

    cout << "Array 1 sebelum ditukar:" << endl;
    tampilArray(array1);

    cout << "\nArray 2 sebelum ditukar:" << endl;
    tampilArray(array2);

    tukarArray(array1, array2, 1, 1);

    cout << "\nSetelah menukar posisi [1][1]:" << endl;

    cout << "\nArray 1:" << endl;
    tampilArray(array1);

    cout << "\nArray 2:" << endl;
    tampilArray(array2);

    p1 = &array1[0][0];
    p2 = &array2[0][0];

    cout << "\nSebelum ditukar menggunakan pointer:" << endl;
    cout << "Nilai p1 = " << *p1 << endl;
    cout << "Nilai p2 = " << *p2 << endl;

    tukarPointer(p1, p2);

    cout << "\nSetelah ditukar menggunakan pointer:" << endl;
    cout << "Nilai p1 = " << *p1 << endl;
    cout << "Nilai p2 = " << *p2 << endl;

    return 0;
}