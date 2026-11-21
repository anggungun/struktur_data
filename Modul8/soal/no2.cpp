#include <iostream>
using namespace std;
const int N = 5;
struct Queue { int info[N]; int head, tail; };

void createQueue(Queue &Q) { Q.head = 0; Q.tail = -1; }
bool isEmptyQueue(Queue Q) { return Q.tail < Q.head; }
bool isFullQueue(Queue Q) { return Q.tail == N - 1 && Q.head == 0; }

void enqueue(Queue &Q, int x) {
    if (isFullQueue(Q)) { cout << "Queue penuh." << endl; return; }
    if (Q.tail == N - 1 && Q.head > 0) {
        int j = 0;
        for (int i = Q.head; i <= Q.tail; i++) Q.info[j++] = Q.info[i];
        Q.tail -= Q.head;
        Q.head = 0;
    }
    Q.info[++Q.tail] = x;
}

int dequeue(Queue &Q) {
    if (isEmptyQueue(Q)) { cout << "Queue kosong." << endl; return -1; }
    int x = Q.info[Q.head++];
    if (Q.head > Q.tail) { Q.head = 0; Q.tail = -1; }
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

int main() {
    Queue Q; createQueue(Q);
    cout << "Queue Alternatif 2" << endl; printInfo(Q);
    enqueue(Q, 5); printInfo(Q);
    enqueue(Q, 2); printInfo(Q);
    enqueue(Q, 7); printInfo(Q);
    dequeue(Q); printInfo(Q);
    enqueue(Q, 4); printInfo(Q);
    dequeue(Q); printInfo(Q);
    dequeue(Q); printInfo(Q);
    return 0;
}
