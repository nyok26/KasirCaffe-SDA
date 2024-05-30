#ifndef HEAD073_H
#define HEAD073_H

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <fstream>
#include <limits>
#include "../231511086/231511086.h"
#include "../kasir.h"

void tampilkanAntrian(const vector<AntrianKasir> &daftarAntrian, const vector<Barang> &daftarBarang);
void tambahBarang(vector<Barang> &daftarBarang);
bool loginAdmin(const string &username, const string &password);
void hapusBarang(vector<Barang>& daftarBarang);

#endif