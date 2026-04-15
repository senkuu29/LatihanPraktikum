// nama : deden ahmad jamil
// nim : 2501518

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "keuangan.h"

int main() {
    Node *head = NULL, *tail = NULL;
    // deklarasi variabel
    int pilihan;
    char tipe[20], deskripsi[100], target[100];
    long jumlah;

    // fitur2
    printf("\n--- Log Transaksi Keuangan ---\n");
    printf("1. Tambah Transaksi Awal\n");
    printf("2. Tambah Transaksi Akhir\n");
    printf("3. Tambah Transaksi Sesudah Transaksi Tertentu\n");
    printf("4. Tambah Transaksi Sebelum Transaksi Tertentu\n");
    printf("5. Tampilkan Log Transaksi\n");
    printf("6. Hitung Saldo Akhir\n");
    printf("0. Keluar\n");

    do {
        printf("\nPilih menu: ");
        scanf(" %d", &pilihan);

        switch(pilihan) {
            case 1:
            case 2:
                // input datanya
                printf("Tipe Transaksi (Pemasukan/Pengeluaran): ");
                scanf(" %[^\n]", tipe); 
                printf("Deskripsi: ");
                scanf(" %[^\n]", deskripsi);
                printf("Jumlah: ");
                scanf("%ld", &jumlah);
                
                // kalo user pilih 1
                if (pilihan == 1) {
                    tambahAwal(&head, &tail, tipe, deskripsi, jumlah);
                } else { //kalo user piilih selain 1
                    tambahAkhir(&head, &tail, tipe, deskripsi, jumlah);
                }
                break;

            case 3: 
                // input datanya
                printf("Tipe Transaksi (Baru): ");
                scanf(" %[^\n]", tipe);
                printf("Deskripsi (Baru): ");
                scanf(" %[^\n]", deskripsi);
                printf("Jumlah (Baru): ");
                scanf("%ld", &jumlah);
                printf("Sisipkan sesudah Deskripsi (Transaksi Acuan): ");
                scanf(" %[^\n]", target);
                
                tambahSesudah(&head, &tail, target, tipe, deskripsi, jumlah);
                printf("> Transaksi \"%s\" berhasil ditambahkan sesudah \"%s\".\n", deskripsi, target);
                break;

            case 4: 
                // input datanya
                printf("Tipe Transaksi (Baru): ");
                scanf(" %[^\n]", tipe);
                printf("Deskripsi (Baru): ");
                scanf(" %[^\n]", deskripsi);
                printf("Jumlah (Baru): ");
                scanf("%ld", &jumlah);
                printf("Sisipkan sebelum Deskripsi (Transaksi Acuan): ");
                scanf(" %[^\n]", target);
                
                // memannggil prosedur tambahsebelum
                tambahSebelum(&head, &tail, target, tipe, deskripsi, jumlah);
                printf("> Transaksi \"%s\" berhasil ditambahkan sebelum \"%s\".\n", deskripsi, target);
                break;

            case 5:
                tampilkanLog(head);
                break;

            case 6:
                printf("Saldo Akhir: %ld\n", hitungSaldo(head));
                break;

            case 0:
                printf("Keluar dari program...\n");
                break;

            default:
                printf("Pilihan tidak valid!\n");
        }
    } while (pilihan != 0);

    return 0;
}