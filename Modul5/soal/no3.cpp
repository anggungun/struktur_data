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

int jumlahInfo(List L) {
    address P = L.first;
    int total = 0;

    while (P != NULL) {
        total = total + P->info;
        P = P->next;
    }

    return total;
}

int main() {
    List L;
    address P;

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

    cout << "Jumlah seluruh elemen: "
         << jumlahInfo(L) << endl;

    return 0;
}
