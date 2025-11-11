# <h1 align="center">Laporan Praktikum Modul 1 - Singly linked </h1>
<p align="center">Olivia Saefali - 103112400142</p>

## Dasar Teori
Algoritma adalah langkah-langkah sistematis yang digunakan untuk memecahkan suatu permasalahan. Dalam pemrograman, algoritma berfungsi sebagai urutan instruksi yang akan dijalankan oleh komputer untuk mencapai hasil tertentu. Bahasa pemrograman seperti C++ digunakan untuk menerjemahkan algoritma tersebut ke dalam bentuk yang dapat dimengerti oleh komputer.[1].

### Operator Aritmatika <br/>
Operator aritmatika adalah operator dasar untuk melakukan operasi matematika seperti penjumlahan, pengurangan, perkalian, dan pembagian. Dalam C++, operator ini digunakan untuk memproses data numerik.

### Logika Pemrograman <br/>
Logika pemrograman adalah kemampuan untuk menyusun alur berpikir yang terstruktur dan sistematis agar komputer dapat menjalankan instruksi sesuai tujuan

## unguided 

### unguided 1 

```C++
#include <iostream>
using namespace std;

int main(){
    float x, y;
    cout << "Masukan bilangan pertama : ";
    cin >> x;
    cout << "Masukan bilangan kedua : ";
    cin >> y;

    cout << "Penjumlahan : ";
    cout  << x + y << endl;
    cout << "Pengurangan : " ;
    cout << x - y << endl;
    cout << "Perkalian : ";
    cout  << x * y << endl;
    cout << "Pembagian : ";
    cout << x / y << endl;
    return 0;
}
```
### Output Unguided 2 :

##### Output 1
![Screenshot Output Unguided 2_1](https://github.com/OliviaSaefalii/103112400142_Olivia-Saefali/blob/main/Pertemuan1_modul1/output1.png)

Program ini menghitung empat operasi aritmatika dasar (tambah, kurang, kali, bagi) dari dua bilangan yang dimasukkan pengguna dan menampilkan hasilnya ke layar.

### Unguided 2

```C++
#include <iostream>
using namespace std;


string ratus [] = {"", "seratus", "dua ratus", "tiga ratus", "empat ratus", "lima ratus", "enam ratus", "tujuh ratus", "delapan ratus", "sembilan ratus"};
string puluh [] = {"", "sepuluh", "dua puluh", "tiga puluh", "empat puluh", "lima puluh", "enam puluh", "tujuh puluh", "delapan puluh", "sembilan puluh"};
string satuan [] = {"", "satu", "dua", "tiga", "empat", "lima", "enam", "tujuh", "delapan", "sembilan"};
string belasan [] = {"sepuluh", "sebelas", "dua belas", "tiga belas", "empat belas", "lima belas", "enam belas", "tujuh belas", "delapan belas", "sembilan belas"};

int main(){
    int angka;
    cout << "Masukan angka : ";
    cin >> angka;

    if(angka < 1 || angka > 999){
        cout << "Angka diluar jangkauan" << endl;
        return 0;
    }

    if(angka / 100 > 0){
        cout << ratus[angka /100 ] << " ";
    }

    if( (angka %100)/10 == 1){
        cout << belasan[(angka %100)/10] << " ";
    } else {
        if((angka %100)/10 > 1){
            cout << puluh[(angka %100)/10] << " ";
        }
        if(angka % 10 > 0){
            cout << satuan[angka % 10] << " ";
        }
    }

    cout << endl;
}
```
##### Output 1
![Screenshot Output Unguided 2_1](https://github.com/OliviaSaefalii/103112400142_Olivia-Saefali/blob/main/Pertemuan1_modul1/output2.png)

Program ini mengonversi angka 1–999 menjadi bentuk tulisan dalam bahasa Indonesia menggunakan array kata untuk satuan, puluhan, belasan, dan ratusan, lalu menampilkannya sebagai output.



## Unguided 3

```C++
#include <iostream>
using namespace std;

int main(){
    int x;
    cout << "Masukan angka : ";
    cin >> x;

    for(int i = x; i >= 1; i--){
        for(int k = 0; k < x - i;k++){
            cout << " ";
        }
        for(int j = i; j >= 1; j--){
           cout << j;
        }
        cout << "*";


        for(int j = 1; j <= i; j++){
            cout << j;
        }
        cout << endl;

    }
    for (int sp = 0 ; sp < x; sp++){
        cout << " ";
    }
    cout << "*" << endl;
    return 0;

}

```
##### Output 1
![Screenshot Output Unguided 2_1](https://github.com/OliviaSaefalii/103112400142_Olivia-Saefali/blob/main/Pertemuan1_modul1/output3.png)

membahas tentang perulangan

## Kesimpulan
Ketiga program menerapkan konsep dasar C++ seperti input-output, percabangan, perulangan, dan operator untuk menyelesaikan masalah secara terstruktur.

## Referensi
[1] Dony Ariyus, Algoritma dan Pemrograman Menggunakan C++, Yogyakarta: Andi, 2019.
[2] Bjarne Stroustrup, The C++ Programming Language, 4th Edition, Addison-Wesley, 2013.
[3] Wahana Komputer, Belajar Dasar Pemrograman C++, Yogyakarta: Andi, 2020.
