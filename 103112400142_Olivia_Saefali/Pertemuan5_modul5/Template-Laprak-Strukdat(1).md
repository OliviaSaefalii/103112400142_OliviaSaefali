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

file "listBuah.h"
```C++
#ifndef LISTBUAH_H
#define LISTBUAH_H
#define Nil NULL
#include <iostream>
using namespace std;

struct buah{
    string nama;
    int jumlah;
    float harga;
};

typedef buah dataBuah;
typedef struct node *address; // men

struct node{
    dataBuah isiData;
    address next;
};
struct linkedList{ //linked list
   address first;
};

bool isEmpty(linkedList List);
void createList(linkedList &List);
address alokasi(string nama, int jumlah, float harga);
void dealokasi(address &node);
void printList(linkedList List);
void insertFirst(linkedList &List, address nodeBaru);
void insertAfter(linkedList &List, address nodeBaru, address prev);
void insertLast(linkedList &List, address nodeBaru);
void deFirst(linkedList &List);
void deLast(linkedList &List);
void deAfter(linkedList &List, address nodeHapus, address nodeprev);
int nbList (linkedList List);
void deleteList(linkedList &List);

void updateFirst(linkedList List);
void updateLast(linkedList List);
void updateAfter(linkedList List, address prev);

#endif

```
file "listBuah.cpp"
```C++
#include <iostream>
using namespace std;

//definisi node
struct Node{//memiliki 2 bagian yaitu data dan pointer
    int data;
    Node* next; //pointer ke node berikutnya
};

//fungsi untuk melakukan pencarian secara binary
Node* binarySearch(Node* head, int key) { //Node* ini pointer (kembalian) // head ini pointer ke node pertama //key ini data yang dicari
    int size = 0; //var size disi 0
    for (Node* current = head; current;current = current->next)size++; //current adalah pointer yan digunakan untuk menyusuri linked linked list
    Node *start = head; //start adalah pointer yang menunjuk ke node pertama
    Node *end = nullptr; //end adalah pointer yang menunjuk ke node terakhir (null karena linked list tidak memiliki pointer ke node terakhir yang pasti)

    while(size > 0) { //selama masih ada elemen > 0
        int mid = size / 2; //bagi size jadi 2
        Node* midNode = start; //midNode adalah pointer yang menunjuk ke node tengah
        for (int i = 0 ; i< mid;i++)midNode = midNode->next; //pindah ke node tengah

        if(midNode->data == key)return midNode; //jika ditemukan data yang cocok, kembalikan node
        if(midNode->data < key) { //jika data midNode lebih kecil dari key, kita cari dibagian kanan
            start = midNode->next; //Mulai pencarian dari node setelah midNode
        }
        else { //jika data midNode lebih besar dari key, kita cari dibagian kiri
            end = midNode; //Akhiri pencarian di midNode
        }
        size -= mid; //kita mengurangi size dengan mid
    }
    return nullptr; //jika key tidak ditemukan
}

//prosedur untuk menambah node
void append(Node*& head, int value) { // Node* ini pointer (kembalian) //fs linear search
    Node* newNode = new Node{value, nullptr}; //new node adalag pointer yang meunjuk ke node baru yang dibuat. // value == null karena node baru berada oaling akhir
    if (!head)head = newNode; // jika head null, head diisi node baru
    else {
        Node* temp = head; //mulai dari head
        while (temp->next)temp = temp->next; //pindah ke node berikutnya sampai node terakhir
        temp->next = newNode; // node terakhir dihubungkan ke node baru
    }
}

int main() {
    Node* head = nullptr; // inisiasi head list masih kosong
    append(head, 10);
    append(head, 20); 
    append(head, 30);
    append(head, 40);
    append(head, 50); //menambah node

    //mencari data 40  menggunakan binarysearch
    Node* result = binarySearch(head, 40); //result ini pointer untuk mencari data 40
    cout << (result? "found": "not found") << endl; // condition ? value_if_true : value_if_false
    return 0;
}
```
file "main.cpp"
```C++
#include "listBuah.h"
#include <iostream>
using namespace std;

int main(){
    linkedList List;
    address nodeA, nodeB, nodeC, nodeD, nodeE = Nil;
    createList(List);

    dataBuah dtBuah;

    nodeA = alokasi("jeruk" , 100, 3000);
    nodeB = alokasi("apel", 75, 4000);
    nodeC = alokasi("pir" , 87, 5000 );
    nodeD = alokasi("semangka", 43, 11500);
    nodeE = alokasi("durian", 15, 31450);

    insertFirst(List, nodeA);
    insertLast(List, nodeB);
    insertAfter(List, nodeC, nodeA);
    insertAfter(List, nodeD, nodeC);
    insertLast(List, nodeE);
    cout << "isi lost detelah dilakukan insert" << endl;
    printList(List);
    cout << " Jumlah node : " << nbList(List) << endl;
    cout << endl;

    updateFirst(List);
    updateLast(List);
    updateAfter(List, nodeD);

    cout << "isi list setelah dlakukan update " << endl;
    printList(List);
    cout << "jumlah node : " << endl;
    cout << endl;
    

    return 0;
}
```
Program ini menunjukkan cara kerja linked list untuk menyimpan dan mengelola data buah secara dinamis. Data dimasukkan, diperbarui, dan ditampilkan menggunakan fungsi insert, update, dan print, sehingga terlihat perubahan isi list dan jumlah node sebelum serta sesudah update.


### Soal Guided 2

file "linear.cpp"
```C++
#include <iostream>
using namespace std;

//definisi node
struct Node{//memiliki 2 bagian yaitu data dan pointer
    int data;
    Node* next; //pointer ke node berikutnya
};

//fungsi untuk melakukan pencarian secara linear
Node* linearSearch(Node* head, int key) {//head adalah pointer ke node pertama, key adalah nilai yang dicari
    Node* current = head; //mulai dari node pertama
    while (current != nullptr) { //selama current tidak null
        if (current->data == key)//jika data pada node saat ini sama dengan key
        return current; //kembalikan pointer ke node yang ditemukan
        current = current->next; //pindah ke node berikutnya
    }
    return nullptr; //jika tidak ditemukan, kembalikan null
}

//prosedur untuk menambah node
void append(Node*& head, int value) { // Node* ini pointer (kembalian) //fs linear search
    Node* newNode = new Node{value, nullptr}; //new node adalag pointer yang meunjuk ke node baru yang dibuat. // value == null karena node baru berada oaling akhir
    if (!head)head = newNode; // jika head null, head diisi node baru
    else {
        Node* temp = head; //mulai dari head
        while (temp->next)temp = temp->next; //pindah ke node berikutnya sampai node terakhir
        temp->next = newNode;
    }
}

int main() {
    Node* head = nullptr; // inisiasi head list masih kosong
    append(head, 10);
    append(head, 20); 
    append(head, 30); //menambah node

    Node* result = linearSearch(head, 20); //result ini pointer untuk mencari data 20
    cout << (result? "found": "not found") << endl; // condition ? value_if_true : value_if_false
    return 0;
}
```
Program ini mencari data dalam linked list menggunakan Linear Search. Struktur Node berisi data dan pointer next. Fungsi append() menambahkan node baru di akhir list, sedangkan linearSearch() menelusuri node dari head hingga menemukan nilai yang dicari. Dalam main(), list berisi 10, 20, dan 30, lalu program mencari angka 20 dan menampilkan “found” jika ada, atau “not found” jika tidak.


### Soal Guided 3

file "binary.cpp"
```C++
#include <iostream>
using namespace std;

//definisi node
struct Node{//memiliki 2 bagian yaitu data dan pointer
    int data;
    Node* next; //pointer ke node berikutnya
};

//fungsi untuk melakukan pencarian secara binary
Node* binarySearch(Node* head, int key) { //Node* ini pointer (kembalian) // head ini pointer ke node pertama //key ini data yang dicari
    int size = 0; //var size disi 0
    for (Node* current = head; current;current = current->next)size++; //current adalah pointer yan digunakan untuk menyusuri linked linked list
    Node *start = head; //start adalah pointer yang menunjuk ke node pertama
    Node *end = nullptr; //end adalah pointer yang menunjuk ke node terakhir (null karena linked list tidak memiliki pointer ke node terakhir yang pasti)

    while(size > 0) { //selama masih ada elemen > 0
        int mid = size / 2; //bagi size jadi 2
        Node* midNode = start; //midNode adalah pointer yang menunjuk ke node tengah
        for (int i = 0 ; i< mid;i++)midNode = midNode->next; //pindah ke node tengah

        if(midNode->data == key)return midNode; //jika ditemukan data yang cocok, kembalikan node
        if(midNode->data < key) { //jika data midNode lebih kecil dari key, kita cari dibagian kanan
            start = midNode->next; //Mulai pencarian dari node setelah midNode
        }
        else { //jika data midNode lebih besar dari key, kita cari dibagian kiri
            end = midNode; //Akhiri pencarian di midNode
        }
        size -= mid; //kita mengurangi size dengan mid
    }
    return nullptr; //jika key tidak ditemukan
}

//prosedur untuk menambah node
void append(Node*& head, int value) { // Node* ini pointer (kembalian) //fs linear search
    Node* newNode = new Node{value, nullptr}; //new node adalag pointer yang meunjuk ke node baru yang dibuat. // value == null karena node baru berada oaling akhir
    if (!head)head = newNode; // jika head null, head diisi node baru
    else {
        Node* temp = head; //mulai dari head
        while (temp->next)temp = temp->next; //pindah ke node berikutnya sampai node terakhir
        temp->next = newNode; // node terakhir dihubungkan ke node baru
    }
}

int main() {
    Node* head = nullptr; // inisiasi head list masih kosong
    append(head, 10);
    append(head, 20); 
    append(head, 30);
    append(head, 40);
    append(head, 50); //menambah node

    //mencari data 40  menggunakan binarysearch
    Node* result = binarySearch(head, 40); //result ini pointer untuk mencari data 40
    cout << (result? "found": "not found") << endl; // condition ? value_if_true : value_if_false
    return 0;
}
```
Program ini mencari data dalam linked list menggunakan Binary Search. Fungsi append() menambah node di akhir list, sedangkan binarySearch()menghitung jumlah elemen lalu mencari nilai tengah untuk dibandingkan dengan data yang dicari. Jika cocok, node dikembalikan; jika tidak, pencarian dilanjutkan ke kiri atau kanan hingga selesai. Dalam main(), program membuat list berisi 10–50 dan mencari angka 40, lalu menampilkan “found” atau “not found”.


## Unguided 

### 1. soal satu
Implementasikan program C++ yang menggunakan algoritma Binary Search pada Linked List untuk mencari elemen tertentu. Program harus mampu:

1.Membuat linked list dengan menambahkan node di akhir
2.Mengimplementasikan binary search pada linked list
3.Menampilkan detail proses pencarian dan hasil akhir Petunjuk Tugas 1: • Gunakan struktur Node dengan data integer dan pointer next • Implementasikan fungsi append() untuk menambah node • Implementasikan fungsi binarySearch() yang mengembalikan pointer ke node yang ditemukan • Data dalam linked list harus terurut (ascending) untuk binary search bekerja dengan benar • Tampilkan langkah-langkah pencarian dan posisi tengah setiap iterasi • Program utama harus membuat linked list dengan minimal 5 elemen dan melakukan pencarian.

file "satu.cpp"
```C++
#include <iostream>
using namespace std;

// Definisi node
struct Node {
    int data;
    Node* next; // pointer ke node berikutnya
};

// Fungsi untuk menampilkan linked list
void displayList(Node* head) {
    if (!head) {
        cout << "Linked list kosong\n";
        return;
    }
    
    cout << "Linked List yang dibuat: ";
    Node* temp = head;
    while (temp) {
        cout << temp->data;
        if (temp->next) cout << " -> ";
        temp = temp->next;
    }
    cout << " -> NULL\n";
}

// Implementasi Binary Search pada Linked List
Node* binarySearch(Node* head, int key) {
    cout << "\nProses Pencarian:\n";
    
    // Hitung ukuran linked list
    int size = 0;
    for (Node* current = head; current; current = current->next)
        size++;
    
    Node* start = head;
    int iteration = 1;
    
    while (size > 0) {
        int mid = size / 2;
        Node* midNode = start;
        
        // Pindah ke node tengah
        for (int i = 0; i < mid; i++)
            midNode = midNode->next;
        
        // Jika ketemu
        if (midNode->data == key) {
            cout << "Iterasi " << iteration << ": Mid = " << midNode->data 
                 << " (indeks tengah) - DITEMUKAN!\n";
            return midNode;
        }
        
        // Jika mid lebih kecil dari key → cari di kanan
        if (midNode->data < key) {
            cout << "Iterasi " << iteration << ": Mid = " << midNode->data 
                 << " (indeks tengah) -> Cari di bagian kanan\n";
            
            int newSize = size - mid - 1;
            if (newSize == 1) {
                Node* lastNode = midNode->next;
                if (lastNode && lastNode->data == key) return lastNode;
                cout << "Tidak ada elemen tersisa\n";
                return nullptr;
            }
            start = midNode->next;
            size = newSize;
        }
        // Jika mid lebih besar dari key → cari di kiri
        else {
            cout << "Iterasi " << iteration << ": Mid = " << midNode->data 
                 << " (indeks tengah) -> Cari di bagian kiri\n";
            
            if (mid == 1) {
                if (start->data == key) return start;
                cout << "Tidak ada elemen tersisa\n";
                return nullptr;
            }
            size = mid;
        }
        iteration++;
    }
    
    cout << "Tidak ada elemen tersisa\n";
    return nullptr;
}

// Tambah node di akhir
void append(Node*& head, int value) {
    Node* newNode = new Node{value, nullptr};
    if (!head) head = newNode;
    else {
        Node* temp = head;
        while (temp->next) temp = temp->next;
        temp->next = newNode;
    }
}

// Hapus semua node (bebaskan memori)
void deleteList(Node*& head) {
    while (head) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

// Main program
int main() {
    Node* head = nullptr;
    int searchKey;
    
    cout << "BINARY SEARCH PADA LINKED LIST\n";
    
    // Membuat linked list
    append(head, 10);
    append(head, 20);
    append(head, 30);
    append(head, 40);
    append(head, 50);
    append(head, 60);
    
    // Tampilkan list
    displayList(head);
    
    // 🔹 Pencarian pertama
    searchKey = 40;
    cout << "Mencari nilai: " << searchKey << "\n";
    
    Node* result = binarySearch(head, searchKey);
    
    if (result) {
        cout << "\nHasil: Nilai " << result->data << " DITEMUKAN pada linked list!\n";
        cout << "Alamat node: " << result << "\n";
        cout << "Data node: " << result->data << "\n";
        if (result->next)
            cout << "Node berikutnya: " << result->next->data << "\n";
        else
            cout << "Node berikutnya: NULL\n";
    } else {
        cout << "\nHasil: Nilai " << searchKey << " TIDAK DITEMUKAN dalam linked list!\n";
    }
    
    // 🔹 Pencarian kedua
    searchKey = 25;
    cout << "Mencari nilai: " << searchKey << "\n";
    
    result = binarySearch(head, searchKey);
    
    if (result) {
        cout << "\nHasil: Nilai " << result->data << " DITEMUKAN pada linked list!\n";
        cout << "Alamat node: " << result << "\n";
        cout << "Data node: " << result->data << "\n";
        if (result->next)
            cout << "Node berikutnya: " << result->next->data << "\n";
        else
            cout << "Node berikutnya: NULL\n";
    } else {
        cout << "\nHasil: Nilai " << searchKey << " TIDAK DITEMUKAN dalam linked list!\n";
    }
    
    deleteList(head);
    return 0;
}

```
### Output Unguided 1 :

##### Output 1
![Screenshot Output Unguided 1_1](https://github.com/OliviaSaefalii/103112400142_Olivia-Saefali/blob/main/Pertemuan5_modul5/unguided/Outputsatu.cpp.png)


Program ini mencari data dalam linked list menggunakan binary search.
Fungsi append() menambah node baru, displayList() menampilkan isi list, dan binarySearch() mencari nilai dengan membagi list menjadi dua bagian secara berulang.
Jika nilai ditemukan, program menampilkan “DITEMUKAN”; jika tidak, “TIDAK DITEMUKAN.”

### soal dua
Implementasikan program C++ yang menggunakan algoritma Linear Search pada Linked List untuk mencari elemen tertentu. Program harus mampu:
1.Membuat linked list dengan menambahkan node di akhir
2.Mengimplementasikan linear search pada linked list
3.Menampilkan detail proses pencarian dan hasil akhir Petunjuk Tugas 2: • Gunakan struktur Node dengan data integer dan pointer next • Implementasikan fungsi append() untuk menambah node • Implementasikan fungsi linearSearch() yang mengembalikan pointer ke node yang ditemukan • Data dalam linked list tidak perlu terurut untuk linear search • Tampilkan setiap langkah pencarian dan node yang sedang diperiksa • Program utama harus membuat linked list dengan minimal 3 elemen dan melakukan pencarian

file "dua.cpp"
```C++
#include <iostream>
using namespace std;


struct Node {
    int data;
    Node* next;
};


void append(Node*& head, int value) {
    Node* newNode = new Node{value, nullptr};
    if (!head) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next)
            temp = temp->next;
        temp->next = newNode;
    }
}


Node* linearSearch(Node* head, int key) {
    Node* current = head;
    int posisi = 1;

    cout << "\nProses Pencarian:\n";

    while (current != nullptr) {
        cout << "Memeriksa node " << posisi << ": " << current->data;
        if (current->data == key) {
            cout << " (Sama) - Ditemukan!\n";
            return current;
        } else {
            cout << " (Tidak Sama)\n";
        }
        current = current->next;
        posisi++;
    }

    cout << "Tidak Ada node Lagi Yang Tersisa\n";
    return nullptr;
}

void printList(Node* head) {
    cout << "Isi Linked List: ";
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL\n";
}

int main() {
    Node* head = nullptr;

    cout << "LINEAR SEARCH PADA LINKED LIST\n";

    append(head, 10);
    append(head, 20);
    append(head, 30);
    append(head, 40);
    append(head, 50);

    printList(head);


    int cari1 = 30;
    cout << "Mencari nilai: " << cari1 << "\n";
    Node* hasil1 = linearSearch(head, cari1);

    if (hasil1) {
        cout << "\nHasil: Nilai " << cari1 << " Ditemukan Pada Linked List!\n";
        cout << "Alamat node: " << hasil1 << "\n";
        cout << "Data node: " << hasil1->data << "\n";
        if (hasil1->next)
            cout << "Node berikutnya: " << hasil1->next->data << "\n";
        else
            cout << "Node berikutnya: NULL\n";
    } else {
        cout << "\nHasil: Nilai " << cari1 << " Tidak Ditemukan Dalam Linked List!\n";
    }

   
    int cari2 = 25;
    cout << "\nMencari nilai: " << cari2 << "\n";
    Node* hasil2 = linearSearch(head, cari2);

    if (hasil2) {
        cout << "\nHasil: Nilai " << cari2 << " Ditemukan Pada Linked List!\n";
        cout << "Alamat node: " << hasil2 << "\n";
        cout << "Data node: " << hasil2->data << "\n";
        if (hasil2->next)
            cout << "Node berikutnya: " << hasil2->next->data << "\n";
        else
            cout << "Node berikutnya: NULL\n";
    } else {
        cout << "\nHasil: Nilai " << cari2 << " Tidak Ditemukan Dalam Linked List!\n";
    }

    return 0;
}
```
### Output Unguided 2 :

##### Output 1
![Screenshot Output Unguided 2_1](https://github.com/OliviaSaefalii/103112400142_Olivia-Saefali/blob/main/Pertemuan5_modul5/unguided/Outputdua.cpp.png)


Program ini menampilkan cara mencari data dalam linked list menggunakan Linear Search.
Fungsi append() menambah node di akhir list, printList() menampilkan isi list, dan linearSearch() menelusuri tiap node dari awal hingga menemukan nilai yang dicari.
Jika data cocok, program menampilkan “Ditemukan”; jika tidak, “Tidak Ditemukan.”


## Kesimpulan
Linked List adalah struktur data di mana tiap elemen (node) saling terhubung lewat pointer. Dua metode pencarian yang digunakan adalah Linear Search, yang menelusuri data satu per satu tanpa perlu urutan, dan Binary Search, yang lebih cepat karena membagi data menjadi dua bagian, namun hanya bisa digunakan pada data yang sudah terurut.


## Referensi
[1]Ginting, S. H. N., Effendi, H., Kumar, S., Marsisno, W., Sitanggang, Y. R. U., Anwar, K., ... & Smrti, N. N. E. (2024). Pengantar struktur data. Penerbit Mifandi Mandiri Digital, 1(01).
[2]Putra, M. Naufal Adrian Pratama. 2023. Algoritma Pemrograman: Linear Search & Binary Search. Medium, 29 Juni 2023. Diakses dari https://medium.com