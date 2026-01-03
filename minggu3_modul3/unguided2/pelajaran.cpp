#include "pelajaran.h"
#include <iostream>
using namespace std;

pelajaran create_pelajaran(string nama, string kode) {
    pelajaran p;
    p.namaPel = nama;
    p.kodePel = kode;
    return p;
}

void tampil_pelajaran(pelajaran p) {
    cout << "Nama Pelajaran : " << p.namaPel << endl;
    cout << "Kode Pelajaran : " << p.kodePel << endl;
}