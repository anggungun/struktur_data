#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

Node *head = nullptr;

void insertLast(int nilai)
{
    Node *baru = new Node;
    baru->data = nilai;
    baru->next = nullptr;

    if (head == nullptr)
    {
        head = baru;
    }
    else
    {
        Node *bantu = head;

        while (bantu->next != nullptr)
        {
            bantu = bantu->next;
        }

        bantu->next = baru;
    }
}

int sum()
{
    int total = 0;
    Node *bantu = head;

    while (bantu != nullptr)
    {
        total = total + bantu->data;
        bantu = bantu->next;
    }

    return total;
}

int main()
{
    int N, nilai;

    cout << "Masukkan jumlah elemen: ";
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        cout << "Masukkan data ke-" << i + 1 << ": ";
        cin >> nilai;
        insertLast(nilai);
    }

    cout << "Jumlah seluruh elemen: " << sum() << endl;

    return 0;
}