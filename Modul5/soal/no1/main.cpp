#include <iostream>
#include "Singlylist.h"
using namespace std;

int main() {
    List L;
    address P1, P2, P3, P4, P5;
    address hasil;

    createList(L);

    P1 = alokasi(2);
    insertFirst(L, P1);

    P2 = alokasi(0);
    insertFirst(L, P2);

    P3 = alokasi(8);
    insertFirst(L, P3);

    P4 = alokasi(12);
    insertFirst(L, P4);

    P5 = alokasi(9);
    insertFirst(L, P5);

    cout << "Isi linked list: ";
    printInfo(L);

    hasil = findElm(L, 8);

    if (hasil != NULL) {
        cout << "Elemen 8 ditemukan." << endl;
    } else {
        cout << "Elemen 8 tidak ditemukan." << endl;
    }

    cout << "Jumlah seluruh elemen: "
         << jumlahInfo(L) << endl;

    return 0;
}
