// nama : deden ahmad jamil
// nim : 2501518

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "keuangan.h"

// Membuat node baru
Node* createNode(char tipe[], char deskripsi[], long jumlah) {
    // pesan node
    Node* newNode = (Node*)malloc(sizeof(Node));

    // kalo node ga kosong
    if (newNode != NULL) {
        // input datanya
        strcpy(newNode->tipe, tipe);
        strcpy(newNode->deskripsi, deskripsi);
        newNode->jumlah = jumlah;

        newNode->next = NULL;
        newNode->prev = NULL;
    }
    return newNode;
}

// Tambah di awal list
void tambahAwal(Node** head, Node** tail, char tipe[], char deskripsi[], long jumlah) {
    Node* newNode = createNode(tipe, deskripsi, jumlah);
    // Kalau list kosong, node baru jadi head sekaligus tail
    if (*head == NULL) {
        *head = *tail = newNode;
    } else {
        // Sambungkan node baru ke depan head yang lama
        newNode->next = *head;
        (*head)->prev = newNode; // Hubungkan balik head lama ke node baru
        *head = newNode; // Geser posisi head ke node yang paling baru
    }
}

// Tambah di akhir list 
void tambahAkhir(Node** head, Node** tail, char tipe[], char deskripsi[], long jumlah) {
    Node* newNode = createNode(tipe, deskripsi, jumlah);

    if (*head == NULL) {
        // Kalau list masih kosong, dia jadi satu-satunya di sana
        *head = *tail = newNode;
    } else {
        // Sambungin ekor (tail) yang lama ke node baru
        (*tail)->next = newNode;
        newNode->prev = *tail; // Hubungkan balik biar bisa mundur

        // Sekarang gantiin posisi tail ke node yang paling ujung
        *tail = newNode; 
    }
}

// Tambah sesudah transaksi tertentu
void tambahSesudah(Node** head, Node** tail, char targetDes[], char tipe[], char deskripsi[], long jumlah) {
    Node* temp = *head;
    // Cari transaksi acuan sampai ketemu atau sampai ujung
    while (temp != NULL && strcmp(temp->deskripsi, targetDes) != 0) {
        temp = temp->next;
    }
    if (temp == NULL) return; // berenti kalau data acuan tidak ada

    if (temp == *tail) {
        tambahAkhir(head, tail, tipe, deskripsi, jumlah);
    } else {
      Node* newNode = createNode(tipe, deskripsi, jumlah);
        // Atur tetangga baru untuk si newNode
        newNode->next = temp->next;
        newNode->prev = temp;
        // Update pointer tetangga lama agar nyambung ke newNode
        temp->next->prev = newNode;
        temp->next = newNode;
    }
}

// Tambah sebelum transaksi tertentu
void tambahSebelum(Node** head, Node** tail, char targetDes[], char tipe[], char deskripsi[], long jumlah) {
    Node* temp = *head;
    // Cari data acuan dari depan ke belakang
    while (temp != NULL && strcmp(temp->deskripsi, targetDes) != 0) { 
        temp = temp->next;
    }
    if (temp == NULL) return; // Keluar kalau target tidak ada

    if (temp == *head) {
        tambahAwal(head, tail, tipe, deskripsi, jumlah);
    } else {
        Node* newNode = createNode(tipe, deskripsi, jumlah);
        // Atur hubungan node baru ke depan (target) dan ke belakang
        newNode->next = temp;
        newNode->prev = temp->prev;
        // Sambungkan node sebelumnya dan target ke node baru ini
        temp->prev->next = newNode;
        temp->prev = newNode;
    }
}

// cetak log
void tampilkanLog(Node* head) {
    Node* temp = head;
    int i = 1;
    printf("\nLog Transaksi:\n");
    while (temp != NULL) {
        long nominal = temp->jumlah;
        printf("%d. %s - %s: %s%ld\n", i++, temp->tipe, temp->deskripsi, 
               (strcmp(temp->tipe, "Pemasukan") == 0 ? "+" : "-"), nominal);
        temp = temp->next;
    }
}

// menghitung total saldo
long hitungSaldo(Node* head) {
    Node* temp = head;
    long total = 0;
    // telusuri semua log transaksi dari awal
    while (temp != NULL) {
        // kalau pemasukan ditambah, kalau pengeluaran dikurang
        if (strcmp(temp->tipe, "Pemasukan") == 0) total += temp->jumlah;
        else total -= temp->jumlah;
        temp = temp->next; // lanjut ke transaksi berikutnya
    }
    return total;
}