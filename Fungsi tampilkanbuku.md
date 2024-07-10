```
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

```