``` 
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
```