#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <conio.h>

using namespace std;

class Buku {
private:
    string judulBuku, pengarangBuku;
    int tahunTerbit, stokBuku;
    bool statusBuku;
public:
    Buku () {}
    Buku (string judul, string pengarang, int tahun, int stok, bool status) {
        judulBuku = judul;
        pengarangBuku = pengarang;
        tahunTerbit = tahun;
        stokBuku = stok;
        statusBuku = status;
    }
}

class Peminjam {
private:
    string namaPeminjam, alamatPeminjam, nomorTelponPeminjam;
public:
    Peminjam () {}
    Peminjam (string nama, string alamat, string nomor) {
        namaPeminjam = nama;
        alamatPeminjam = alamat;
        nomorTeleponPeminjam = nomor;
    }
}

Buku daftarBuku[100];

int n;

int main () {
    cout << ":::::::::::::::: SELAMAT DATANG DI PERPUSTAKAAN PUTRA BANGSA ::::::::::::::::\n";
    cout << "-----------------------------------------------------------------------------\n";

    cout << "Silahkan Anda bisa memilih layanan berikut ini :\n";
    cout << "[1] Menambahkan Buku Baru \n";
    cout << "[2] Mencari Buku\n";
    cout << "[3] Mengedit Informasi Buku\n";
    cout << "[4] Meminjam Buku\n";
    cout << "[5] Mengembalikan Buku\n";
    cout << "[6] Menampilkan Daftar Buku\n";
    cout << "[7] Keluar\n";
    cout << "\n";
    
    cout << "Silahkan tentukan pilihan Anda [1] - [7]\n";
    cin >> n ;

    switch(n) {
        case 5 : {
    cout<    
        }
    }
    
    return 0;
}
