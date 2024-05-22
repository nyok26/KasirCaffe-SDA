#ifndef HEAD086_H
#define HEAD086_H

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <fstream>
#include "../kasir.h"

void tambahPelangganKeAntrian(AntrianKasir &antrian, Pelanggan &pelanggan);
void tampilkanKeranjangBelanja(const AntrianKasir &antrian, const string &username);
bool loginPelanggan(const string &username, const string &password);
void registerPelanggan();
void tampilkanDaftarBarang(const vector<Barang> &daftarBarang);

#endif