#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definisi struktur data pasien (Linked List)
struct Node {
    int id;
    char nama[50];
    char penyakit[50];
    struct Node *next;
};

struct Node *head = NULL;

// Menampilkan semua data dari awal sampai akhir
void tampilkan() {
    struct Node *bantu = head;
    printf("\nData Antrian Pasien:\n");
    printf("==========================================\n");
    while (bantu != NULL) {
        printf("ID: %d | Nama: %s | Penyakit: %s\n", bantu->id, bantu->nama, bantu->penyakit);
        bantu = bantu->next;  // Geser ke node berikutnya
      }
      printf("==========================================\n");
}

// Menambah data di urutan paling depan
void insertAwal(int id, char nama[], char penyakit[]) {
    struct Node *baru = (struct Node*)malloc(sizeof(struct Node));
    baru->id = id;
    strcpy(baru->nama, nama);
    strcpy(baru->penyakit, penyakit);
    
    baru->next = head;   // Sambungkan ke head lama
    head = baru;         // Jadikan node baru sebagai head
}

// Menambah data di urutan paling belakang
void insertAkhir(int id, char nama[], char penyakit[]) {
    struct Node *baru = (struct Node*)malloc(sizeof(struct Node));
    baru->id = id;
    strcpy(baru->nama, nama);
    strcpy(baru->penyakit, penyakit);
    baru->next = NULL;

    if (head == NULL) {
        head = baru;    // Jika kosong, langsung jadi head
    } else {
        struct Node *bantu = head;
        while (bantu->next != NULL) {
            bantu = bantu->next;  // Cari node terakhir
        }
        bantu->next = baru;       // Hubungkan node terakhir ke node baru
    }
}

void insertTengahSebelum(int idCari, int idBaru, char namaBaru[], char penyakitBaru[]) {
    if (head == NULL) return;  // Keluar kalau list masih kosong

    // Kalau ternyata yang dicari itu data pertama
    if (head->id == idCari) {
        insertAwal(idBaru, namaBaru, penyakitBaru);
        return;
    }

    struct Node *bantu = head;
    // Cari posisi berhenti tepat di depan node yang dituju
    while (bantu->next != NULL && bantu->next->id != idCari) {
        bantu = bantu->next;
    }

    // Kalau idCari ketemu (nggak sampai ujung list)
    if (bantu->next != NULL) {
        struct Node *baru = (struct Node*)malloc(sizeof(struct Node));
        baru->id = idBaru;
        strcpy(baru->nama, namaBaru);
        strcpy(baru->penyakit, penyakitBaru);

        // Sambungin pointer: baru ke depan, bantu ke baru
        baru->next = bantu->next;
        bantu->next = baru;
    }
}