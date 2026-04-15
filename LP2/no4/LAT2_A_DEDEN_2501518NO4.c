#include <stdio.h>

// adt internal dan termasuk struct Alamat
typedef struct
{
  char kota[50];
  int kodePos;
} Alamat;

// adt internal dan termasuk struct Pegawai
typedef struct
{
  char nama[50];
  char jabatan[30];
  Alamat alamats;
} Pegawai;

// prosedur untuk menampilkan nama" pegawai
void tampilPegawai(Pegawai *p, int n)
{
  printf("\n======DATA PEGAWAI======\n");
  for (int i = 0; i < n; i++)
  {
    printf("Nama     : %s\n", (p + i)->nama);
    printf("Jabatan  : %s\n", (p + i)->jabatan);
    printf("Kota     : %s\n", (p + i)->alamats.kota);
    printf("Kodepos  : %d\n", (p + i)->alamats.kodePos);
    printf("\n");
  }
}

int main()
{
  int n;
  printf("\nMasukkan jumlah Pegawai: ");
  scanf(" %d", &n);

  // memanggil struct Pegawai dan membuat array A
  Pegawai A[n];

  // proses input data Pegawai
  for (int i = 0; i < n; i++)
  {
    printf("\nNama: ");
    scanf(" %[^\n]s", (A + i)->nama);
    printf("Jabatan: ");
    scanf(" %[^\n]s", (A + i)->jabatan);
    printf("Kota: ");
    scanf(" %[^\n]s", (A + i)->alamats.kota);
    printf("Kodepos: ");
    scanf(" %d", &(A + i)->alamats.kodePos);
  }

  // pemanggilan prosedur tampilpegawai dengan memasukan array A dan jumlah pegawai(n)
  tampilPegawai(A, n);

  return 0;
}