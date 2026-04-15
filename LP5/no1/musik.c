// nama : deden
// nim : 2501518

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "musik.h"

Musik *current = NULL;

// pabrik node
Musik* createNode(char judul[], char penyanyi[]) {
  // pesan node baru
  Musik *baru = (Musik*) malloc(sizeof(Musik));

  // input datanya
  strcpy(baru->judul, judul);
  strcpy(baru->Penyanyi, penyanyi);

  baru->next = NULL;
  baru->prev = NULL;

  return baru;
}

// prosedur nambahin node baru
void addSong(Musik **head, char judul[], char penyanyi[]) {
  Musik *baru = createNode(judul, penyanyi);

  if (*head == NULL)
  {
    *head = baru;
  }else {
    baru->next = *head;
    (*head)->prev = baru;
    *head = baru;
  }

  // printf("yang udah di inputkan\n");
  // printf("judul lagu: %s  | %s", baru->judul, baru->Penyanyi);
}

// prosedur untuk menampikan semua data
void showPlaylist(Musik *head){
  Musik *temp = head;

  int no = 1;

  printf("Daftar Musik:\n");
  while (temp != NULL)
  {
    printf("%d. %s - %s\n", no, temp->judul, temp->Penyanyi);
    temp = temp->next;
    no++;
  }
  
}

// prosedur search by judul
void searchByTitle(Musik *head, char target[]) {
    // pointer sementara untuk mencari target
    Musik *temp = head;
    int no = 1;
    int found = 0;

    // Telusuri list selama node tidak kosong
    while (temp != NULL) {
        // membandingkan jdul menggunakan strcasecmp agar tidak memedulikan huruf besar/kecil
        if (strcasecmp(temp->judul, target) == 0) {
            printf("> Song found: %d. %s - %s\n", no, temp->judul, temp->Penyanyi);
            found = 1;
            break;
        }
        // Geser pointer ke node selanjutnya
        temp = temp->next;
        no++;
    }
}

// prosedur search by artis
void searchByArtist(Musik *head, char target[]) {
    Musik *temp = head;
    int no = 1;
    int found = 0;

    // Lakukan penelusuran dari head sampai akhir
    while (temp != NULL) {
        // Bandingkan penyanyi dengan target (strcasecmp agar tidak case-sensitive)
        if (strcasecmp(temp->Penyanyi, target) == 0) {
            printf("> Song found: %d. %s %s\n", no, temp->judul, temp->Penyanyi);
            found = 1;
        }
        temp = temp->next; // Geser ke node selanjutnya
        no++;
    }

    // kalo tidak di temukan
    if (!found) {
        printf("Lagu oleh penyanyi '%s' tidak ditemukan.\n", target);
    }
}

// prosedur untuk play musik
void playSong(Musik *head, char target[]) {
    Musik *temp = head;  //pointer untuk menelusuri list
    // Perulangan untuk mencari lagu berdasarkan judul
    while (temp != NULL) {
        // Bandingkan judul input dngan node
        if (strcasecmp(temp->judul, target) == 0) {
            current = temp; // untuk menandai bhwa ini sedang di putar
            printf("Now Playing: %s - %s\n", current->judul, current->Penyanyi);
            return;
        }
        temp = temp->next; // Geser ke node berikutnya
    }
    printf("Lagu tidak ditemukan.\n");
}

// prsedur play next musik
void nextSong() {
    // Pastikan ada lagu yang diputar dan ada lagu setelahnya
    if (current != NULL && current->next != NULL) {
        current = current->next;  //geser
        printf("Now Playing: %s %s\n", current->judul, current->Penyanyi);
    } else {
        // kalo curret->next nya udah di ujung
        printf("Sudah di akhir playlist.\n");
    }
}

// prosedur play mundur musik 
void previousSong() {
    // Pastikan ada lagu yang diputar dan ada lagu setelahnya
    if (current != NULL && current->prev != NULL) {
        current = current->prev; //geser kebelakang
        printf("Now Playing: %s %s\n", current->judul, current->Penyanyi);
    } else {
        // kalo curret->next nya udah di ujung
        printf("Sudah di awal playlist.\n");
    }
}