#include <iostream>
using namespace std;

int main(){
    int matriks[3][3];
    int jumlahDiagonal = 0;

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cin >> matriks[i][j];
        }
    }

    for (int i = 0; i < 3; i++)
    {
        jumlahDiagonal = jumlahDiagonal + matriks[i][i];
    }

    cout << jumlahDiagonal << endl;

    return 0;
}