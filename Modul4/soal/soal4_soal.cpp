#include <iostream>
#include <string>
using namespace std;

struct Node
{
    string judul;
    int tahun;
    Node *next;
};

Node *head = nullptr;

void insertLast(string judul, int tahun)
{
    Node *baru = new Node;
    baru->judul = judul;
    baru->tahun = tahun;
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

void deleteLast()
{
    if (head == nullptr)
    {
        cout << "Daftar buku kosong!" << endl;
        return;
    }

    if (head->next == nullptr)
    {
        delete head;
        head = nullptr;
    }
    else
    {
        Node *bantu = head;

        while (bantu->next->next != nullptr)
        {
            bantu = bantu->next;
        }

        delete bantu->next;
        bantu->next = nullptr;
    }
}

void tampilBuku()
{
    Node *bantu = head;

    cout << "Daftar Buku:" << endl;

    if (bantu == nullptr)
    {
        cout << "Kosong" << endl;
    }

    while (bantu != nullptr)
    {
        cout << bantu->judul << endl;
        cout << "(" << bantu->tahun << ")" << endl;

        bantu = bantu->next;
    }
}

int main()
{
    int N, tahun;
    string judul;

    cout << "Masukkan jumlah buku: ";
    cin >> N;
    cin.ignore();

    for (int i = 0; i < N; i++)
    {
        cout << "\nMasukkan judul buku ke-" << i + 1 << ": ";
        getline(cin, judul);

        cout << "Masukkan tahun terbit: ";
        cin >> tahun;
        cin.ignore();

        insertLast(judul, tahun);
    }

    deleteLast();

    tampilBuku();

    return 0;
}