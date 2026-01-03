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

file "Array"
```C++
#include <iostream>
using namespace std;

int main() {
    int arr[5];

    for (int i = 0; i < 5; i++) {
        cout << "Masukan value indeks ke-" << i << " : ";
        cin >> arr[i];
    }
    int j=0;
    while (j < 5) {
        cout << "Isi indeks ke-" << j << " : " << arr[j] << endl;
        j++;
    }
    return 0;
}
```

### Guided 2

file "array pointer"
```C++
#include<iostream>
using namespace std;

int main(){
    int arr[] = {10,20,30,40,50};
    int*ptr = arr; //pointer yang menunjuk ke elemen pertama array

    //mengakses elemen array menggunakan pointer
    for(int i = 0; i<5; ++i){
        cout << " Elemen array ke-" << i+1 << " menggunakan pointer : " << *(ptr + i) << endl;
    }

    for (int i = 0; i < 5; ++i){
        cout << "elemen array ke-" << i + 1 << " menggunakan indeks: " << arr[i] << endl;
    }

    return 0;
}
```
### Guided 3
file "fungsi prosedur"
```C++
#include <iostream>
using namespace std;

int cariMAX (int arr[], int ukuran){
    int MAX = arr[0];
    for (int i = 1; i < ukuran; i++){
        if(arr[i] > MAX){
            MAX = arr[i];
        }
    }
    return MAX;
}

void operasiAritmatika(int arr[], int ukuran){
    int totaljumlah = 0;
    for(int i = 0; i < ukuran; i ++){
        totaljumlah += arr[i];
    }
    cout << " total penjumlahan : " << totaljumlah << endl;

    int totalKali = 1;
    for(int i = 0; i < ukuran; i++){
        totalKali *= arr[i];
    }

    cout << " total perkalian : " << totalKali << endl;
}
    int main (){
    const int ukuran = 5;
    int arr[ukuran];
    for (int i = 0; i < ukuran; i++){
        cout << "masukan nilai arrray ke-" << i << " : ";
        cin >> arr[i];
    }
    cout << endl;
    cout << "nilai terbesar dalam array : " << cariMAX(arr, ukuran)<< endl;

    operasiAritmatika(arr, ukuran);
    return 0;

}

```
## Unguided 

### 1. Buatlah program yang dapat melakukan operasi penjumlahan, pengurangan, dan perkalian matriks 3x3 tersebut. Buat prosedur untuk masing-masing operasi yang dilakukan jumlahMatriks() untuk operasi penjumlahan, kurangMatriks() untuk pengurangan, dan kaliMatriks() untuk perkalian. Buat program tersebut menggunakan menu switch-case seperti berikut ini :

```C++
#include<iostream>
using namespace std;

void tampilHasil(int arr [3][3]){
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            cout << arr [i][j] << " ";
        }
        cout << endl;
    }

}

void jumlahMatriks(int arrA[3][3], int arrB[3][3], int hasil[3][3]){
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            hasil[i][j] = arrA[i][j] + arrB[i][j];
        }

    }
}
void kurangMatriks(int arrA[3][3], int arrB[3][3], int hasil[3][3]){
    for (int i = 0;i <3; i++){
        for (int j = 0; j < 3; j++){
            hasil[i][j] = arrA[i][j] - arrB[i][j];
        }
    }
}

void kaliMatriks(int arrA[3][3], int arrB[3][3], int hasil[3][3]){
    for (int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            for(int k = 0; k < 3; k++){
                hasil[i][j] += arrA[i][k] * arrB[k][j];
            }
        }
    }
}


  

int main(){
    int arrA [3][3] = {
        {7, 12, 22},
        {31, 6, 41},
        {15, 19, 36}
    };
    int arrB [3][3] = {
        {11, 34, 7},
        {3, 25, 41},
        {5, 18, 33}
    };
    int hasil[3][3] = {0};

    int pilihan;
    cout << " --- Menu Program Matriks --- " << endl;
    cout << " 1. Penjumlahan matriks " << endl;
    cout << " 2. Pengurangan matriks " << endl;
    cout << " 3. Perkalian matriks " << endl;
    cout << " 4. Keluar " << endl;
    cout << " Masukan angka : " << endl;
    cin >>  pilihan ;

    switch (pilihan){
        case 1 :
        jumlahMatriks(arrA, arrB, hasil);
        cout << "Hasil penjumlahan matriks : " << endl;
        tampilHasil(hasil);
        break;
        case 2 :
        kurangMatriks(arrA, arrB, hasil);
        cout << "Hasil pengurangan matriks : " << endl;
        tampilHasil(hasil);
        break;
        case 3 :
        kaliMatriks(arrA, arrB, hasil);
        cout << "Hasil perkalian matriks : " << endl;
        tampilHasil(hasil);
        break;
        case 4 :
        cout << "Keluar " << endl;
        break;
        default :
        cout << " pilihan salah " << endl;
    }
    


    return 0;
}

```

### Output Unguided 1 :

##### Output 1
![Screenshot Output Unguided 1_1]: (https://github.com/OliviaSaefalii/
103112400142_OliviaSaefali/blob/main/pertemuan2/outputunguided1modul2.png)

##### Output 2
![Screenshot Output Unguided 1_1]: (https://github.com/OliviaSaefalii/
103112400142_OliviaSaefali/blob/main/pertemuan2/output1Modul1.png)

Program menghitung operasi matriks 3x3 menggunakan prosedur dan menu switch-case

### 2. Buatlah program menghitung luas dan keliling persegi panjang dengan proses perhitungan dan perubahan nilainya menggunakan pointer

```C++
#include<iostream>
using namespace std;

int main(){
    int panjang = 10, lebar = 5 ;
    int *ptrPanjang, *ptrLebar;

    cout << " --- Nilai Awal --- " << endl;
    cout << " Panjang : " << panjang << endl;
    cout << " Lebar : " << lebar << endl;

    ptrPanjang = &panjang;
    ptrLebar = &lebar;

    int luas = (*ptrPanjang) * (*ptrLebar);
    int keliling = 2 * (*ptrPanjang + *ptrLebar);

    cout << " --- Hasil Perhitungan --- " << endl;
    cout << " Luas Persegi Panjang : " << luas << endl;
    cout << " Keliling Persegi Panjang : " << keliling << endl;

    *ptrPanjang = 12;
    *ptrLebar = 6;

   luas = (*ptrPanjang) * (*ptrLebar);
   keliling = 2 * (*ptrPanjang + *ptrLebar);

   cout << " --- Nilai Setelah Diubah Melalui Pointer --- " << endl;
   cout << " Panjang Baru : " << *ptrPanjang << endl;
   cout << " Lebar Baru : " << *ptrLebar << endl;
   cout << " Luas  Baru : " << luas << endl;
   cout << " Keliling Baru : " << keliling << endl;
    


    return 0;
}
```

### Output Unguided 2 :

##### Output 1
![Screenshot Output Unguided 1_1](https://github.com/OliviaSaefalii/
103112400142_OliviaSaefali/blob/main/pertemuan2/output2modul2.png)


Program menghitung luas persegi panjang menggunakan pointer dan menampilkan hasil setelah nilai diubah.


## Kesimpulan
Array digunakan untuk menyimpan kumpulan data bertipe sama secara berurutan di memori. Pointer berfungsi menyimpan alamat memori suatu variabel agar akses data lebih efisien. Prosedur digunakan untuk membagi program menjadi bagian-bagian terstruktur agar mudah dipahami.

## Referensi
[2] Deitel, P., & Deitel, H. (2017). C++ How to Program (10th ed.). Pearson Education.

