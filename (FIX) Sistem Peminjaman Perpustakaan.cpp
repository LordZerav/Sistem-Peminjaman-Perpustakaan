#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

// Deklarasi Class Buku sebagai representasi buku di perpustakaan
class Buku {
public:
    string judul;       // Judul buku
    string pengarang;   // Nama pengarang
    string idbuku;      // ID buku
    int no;             // Nomor buku
    int tahunterbit;    // Tahun terbit buku
    int stokbuku;       // Stok buku
    bool statusbuku;    // Status buku : dipinjam atau tersedia

    // Konstruktor buku
    Buku() : no(0), tahunterbit(0), stokbuku(0), statusbuku(false) {}

    // Untuk mengonversi data buku menjadi string format untuk penyimpanan ke file
    string toString() const {
        return judul + ";" + pengarang + ";" + idbuku + ";" + to_string(no) + ";" + to_string(tahunterbit) + ";" + to_string(stokbuku) + ";" + (statusbuku ? "1" : "0") + "\n";
    }
};

// Deklarasi Class Perpustakaan untuk mengelola buku yang ada di perpustakaan
class Perpustakaan {
public:
    vector<Buku> bukuList;
    const string fileName = "DBase.txt";

    void bacaData() {
        ifstream file(fileName);
        if (!file.is_open()) return;

        bukuList.clear(); // Untuk clear existing data
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

            bukuList.push_back(buku); // Menambahkan buku ke daftar buku
        }
        file.close();
    }

    // Menyimpan data buku ke file
    void simpanData() {
        ofstream file(fileName);
        for (auto &buku : bukuList) {
            file << buku.toString(); // Menyimpan data buku dalam format string ke file
        }
        file.close();
    }

    // Menambahkan buku baru
    void tambahBuku() {
        int banyakBuku;
        cout << "\n";
        cout << "=====================================\n";
        cout << "|          TAMBAHKAN BUKU           |\n";
        cout << "=====================================\n";
        cout << "\n";
        cout << "Masukkan jumlah buku yang ingin ditambahkan: ";
        cin >> banyakBuku;

        for (int a = 0; a < banyakBuku; ++a) {
            cout << "\n";
            cout << "Data Buku Ke-" << a + 1 << ":\n";
            Buku buku;
            buku.no = bukuList.size() + 1;

            cout << "Masukkan ID Buku\t: ";
            cin.ignore(); // Membersihkan newline dari buffer
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
        
    system("cls");
    }

    // Mencari buku berdasarkan judul buku
    void cariBuku() {
        bacaData();
        string judul;
        cout << "\n";
        cout << "================================\n";
        cout << "|          CARI BUKU           |\n";
        cout << "================================\n";
        cout << "\n";
        cout << "Masukkan Judul Buku yang Dicari: ";
        cin.ignore(); // Membersihkan newline dari buffer
        getline(cin, judul);

        for (auto &buku : bukuList) {
            if (buku.judul == judul) {
                // Menampilkan informasi buku yang telah ditemukan
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

    // Mengedit informasi buku berdasarkan judul buku
    void editBuku() {
        string judul;
        cout << "\n";
        cout << "=========================================\n";
        cout << "|         EDIT INFORMASI BUKU           |\n";
        cout << "=========================================\n";
        cout << "\n";
        cout << "Masukkan Judul Buku yang Ingin Diedit: ";
        cin.ignore(); // Membersihkan newline dari buffer
        getline(cin, judul);

        for (auto &buku : bukuList) {
            if (buku.judul == judul) {
                // Memperbarui informasi buku
                cout << "Masukkan Pengarang Baru: ";
                getline(cin, buku.pengarang);
                cout << "Masukkan Tahun Terbit Baru: ";
                cin >> buku.tahunterbit;
                simpanData();
                return;

            }
        }
        cout << "Buku Tidak Ditemukan\n";

    system("cls");
    }

    // Meminjam buku berdasarkan judul buku
    void pinjamBuku() {
        string judul;
        cout << "\n";
        cout << "==================================\n";
        cout << "|          PINJAM BUKU           |\n";
        cout << "==================================\n";
        cout << "\n";
        cout << "Masukkan Judul Buku yang Ingin Dipinjam: ";
        cin.ignore(); // Membersihkan newline dari buffer
        getline(cin, judul);

        for (auto &buku : bukuList) {
            if (buku.judul == judul && !buku.statusbuku) {
                buku.statusbuku = true; // Mengubah status buku menjadi dipinjam
                simpanData();
                cout << "Buku Berhasil Dipinjam\n";
                return;
            }
        }
        cout << "Buku Tidak Ditemukan atau Sudah Dipinjam\n";
    }

    // Mengembalikan buku berdasarkan judul buku
    void kembalikanBuku() {
        string judul;
        cout << "\n";
        cout << "======================================\n";
        cout << "|          KEMBALIKAN BUKU           |\n";
        cout << "======================================\n";
        cout << "\n";
        cout << "Masukkan Judul Buku yang Ingin Dikembalikan: ";
        cin.ignore(); // Membersihkan newline dari buffer
        getline(cin, judul);

        for (auto &buku : bukuList) {
            if (buku.judul == judul && buku.statusbuku) {
                buku.statusbuku = false; // Mengubah status buku menjadi tersedia
                simpanData();
                cout << "Buku Berhasil Dikembalikan\n";
                return;
            }
        }
        cout << "Buku Tidak Ditemukan atau Belum Dipinjam\n";
    }

    // Menampilkan semua daftar buku di perpustakaan
    void tampilkanBuku() {
        cout << "\n";
        cout << "==================================\n";
        cout << "|          DAFTAR BUKU           |\n";
        cout << "==================================\n";
        cout << "\n";
        cout << "Daftar Buku di Perpustakaan:\n";
        cout << "\n";
        for (auto &buku : bukuList) {
            // Menampilkan informasi buku
            cout << "Judul Buku\t : " << buku.judul << "\n";
            cout << "Pengarang\t : " << buku.pengarang << "\n";
            cout << "Diterbitkan\t : " << buku.tahunterbit << "\n";
            cout << "Status Buku\t : " << (buku.statusbuku ? "Dipinjam" : "Tersedia") << "\n";
            cout << "\n";
        }
    }

    // Keluar dari program
    void keluar() {
        cout << "\n";
        cout << "===========================================================================\n";
        cout << "|          Terima Kasih Telah Menggunakan Layanan Perpustakaan Kami       |\n";
        cout << "===========================================================================\n";
        cout << "\n";
    }
};

// Program Utama dan Outputnya

int main() {
    Perpustakaan perpustakaan;
    perpustakaan.bacaData(); // Membaca data buku dari file

    while (true) {
        cout << "\n";
        cout << "==================================================================\n";
        cout << "|          SELAMAT DATANG DI PERPUSTAKAAN PUTRA BANGSA           |\n";
        cout << "==================================================================\n";
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
            system("cls");
            perpustakaan.tambahBuku();

        } else if (n == 2) {
            system("cls");
            perpustakaan.cariBuku();

        } else if (n == 3) {
            system("cls");
            perpustakaan.editBuku();

        } else if (n == 4) {
            system("cls");
            perpustakaan.pinjamBuku();

        } else if (n == 5) {
            system("cls");
            perpustakaan.kembalikanBuku();

        } else if (n == 6) {
            system("cls");
            perpustakaan.tampilkanBuku();

        } else if (n == 7) {
            system("cls");
            perpustakaan.keluar();
            return 0;
            
        } else {
            system("cls");
            cout << "\n";
            cout << "Pilihan Anda tidak valid, Silakan coba lagi.\n";
            cout << "\n";
        }
    }

    return 0;
}
