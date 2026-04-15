// nama : deden ahmad jamil
// nim : 2501518

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Struktur Mahasiswa
typedef struct Mahasiswa
{
    char nim[50];
    char nama[50];
    float nilai;
    struct Mahasiswa *next;
} mahasiswa;

// Pointer Global untuk Head
mahasiswa *head = NULL;

// Fungsi untuk mencetak seluruh data
void cetaklist(mahasiswa *head)
{
    mahasiswa *temp = head;
    int nomor = 1;

    printf("\nDAFTAR MAHASISWA\n");
    if (temp == NULL)
    {
        printf("List masih kosong.\n");
    }

    while (temp != NULL)
    {
        printf("%d. NIM: %s, Nama: %s, Nilai: %.2f\n", nomor, temp->nim, temp->nama, temp->nilai);
        temp = temp->next;
        nomor++;
    }
}

// Fungsi untuk mencari data berdasarkan NIM
mahasiswa *cariNIM(mahasiswa *head, char nimDicari[])
{
    mahasiswa *temp = head;
    while (temp != NULL)
    {
        if (strcmp(temp->nim, nimDicari) == 0)
        {
            return temp;
        }
        temp = temp->next;
    }
    return NULL;
}

// Fungsi Tambah di Awal (Menu 1)
void tambahAwal(mahasiswa **head, char nim[], char nama[], float nilai)
{
    // pesan gerbong baru dengan nama baru
    mahasiswa *baru = (mahasiswa *)malloc(sizeof(mahasiswa));
    strcpy(baru->nim, nim);
    strcpy(baru->nama, nama);
    baru->nilai = nilai;

    baru->next = *head; // Node baru menunjuk ke head lama
    *head = baru;       // Head utama pindah ke node baru
    printf("\nData berhasil ditambahkan di awal.\n");
    printf("\n");
}

// Fungsi Tambah Setelah NIM tertentu (Menu 2)
void tambahSetelah(mahasiswa *head, char cariNim[], char nim[], char nama[], float nilai)
{
    mahasiswa *target = cariNIM(head, cariNim);

    if (target == NULL)
    {
        printf("Data tidak ditemukan.\n");
        return;
    }

    mahasiswa *baru = (mahasiswa *)malloc(sizeof(mahasiswa));
    strcpy(baru->nim, nim);
    strcpy(baru->nama, nama);
    baru->nilai = nilai;

    // Proses menyisipkan node di tengah (setelah target)
    baru->next = target->next;
    target->next = baru;
    printf("Data berhasil ditambahkan.\n");
    printf("\n");
}

// Fungsi Tambah Sebelum NIM tertentu (Menu 3)
void tambahSebelum(mahasiswa **head, char cariNim[], char nim[], char nama[], float nilai)
{
    if (*head == NULL)
    {
        printf("Data tidak ditemukan.\n");
        return;
    }

    // Jika yang dicari adalah node pertama, panggil fungsi tambahAwal
    if (strcmp((*head)->nim, cariNim) == 0)
    {
        tambahAwal(head, nim, nama, nilai);
        return;
    }

    mahasiswa *temp = *head;
    // Mencari node yang berada tepat sebelum node target
    while (temp->next != NULL && strcmp(temp->next->nim, cariNim) != 0)
    {
        temp = temp->next;
    }

    if (temp->next == NULL)
    {
        printf("Data tidak ditemukan.\n");
    }
    else
    {
        mahasiswa *baru = (mahasiswa *)malloc(sizeof(mahasiswa));
        strcpy(baru->nim, nim);
        strcpy(baru->nama, nama);
        baru->nilai = nilai;

        baru->next = temp->next;
        temp->next = baru;
        printf("Data berhasil ditambahkan.\n");
    }
}

int main()
{
    int pilihan;
    char nim[50], nama[50], cariNim[50];
    float nilai;

    do
    {
        printf("Pilih: ");
        scanf("%d", &pilihan);

        switch (pilihan)
        {
        case 1:
            printf("\nMasukkan NIM: ");
            scanf(" %[^\n]s", nim);
            printf("Nama: ");
            scanf(" %[^\n]s", nama);
            printf("Nilai: ");
            scanf("%f", &nilai);
            tambahAwal(&head, nim, nama, nilai);
            break;

        case 2:
            cetaklist(head);
            printf("Masukkan NIM acuan (data akan ditambah setelah NIM ini): ");
            scanf(" %[^\n]s", cariNim);

            // Validasi keberadaan NIM
            mahasiswa *cek = cariNIM(head, cariNim);
            if (cek == NULL)
            {
                printf("Data tidak ditemukan.\n");
            }
            else
            {
                printf("Masukkan NIM: ");
                scanf(" %[^\n]s", nim);
                printf("Nama: ");
                scanf(" %[^\n]s", nama);
                printf("Nilai: ");
                scanf("%f", &nilai);
                tambahSetelah(head, cariNim, nim, nama, nilai);
            }
            break;

        case 3:
            cetaklist(head);
            printf("Masukkan NIM acuan (data akan ditambah sebelum NIM ini): ");
            scanf(" %[^\n]s", cariNim);

            // Cek dulu pake cariNIM
            mahasiswa *cekSebelum = cariNIM(head, cariNim);

            if (cekSebelum == NULL)
            {
                printf("Data tidak ditemukan.\n");
            }
            else
            {
                printf("Masukkan NIM: ");
                scanf(" %[^\n]s", nim);
                printf("Nama: ");
                scanf(" %[^\n]s", nama);
                printf("Nilai: ");
                scanf("%f", &nilai);
                tambahSebelum(&head, cariNim, nim, nama, nilai); // Pakai &head karena bisa mengubah head
            }
            break;

        case 4:
            printf("Masukkan NIM yang dicari: ");
            scanf(" %[^\n]s", cariNim);
            mahasiswa *ketemu = cariNIM(head, cariNim);
            if (ketemu)
            {
                printf("Data ditemukan Nama: %s, Nilai: %.2f\n", ketemu->nama, ketemu->nilai);
            }
            else
            {
                printf("Data tidak ditemukan.\n");
            }
            break;

        case 5:
            cetaklist(head);
            break;

        case 6:
            printf("Program selesai.\n");
            break;

        default:
            printf("Pilihan tidak valid!\n");
        }
    } while (pilihan != 6);

    return 0;
}