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

### Soal Guided 1 

file "list.h"
```C++
#ifndef LIST_H
#define LIST_H
#define Nil NULL

#include<iostream>
using namespace std;
struct mahasiswa{
    string nama; 
    string nim;
    int umur;
};
typedef mahasiswa dataMahasiswa;
typedef struct node *address;
struct node{ 
    dataMahasiswa isidata;
    address next;
};
struct linkedlist{ 
    address first;
};
bool isEmpty(linkedlist List);
void createList(linkedlist &List);
address alokasi(string nama, string nim, int umur);
void dealokasi(address &node);
void printList(linkedlist List);
void insertFirst(linkedlist &List, address nodeBaru);
void insertAfter(linkedlist &List, address nodeBaru, address Prev);
void insertLast(linkedlist &List, address nodeBaru);

#endif
```
file "list.cpp"
```C++
#include "list.h"
#include <iostream>
using namespace std;
bool isEmpty(linkedlist List) {
    if(List.first == Nil){
        return true; 
    } else {
        return false;
    }
}
void createList(linkedlist &List) {
    List.first = Nil;
}
address alokasi(string nama, string nim, int umur) { 
    address nodeBaru = new node; 
    nodeBaru->isidata.nama = nama;
    nodeBaru->isidata.nim = nim; 
    nodeBaru->isidata.umur = umur;
    nodeBaru->next = Nil;
    return nodeBaru;
}
void dealokasi(address &node) {
    node->next = Nil;
    delete node;
}
void insertFirst(linkedlist &List, address nodeBaru) {
    nodeBaru->next = List.first; 
    List.first = nodeBaru;
}
void insertAfter(linkedlist &List, address nodeBaru, address Prev) {
    if (Prev != Nil) {
        nodeBaru->next = Prev->next;
        Prev->next = nodeBaru;
    } else {
        cout << "Node sebelumnya tidak valid!" << endl;
    }
}
void insertLast(linkedlist &List, address nodeBaru) {
    if (isEmpty(List) == true) {
        List.first = nodeBaru;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu->next != Nil) {
            nodeBantu = nodeBantu->next;
        }
        nodeBantu->next = nodeBaru;
    }
}
void printList(linkedlist List) {
    if (isEmpty(List) == true) {
        cout << "List kosong." << endl;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu != Nil) { 
            cout << "Nama : " << nodeBantu->isidata.nama << ", NIM : " << nodeBantu->isidata.nim 
            << ", Usia : " << nodeBantu->isidata.umur << endl;
            nodeBantu = nodeBantu->next;
        }
    }
}
```
file "main.cpp"
```C++
#include "list.h"
#include<iostream>
using namespace std;

int main(){
    linkedlist List;
    address nodeA, nodeB, nodeC, nodeD, nodeE = Nil;
    createList(List);

    dataMahasiswa mhs;

    nodeA = alokasi("Dhimas", "2311102151", 20);
    nodeB = alokasi("Arvin", "2211110014", 21);
    nodeC = alokasi("Rizal", "2311110029", 20);
    nodeD = alokasi("Satrio", "2211102173", 21);
    nodeE = alokasi("Joshua", "2311102133", 21);

    insertFirst(List, nodeA);
    insertLast(List, nodeB);
    insertAfter(List, nodeC, nodeA);
    insertAfter(List, nodeD, nodeC);
    insertLast(List, nodeE);

    cout << "--- ISI LIST SETELAH DILAKUKAN INSERT ---" << endl;
    printList(List);

    return 0;
}
```
Program ini menerapkan konsep linked list untuk menyimpan data mahasiswa secara dinamis. Setiap elemen list berisi informasi mahasiswa dan penunjuk ke elemen berikutnya. Fungsi-fungsi seperti pembuatan list, penambahan data di berbagai posisi, serta pencetakan isi list digunakan untuk mengelola data. Melalui contoh lima mahasiswa, program memperlihatkan proses penyimpanan dan penelusuran data secara berantai.

### Soal Guided 2

file "list.h"
```C++
#ifndef LIST_H
#define LIST_H
#define Nil NULL

#include <iostream>
using namespace std;
struct mahasiswa{
    string nama; 
    string nim;
    int umur;
};
typedef mahasiswa dataMahasiswa;
typedef struct node *address;
struct node{ 
    dataMahasiswa isidata;
    address next;
};
struct linkedlist{ 
    address first;
};
bool isEmpty(linkedlist List);
void createList(linkedlist &List);
address alokasi(string nama, string nim, int umur);
void dealokasi(address &node);
void printList(linkedlist List);
void insertFirst(linkedlist &List, address nodeBaru);
void insertAfter(linkedlist &List, address nodeBaru, address Prev);
void insertLast(linkedlist &List, address nodeBaru);

void delFirst(linkedlist &List);
void delLast(linkedlist &List);
void delAfter(linkedlist &List, address nodeHapus, address nodePrev);
int nbList(linkedlist List);
void deleteList(linkedlist &List);

#endif
```
file "list.cpp"
```C++
#include "list.h"
#include <iostream>
using namespace std;

bool isEmpty(linkedlist List) {
    if(List.first == Nil){
        return true; 
    } else {
        return false;
    }
}

void createList(linkedlist &List) {
    List.first = Nil;
}

address alokasi(string nama, string nim, int umur) { 
    address nodeBaru = new node; 
    nodeBaru->isidata.nama = nama;
    nodeBaru->isidata.nim = nim; 
    nodeBaru->isidata.umur = umur;
    nodeBaru->next = Nil;
    return nodeBaru;
}

void dealokasi(address &node) {
    node->next = Nil;
    delete node;
}

void insertFirst(linkedlist &List, address nodeBaru) {
    nodeBaru->next = List.first; 
    List.first = nodeBaru;
}

void insertAfter(linkedlist &List, address nodeBaru, address Prev) {
    if (Prev != Nil) { 
        nodeBaru->next = Prev->next;
        Prev->next = nodeBaru;
    } else {
        cout << "Node sebelumnya tidak valid!" << endl;
    }
}

void insertLast(linkedlist &List, address nodeBaru) {
    if (isEmpty(List)) {
        List.first = nodeBaru;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu->next != Nil) {
            nodeBantu = nodeBantu->next;
        }
        nodeBantu->next = nodeBaru;
    }
}

void delFirst(linkedlist &List){
    address nodeHapus;
    if (isEmpty(List) == false) {
        nodeHapus = List.first;
        List.first = List.first->next;
        nodeHapus->next = Nil;
        dealokasi(nodeHapus);
    } else {
        cout << "List kosong!" << endl;
    }
}

void delLast(linkedlist &List){
    address nodeHapus, nodePrev;
    if(isEmpty(List) == false){
        nodeHapus = List.first;
        if(nodeHapus->next == Nil){
            List.first->next = Nil;
            dealokasi(nodeHapus);
        } else { 
            while(nodeHapus->next != Nil){
                nodePrev = nodeHapus; 
                nodeHapus = nodeHapus->next;
            }
            nodePrev->next = Nil; 
            dealokasi(nodeHapus);
        }
    } else {
        cout << "list kosong" << endl;
    }
}

void delAfter(linkedlist &List, address nodeHapus, address nodePrev){
    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else { 
        if (nodePrev != Nil && nodePrev->next != Nil) { 
            nodeHapus = nodePrev->next;       
            nodePrev->next = nodeHapus->next;  
            nodeHapus->next = Nil;         
            dealokasi(nodeHapus);
        } else {
            cout << "Node sebelumnya (prev) tidak valid!" << endl;
        }
    }
}

void printList(linkedlist List) {
    if (isEmpty(List)) {
        cout << "List kosong." << endl;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu != Nil) { 
            cout << "Nama : " << nodeBantu->isidata.nama << ", NIM : " << nodeBantu->isidata.nim << ", Usia : " << nodeBantu->isidata.umur << endl;
            nodeBantu = nodeBantu->next;
        }
    }
}

int nbList(linkedlist List) {
    int count = 0;
    address nodeBantu = List.first;
    while (nodeBantu != Nil) {
        count++;
        nodeBantu = nodeBantu->next; 
    }
    return count;
}

void deleteList(linkedlist &List){

    address nodeBantu, nodeHapus;
    nodeBantu = List.first;
    while(nodeBantu != Nil){
        nodeHapus = nodeBantu;
        nodeBantu = nodeBantu->next;
        dealokasi(nodeHapus); 
    }
    List.first = Nil; 
    cout << "List sudah terhapus!" << endl;
}
```
file "main.cpp"
```C++
#include "list.h"
#include<iostream>
using namespace std;

int main(){
    linkedlist List;
    address nodeA, nodeB, nodeC, nodeD, nodeE = Nil;
    createList(List);

    dataMahasiswa mhs;

    nodeA = alokasi("Dhimas", "2311102151", 20);
    nodeB = alokasi("Arvin", "2211110014", 21);
    nodeC = alokasi("Rizal", "2311110029", 20);
    nodeD = alokasi("Satrio", "2211102173", 21);
    nodeE = alokasi("Joshua", "2311102133", 21);

    insertFirst(List, nodeA);
    insertLast(List, nodeB);
    insertAfter(List, nodeC, nodeA);
    insertAfter(List, nodeD, nodeC);
    insertLast(List, nodeE);

    cout << "ISI LIST SETELAH DILAKUKAN INSERT" << endl;
    printList(List);
    cout << "jumlah node : " << nbList(List) << endl;
    cout << endl;

    delFirst(List);
    delLast(List);
    delAfter(List, nodeD, nodeC);

    cout << "ISI LIST SETELAH DILAKUKAN DELETE" << endl;
    printList(List);
    cout << "jumlah node : " << nbList(List) << endl;
    cout << endl;

    deleteList(List);
    cout << "ISI LIST SETELAH DILAKUKAN HAPUS LIST" << endl;
    printList(List);
    cout << "jumlah node : " << nbList(List) << endl;
    cout << endl;

    return 0;
}
```
Program ini mengimplementasikan linked list yang dapat melakukan operasi tambah dan hapus data secara dinamis. Selain menambah data di awal, tengah, dan akhir list, program juga dapat menghapus node di berbagai posisi, menghitung jumlah data, serta menghapus seluruh isi list. Melalui contoh lima data mahasiswa, program menampilkan hasil perubahan list setelah proses insert, delete, dan clear dilakukan.



## Unguided 

### 1. Buat ADT singly linked list dalam file "Singlylist.h",Kemudian buatlah implementasi dari procedure-procedure yang digunakan didalam file “Singlylist.cpp”,Kemudian buat program utama didalam file “main.cpp”.

file "singlylist.h"
```C++
#ifndef SINGLYLIST_H
#define SINGLYLIST_H

#include <iostream>
using namespace std;

typedef int infotype;
typedef struct ElmList *address;

struct ElmList {
    infotype info;
    address next;
};

struct List {
    address first;
};

void createList(List &L);
address alokasi(infotype x);
void dealokasi(address &P);
void insertFirst(List &L, address P);
void printInfo(List L);

#endif
```
file "singlylist.cpp"
```C++
#include "Singlylist.h"

void createList(List &L) {
    L.first = NULL;
}

address alokasi(infotype x) {
    address P = new ElmList;
    if (P != NULL) {
        P->info = x;
        P->next = NULL;
    }
    return P;
}

void dealokasi(address &P) {
    delete P;
    P = NULL;
}

void insertFirst(List &L, address P) {
    P->next = L.first;
    L.first = P;
}

void printInfo(List L) {
    address P = L.first;
    while (P != NULL) {
        cout << P->info << " ";
        P = P->next;
    }
    cout << endl;
}
```
file "main.cpp"
```C++
#include "Singlylist.h"

int main() {
    List L;
    address P1, P2, P3, P4, P5;

    createList(L);

    P1 = alokasi(2);
    insertFirst(L, P1);

    P2 = alokasi(0);
    insertFirst(L, P2);

    P3 = alokasi(8);
    insertFirst(L, P3);

    P4 = alokasi(12);
    insertFirst(L, P4);

    P5 = alokasi(9);
    insertFirst(L, P5);

    printInfo(L);

    return 0;
}
```
### Output Unguided 1 :

##### Output 1
![Screenshot Output Unguided 1_1](https://github.com/OliviaSaefalii/103112400142_Olivia-Saefali
/blob/main/pertemuan4_modul4/Output1-Unguided1-Modul1.png)

pProgram ini membuat singly linked list berisi data bertipe integer.
Fungsi createList() membuat list kosong, alokasi() membuat node baru, insertFirst() menambah node di awal list, dan printInfo() menampilkan semua elemen.
Pada main, lima angka dimasukkan ke list, lalu seluruh isi list ditampilkan di layar.

### 2. Dari soal Latihan pertama, lakukan penghapusan node 9 menggunakan deleteFirst(), node 2 menggunakan deleteLast(), dan node 8 menggunakan deleteAfter(). Kemudian tampilkan jumlah node yang tersimpan menggunakan nbList() dan lakukan penghapusan seluruh node menggunakan deleteList().

file "singlylist.h"
```C++
#include "list.h"
#include <iostream>
using namespace std;

int main() {
    linkedlist List;
    address node1, node2, node8, node9 = Nil;
    createList(List);

    node9 = alokasi("Node 9", "009", 21);
    node2 = alokasi("Node 2", "002", 20);
    node8 = alokasi("Node 8", "008", 22);

    insertFirst(List, node9);
    insertLast(List, node2);
    insertAfter(List, node8, node9);

    printList(List);
    cout << "Jumlah node : " << nbList(List) << endl << endl;

    delFirst(List);          
    delLast(List);           
    delAfter(List, node8, node9); 

    
    printList(List);
    cout << "Jumlah node : " << nbList(List) << endl << endl;

    
    deleteList(List);
    cout << "- List Berhasil Terhapus -" << endl;
    cout << "Jumlah node : " << nbList(List) << endl;

    return 0;
}
```
file "singlylist.cpp"
```C++
#include "singlylist.h"

void createList(List &L) {
    L.first = Nil;
}

bool isEmpty(List L) {
    return (L.first == Nil);
}

address alokasi(string nama, string nim, int umur) {
    address P = new node;
    P->info.nama = nama;
    P->info.nim = nim;
    P->info.umur = umur;
    P->next = Nil;
    return P;
}

void dealokasi(address &P) {
    delete P;
    P = Nil;
}

void insertFirst(List &L, address P) {
    P->next = L.first;
    L.first = P;
}

void insertAfter(List &L, address P, address Prec) {
    if (Prec != Nil) {
        P->next = Prec->next;
        Prec->next = P;
    }
}

void insertLast(List &L, address P) {
    if (isEmpty(L)) {
        L.first = P;
    } else {
        address Q = L.first;
        while (Q->next != Nil) {
            Q = Q->next;
        }
        Q->next = P;
    }
}

void printInfo(List L) {
    if (isEmpty(L)) {
        cout << "List kosong." << endl;
    } else {
        address P = L.first;
        while (P != Nil) {
            cout << P->info.umur << " ";
            P = P->next;
        }
        cout << endl;
    }
}

void delFirst(List &L) {
    if (!isEmpty(L)) {
        address P = L.first;
        L.first = P->next;
        dealokasi(P);
    }
}

void delLast(List &L) {
    if (!isEmpty(L)) {
        address P = L.first, Q = Nil;
        while (P->next != Nil) {
            Q = P;
            P = P->next;
        }
        if (Q == Nil) {
            L.first = Nil;
        } else {
            Q->next = Nil;
        }
        dealokasi(P);
    }
}

void delAfter(List &L, address Prec) {
    if (!isEmpty(L) && Prec != Nil && Prec->next != Nil) {
        address P = Prec->next;
        Prec->next = P->next;
        dealokasi(P);
    }
}

int nbList(List L) {
    int count = 0;
    address P = L.first;
    while (P != Nil) {
        count++;
        P = P->next;
    }
    return count;
}

void deleteList(List &L) {
    address P;
    while (L.first != Nil) {
        P = L.first;
        L.first = L.first->next;
        dealokasi(P);
    }
    cout << "- List Berhasil Terhapus -" << endl;
}
```
file "main.cpp"
```C++
#include "singlylist.h"
#include <iostream>
using namespace std;

int main() {
    List L;
    address P1, P2, P3;
    createList(L);

   
    P1 = alokasi("A", "001", 9);
    P2 = alokasi("B", "002", 8);
    P3 = alokasi("C", "003", 2);

    
    insertFirst(L, P1); 
    insertLast(L, P2);   
    insertLast(L, P3);   

    printInfo(L);
    cout << "Jumlah node : " << nbList(L) << endl;

    
    delFirst(L);          
    delLast(L);           
    delAfter(L, L.first);

    printInfo(L);
    cout << "Jumlah node : " << nbList(L) << endl;

    
    deleteList(L);
    cout << "Jumlah node : " << nbList(L) << endl;

    return 0;
}
```

### Output Unguided 2 :

##### Output 1
![Screenshot Output Unguided 2_1](https://github.com/OliviaSaefalii/103112400142_Olivia-Saefali
/blob/main/pertemuan4_modul4/Output-Unguided2-modul1.png)

rogram ini menunjukkan cara menghapus node pada singly linked list.
Fungsi delFirst() hapus node pertama, delLast() hapus node terakhir, delAfter() hapus node setelah node tertentu, nbList() hitung jumlah node, dan deleteList() hapus semua node.
Program menambah beberapa node, lalu menghapusnya satu per satu sesuai instruksi hingga list kosong.



## Kesimpulan
singly linked list memungkinkan penyimpanan dan pengelolaan data secara dinamis tanpa batasan ukuran tetap seperti array.
Melalui operasi insert dan delete, data dapat ditambahkan atau dihapus di berbagai posisi dalam list dengan efisien.
Struktur ini memudahkan pengaturan data secara fleksibel dan menjadi dasar penting dalam pengembangan algoritma dan struktur data lanjutan.

## Referensi
[1] A. Rahman, “Analisis dan Implementasi Struktur Data Linked List pada Bahasa C++,” *Jurnal Ilmiah Komputer dan Informatika (KOMPUTA)*, vol. 9, no. 1, pp. 10–15, 2021.  
[2] S. Widianto, “Implementasi Struktur Data Linked List untuk Pengelolaan Data Dinamis,” *Jurnal Teknologi Informasi dan Komputer (Teknika)*, vol. 7, no. 2, pp. 45–52, 2020.

