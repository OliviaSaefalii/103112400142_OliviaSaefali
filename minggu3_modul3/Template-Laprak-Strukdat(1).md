# <h1 align="center">Laporan Praktikum Modul 1 - Singly linked </h1>
<p align="center">Olivia Saefali - 103112400142</p>

## Dasar Teori
Struktur data adalah metode untuk mengorganisasi dan menyimpan data agar dapat diakses serta dikelola secara efisien. Dengan menggunakan struktur data yang tepat, algoritma yang dikembangkan menjadi lebih jelas dalam logika dan lebih efektif dalam eksekusi [1].

### A. ...<br/>
...
#### 1. ...
#### 2. ...
#### 3. ...

### B. ...<br/>
...
#### 1. ...
#### 2. ...
#### 3. ...

## Guided 

### Guided 1 

```C++
#include <iostream>
using namespace std;

struct mahasiswa{
    string nama;
    float nilai1, nilai2;

};

void inputMhs(mahasiswa &m){
    cout << " input nama : ";
    cin >> m.nama;
    cout << " input nilai 1 : ";
    cin >> m.nilai1;
    cout << " input nilai 2 : ";
    cin >> m.nilai2;

}

float rata2(mahasiswa m){
    return float(m.nilai1 + m.nilai2) / 2;

}

int main(){
    mahasiswa mhs;
    inputMhs(mhs);

    cout << "rata -rata nilai adalah : " << rata2(mhs) << endl;

    return 0;
}

```
### Guided 2

```C++
#ifndef MAHASISWA_H
#define MAHASISWA_H
struct mahasiswa
{
  char nim[10];
  int nilai1, nilai2;
    /* data */
};

void inputMhs(mahasiswa &m);
float rata2(mahasiswa m);

#endif
```
```C++
#include <iostream>
#include "mahasiswa.h"
using namespace std;

void inputMhs(mahasiswa &m){
    cout << " input nim : ";
    cin >> m.nim;
    cout << " input nilai 1 : ";
    cin >> m.nilai1;
    cout << " input nilai 2 : ";
    cin >> m.nilai2;

}

float rata2(mahasiswa m){
    return (float)(m.nilai1 + m.nilai2) / 2;
}

```

```C++
#include <iostream>
#include "mahasiswa.h"
#include <cstdlib>
using namespace std;

int main(){
    mahasiswa mhs;
    inputMhs(mhs);

    cout << "rata -rata nilai adalah : " << rata2 
    (mhs) << endl;
    system("pause");
    return 0;
}
```



## Unguided 

### 1. Buat program yang dapat menyimpan data mahasiswa maksimal 10 ke dalam sebuah array dengan field nama, nim, uts, uas, tugas dan nilai akhir. nilai akhir yang diperoleh dengan rumus 0.3uts + 0.4uas + 0.3*tugas.

```C++
#include <iostream>
using namespace std;

float hitungNilaiAkhir(float uts, float uas, float tugas) {
    return 0.3 * uts + 0.4 * uas + 0.3 * tugas;
}

int main() {
    string nama, nim;
    float uts, uas, tugas;
    int n;

    cout << "Jumlah mahasiswa (maks 10): ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cout << "\nNama: "; cin >> nama;
        cout << "NIM : "; cin >> nim;
        cout << "UTS : "; cin >> uts;
        cout << "UAS : "; cin >> uas;
        cout << "Tugas: "; cin >> tugas;

        cout << "Nilai Akhir: " << hitungNilaiAkhir(uts, uas, tugas) << endl;
    }
}
```

##### Output 1
![Screenshot Output Unguided 1_1](https://github.com/OliviaSaefalii/103112400142_OliviaSaefali/blob/main/Minggu3_Modul3/unguided1modul3.png)

Program ini menghitung nilai akhir maksimal 10 mahasiswa berdasarkan nilai UTS, UAS, dan tugas. Data disimpan dalam struct mahasiswa, sedangkan perhitungan nilai akhir dilakukan menggunakan fungsi hitungNilai.

### 2. 

file "pelajaran.h"
```C++
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
```
file "pelajaran.cpp"
```C++
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
```
file "main.cpp"
```C++
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

```

### Output Unguided 2 :

##### Output 1
![Screenshot Output Unguided 1_1](https://github.com/OliviaSaefalii/103112400142_OliviaSaefali/blob/main/Minggu3_Modul3/unguided2modul3.png)

Program ini digunakan untuk membuat dan menampilkan data pelajaran yang berisi nama pelajaran dan kode pelajaran, menggunakan file header (.h), file implementasi (.cpp), dan file utama (main.cpp)

### 3. 
```C++
#include<iostream>
using namespace std;

void showArray(int arr[3][3]){
    for(int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            cout << arr[i][j] << " ";

        }
        cout << endl;
    }
}

void changeNilai(int arr1[3][3], int arr2[3][3], int nilai1, int nilai2){
    int *x1  = nullptr;
    int *x2 = nullptr;
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            if(arr1[i][j] == nilai1){
                x1 = &arr1[i][j];
            }
        }
    } 

    for(int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            if(arr2[i][j] == nilai2){
                x2 = &arr2[i][j];
            }
        }
    }

    if (x1 != nullptr && x2 != nullptr){
        int temp = *x1;
        *x1 = *x2;
        *x2 = temp;
    }else{
        cout << "Nilai Tidak Ditemukan!" << endl;
    }
}

int main(){
    int arr1[3][3] = {
        {1,2,3},
        {4,5,6},
        {7,8,9}
    
    };
    int arr2[3][3] = {
        {9,8,7},
        {6,5,4},
        {3,2,1}
    };

    cout << "Array A : " << endl;
    showArray(arr1);
    cout << "Array B : " << endl;
    showArray(arr2);

    int nilai1, nilai2;
    cout << "Masukan Nilai Dari Array A : ";
    cin >> nilai1;
    cout << "Masukan Nilai Dari Array B : ";
    cin >> nilai2;
    changeNilai(arr1, arr2, nilai1, nilai2);
    cout << "Array A Setelah Ditukar : " << endl;
    showArray(arr1);
    cout << "Array B Setelah Ditukar : " << endl;
    showArray(arr2);

    return 0;
}
```
### Output Unguided 3 :

##### Output 1
![Screenshot Output Unguided 1_1](https://github.com/OliviaSaefalii/103112400142_OliviaSaefali/blob/main/Minggu3_Modul3/unguided3modul3.png)

penjelasan unguided 3

## Kesimpulan
ADT memisahkan definisi perilaku tipe data dari implementasinya, memungkinkan pembuatan program yang terstruktur, efisien, dan mudah dikembangkan. Penggunaan struct untuk tipe data, pointer untuk struktur dinamis seperti linked list, serta pemrograman modular meningkatkan keterbacaan dan pemeliharaan kode. Praktikum ini menekankan penerapan ADT untuk program yang rapi, fleksibel, dan mudah dikelola.

## Referensi
[1] Kadir, Abdul. Algoritma dan Pemrograman Menggunakan C++. Yogyakarta: Andi, 2020.