#ifndef PELAJARAN_H
#define PELAJARAN_H
#include <iostream>
using namespace std;

typedef struct {
    string namaPel;
    string kodePel;
} pelajaran;

pelajaran create_pelajaran(string nama, string kode);

void tampil_pelajaran(pelajaran p);

#endif