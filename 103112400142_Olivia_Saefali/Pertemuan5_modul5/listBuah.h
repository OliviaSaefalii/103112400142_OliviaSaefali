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