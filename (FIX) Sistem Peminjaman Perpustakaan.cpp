#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

class Buku {
public:
    string judul;
    string pengarang;
    string idbuku;
    int no;
    int tahunterbit;
    int stokbuku;
    bool statusbuku;

    Buku() : no(0), tahunterbit(0), stokbuku(0), statusbuku(false) {}

    string toString() const {
        return judul + ";" + pengarang + ";" + idbuku + ";" + to_string(no) + ";" + to_string(tahunterbit) + ";" + to_string(stokbuku) + ";" + (statusbuku ? "1" : "0") + "\n";
    }
};

class Perpustakaan {
public:
    vector<Buku> bukuList;
    const string fileName = "DBase.txt";

    void bacaData() {
        ifstream file(fileName);
        if (!file.is_open()) return;

        string line;
        while (getline(file, line)) {
            Buku buku;
            size_t pos = 0;
            pos = line.find(";"); buku.judul = line.substr(0, pos); line.erase(0, pos + 1);
            pos = line.find(";"); buku.pengarang = line.substr(0, pos); line.erase(0, pos + 1);
            pos = line.find(";"); buku.idbuku = line.substr(0, pos); line.erase(0, pos + 1);
            pos = line.find(";"); buku.no = stoi(line.substr(0, pos)); line.erase(0, pos + 1);
            pos = line.find(";"); buku.tahunterbit = stoi(line.substr(0, pos)); line.erase(0, pos + 1);
            pos = line.find(";"); buku.stokbuku = stoi(line.substr(0, pos)); line.erase(0, pos + 1);
            buku.statusbuku = (line == "1");

            bukuList.push_back(buku);
        }
        file.close();
    }

    void simpanData() {
        ofstream file(fileName);
        for (auto &buku : bukuList) {
            file << buku.toString();
        }
        file.close();
    }

    void tambahBuku() {
        int banyakBuku;
        cout << "\n";
        cout << "Masukkan jumlah buku yang ingin ditambahkan: ";
        cin >> banyakBuku;

        for (int a = 0; a < banyakBuku; ++a) {
            cout << "\n";
            cout << "Data Buku Ke-" << a + 1 << ":\n";
            Buku buku;
            buku.no = bukuList.size() + 1;

            cout << "Masukkan ID Buku\t: ";
            cin.ignore();
            getline(cin, buku.idbuku);

            cout << "Masukkan Judul Buku Baru\t: ";
            getline(cin, buku.judul);

            cout << "Masukkan Nama Pengarang Buku\t: ";
            getline(cin, buku.pengarang);

            cout << "Masukkan Tahun Buku\t: ";
            cin >> buku.tahunterbit;

            cout << "Masukkan Stok Buku\t: ";
            cin >> buku.stokbuku;

            buku.statusbuku = false;
            bukuList.push_back(buku);
        }
        cout << "\n";
        cout << "Data Buku telah disimpan\n";
        cout << "\n";
        simpanData();
    }

    void cariBuku() {
        bacaData();
        string judul;
        cout << "\n";
        cout << "Masukkan Judul Buku yang Dicari: ";
        cin.ignore(); // Membersihkan newline dari buffer
        getline(cin, judul);

        for (auto &buku : bukuList) {
            if (buku.judul == judul) {
                cout << "Judul Buku\t : " << buku.judul << "\n";
                cout << "Pengarang\t : " << buku.pengarang << "\n";
                cout << "Diterbitkan\t : " << buku.tahunterbit << "\n";
                cout << "Status Buku\t : " << (buku.statusbuku ? "Dipinjam" : "Tersedia") << "\n";
                cout << "\n";
                return;
            }
        }

        cout << "Buku Tidak Ditemukan\n";
        cout << "\n";
    }

    void editBuku() {
        string judul;
        cout << "\n";
        cout << "Masukkan Judul Buku yang Ingin Diedit: ";
        cin.ignore(); // Membersihkan newline dari buffer
        getline(cin, judul);

        for (auto &buku : bukuList) {
            if (buku.judul == judul) {
                cout << "Masukkan Pengarang Baru: ";
                getline(cin, buku.pengarang);
                cout << "Masukkan Tahun Terbit Baru: ";
                cin >> buku.tahunterbit;
                simpanData();
                return;
            }
        }
        cout << "Buku Tidak Ditemukan\n";
    }

    void pinjamBuku() {
        string judul;
        cout << "\n";
        cout << "Masukkan Judul Buku yang Ingin Dipinjam: ";
        cin.ignore(); // Membersihkan newline dari buffer
        getline(cin, judul);

        for (auto &buku : bukuList) {
            if (buku.judul == judul && !buku.statusbuku) {
                buku.statusbuku = true;
                simpanData();
                cout << "Buku Berhasil Dipinjam\n";
                return;
            }
        }
        cout << "Buku Tidak Ditemukan atau Sudah Dipinjam\n";
    }

    void kembalikanBuku() {
        string judul;
        cout << "\n";
        cout << "Masukkan Judul Buku yang Ingin Dikembalikan: ";
        cin.ignore(); // Membersihkan newline dari buffer
        getline(cin, judul);

        for (auto &buku : bukuList) {
            if (buku.judul == judul && buku.statusbuku) {
                buku.statusbuku = false;
                simpanData();
                cout << "Buku Berhasil Dikembalikan\n";
                return;
            }
        }
        cout << "Buku Tidak Ditemukan atau Belum Dipinjam\n";
    }

    void tampilkanBuku() {
        cout << "\n";
        cout << "Daftar Buku di Perpustakaan:\n";
        cout << "\n";
        for (auto &buku : bukuList) {
            cout << "Judul Buku\t : " << buku.judul << "\n";
            cout << "Pengarang\t : " << buku.pengarang << "\n";
            cout << "Diterbitkan\t : " << buku.tahunterbit << "\n";
            cout << "Status Buku\t : " << (buku.statusbuku ? "Dipinjam" : "Tersedia") << "\n";
            cout << "\n";
        }
    }

    void keluar() {
        cout << "\n";
        cout << "Terima kasih telah menggunakan layanan perpustakaan.\n";
    }
};

int main() {
    Perpustakaan perpustakaan;
    perpustakaan.bacaData();

    while (true) {
        cout << "::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n";
        cout << "\n";
        cout << " \t \t SELAMAT DATANG DI PERPUSTAKAAN PUTRA BANGSA \t \t \n";
        cout << "\n";
        cout << "::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n";
        cout << "\n";

        cout << "Silahkan Anda bisa memilih layanan berikut ini :\n";
        cout << "\n";

        cout << "[1] Menambahkan Buku Baru \n";
        cout << "[2] Mencari Buku\n";
        cout << "[3] Mengedit Informasi Buku\n";
        cout << "[4] Meminjam Buku\n";
        cout << "[5] Mengembalikan Buku\n";
        cout << "[6] Menampilkan Daftar Buku\n";
        cout << "[7] Keluar\n";
        cout << "\nSilahkan tentukan pilihan Anda [1] - [7]\n";

        int n;
        cin >> n;

        if (n == 1) {
            perpustakaan.tambahBuku();
        } else if (n == 2) {
            perpustakaan.cariBuku();
        } else if (n == 3) {
            perpustakaan.editBuku();
        } else if (n == 4) {
            perpustakaan.pinjamBuku();
        } else if (n == 5) {
            perpustakaan.kembalikanBuku();
        } else if (n == 6) {
            perpustakaan.tampilkanBuku();
        } else if (n == 7) {
            perpustakaan.keluar();
            return 0;
        } else {
            cout << "Pilihan Anda tidak valid, Silakan coba lagi.\n";
        }
    }

    return 0;
}
