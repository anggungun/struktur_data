#include <iostream>
#include "Doublylist.h"
using namespace std;

int main() {
    List L;
    address P;
    infotype K;

    createList(L);

    K.nopol = "D001";
    K.warna = "Merah";
    K.thnBuat = 2020;
    P = alokasi(K);
    insertLast(L, P);

    K.nopol = "D002";
    K.warna = "Hitam";
    K.thnBuat = 2021;
    P = alokasi(K);
    insertLast(L, P);

    K.nopol = "D003";
    K.warna = "Putih";
    K.thnBuat = 2022;
    P = alokasi(K);
    insertLast(L, P);

    K.nopol = "D004";
    K.warna = "Biru";
    K.thnBuat = 2023;
    P = alokasi(K);
    insertLast(L, P);

    cout << "DATA KENDARAAN" << endl;
    printInfo(L);

    return 0;
}
