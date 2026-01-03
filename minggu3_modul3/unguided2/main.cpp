#include <iostream>
#include "pelajaran.h"
using namespace std;

int main() {
    string namaPel, kodePel;

    cout << "Masukkan nama pelajaran : ";
    getline(cin, namaPel);
    cout << "Masukkan kode pelajaran : ";
    cin >> kodePel;

    pelajaran p = create_pelajaran(namaPel, kodePel);

    cout << "\nData Pelajaran:\n";
    tampil_pelajaran(p);

    return 0;
}