
#include <iostream>
using namespace std;

typedef int infotype;
typedef struct ElmList *address;

struct ElmList {
    infotype info;
    address next;
};

struct List {
    address first;
};

void createList(List &L) {
    L.first = NULL;
}

address alokasi(infotype x) {
    address P = new ElmList;
    P->info = x;
    P->next = NULL;
    return P;
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

int main() {
    List L;
    address P;
    address hasil;

    createList(L);

    P = alokasi(2);
    insertFirst(L, P);

    P = alokasi(0);
    insertFirst(L, P);

    P = alokasi(8);
    insertFirst(L, P);

    P = alokasi(12);
    insertFirst(L, P);

    P = alokasi(9);
    insertFirst(L, P);

    cout << "Isi linked list: ";
    printInfo(L);

    hasil = findElm(L, 8);

    if (hasil != NULL) {
        cout << "Elemen 8 ditemukan." << endl;
    } else {
        cout << "Elemen 8 tidak ditemukan." << endl;
    }

    return 0;
}
