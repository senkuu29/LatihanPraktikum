#include <stdio.h>

// struct Buku
typedef struct
{
  char judul[50];
  int tahunTerbit;
} Buku;

// prosedur untuk menampilkan hasil
void cetakBuku(Buku *b, int n)
{
  printf("DAFTAR BUKU\n");
  for (int i = 0; i < n; i++)
  {
    printf("%d. %s (%d)\n", i + 1, (b + i)->judul, (b + i)->tahunTerbit);
  }
}

int main()
{
  int n;
  printf("Masukkan Jumlah Buku: ");
  scanf("%d", &n);

  Buku books[n];

  // proses peng inputan
  for (int i = 0; i < n; i++)
  {
    printf("Masukkan Judul Buku: ");
    scanf(" %[^\n]s", books[i].judul);
    printf("Masukkan Tahun Terbit: ");
    scanf(" %d", &books[i].tahunTerbit);
    printf("\n");
  }
  // memanggil + nama array + jmlBuku/n
  cetakBuku(books, n);
  return 0;
}