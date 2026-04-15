// nama : deden ahmad jamil
// nim : 2501518

#include "donat.h"

int main() {
    Node *head = NULL;
    Node *tail = NULL;
    // deklarasi variabel
    int pilihan, jumlah;
    char nama[50];

    // fitur2
    printf("\nDonat's Waiting List:\n");
    printf("1. Tambah Data\n");
    printf("2. Lihat Daftar Data Pesanan\n");
    printf("3. Cari Pesanan Berdasarkan Nama\n");
    printf("4. Tampilkan Pesanan yang Sedang Dilayani\n");
    printf("5. Edit Data\n");
    printf("6. Hapus Data Awal\n");
    printf("7. Hapus Data Akhir\n");
    printf("8. Hapus Data Berdasarkan Nama\n");
    printf("9. Keluar\n");
    do {
        
        printf("\nPilih menu: ");
        if (scanf("%d", &pilihan) != 1) {
            while (getchar() != '\n');
            continue;
        }

        switch (pilihan) {
            case 1:
                printf("Nama Pemesan: ");
                scanf(" %[^\n]", nama);
                printf("Jumlah Pesanan: ");
                scanf("%d", &jumlah);
                tambahAkhir(&head, &tail, nama, jumlah);
                break;

            case 2:
                tampilkanDaftar(head);
                break;

            case 3:
                printf("Masukkan nama pemesan: ");
                scanf(" %[^\n]", nama);
                cariNama(head, nama);
                break;

            case 4:
                sedangDilayani(head);
                break;

            case 5:
                printf("Masukkan nama pemesan: ");
                scanf(" %[^\n]", nama);
                printf("Masukkan jumlah pesanan yang baru: ");
                scanf("%d", &jumlah);
                editData(head, nama, jumlah);
                break;

            case 6:
                // Hapus awal (untuk pesanan yang sudah dilayani)
                hapusAwal(&head, &tail);
                tampilkanDaftar(head);
                break;

            case 7:
                // Hapus akhir (untuk pesanan yang dibatalkan)
                hapusAkhir(&head, &tail);
                tampilkanDaftar(head);
                break;

            case 8:
                printf("Masukkan nama pemesan: ");
                scanf(" %[^\n]", nama);
                hapusNama(&head, &tail, nama);
                tampilkanDaftar(head);
                break;

            case 9:
                printf("\nKeluar dari program...\n");
                break;

            default:
                printf("\nPilihan tidak valid!\n");
                break;
        }
    } while (pilihan != 9);

    while (head != NULL) {
        hapusAwal(&head, &tail);
    }

    return 0;
}