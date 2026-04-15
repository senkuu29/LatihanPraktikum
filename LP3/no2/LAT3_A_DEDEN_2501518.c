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

// prosedur untuk mencetak seluruh data
void cetaklist(mahasiswa *head)
{
  mahasiswa *temp = head;
  int nomor = 1;

  printf("DAFTAR MAHASISWA\n");
  while (temp != NULL)
  {
    printf("%d. NIM: %s,  Nama: %s, Nilai: %.2f\n", nomor, temp->nim, temp->nama, temp->nilai);
    temp = temp->next;
    nomor++;
  }
  printf("\n");
}

// prosedur untuk menambah data
void addData(mahasiswa **head)
{
  int n;
  printf("Masukkan jumlah mahasiswa: ");
  scanf(" %d", &n);

  for (int i = 0; i < n; i++)
  {
    // pesan node baru
    mahasiswa *kumpulanMahasiswa = (mahasiswa *)malloc(sizeof(mahasiswa));

    // penginputan data
    printf("\nMasukkan NIM: ");
    scanf(" %[^\n]s", kumpulanMahasiswa->nim);
    printf("Nama: ");
    scanf(" %[^\n]s", kumpulanMahasiswa->nama);
    printf("Nilai: ");
    scanf(" %f", &kumpulanMahasiswa->nilai);

    kumpulanMahasiswa->next = NULL;

    if (*head == NULL)
    {
      *head = kumpulanMahasiswa;
    }
    else
    {
      mahasiswa *temp = *head;
      while (temp->next != NULL)
      {
        temp = temp->next;
      }
      temp->next = kumpulanMahasiswa;
    }
  }
  printf("\nData berhasil ditambahkan.\n\n");
}

// fungsi untuk mencari data by nim
mahasiswa *cariNIM(mahasiswa *head, char nimDicari[])
{
  mahasiswa *temp = head;

  while (temp != NULL)
  {
    if (strcmp(temp->nim, nimDicari) == 0)
    {
      return temp; // kalo ketemu stop lalu kasihtau alamatnya
    }
    // ini kalo yg dicari gada di gerbong itu maka lanjut ke gerbong selanjutnya
    temp = temp->next;
  }
  return NULL;
}

// main fungsi
int main()
{
  int pilihan;
  do
  {
    char nimCari[50];

    // untuk memilih fitur
    printf("Pilih: ");
    scanf(" %d", &pilihan);

    switch (pilihan)
    {
    case 1:
      // fitur 1 untuk menambahkan data
      addData(&head);
      break;
    case 2:
      // fitur 2 untuk mencari data by nim
      printf("Masukkan NIM yang dicari: ");
      scanf(" %[^\n]s", nimCari);

      mahasiswa *ketemu = cariNIM(head, nimCari);

      // ketika data yang dicari ketemu
      if (ketemu != NULL)
      {
        printf("Data ditemukan: Nama: %s, Nilai: %.2f\n", ketemu->nama, ketemu->nilai);
        printf("\n");
      }
      else
      {
        printf("Data tidak ditemukan.\n");
        printf("\n");
      }
      break;
    case 3:
      // fitur 3 untuk mencetak list
      cetaklist(head);
      break;
    case 4:
      printf("Program selesai.");
    default:
      break;
    }
  } while (pilihan != 4);
}
