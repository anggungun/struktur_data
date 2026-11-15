#include <iostream>
using namespace std;

struct Stack { int info[20]; int top; };

void createStack(Stack &S) { S.top = -1; }
bool isEmpty(Stack S) { return S.top == -1; }

void push(Stack &S, int x) {
    if (S.top < 19) S.info[++S.top] = x;
}

int pop(Stack &S) {
    if (!isEmpty(S)) return S.info[S.top--];
    return -1;
}

void printInfo(Stack S) {
    for (int i = S.top; i >= 0; i--) cout << char(S.info[i]);
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

void getInputStream(Stack &S) {
    char karakter;
    cout << "Masukkan karakter (tekan Enter untuk selesai): ";
    while (cin.get(karakter) && karakter != '\n') {
        if (S.top < 19) push(S, karakter);
    }
}

int main() {
    Stack S;
    createStack(S);
    getInputStream(S);

    cout << "Isi stack:" << endl;
    printInfo(S);
    cout << "Balik stack:" << endl;
    balikStack(S);
    printInfo(S);
    return 0;
}
