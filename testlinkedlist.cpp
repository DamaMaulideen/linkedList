#include <iostream>
// #include <curses.h>

using namespace std;

typedef struct Data
{
    int nilai;
    string nama;
    Data *next;
};

Data *head;
Data *tail;

void awal()
{
    head = NULL;
}

bool isEmpty()
{
    if (head == NULL)
        return true;
    return false;
}

void tambahDataDepan(int nilaiBaru, string namaBaru)
{
    Data *baru;
    baru = new Data;
    baru->nilai = nilaiBaru;
    baru->nama = namaBaru;
    baru->next = NULL;
    
    if (isEmpty())
    {
        head = baru;
        head->next = NULL;
    }
    else
    {
        baru->next = head;
        head = baru;
    }
    cout << "Data Depan Nama : "<< namaBaru << " Nilai : " << nilaiBaru << " Masuk" << endl;
}

void tambahDataBelakang(int nilaiBaru)
{
    Data *baru, *bantu;
    baru = new Data;
    baru->nilai = nilaiBaru;
    baru->next = NULL;
    if (isEmpty())
    {
        head = baru;
        head->next = NULL;
    }
    else
    {
        bantu = head;
        while (bantu->next != NULL)
        {
            bantu = bantu->next;
        }
        bantu->next = baru;
    }
    cout << "Data Belakang " << nilaiBaru << " Masuk" << endl;
}

void hapusDepan()
{
    Data *hapus;
    int d;
    if (!isEmpty())
    {
        if (head->next != NULL)
        {
            hapus = head;
            d = hapus->nilai;
            head = hapus->next;
            delete hapus;
        }
        else
        {
            d = head->nilai;
            head = NULL;
        }
        cout << d << " Terhapus" << endl;
    }
    else
        cout << "Masih Kosong" << endl;
}

void hapusBelakang()
{
    Data *hapus, *bantu;
    int tmp;
    if (!isEmpty())
    {
        if (head->next != NULL)
        {
            bantu = head;
            while (bantu->next->next != NULL)
            {
                bantu = bantu->next;
            }
            hapus = bantu->next;
            tmp = hapus->nilai;
            bantu->next = NULL;
            delete hapus;
        }
        else
        {
            tmp = head->nilai;
            head = NULL;
        }
        cout << tmp << " Terhapus" << endl;
    }
    else
        cout << "Masih Kosong" << endl;
}

void Cetak()
{
    if (!isEmpty())
    {
        Data *  bantu;
        bantu = head;
        do
        {
            cout << bantu->nilai << " ";
            bantu = bantu->next;
        } while (bantu != NULL);
        cout << endl;
    }
}

int panjang()
{
    int count = 0;
    if (!isEmpty())
    {
        count = 1;
        Data *bantu;
        bantu = head;
        if (bantu->next == NULL)
        {
            count = 1;
        }
        else
        {
            do
            {
                count++;
                bantu = bantu->next;
            } while (bantu->next != NULL);
        }
    }
    else
    {
        count = 0;
    }
    return count;
}

int main()
{
    int pil, nilaiBaru;
    string namaBaru;
    awal();
    do
    {

        // initscr();
        system("cls");
        cout << endl;
        cout << "==============================" << endl;
        cout << " PROGRAM LINKED LIST " << endl;
        cout << "==============================" << endl;
        cout << "1. Tambah Data Depan" << endl;
        cout << "2. Tambah Data Belakang" << endl;
        cout << "3. Hapus Data Depan" << endl;
        cout << "4. Hapus Data Belakang" << endl;
        cout << "5. Panjang Linked List" << endl;
        cout << "==============================" << endl;
        cout << "Masukkan Pilihan Anda : ";
        cin >> pil;
        switch (pil)
        {
        case 1: /* system("cls"); */
            cout << "Masukkan Nilai = ";
            cin >> nilaiBaru;
            cout << "Masukkan Nama = ";
            cin >> namaBaru;
            tambahDataDepan(nilaiBaru, namaBaru);
            Cetak();
            cout << endl;
            break;
        case 2: /* system("cls"); */
            cout << "Masukkan Data = ";
            cin >> nilaiBaru;
            tambahDataBelakang(nilaiBaru);
            Cetak();
            cout << endl;
            break;
        case 3: /* system("cls"); */
            hapusDepan();
            Cetak();
            cout << endl;
            break;
        case 4: /* system("cls"); */
            hapusBelakang();
            Cetak();
            cout << endl;
            break;
        case 5: /* system("cls"); */
            Cetak();
            cout << panjang();
            cout << endl;
            break;
        default: /* system("cls"); */
            cout << "\n Maaf, Pilihan Anda Salah";
            cout << endl;
        }
        // getch();
    } while (pil != 7);
    return 0;
}