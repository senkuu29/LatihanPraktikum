// nama: deden ahmad jamil
// nim : 2501518

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include "library.c"

int main(){
  Library *head = NULL;

  // deklarasi variabel
  int pilihan;
  char sub;

  int jumlahHal;
  char judul[50], penulis[50], status[50], search[100], ubahStatus[50];

  // fitur"nya
  printf("\nour E-Book Library! :p\n");
  printf("1. Tambah Awal\n");
  printf("2. Tambah Akhir\n");
  printf("3. Daftar Buku\n");
  printf("4. Cari Buku\n");
  printf("5. Tampil Buku yang Sedang Dibaca\n");
  printf("6. Ubah Status Buku\n");
  printf("0. Keluar\n");
  do
  {
    printf("\nPilih menu: ");
    scanf(" %d", &pilihan);

    switch (pilihan)
    {
    case 1:
      // input data
      printf("Judul buku: ");
      scanf(" %[^\n]s", judul);
      
      printf("Penulis: ");
      scanf(" %[^\n]s", penulis);

      printf("Jumlah halaman: ");
      scanf(" %d", &jumlahHal);

      printf("Status (Belum/Tamat): ");
      scanf(" %[^\n]s", status);

      addFirstBook(&head, judul, penulis, jumlahHal, status);
      break;
    case 2:
      // input data
      printf("Judul buku: ");
      scanf(" %[^\n]s", judul);
      
      printf("Penulis: ");
      scanf(" %[^\n]s", penulis);

      printf("Jumlah halaman: ");
      scanf(" %d", &jumlahHal);

      printf("Status (Belum/Tamat): ");
      scanf(" %[^\n]s", status);

      addLastBook(&head, judul, penulis, jumlahHal, status);
      break;
    case 3:
        daftarBuku(head);  // fitur melihat semua data
      break;
    case 4:
        // search
        printf("Masukkan judul buku yang dicari: ");
        scanf(" %[^\n]s", search);

        searchByJudul(head, search);
        break;
      break;
    case 5:
        tampilkanBookmark();
        break;
      break;
    case 6:
        printf("Masukkan judul buku: ");
        scanf(" %[^\n]s", ubahStatus);

        ubahStatusBuku(&head, ubahStatus);
      break;
    case 0:
      printf("keluar..\n");
      break;
    default:
      printf("Pilihlah sesuai dengan nomor yang ada (0-6)\n");
      break;
    }
  } while (pilihan != 0);
}