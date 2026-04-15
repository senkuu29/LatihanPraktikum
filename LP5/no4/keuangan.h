// nama : deden ahmad jamil
// nim : 2501518

#ifndef KEUANGAN_H
#define KEUANGAN_H

// struct keuangan
typedef struct Node {
    char tipe[20];
    char deskripsi[100];
    long jumlah;
    struct Node* next;
    struct Node* prev;
} Node;

// Deklarasi Prosedur 
Node* createNode(char tipe[], char deskripsi[], long jumlah);

void tambahAwal(Node** head, Node** tail, char tipe[], char deskripsi[], long jumlah);
void tambahAkhir(Node** head, Node** tail, char tipe[], char deskripsi[], long jumlah);

void tambahSesudah(Node** head, Node** tail, char targetDes[], char tipe[], char deskripsi[], long jumlah);
void tambahSebelum(Node** head, Node** tail, char targetDes[], char tipe[], char deskripsi[], long jumlah);

void tampilkanLog(Node* head);
long hitungSaldo(Node* head);

#endif