#include "231511073/231511073.h"
#include "231511086/231511086.h"

int main() {
    vector<AntrianKasir> daftarAntrian;
    vector<Barang> daftarBarang;

    while (true) {
        cout << "=========================================" << endl;
        cout << setw(15) << left << "Dashboard" << endl;
        cout << "=========================================" << endl;
        cout << "Menu:" << endl;
        cout << "1. Login Admin" << endl;
        cout << "2. Login Pelanggan" << endl;
        cout << "3. Register Pelanggan" << endl;
        cout << "4. Keluar" << endl;
        cout << "Pilih menu: ";

        int pilihan;
        cin >> pilihan;

        switch (pilihan) {
        case 1: {
            system("CLS");
            string username, password;
            cout << "Masukkan nama pengguna: ";
            cin >> username;
            cout << "Masukkan kata sandi: ";
            cin >> password;
            if (loginAdmin(username, password)) {
                cout << "Login berhasil sebagai admin." << endl;
                while (true) {
                    cout << "\nMenu Admin:" << endl;
                    cout << "1. Tambah Kasir" << endl;
                    cout << "2. Tambah Barang" << endl;
                    cout << "3. Tampilkan Antrian" << endl;
                    cout << "4. Logout" << endl;
                    cout << "Pilih menu: ";

                    int pilihanAdmin;
                    cin >> pilihanAdmin;

                    switch (pilihanAdmin) {
                    case 1: {
                        system("CLS");
                        string namaKasir;
                        cout << "Masukkan nama kasir baru: ";
                        cin >> namaKasir;
                        AntrianKasir antrian = {namaKasir, nullptr, nullptr};
                        daftarAntrian.push_back(antrian);
                        cout << "Kasir berhasil ditambahkan." << endl;
                        break;
                    }
                    case 2: {
                        system("CLS");
                        tambahBarang(daftarBarang);
                        break;
                    }
                    case 3: {
                        system("CLS");
                        tampilkanAntrian(daftarAntrian, daftarBarang);
                        break;
                    }
                    case 4: {
                        system("CLS");
                        cout << "Logout dari admin." << endl;
                        break;
                    }
                    default: {
                        cout << "Pilihan tidak valid." << endl;
                        break;
                    }
                    }

                    if (pilihanAdmin == 4) {
                        break;
                    }
                }
            } else {
                cout << "Login gagal. Nama pengguna atau kata sandi salah." << endl;
            }
            break;
        }
        case 2: {
            system("CLS");
            string username, password;
            cout << "Masukkan nama pengguna: ";
            cin >> username;
            cout << "Masukkan kata sandi: ";
            cin >> password;
            if (loginPelanggan(username, password)) {
                cout << "Login berhasil sebagai pelanggan." << endl;
                while (true) {
                    cout << "\nMenu Pelanggan:" << endl;
                    cout << "1. Tambah barang ke keranjang" << endl;
                    cout << "2. Lihat keranjang belanja" << endl;
                    cout << "3. Checkout" << endl;
                    cout << "4. Logout" << endl;
                    cout << "Pilih menu: ";

                    int pilihanPelanggan;
                    cin >> pilihanPelanggan;

                    switch (pilihanPelanggan) {
                    case 1: {
                        system("CLS");
                        cout << "Daftar kasir yang tersedia:" << endl;
                        for (int i = 0; i < daftarAntrian.size(); ++i) {
                            cout << i << ". " << daftarAntrian[i].namaKasir << endl;
                        }
                        int nomorKasir;
                        cout << "Masukkan nomor kasir yang ingin Anda pilih: ";
                        cin >> nomorKasir;
                        if (nomorKasir < 0 || nomorKasir >= daftarAntrian.size()) {
                            cout << "Kasir tidak ditemukan." << endl;
                            break;
                        }

                        cout << "Daftar barang yang tersedia:" << endl;
                        tampilkanDaftarBarang(daftarBarang);

                        while (true) {
                            int nomorBarang;
                            cout << "Masukkan nomor barang yang ingin Anda beli (0 untuk selesai): ";
                            cin >> nomorBarang;
                            if (nomorBarang == 0) {
                                break; // Keluar dari loop jika pelanggan memilih untuk selesai
                            } else if (nomorBarang < 0 || nomorBarang > daftarBarang.size()) {
                                cout << "Barang tidak ditemukan." << endl;
                                continue; // Kembali ke pengulangan berikutnya dalam loop
                            }

                            // Copy barang ke keranjang belanja pelanggan pada kasir yang dipilih
                            Barang barangDibeli = daftarBarang[nomorBarang - 1];
                            Pelanggan pelanggan = {username, {barangDibeli}, nullptr};
                            tambahPelangganKeAntrian(daftarAntrian[nomorKasir], pelanggan);
                            cout << "Barang berhasil ditambahkan ke keranjang." << endl;
                        }
                        break;
                    }

                    case 2: {
                        system("CLS");
                        // Mencari antrian kasir yang sesuai dengan nama pelanggan
                        bool keranjangDitemukan = false;
                        for (const AntrianKasir &antrian : daftarAntrian) {
                            Pelanggan *current = antrian.head;
                            while (current != nullptr) {
                                if (current->nama == username) {
                                    tampilkanKeranjangBelanja(antrian, username);
                                    keranjangDitemukan = true;
                                    break;
                                }
                                current = current->next;
                            }
                        }
                        if (!keranjangDitemukan) {
                            cout << "Anda belum memilih kasir atau keranjang belanja Anda kosong." << endl;
                        }
                        break;
                    }

                    case 3: {
                        system("CLS");
                        for (AntrianKasir &antrian : daftarAntrian) {
                            Pelanggan *current = antrian.head;
                            Pelanggan *prev = nullptr;
                            while (current != nullptr) {
                                if (current->nama == username) {
                                    double totalHarga = 0.0;
                                    while (true) {
                                        cout << "Keranjang Belanja Anda:" << endl;
                                        for (int i = 0; i < current->keranjangBelanja.size(); ++i) {
                                            cout << i + 1 << ". " << current->keranjangBelanja[i].nama << " (Rp" << current->keranjangBelanja[i].harga << ")" << endl;
                                        }
                                        cout << "Masukkan nomor barang yang ingin Anda checkout (0 untuk selesai): ";
                                        int nomorBarang;
                                        cin >> nomorBarang;
                                        if (nomorBarang == 0) {
                                            break;
                                        } else if (nomorBarang < 1 || nomorBarang > current->keranjangBelanja.size()) {
                                            cout << "Barang tidak ditemukan." << endl;
                                            continue;
                                        }
                                        totalHarga += current->keranjangBelanja[nomorBarang - 1].harga;
                                        current->keranjangBelanja.erase(current->keranjangBelanja.begin() + (nomorBarang - 1));
                                    }

                                    cout << "Total harga belanja: Rp" << totalHarga << endl;
                                    if (current->keranjangBelanja.empty()) {
                                        // Hapus pelanggan dari antrian
                                        if (prev == nullptr) {
                                            antrian.head = current->next;
                                        } else {
                                            prev->next = current->next;
                                        }
                                        if (current == antrian.tail) {
                                            antrian.tail = prev;
                                        }
                                        delete current;
                                        cout << "Anda telah checkout dan dihapus dari antrian." << endl;
                                    }
                                    break;
                                }
                                prev = current;
                                current = current->next;
                            }
                        }
                        break;
                    }
                    case 4: {
                        system("CLS");
                        cout << "Logout dari pelanggan." << endl;
                        break;
                    }
                    default: {
                        cout << "Pilihan tidak valid." << endl;
                        break;
                    }
                    }

                    if (pilihanPelanggan == 4) {
                        break;
                    }
                }
            } else {
                cout << "Login gagal. Nama pengguna atau kata sandi salah." << endl;
            }
            break;
        }
        case 3: {
            registerPelanggan();
            break;
        }
        case 4: {
            cout << "Terima kasih, program selesai." << endl;
            return 0;
        }
        default: {
            cout << "Pilihan tidak valid." << endl;
            break;
        }
        }
    }

    return 0;
}