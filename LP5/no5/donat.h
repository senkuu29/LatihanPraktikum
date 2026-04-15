// nama : deden ahmad jamil
// nim : 2501518

#ifndef DONAT_H
#define DONAT_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// tructnya
typedef struct Node {
    char nama[50];
    int jumlah;
    int total;
    struct Node *next;
    struct Node *prev;
} Node;

// Deklarasi Prosedur
Node* createNode(char nama[], int jumlah);
void tambahAkhir(Node** head, Node** tail, char nama[], int jumlah);
void tampilkanDaftar(Node* head);
void cariNama(Node* head, char nama[]);
void sedangDilayani(Node* head);
void editData(Node* head, char nama[], int jumlahBaru);
void hapusAwal(Node** head, Node** tail);
void hapusAkhir(Node** head, Node** tail);
void hapusNama(Node** head, Node** tail, char nama[]);

#endif