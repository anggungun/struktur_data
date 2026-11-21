#include <iostream>
#include "queue.h"
using namespace std;

// Alternatif 1: head tetap, elemen digeser saat dequeue.
void createQueue(Queue &Q) { Q.head = 0; Q.tail = -1; }
bool isEmptyQueue(Queue Q) { return Q.tail == -1; }
bool isFullQueue(Queue Q) { return Q.tail == 4; }

void enqueue(Queue &Q, infotype x) {
    if (isFullQueue(Q)) cout << "Queue penuh." << endl;
    else Q.info[++Q.tail] = x;
}

infotype dequeue(Queue &Q) {
    if (isEmptyQueue(Q)) { cout << "Queue kosong." << endl; return -1; }
    int x = Q.info[Q.head];
    for (int i = Q.head; i < Q.tail; i++) Q.info[i] = Q.info[i + 1];
    Q.tail--;
    return x;
}

void printInfo(Queue Q) {
    cout << "H=";
    if (isEmptyQueue(Q)) cout << "-"; else cout << Q.head;
    cout << " T=";
    if (isEmptyQueue(Q)) cout << "-"; else cout << Q.tail;
    cout << " | ";
    if (isEmptyQueue(Q)) cout << "Queue kosong";
    else for (int i = Q.head; i <= Q.tail; i++) cout << Q.info[i] << " ";
    cout << endl;
}
