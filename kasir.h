#ifndef KASIR_H
#define KASIR_H

#include <iostream>
#include <string>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <fstream>


using namespace std;

// Struktur data untuk Barang
struct Barang {
    string nama;
    double harga;
    Barang() {}  // Konstruktor default kosong
    Barang(const string& n, double h) : nama(n), harga(h) {}
};

// Struktur data untuk Pelanggan
struct Pelanggan
{
    string nama;
    vector<Barang> keranjangBelanja; // Keranjang belanja pelanggan
    Pelanggan *next;                 // Pointer ke pelanggan berikutnya
};

// Struktur data untuk Antrian Kasir
struct AntrianKasir
{
    string namaKasir;
    Pelanggan *head; // Pointer ke pelanggan pertama di antrian
    Pelanggan *tail; // Pointer ke pelanggan terakhir di antrian
};


#endif
