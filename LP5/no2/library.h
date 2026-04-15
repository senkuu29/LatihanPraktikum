// nama : deden ahmad jamil
// nim : 2501518

#ifndef LIBRARY_H
#define LIBRARY_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// struct buku
typedef struct Library {
  char judul[100];
  char penulis[100];
  int jumlahHal;
  char status[50];
  struct Library *next;
  struct Library *prev;
} Library;

// variabel globalnya
Library *bookmark = NULL;

Library* createNode(char judul[], char penulis[], int jumlahHal, char status[]);
void addFirstBook(Library **head, char judul[], char penulis[], int jumlahHal, char status[]);
void addLastBook(Library **head, char judul[], char penulis[], int jumlahHal, char status[]);
void daftarBuku(Library *head);
void searchByJudul(Library *head, char judul[]);
void tampilkanBookmark();
void ubahStatusBuku(Library **head, char judul[]);

#endif