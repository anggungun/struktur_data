#include <iostream>
#include "Singlylist.h"
using namespace std;

void createList(List &L) {
    L.first = NULL;
}

address alokasi(infotype x) {
    address P = new ElmList;
    P->info = x;
    P->next = NULL;
    return P;
}

void dealokasi(address &P) {
    delete P;
    P = NULL;
}

void insertFirst(List &L, address P) {
    P->next = L.first;
    L.first = P;
}

void printInfo(List L) {
    address P = L.first;

    while (P != NULL) {
        cout << P->info << " ";
        P = P->next;
    }

    cout << endl;
}

// Fungsi pencarian elemen
address findElm(List L, infotype x) {
    address P = L.first;

    while (P != NULL) {
        if (P->info == x) {
            return P;
        }
        P = P->next;
    }

    return NULL;
}

// Fungsi menghitung jumlah semua elemen
int jumlahInfo(List L) {
    address P = L.first;
    int total = 0;

    while (P != NULL) {
        total = total + P->info;
        P = P->next;
    }

    return total;
}
