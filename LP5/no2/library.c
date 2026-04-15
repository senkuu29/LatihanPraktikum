// nama : deden
// nim : 2501518

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "library.h"

Library *current = NULL;

// pabrik node
Library* createNode(char judul[], char penulis[], int jumlahHal, char status[]) {
  // pesan node baru
  Library *baru = (Library*) malloc(sizeof(Library));

  // input datanya
  strcpy(baru->judul, judul);
  strcpy(baru->penulis, penulis);
  baru->jumlahHal = jumlahHal;
  strcpy(baru->status, status);

  baru->next = NULL;
  baru->prev = NULL;

  return baru;
}

// prosedur nambahin node baru diawal
void addFirstBook(Library **head, char judul[], char penulis[], int jumlahHal, char status[]) {
  Library *baru = createNode(judul, penulis, jumlahHal, status);

    // kalo head nya kosong
    if (*head == NULL)
    {
        *head = baru;
    }else {
        baru->next = *head; //menghunugkan node baru ke node lama
        (*head)->prev = baru; //kemudian menggeser penanda head ke node yang baru
        *head = baru;
    }
  // bookmark otomatis menunjuk ke buku paling baru ini
  bookmark = baru;
}

// menambahkan data di akhir
void addLastBook(Library **head, char judul[], char penulis[], int jumlahHal, char status[]) {
    Library *baru = createNode(judul, penulis, jumlahHal, status);

    // kalo headnya masi kosong
    if (*head == NULL) {
        *head = baru;
        if (bookmark == NULL) {
            bookmark = baru;
        }
        return;
    }

    Library *temp = *head;

    // temp akan terus maju sampai ketemu NULL
    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = baru; // ketika udh nemu null maka baru di sambungkan disini
    baru->prev = temp; // prev baru sambungin ke gerbong sebelumnya
}

// prosedur untuk menampikan semua data
void daftarBuku(Library *head){
  Library *temp = head;

  int no = 1;

  printf("Perpustakaan:\n");
  while (temp != NULL)
  {
    printf("%d. %s - %s - %d halaman - %s\n", no, temp->judul, temp->penulis, temp->jumlahHal, temp->status);
    temp = temp->next;
    no++;
  }
}

// prosedur search by judul
void searchByJudul(Library *head, char target[]) {
    Library *temp = head;
    int no = 1;
    int found = 0;

    // cari terus sampe node kosong
    while (temp != NULL) {
        // membandingkan jdul menggunakan strcasecmp agar tidak memedulikan huruf besar/kecil
        if (strcasecmp(temp->judul, target) == 0) {
            printf("> Book found: %d. %s - %s - %d halaman - %s\n", no, temp->judul, temp->penulis, temp->jumlahHal, temp->status);
            found = 1;
            break;
        }
        // Geser pointer ke node selanjutnya
        temp = temp->next;
        no++;
    }
}

// menampilkan yang sedang di baca
void tampilkanBookmark() {
    if (bookmark == NULL) {
        printf("> Saat ini tidak ada buku yang sedang dibaca.\n");
    } else {
        printf("> Now Reading: %s - %s - %d\n", bookmark->judul, bookmark->penulis, bookmark->jumlahHal);
    }
}

// prosedur untuk mengubah status
void ubahStatusBuku (Library **head, char judulDicari[]) {
    Library *temp = *head;

    while (temp != NULL)
    {
        // mencari judul yang dicari
        if (strcasecmp(temp->judul, judulDicari) == 0)
        {
            strcpy(temp->status, "Tamat");
            printf("Buku ditemukan! Berhasil mengubah status!\n");

                // untuk menampilkan next book
                if (temp == bookmark) {
                    if (bookmark->next != NULL) {
                        bookmark = bookmark->next;
                        printf("> Next Book to Read: %s\n", bookmark->judul);
                    }
                }
            return;
        }
        temp = temp->next;
    }
    
}