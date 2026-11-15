#include <iostream>
using namespace std;

struct Stack { int info[20]; int top; };

void createStack(Stack &S) { S.top = -1; }
bool isEmpty(Stack S) { return S.top == -1; }
bool isFull(Stack S) { return S.top == 19; }

void push(Stack &S, int x) {
    if (!isFull(S)) S.info[++S.top] = x;
}

int pop(Stack &S) {
    if (!isEmpty(S)) return S.info[S.top--];
    return -1;
}

void printInfo(Stack S) {
    for (int i = S.top; i >= 0; i--) cout << S.info[i] << " ";
    cout << endl;
}

void pushAscending(Stack &S, int x) {
    Stack B;
    createStack(B);
    while (!isEmpty(S) && S.info[S.top] > x) push(B, pop(S));
    push(S, x);
    while (!isEmpty(B)) push(S, pop(B));
}

void balikStack(Stack &S) {
    int kiri = 0, kanan = S.top;
    while (kiri < kanan) {
        int temp = S.info[kiri];
        S.info[kiri] = S.info[kanan];
        S.info[kanan] = temp;
        kiri++;
        kanan--;
    }
}

int main() {
    Stack S;
    createStack(S);
    pushAscending(S, 3);
    pushAscending(S, 4);
    pushAscending(S, 8);
    pushAscending(S, 2);
    pushAscending(S, 3);
    pushAscending(S, 9);

    cout << "Isi stack ascending:" << endl;
    printInfo(S);
    cout << "Balik stack:" << endl;
    balikStack(S);
    printInfo(S);
    return 0;
}
