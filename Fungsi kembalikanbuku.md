```
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

```