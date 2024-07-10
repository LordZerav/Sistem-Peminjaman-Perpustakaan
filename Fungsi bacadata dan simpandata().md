```
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

```