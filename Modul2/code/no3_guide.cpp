//PARAMETER FUNGSI
#include <iostream>
using namespace std;

//pemanggilan nilai dengan VALUE (cuma disalin, data asli aman)
void tukarValue(int x, int y) {
    int temp = x;
    x = y;
    y = temp;
}

//pemanggilan nilai dengan POINTER (alamat dikirim pakai pointer, data aslinya berubah)
void tukarPointer(int *px, int *py) {
    int temp = *px;
    *px = *py;
    *py = temp;
}


//pemanggilan nilai dengan REFERENCE (paling clean, data asli ikut berubah)
void tukarReference(int &px, int &py) {
    int temp = px;
    px = py;
    py = temp;
}

int main(){
    int a = 4, b = 6;
    cout << "Kondisi awal -> a: " << a << " b: " << b << endl;

    //VALUE
    tukarValue(a, b);
    cout << "setelah tukarValue: " << a << " b: " << b << endl;

    //POINTER
    tukarPointer(&a, &b);
    cout << "setelah tukarPointer: " << a << " b: " << b << endl;

    //REFERENCE
    tukarReference(a, b);
    cout << "setelah tukarReference: " << a << " b: " << b <<endl;

    return 0;
}