// nama : deden ahmad jamil
// nim : 2501518

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Mahasiswa
{
  char nama[50];
  char nim[50];
  float nilai;
  struct Mahasiswa *next;
} mahasiswa;

mahasiswa *head = NULL;

// prosedur untuk mencetak datanya
void cetaklist(mahasiswa *head)
{
  mahasiswa *temp = head;
  int nomor = 1;

  printf("\nDAFTAR MAHASISWA\n");
  while (temp != NULL)
  {
    printf("%d. NIM: %s,  Nama: %s, Nilai: %.2f\n", nomor, temp->nim, temp->nama, temp->nilai);
    temp = temp->next;
    nomor++;
  }
}

int main()
{
  int n;
  printf("Masukkan jumlah mahasiswa: ");
  scanf(" %d", &n);

  for (int i = 0; i < n; i++)
  {
    // pesan node baru
    mahasiswa *kumpulanMahasiswa = (mahasiswa *)malloc(sizeof(mahasiswa));

    // penginputan datanya
    printf("Masukkan nama mahasiswa: ");
    scanf(" %[^\n]s", kumpulanMahasiswa->nama);
    printf("Masukkan nim mahasiswa: ");
    scanf(" %[^\n]s", kumpulanMahasiswa->nim);
    printf("Masukkan nilai mahasiswa: ");
    scanf(" %f", &kumpulanMahasiswa->nilai);
    printf("\n");

    kumpulanMahasiswa->next = NULL;

    // pendeklarasian head ketika head itu kosong maka di isi oleh gerbong baru tsb
    if (head == NULL)
    {
      head = kumpulanMahasiswa;
    }
    else
    {
      mahasiswa *temp = head;
      while (temp->next != NULL)
      {
        temp = temp->next;
      }
      temp->next = kumpulanMahasiswa;
    }
  }
  cetaklist(head);
}
