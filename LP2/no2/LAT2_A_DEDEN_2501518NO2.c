#include <stdio.h>

// adt internal dan termasuk struct
typedef struct
{
  char Nama[50];
  int UTS;
  int UAS;
  float nilaiAkhir;
} Nilai;

// fungsi buat menghitung nilai akhir dan sekaligus menampilkan output
int hitungNilaiAkhir(Nilai *m, int n)
{
  printf("======Nilai Mahasiswa======\n");
  for (int i = 0; i < n; i++)
  {
    (m + i)->nilaiAkhir = ((m + i)->UTS * 0.4) + ((m + i)->UAS * 0.6);
    printf("Nama       : %s\n", (m + i)->Nama);
    printf("UTS        : %d\n", (m + i)->UTS);
    printf("UAS        : %d\n", (m + i)->UAS);
    printf("Nilai Akhir: %.2f\n", (m + i)->nilaiAkhir);
    printf("\n");
  }
}

int main()
{
  int n;

  printf("\nMasukkan Jumlah Mahasiswa: ");
  scanf("%d", &n);

  Nilai mahasiswa[n];

  // tempat penginputan data mhs
  for (int i = 0; i < n; i++)
  {
    printf("Masukkan Nama Mahasiswa: ");
    scanf(" %s", (mahasiswa + i)->Nama);
    printf("Masukkan Nilai UTS: ");
    scanf(" %d", &(mahasiswa + i)->UTS);
    printf("Masukkan Nilai UAS: ");
    scanf(" %d", &(mahasiswa + i)->UAS);
    printf("\n");
  }

  // pemanggilan fungsi hitungakhir
  hitungNilaiAkhir(mahasiswa, n);
}