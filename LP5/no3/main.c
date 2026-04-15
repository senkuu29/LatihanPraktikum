// nama: deden ahmad jamil
// nim: 2501518

#include "tugas.c"

int main() {
  Tugas *head = NULL;
  
  // deklarasi variabel
  int pilihan, prioritas;
  char namaTugas[100], deadline[50], target[100];

  // fitur2
  printf("\n--- Sistem Manajemen Tugas Harian ---\n");
  printf("1. Tambah Tugas Awal\n");
  printf("2. Tambah Tugas Akhir\n");
  printf("3. Tambah Tugas Sesudah Tugas Tertentu\n");
  printf("4. Tambah Tugas Sebelum Tugas Tertentu\n");
  printf("5. Tampilkan Daftar Tugas\n");
  printf("0. Keluar\n");

  do {
    printf("\nPilih menu: ");
    scanf("%d", &pilihan);

    switch (pilihan) {
      case 1:
        // input
        printf("Nama Tugas: ");
        scanf(" %[^\n]s", namaTugas);

        printf("Deadline: ");
        scanf(" %[^\n]s", deadline);

        printf("Prioritas (1=Tinggi, 2=Sedang, 3=Rendah): ");
        scanf("%d", &prioritas);
        
        tugasAwal(&head, namaTugas, deadline, prioritas);
        break;

      case 2:
        // input
        printf("Nama Tugas: ");
        scanf(" %[^\n]s", namaTugas);

        printf("Deadline: ");
        scanf(" %[^\n]s", deadline);

        printf("Prioritas (1=Tinggi, 2=Sedang, 3=Rendah): ");
        scanf("%d", &prioritas);
        
        tugasAkhir(&head, namaTugas, deadline, prioritas);
        break;

      case 3:
        // input
        printf("Nama Tugas (Baru): ");
        scanf(" %[^\n]s", namaTugas);

        printf("Deadline (Baru): ");
        scanf(" %[^\n]s", deadline);

        printf("Prioritas (Baru): ");
        scanf("%d", &prioritas);

        printf("\nSisipkan sesudah Tugas (Nama Tugas Acuan): ");
        scanf(" %[^\n]s", target);

        // Panggil fungsinya
        tugasSesudahTertentu(&head, namaTugas, deadline, prioritas, target);
        
        // Pesan konfirmasi
        printf("> Tugas \"%s\" berhasil ditambahkan sesudah \"%s\".\n", namaTugas, target);
        break;
        
        tugasSesudahTertentu(&head, namaTugas, deadline, prioritas, target);
        break;

      case 4:
        // input 
        printf("Nama Tugas (Baru): ");
        scanf(" %[^\n]s", namaTugas);

        printf("Deadline (Baru): ");
        scanf(" %[^\n]s", deadline);

        printf("Prioritas (Baru): ");
        scanf("%d", &prioritas);

        printf("Sisipkan sebelum Tugas (Nama Tugas Acuan): ");
        scanf(" %[^\n]s", target);

        // fungsi tambah sebelum
        tugasSebelumTertentu(&head, namaTugas, deadline, prioritas, target);
        
        printf("> Tugas \"%s\" berhasil ditambahkan sebelum \"%s\".\n", namaTugas, target);
        break;

      case 5:
        TampilkanDaftarTugas(head);
        break;

      case 0:
        printf("Keluar dari program..\n");
        break;
      
      default:
        printf("Pilihan tidak tersedia.\n");
        break;
    }

  } while (pilihan != 0);

  return 0;
}