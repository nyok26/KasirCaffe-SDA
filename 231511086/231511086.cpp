#include "231511086.h"

// Fungsi untuk menambahkan pelanggan ke antrian kasir
void tambahPelangganKeAntrian(AntrianKasir &antrian, Pelanggan &pelanggan) {
    Pelanggan *current = antrian.head;
    while (current != nullptr) {
        if (current->nama == pelanggan.nama) {
            // Tambahkan barang ke keranjang pelanggan yang sudah ada
            current->keranjangBelanja.insert(current->keranjangBelanja.end(), pelanggan.keranjangBelanja.begin(), pelanggan.keranjangBelanja.end());
            return;
        }
        current = current->next;
    }

    // Jika pelanggan tidak ditemukan, tambahkan pelanggan baru ke antrian
    Pelanggan *pelangganBaru = new Pelanggan{pelanggan.nama, pelanggan.keranjangBelanja, nullptr};
    if (antrian.head == nullptr) {
        antrian.head = pelangganBaru;
        antrian.tail = pelangganBaru;
    } else {
        antrian.tail->next = pelangganBaru;
        antrian.tail = pelangganBaru;
    }
}

// Fungsi untuk menampilkan keranjang belanja pelanggan
void tampilkanKeranjangBelanja(const AntrianKasir &antrian, const string &username) {
    cout << "Pesanan " << username << " pada Kasir " << antrian.namaKasir << ":" << endl;
    Pelanggan *current = antrian.head;
    while (current != nullptr) {
        if (current->nama == username) {
            for (const Barang &barang : current->keranjangBelanja) {
                cout << "- " << barang.nama << " (Rp" << barang.harga << ")" << endl;
            }
        }
        current = current->next;
    }
}

void tampilkanDaftarBarang(const vector<Barang>& daftarBarang) {
    cout << "Daftar Menu:" << endl;
    for (int i = 0; i < daftarBarang.size(); ++i) {
        cout << i + 1 << ". " << daftarBarang[i].nama << " (Rp " << daftarBarang[i].harga << ")" << endl;
    }
    cout << endl;
}

// Fungsi untuk register pelanggan
void registerPelanggan() {
    string username, password;
    cout << "Masukkan nama pengguna: ";
    cin >> username;
    cout << "Masukkan kata sandi: ";
    cin >> password;
    ofstream file("Assets/pelanggan.txt", ios::app);
    file << username << " " << password << endl;
    file.close();
    cout << "Pendaftaran berhasil." << endl;
}

// Fungsi untuk login pelanggan
bool loginPelanggan(const string &username, const string &password) {
    ifstream file("Assets/pelanggan.txt");
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
