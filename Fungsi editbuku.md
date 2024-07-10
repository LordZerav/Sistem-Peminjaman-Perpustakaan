```
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

```