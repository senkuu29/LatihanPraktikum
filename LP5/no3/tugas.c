// nama : deden ahmad jamil
// nim : 2501518

#include "tugas.h"

// Pabrik node
Tugas* createNode(char namatugas[], char deadline[], int prioritas) {
    // pesan node
    Tugas *baru = (Tugas*) malloc(sizeof(Tugas));

    // input data
    strcpy(baru->namaTugas, namatugas);
    strcpy(baru->deadline, deadline);
    baru->prioritas = prioritas;

    baru->next = NULL;  // node baru pegang null
    baru->prev = NULL;  // node baru dengan prev nya juga pegang null
    return baru;
}

// Tambah tugas di posisi paling depan
void tugasAwal(Tugas **head, char namaTugas[], char deadline[], int prioritas) {
    Tugas *baru = createNode(namaTugas, deadline, prioritas);
    if (*head == NULL) {
        *head = baru; // Kalau list kosong, ya ini jadi head nya
    } else {
        baru->next = *head;  // Sambungin ke node lama
        (*head)->prev = baru;// Node lama suruh nunjuk balik ke yang baru
        *head = baru;      // Head pindah ke depan
    }
}

// Tambah tugas di urutan paling akhir
void tugasAkhir(Tugas **head, char namaTugas[], char deadline[], int prioritas) {
    Tugas *baru = createNode(namaTugas, deadline, prioritas);
    if (*head == NULL) {
        *head = baru;
        return;
    }
    Tugas *temp = *head;

    // nyari node terakhir yang next-nya NULL
    while (temp->next != NULL) {
        temp = temp->next;
    }

    // Kalau udah ketemu sambungin
    temp->next = baru;
    baru->prev = temp;
}

// Sisipin tugas sebelum tugas yang udah ada
void tugasSebelumTertentu(Tugas **head, char namaTugas[], char deadline[], int prioritas, char target[]) {
    if (*head == NULL) return;

    // Cari dulu tugas yang mau dijadiin patokan
    Tugas *temp = *head;
    while (temp != NULL && strcmp(temp->namaTugas, target) != 0) {
        temp = temp->next;
    }

    // Kalau nggak ketemu, kelar
    if (temp == NULL) {
        printf("Tugas target '%s' tidak ditemukan!\n", target);
        return;
    }

    // Kalau patokannya di depan sendiri, pake fungsi tugasAwal aja biar simpel
    if (temp == *head) {
        tugasAwal(head, namaTugas, deadline, prioritas);
        return;
    }

    Tugas *baru = createNode(namaTugas, deadline, prioritas);
    baru->next = temp;  // depan baru itu si target
    baru->prev = temp->prev; // belakang baru itu mantannya target
    temp->prev->next = baru; // Mantan target sekarang nunjuk ke baru
    temp->prev = baru; // target sekarang nunjuk balik ke baru
}

// Sisipin tugas setelah tugas yang udah ada
void tugasSesudahTertentu(Tugas **head, char namaTugas[], char deadline[], int prioritas, char target[]) {
    Tugas *temp = *head;

    // Cari target berdasarkan nama tugas
    while (temp != NULL && strcmp(temp->namaTugas, target) != 0) {
        temp = temp->next;
    }

    // kalo gada
    if (temp == NULL) {
        printf("\n[!] Tugas acuan \"%s\" tidak ditemukan di daftar.\n", target);
        return; 
    }

    // Sambungin node baru ke depan dan belakangnya
    Tugas *baru = createNode(namaTugas, deadline, prioritas);
    baru->next = temp->next;
    baru->prev = temp;

    // Kalau setelah target masih ada node lain, suruh dia nunjuk balik ke baru
    if (temp->next != NULL) {
        temp->next->prev = baru;
    }
    temp->next = baru; // Target sekarang punya next baru
}

// menampilkan semua tugas
void TampilkanDaftarTugas(Tugas *head) {
    if (head == NULL) {
        printf("\nDaftar Tugas kosong.\n");
        return;
    }

    Tugas *temp = head;
    int i = 1;
    char teksPrioritas[20];

    printf("\nDaftar Tugas:\n");
    while (temp != NULL) {
       // Konversi angka prioritas ke teks
        if (temp->prioritas == 1) {
            strcpy(teksPrioritas, "Tinggi");
        } else if (temp->prioritas == 2) {
            strcpy(teksPrioritas, "Sedang");
        } else {
            strcpy(teksPrioritas, "Rendah");
        }

        printf("%d. %s (Deadline: %s, Prioritas: %s)\n", 
                i, temp->namaTugas, temp->deadline, teksPrioritas);
        
        temp = temp->next;
        i++;
    }
}