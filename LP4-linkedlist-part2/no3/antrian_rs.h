// nama : deden ahmad jamil
// nim : 2501518

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

// Update penyakit pasien kalau ID-nya cocok
void updatePenyakit(int idCari, char penyakitBaru[]) {
    struct Node *bantu = head;
    while (bantu != NULL) {
        if (bantu->id == idCari) {
            strcpy(bantu->penyakit, penyakitBaru);  // Timpa penyakit lama
            printf("Data pasien %s berhasil diperbarui.\n", bantu->nama);
            return;
        }
        bantu = bantu->next;
    }
}

// Tambah data setelah ID tertentu
void insertTengahSesudah(int idCari, int idBaru, char namaBaru[], char penyakitBaru[]) {
    struct Node *bantu = head;

    // Cari ID yang dimaksud
    while (bantu != NULL && bantu->id != idCari) {
        bantu = bantu->next;
    }

    // Kalau ketemu, selipkan di depannya
    if (bantu != NULL) {
        struct Node *baru = (struct Node*)malloc(sizeof(struct Node));
        baru->id = idBaru;
        strcpy(baru->nama, namaBaru);
        strcpy(baru->penyakit, penyakitBaru);
        
        baru->next = bantu->next;    // Baru nunjuk ke temannya bantu
        bantu->next = baru;          // Bantu sekarang nunjuk ke baru
    }
}

// Buang data pertama
void hapusAwal() {
    if (head != NULL) {
        struct Node *temp = head;  // Pegang dulu biar nggak hilang
        head = head->next;         // Pindahin head ke orang kedua
        free(temp);                // Hapus data yang tadi dipegang
    }
}

// Buang data paling ujung
void hapusAkhir() {
    if (head == NULL) return; // Kalau kosong ya nggak ada yang dihapus
    // Kalau cuma sendirian, langsung hapus aja
    if (head->next == NULL) {
        free(head);
        head = NULL;
        return;
    }
    struct Node *bantu = head;
    // Cari satu orang sebelum orang terakhir
    while (bantu->next->next != NULL) {
        bantu = bantu->next;
    }
    free(bantu->next);  // Hapus yang paling belakang
    bantu->next = NULL; // Putus biar nggak nyari yang udah nggak ada
}