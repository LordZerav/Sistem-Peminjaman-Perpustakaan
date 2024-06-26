#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <conio.h>
#include <vector>

using namespace std;

class Buku {
    public:
        string judulBuku; 
        string pengarangBuku;
        string idBuku;
        int no;
        int tahunTerbit; 
        int stokBuku; 
        bool statusBuku;
};

class Peminjam {
    public:
        string namaPeminjam;
        string asaldaerahPeminjam;
        string nomorTeleponPeminjam;
};

int n;        
int banyakData; 

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
    
    
    if (n == 1) {
        int namBuku;
        cout << ":::::::: Menambahkan Buku Baru ::::::::\n";
        cout << "---------------------------------------\n";
        
        cout << "Jumlah Buku Ditambahkan\t : ";
        cin >> banyakData;
        
        vector <Buku> dataBuku (banyakData);
        for (int a = 0; a < banyakData; ++a) {
            cout << "Data Buku Ke-" << a + 1 << ":\n";
            dataBuku[a].no = a + 1; 
        
            Buku buku;
            cout << "Masukkan ID Buku\t : \n";
            cin.ignore();
            getline(cin, dataBuku[a].idBuku);
            cout << "Masukkan Judul Buku Baru\t : \n";
            cin >> dataBuku[a].judulBuku;
            cin.ignore();
            getline(cin, dataBuku[a].judulBuku);
            cout << "Masukkan Nama Pengarang Buku\t : \n";
            cin >> dataBuku[a].pengarangBuku; 
            cout << "Masukkan Tahun Buku\t \n";
            cin >> dataBuku[a].tahunTerbit;
            cout << "Masukkan Stok Buku\t \n";
            cin >> dataBuku[a].stokBuku; 

        }
        
    }
}