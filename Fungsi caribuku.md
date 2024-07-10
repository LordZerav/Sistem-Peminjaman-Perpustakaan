```
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

```