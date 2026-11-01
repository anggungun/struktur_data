#include <iostream>
#include <string>
using namespace std;

struct kendaraan {
    string nopol;
    string warna;
    int thnBuat;
};

typedef kendaraan infotype;
typedef struct ElmList *address;

struct ElmList {
    infotype info;
    address next;
    address prev;
};

struct List {
    address first;
    address last;
};

void createList(List &L) {
    L.first = NULL;
    L.last = NULL;
}

address alokasi(infotype x) {
    address P = new ElmList;
    P->info = x;
    P->next = NULL;
    P->prev = NULL;
    return P;
}

void insertLast(List &L, address P) {
    if (L.first == NULL) {
        L.first = P;
        L.last = P;
    } else {
        P->prev = L.last;
        L.last->next = P;
        L.last = P;
    }
}

void printInfo(List L) {
    address P = L.first;

    while (P != NULL) {
        cout << P->info.nopol << " - "
             << P->info.warna << " - "
             << P->info.thnBuat << endl;

        P = P->next;
    }
}

address findElm(List L, string x) {
    address P = L.first;

    while (P != NULL) {
        if (P->info.nopol == x) {
            return P;
        }

        P = P->next;
    }

    return NULL;
}

int main() {
    List L;
    address P, hasil;
    infotype K;

    createList(L);

    K = {"D001", "Merah", 2020};
    P = alokasi(K);
    insertLast(L, P);

    K = {"D002", "Hitam", 2021};
    P = alokasi(K);
    insertLast(L, P);

    K = {"D003", "Putih", 2022};
    P = alokasi(K);
    insertLast(L, P);

    K = {"D004", "Biru", 2023};
    P = alokasi(K);
    insertLast(L, P);

    cout << "DATA KENDARAAN:" << endl;
    printInfo(L);

    hasil = findElm(L, "D001");

    cout << endl;

    if (hasil != NULL) {
        cout << "Kendaraan ditemukan!" << endl;
        cout << "Nomor Polisi: " << hasil->info.nopol << endl;
        cout << "Warna: " << hasil->info.warna << endl;
        cout << "Tahun Buat: " << hasil->info.thnBuat << endl;
    } else {
        cout << "Kendaraan tidak ditemukan." << endl;
    }

    return 0;
}
