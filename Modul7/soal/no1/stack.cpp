#include <iostream>
#include "stack.h"
using namespace std;

void createStack(Stack &S) { S.top = -1; }

void push(Stack &S, infotype x) {
    if (S.top < 19) {
        S.top++;
        S.info[S.top] = x;
    }
}

infotype pop(Stack &S) {
    if (S.top >= 0) {
        infotype x = S.info[S.top];
        S.top--;
        return x;
    }
    return -1;
}

void printInfo(Stack S) {
    for (int i = S.top; i >= 0; i--) cout << S.info[i] << " ";
    cout << endl;
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
