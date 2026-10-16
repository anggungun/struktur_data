#include <iostream>
#include <string>
using namespace std;

struct Node
{
    string nama;
    Node *next;
};

Node *head = nullptr;
Node *tail = nullptr;

void insertLast(string nama)
{
    Node *baru = new Node;
    baru->nama = nama;
    baru->next = nullptr;

    if (head == nullptr)
    {
        head = baru;
        tail = baru;
    }
    else
    {
        tail->next = baru;
        tail = baru;
    }
}

void deleteFirst()
{
    if (head == nullptr)
    {
        cout << "Antrean kosong!" << endl;
        return;
    }

    Node *hapus = head;
    cout << "Nasabah yang dilayani: " << head->nama << endl;

    head = head->next;

    if (head == nullptr)
    {
        tail = nullptr;
    }
    delete hapus;
}

void tampilAntrean()
{
    cout << "Antrean: ";

    if (head == nullptr)
    {
        cout << "Kosong";
    }
    else
    {
        Node *bantu = head;

        while (bantu != nullptr)
        {
            cout << bantu->nama;
            if (bantu->next != nullptr)
            {
                cout << " -> ";
            }
            bantu = bantu->next;
        }
    }
    cout << endl;
}

int main()
{
    int pilihan;
    string nama;

    do
    {
        cout << "\n=== MENU ANTREAN BANK ===" << endl;
        cout << "1. Tambah nasabah" << endl;
        cout << "2. Layani nasabah" << endl;
        cout << "3. Keluar" << endl;
        cout << "Pilih menu: ";
        cin >> pilihan;

        if (pilihan == 1)
        {
            cout << "Masukkan nama nasabah: ";
            cin >> ws;
            getline(cin, nama);

            insertLast(nama);
            tampilAntrean();
        }
        else if (pilihan == 2)
        {
            deleteFirst();
            tampilAntrean();
        }
        else if (pilihan == 3)
        {
            cout << "Program selesai." << endl;
        }
        else
        {
            cout << "Pilihan tidak valid!" << endl;
        }

    } while (pilihan != 3);

    return 0;
}