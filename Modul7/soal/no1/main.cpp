#include <iostream>
#include "stack.h"
using namespace std;

int main() {
    Stack S;
    createStack(S);

    push(S, 3);
    push(S, 4);
    push(S, 8);
    pop(S);
    push(S, 2);
    push(S, 3);
    pop(S);
    push(S, 9);

    cout << "Isi stack:" << endl;
    printInfo(S);

    cout << "Balik stack:" << endl;
    balikStack(S);
    printInfo(S);

    return 0;
}
