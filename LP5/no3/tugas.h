// nama : deden ahmad jamil
// nim : 2501518

#ifndef TUGAS_H
#define TUGAS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// struct tugas
typedef struct Tugas {
  char namaTugas[100];
  char deadline[50];
  int prioritas;
  struct Tugas *next;
  struct Tugas *prev;
} Tugas;

Tugas* createNode(char namaTugas[], char deadline[], int prioritas);

void tugasAwal(Tugas **head, char namaTugas[], char deadline[], int prioritas);
void tugasAkhir(Tugas **head, char namaTugas[], char deadline[], int prioritas);

void tugasSebelumTertentu(Tugas **head, char namaTugas[], char deadline[], int prioritas, char targetNama[]);
void tugasSesudahTertentu(Tugas **head, char namaTugas[], char deadline[], int prioritas, char targetNama[]);

void TampilkanDaftarTugas(Tugas *head);

#endif