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

//menghapus elemen pertama
void deleteFirst(List &L, address &P) {
    if (L.first != NULL) {
        P = L.first;

        L.first = L.first->next;

        if (L.first != NULL) {
            L.first->prev = NULL;
        } else {
            L.last = NULL;
        }

        P->next = NULL;
        P->prev = NULL;
    }
}

//menghapus elemen terakhir
void deleteLast(List &L, address &P) {
    if (L.last != NULL) {
        P = L.last;

        L.last = L.last->prev;

        if (L.last != NULL) {
            L.last->next = NULL;
        } else {
            L.first = NULL;
        }

        P->next = NULL;
        P->prev = NULL;
    }
}

//menghapus elemen setelah Prec
void deleteAfter(List &L, address Prec, address &P) {
    if (Prec != NULL && Prec->next != NULL) {
        P = Prec->next;

        Prec->next = P->next;

        if (P->next != NULL) {
            P->next->prev = Prec;
        } else {
            L.last = Prec;
        }

        P->next = NULL;
        P->prev = NULL;
    }
}

int main() {
    List L;
    address P, hapus, cari;
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

    cout << "DATA KENDARAAN SEBELUM DIHAPUS:" << endl;
    printInfo(L);

    //mencari kendaraan D003
    cari = L.first;

    while (cari != NULL && cari->info.nopol != "D003") {
        cari = cari->next;
    }

    //menghapus kendaraan D003
    if (cari != NULL) {
        if (cari == L.first) {
            deleteFirst(L, hapus);
        } else if (cari == L.last) {
            deleteLast(L, hapus);
        } else {
            deleteAfter(L, cari->prev, hapus);
        }

        cout << endl;
        cout << "Kendaraan D003 berhasil dihapus." << endl;

        delete hapus;
        hapus = NULL;
    } else {
        cout << "Kendaraan D003 tidak ditemukan." << endl;
    }

    cout << endl;
    cout << "DATA KENDARAAN SETELAH DIHAPUS:" << endl;
    printInfo(L);

    return 0;
}
