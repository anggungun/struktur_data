#include <iostream>
using namespace std;
const int N = 5;
struct Queue { int info[N]; int head, tail; };

void createQueue(Queue &Q) { Q.head = -1; Q.tail = -1; }
bool isEmptyQueue(Queue Q) { return Q.head == -1; }
bool isFullQueue(Queue Q) {
    return !isEmptyQueue(Q) && (Q.tail + 1) % N == Q.head;
}

void enqueue(Queue &Q, int x) {
    if (isFullQueue(Q)) { cout << "Queue penuh." << endl; return; }
    if (isEmptyQueue(Q)) Q.head = Q.tail = 0;
    else Q.tail = (Q.tail + 1) % N;
    Q.info[Q.tail] = x;
}

int dequeue(Queue &Q) {
    if (isEmptyQueue(Q)) { cout << "Queue kosong." << endl; return -1; }
    int x = Q.info[Q.head];
    if (Q.head == Q.tail) Q.head = Q.tail = -1;
    else Q.head = (Q.head + 1) % N;
    return x;
}

void printInfo(Queue Q) {
    cout << "H=";
    if (isEmptyQueue(Q)) cout << "-"; else cout << Q.head;
    cout << " T=";
    if (isEmptyQueue(Q)) cout << "-"; else cout << Q.tail;
    cout << " | ";
    if (isEmptyQueue(Q)) cout << "Queue kosong";
    else {
        int i = Q.head;
        while (true) {
            cout << Q.info[i] << " ";
            if (i == Q.tail) break;
            i = (i + 1) % N;
        }
    }
    cout << endl;
}

int main() {
    Queue Q; createQueue(Q);
    cout << "Queue Alternatif 3 (Circular Queue)" << endl; printInfo(Q);
    enqueue(Q, 5); printInfo(Q);
    enqueue(Q, 2); printInfo(Q);
    enqueue(Q, 7); printInfo(Q);
    dequeue(Q); printInfo(Q);
    enqueue(Q, 4); printInfo(Q);
    dequeue(Q); printInfo(Q);
    dequeue(Q); printInfo(Q);
    return 0;
}
