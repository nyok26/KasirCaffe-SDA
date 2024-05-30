#include "231511073/231511073.h"
#include "231511086/231511086.h"

int main()
{
    vector<AntrianKasir> daftarAntrian;
    vector<Barang> daftarBarang;
    daftarBarang.clear();
    while (true)
    {
        cout << "=========================================" << endl;
        cout << setw(15) << left << "Dashboard Kasir Caffe" << endl;
        cout << "=========================================" << endl;
        cout << "Menu:" << endl;
        cout << "1. Login Admin" << endl;
        cout << "2. Login Pelanggan" << endl;
        cout << "3. Register Pelanggan" << endl;
        cout << "4. Keluar" << endl;
        cout << "Pilih menu: ";

        int pilihan;
        cin >> pilihan;

        switch (pilihan)
        {
        case 1:
        {
            system("CLS");
            string username, password;
            cout << "Masukkan nama pengguna: ";
            cin >> username;
            cout << "Masukkan kata sandi: ";
            cin >> password;
            if (loginAdmin(username, password))
            {
                cout << "Login berhasil sebagai admin." << endl;
                while (true)
                {
                    cout << "\nMenu Admin:" << endl;
                    cout << "1. Tambah Kasir" << endl;
                    cout << "2. Tambah Menu" << endl;
                    cout << "3. Tampilkan Antrian" << endl;
                    cout << "4. Tampilkan Daftar Menu" << endl;
                    cout << "5. Tampilkan Daftar Kasir" << endl;
                    cout << "6. Hapus Barang" << endl;
                    cout << "7. Logout" << endl;
                    cout << "Pilih menu: ";

                    int pilihanAdmin;
                    cin >> pilihanAdmin;

                    switch (pilihanAdmin)
                    {
                    case 1:
                    {
                        system("CLS");
                        string namaKasir;
                        cout << "Masukkan nama kasir baru: ";
                        cin >> namaKasir;
                        AntrianKasir antrian = {namaKasir, nullptr, nullptr};
                        daftarAntrian.push_back(antrian);
                        cout << "Kasir " << namaKasir << " berhasil ditambahkan." << endl;
                        break;
                    }
                    case 2:
                    {
                        system("CLS");
                        tambahBarang(daftarBarang);
                        break;
                    }
                    case 3:
                    {
                        system("CLS");
                        tampilkanAntrian(daftarAntrian, daftarBarang);
                        break;
                    }
                    case 4:
                    {
                        system("CLS");
                        if (daftarBarang.empty())
                        {
                            cout << "Belum ada menu yang ditambahkan" << endl;
                            break;
                        }
                        tampilkanDaftarBarang(daftarBarang);
                        cout << endl;
                        break;
                    }
                    case 5:
                    {
                        system("CLS");
                        if (daftarAntrian.empty())
                        {
                            cout << "Belum ada kasir yang ditambahkan" << endl;
                            break;
                        }
                        cout << "Daftar kasir yang tersedia:" << endl;
                        for (int i = 0; i < daftarAntrian.size(); ++i)
                        {
                            cout << i << ". " << daftarAntrian[i].namaKasir << endl;
                        }
                        break;
                    }
                    case 6:
                    {
                        system("CLS");
                        hapusBarang(daftarBarang);
                        break;
                    }
                    case 7:
                    {
                        system("CLS");
                        cout << "Logout dari admin." << endl;
                        break;
                    }
                    default:
                    {
                        cout << "Pilihan tidak valid." << endl;
                        break;
                    }
                    }

                    if (pilihanAdmin == 7)
                    {
                        break;
                    }
                }
            }
            else
            {
                cout << "Login gagal. Nama pengguna atau kata sandi salah." << endl;
            }
            break;
        }
        case 2:
        {
            system("CLS");
            string username, password;
            cout << "Masukkan nama pengguna: ";
            cin >> username;
            cout << "Masukkan kata sandi: ";
            cin >> password;
            if (loginPelanggan(username, password))
            {
                cout << "Halo " << username << " Selamat Datang";
                while (true)
                {
                    cout << "\nMenu Pelanggan:" << endl;
                    cout << "1. Pesan menu" << endl;
                    cout << "2. Tampilkan Daftar Menu" << endl;
                    cout << "3. Lihat pesanan anda" << endl;
                    cout << "4. Bayar" << endl;
                    cout << "5. Logout" << endl;
                    cout << "Pilih menu: ";

                    int pilihanPelanggan;
                    cin >> pilihanPelanggan;

                    switch (pilihanPelanggan)
                    {
                    case 1:
                    {
                        system("CLS");

                        // Periksa apakah daftarBarang kosong
                        if (daftarBarang.empty())
                        {
                            cout << "Tidak ada menu yang tersedia." << endl;
                            break;
                        }

                        // Tampilkan daftar menu
                        cout << "Daftar Menu yang tersedia:" << endl;
                        tampilkanDaftarBarang(daftarBarang);

                        vector<Barang> keranjangBelanja;
                        while (true)
                        {
                            int nomorBarang;
                            cout << "Masukkan nomor Menu yang ingin Anda beli (0 untuk selesai): ";
                            cin >> nomorBarang;

                            if (nomorBarang == 0)
                            {
                                break; // Keluar dari loop jika pelanggan memilih untuk selesai
                            }
                            else if (nomorBarang < 1 || nomorBarang > daftarBarang.size())
                            {
                                cout << "Menu tidak ditemukan." << endl;
                                continue; // Kembali ke pengulangan berikutnya dalam loop
                            }

                            // Tambahkan barang ke keranjang belanja
                            Barang barangDibeli = daftarBarang[nomorBarang - 1];
                            keranjangBelanja.push_back(barangDibeli);
                            cout << "Menu berhasil ditambahkan ke keranjang." << endl;
                        }

                        // Periksa apakah daftarAntrian kosong
                        if (daftarAntrian.empty())
                        {
                            cout << "Tidak ada kasir yang tersedia." << endl;
                            break;
                        }

                        // Tampilkan daftar kasir dengan jumlah antrian
                        cout << "Daftar kasir yang tersedia:" << endl;
                        for (int i = 0; i < daftarAntrian.size(); ++i)
                        {
                            int jumlahAntrian = 0;
                            Pelanggan *current = daftarAntrian[i].head;
                            while (current != nullptr)
                            {
                                jumlahAntrian++;
                                current = current->next;
                            }
                            cout << i << ". " << daftarAntrian[i].namaKasir << " (Jumlah antrian: " << jumlahAntrian << ")" << endl;
                        }

                        cout << "Masukkan nomor kasir yang ingin Anda pilih untuk pembayaran: ";
                        int nomorKasir;
                        cin >> nomorKasir;

                        if (nomorKasir < 0 || nomorKasir >= daftarAntrian.size())
                        {
                            cout << "Kasir tidak ditemukan." << endl;
                            break;
                        }

                        // Tambahkan pelanggan ke antrian kasir yang dipilih
                        Pelanggan pelanggan = {username, keranjangBelanja, nullptr};
                        tambahPelangganKeAntrian(daftarAntrian[nomorKasir], pelanggan);
                        cout << "Pesanan Anda berhasil ditambahkan ke antrian." << endl;
                        break;
                    }

                    case 2:
                    {
                        system("CLS");
                        if (daftarBarang.empty())
                        {
                            cout << "Menu tidak tersedia" << endl;
                            break;
                        }
                        tampilkanDaftarBarang(daftarBarang);
                        cout << endl;
                        break;
                    }
                    case 3:
                    {
                        system("CLS");
                        // Mencari antrian kasir yang sesuai dengan nama pelanggan
                        bool keranjangDitemukan = false;
                        for (const AntrianKasir &antrian : daftarAntrian)
                        {
                            Pelanggan *current = antrian.head;
                            while (current != nullptr)
                            {
                                if (current->nama == username)
                                {
                                    tampilkanKeranjangBelanja(antrian, username);
                                    keranjangDitemukan = true;
                                    break;
                                }
                                current = current->next;
                            }
                        }
                        if (!keranjangDitemukan)
                        {
                            cout << "Anda belum memilih kasir atau Anda belum pesan." << endl;
                        }
                        break;
                    }

                    case 4:
                    {
                        system("CLS");
                        if (daftarAntrian.empty())
                        {
                            cout << "Anda belum memesan menu apapun" << endl;
                            break;
                        }

                        bool found = false;    // Untuk melacak apakah pelanggan ditemukan
                        int posisiAntrian = 0; // Untuk melacak posisi pelanggan dalam antrian

                        for (AntrianKasir &antrian : daftarAntrian)
                        {
                            Pelanggan *current = antrian.head;
                            Pelanggan *prev = nullptr;

                            while (current != nullptr)
                            {
                                posisiAntrian++;

                                if (current->nama == username)
                                {
                                    found = true;

                                    if (current == antrian.head)
                                    {
                                        double totalHarga = 0.0;

                                        cout << "Pesanan anda :" << endl;
                                        for (int i = 0; i < current->keranjangBelanja.size(); ++i)
                                        {
                                            cout << i + 1 << ". " << current->keranjangBelanja[i].nama << " (Rp" << current->keranjangBelanja[i].harga << ")" << endl;
                                            totalHarga += current->keranjangBelanja[i].harga;
                                        }

                                        cout << "Total harga pesanan anda : Rp" << totalHarga << endl;
                                        cout << "Apakah Anda ingin membayar pesanan ini? (y/n): ";
                                        char konfirmasi;
                                        cin >> konfirmasi;

                                        if (konfirmasi == 'y')
                                        {
                                            if (prev == nullptr)
                                            {
                                                antrian.head = current->next;
                                            }
                                            else
                                            {
                                                prev->next = current->next;
                                            }
                                            if (current == antrian.tail)
                                            {
                                                antrian.tail = prev;
                                            }
                                            delete current;
                                            cout << "Anda telah bayar dan dihapus dari antrian." << endl;
                                        }
                                    }
                                    else
                                    {
                                        cout << "Pembayaran hanya bisa dilakukan oleh pelanggan di antrian pertama." << endl;
                                        cout << "Anda berada di antrian ke-" << posisiAntrian << " dalam antrian kasir."  << antrian.namaKasir << endl;
                                    }
                                    break;
                                }

                                prev = current;
                                current = current->next;
                            }

                            if (found)
                                break;
                        }

                        if (!found)
                        {
                            cout << "Pelanggan tidak ditemukan dalam antrian." << endl;
                        }

                        break;
                    }

                    case 5:
                    {
                        system("CLS");
                        cout << "Logout dari pelanggan." << endl;
                        break;
                    }
                    default:
                    {
                        cout << "Pilihan tidak valid." << endl;
                        break;
                    }
                    }

                    if (pilihanPelanggan == 5)
                    {
                        break;
                    }
                }
            }
            else
            {
                cout << "Login gagal. Nama pengguna atau kata sandi salah." << endl;
            }
            break;
        }
        case 3:
        {
            registerPelanggan();
            break;
        }
        case 4:
        {
            cout << "Terima kasih, program selesai." << endl;
            return 0;
        }
        default:
        {
            cout << "Pilihan tidak valid." << endl;
            break;
        }
        }
    }

    return 0;
}
