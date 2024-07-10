```
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

```