#include "231511073.h"


// Fungsi untuk menampilkan antrian kasir beserta barang yang dipilih oleh pelanggan
void tampilkanAntrian(const vector<AntrianKasir> &daftarAntrian, const vector<Barang> &daftarBarang) {
    cout << "=========================================" << endl;
    cout << setw(15) << left << "Antrian Kasir" << endl;
    cout << "=========================================" << endl;

    bool antrianKosong = true; // Tandai apakah setidaknya satu antrian memiliki pelanggan atau tidak
    for (const AntrianKasir &antrian : daftarAntrian) {
        cout << "Kasir: " << antrian.namaKasir << endl;
        Pelanggan *current = antrian.head;
        while (current != nullptr) {
            cout << "-----------------------------------------" << endl;
            cout << "Pelanggan: " << current->nama << endl;
            cout << "Menu yang dibeli:" << endl;
            for (size_t i = 0; i < current->keranjangBelanja.size(); ++i) {
                cout << setw(3) << right << i + 1 << ". " << setw(15) << left << current->keranjangBelanja[i].nama << " (Rp" << current->keranjangBelanja[i].harga << ")" << endl;
            }
            current = current->next;
            antrianKosong = false; // Set antrianKosong ke false jika setidaknya satu antrian memiliki pelanggan
        }
    }

    // Tampilkan pesan jika antrian kosong
    if (antrianKosong) {
        cout << "Antrian kosong." << endl;
    }
}


// Fungsi untuk menambahkan barang dan harganya
void tambahBarang(vector<Barang>& daftarBarang) {
    string namaBarang;
    double hargaBarang;
    cout << "Masukkan nama menu: ";
    cin >> ws; // Mengabaikan karakter whitespace di awal
    getline(cin, namaBarang);

    cout << "Masukkan harga menu: ";
    cin >> hargaBarang;

    cout << "Nama menu yang dimasukkan: " << namaBarang << endl;
    cout << "Harga menu yang dimasukkan: " << hargaBarang << endl;

    Barang barang(namaBarang, hargaBarang);
    daftarBarang.push_back(barang);
    cout << "Menu berhasil ditambahkan." << endl;
}

//fungsi untuk menghapus barang
void hapusBarang(vector<Barang>& daftarBarang) {
    if (daftarBarang.empty()) {
        cout << "Tidak ada menu yang dapat dihapus." << endl;
        return;
    }

    tampilkanDaftarBarang(daftarBarang);

    int nomorBarang;
    cout << "Masukkan nomor menu yang ingin dihapus: ";
    cin >> nomorBarang;

    if (nomorBarang < 1 || nomorBarang > static_cast<int>(daftarBarang.size())) {
        cout << "Nomor menu tidak valid." << endl;
        return;
    }

    // Hapus menu dari daftarBarang
    daftarBarang.erase(daftarBarang.begin() + nomorBarang - 1);
    cout << "Menu berhasil dihapus." << endl;
}


// Fungsi untuk login admin
bool loginAdmin(const string &username, const string &password) {
    ifstream file("Assets/admin.txt");
    string storedUsername, storedPassword;
    while (file >> storedUsername >> storedPassword) {
        if (username == storedUsername && password == storedPassword) {
            file.close();
            return true;
        }
    }
    file.close();
    return false;
}

