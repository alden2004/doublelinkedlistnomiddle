#include <iostream>

using namespace std;

struct Datafilm {
    string judul;
    int durasi;
    int harga;
    Datafilm *prev;
    Datafilm *next;
};

Datafilm *kepala, *ekor, *cur, *newnode, *del;

// Membuat double linked list
void doublelinkedlist(string judul, int durasi, int harga) {
    kepala = new Datafilm();
    kepala->judul = judul;
    kepala->durasi = durasi;
    kepala->harga = harga;
    kepala->prev = NULL;
    kepala->next = NULL;
    ekor = kepala;
}

// Tambah awalan
void addfirst(string judul, int durasi, int harga) {
    if (kepala == NULL) {
        cout << "Double linked list belum dibuat" << endl;
    } else {
        newnode = new Datafilm();
        newnode->judul = judul;
        newnode->durasi = durasi;
        newnode->harga = harga;
        newnode->prev = NULL;
        newnode->next = kepala; 
        kepala->prev = newnode;
        kepala = newnode;
    }
}

// Tambah node di akhir
void addlast(string judul, int durasi, int harga) {
    if (kepala == NULL) {
        cout << "Double linked list belum dibuat" << endl;
    } else {
        newnode = new Datafilm();
        newnode->judul = judul;
        newnode->durasi = durasi;
        newnode->harga = harga;
        newnode->prev = ekor;
        newnode->next = NULL; 
        ekor->next = newnode;
        ekor = newnode;
    }
}

// Remove first
void removefirst() {
    if (kepala == NULL) {
        cout << "Double linked list belum dibuat" << endl;
    } else {
        del = kepala;
        kepala = kepala->next;
        if (kepala != NULL) {
            kepala->prev = NULL;
        } else {
            ekor = NULL;
        }
        delete del;
    }
}

// Remove last
void removelast() {
    if (kepala == NULL) {
        cout << "Double linked list belum dibuat" << endl;
    } else {
        del = ekor;
        ekor = ekor->prev;
        if (ekor != NULL) {
            ekor->next = NULL;
        } else {
            kepala = NULL;
        }
        delete del;
    }
}

// Cetak double linked list
void cetakdouble() {
    if (kepala == NULL) {
        cout << "Double linked list belum dibuat" << endl;
    } else {
        cout << "Isi data film:" << endl;
        cur = kepala;
        while (cur != NULL) {
            cout << "Judul: " << cur->judul << endl;
            cout << "Durasi: " << cur->durasi << " menit" << endl;
            cout << "Harga: " << cur->harga << " rupiah" << endl;
            cout << endl;
            cur = cur->next;
        }
    }
}

int main() {
    doublelinkedlist("Ghost Rider", 180, 65000);
    cetakdouble();

    addfirst("Royal Enfield", 120, 50000);
    cetakdouble();

    addlast("Ultraman Legend", 120, 50000);
    cetakdouble();

    removefirst();
    cetakdouble();

    removelast();
    cetakdouble();

    return 0;
}
