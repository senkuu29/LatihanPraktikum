// nama : deden ahmad jamil
// nim : 2501518

#include "donat.h"

Node* createNode(char nama[], int jumlah) {
  // Siapin tempat di memori buat antrian baru
    Node* newNode = (Node*)malloc(sizeof(Node));
    // Masukin data pembeli & hitung total harganya
    strcpy(newNode->nama, nama);
    newNode->jumlah = jumlah;
    newNode->total = jumlah * 12000;

    // Putusin dulu koneksi ke depan & belakang (set ke NULL)
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

void tambahAkhir(Node** head, Node** tail, char nama[], int jumlah) {
  // Bikin node baru buat pembeli yang baru dateng
    Node* newNode = createNode(nama, jumlah);

    // Kalau antrian masih kosong, dia jadi yang pertama sekaligus terakhir
    if (*head == NULL) {
        *head = *tail = newNode;
    } else {
      // Kalau udah ada orang, taruh di belakang tail lama
        (*tail)->next = newNode;
        // Sambungin balik ke tail lama biar jadi dua arah
        newNode->prev = *tail;
        // Sekarang dia yang jadi tail (paling belakang)
        *tail = newNode;
    }
}

void tampilkanDaftar(Node* head) {
  // Mulai dari depan (head)
    Node* temp = head;
    int i = 1;
    printf("\nWaiting List Pesanan Donat:\n");
    // Looping terus selama node-nya nggak kosong (NULL)
    while (temp != NULL) {
      // Print data pembeli satu-satu
        printf("%d. %s : %d item dengan total Rp%d\n", i++, temp->nama, temp->jumlah, temp->total);
        // Pindah ke orang berikutnya di antrian
        temp = temp->next;
    }
}

void cariNama(Node* head, char nama[]) {
  // Mulai cari dari depan antrian
    Node* temp = head;

    // Cek satu-satu sampai ujung antrian
    while (temp != NULL) {
      // Kalau nama di node sama dengan yang dicari (strcmp balikin 0)
        if (strcmp(temp->nama, nama) == 0) {
            printf("\nPesanan Ditemukan -> %s : %d item dengan total Rp%d\n", temp->nama, temp->jumlah, temp->total);
            return;
        }
        // Geser ke node berikutnya kalau belum ketemu
        temp = temp->next;
    }
    // keluar kalo ga nemu apa apa
    printf("\nData tidak ditemukan.\n");
}

void sedangDilayani(Node* head) {
    // Cek dulu, ada orangnya nggak di antrian
    if (head != NULL) {
        // Karena ini antrian, yang paling depan (head) yang dilayani duluan
        printf("\nPesanan yang sedang dilayani saat ini -> %s : %d item dengan total Rp%d\n", head->nama, head->jumlah, head->total);
    } else {
        // Kalau NULL berarti kosong melompong
        printf("\nTidak ada antrian.\n");
    }
}

void editData(Node* head, char nama[], int jumlahBaru) {
    // Mulai telusuri dari depan (head)
    Node* temp = head;
    
    // Cari terus sampai ketemu atau sampai antrian habis
    while (temp != NULL) {
        // Kalau nama yang diinput cocok sama yang ada di antrian
        if (strcmp(temp->nama, nama) == 0) {
            // Update jumlah pesanan sama hitung ulang total harganya
            temp->jumlah = jumlahBaru;
            temp->total = jumlahBaru * 12000;
            return; // Berhenti kalau sudah beres di-update
        }
        // Geser ke orang berikutnya
        temp = temp->next;
    }
}

void hapusAwal(Node** head, Node** tail) {
    // Kalau antrian kosong, ya nggak ada yang bisa dihapus
    if (*head == NULL) return;
    
    Node* temp = *head;
    
    // Kalau cuma ada satu orang di antrian
    if (*head == *tail) {
        // Set head sama tail ke NULL karena sekarang jadi kosong
        *head = *tail = NULL;
    } else {
        // Geser head ke orang berikutnya
        *head = (*head)->next;
        // Set prev-nya ke NULL karena dia sekarang jadi yang paling depan
        (*head)->prev = NULL;
    }
    free(temp);
}

void hapusAkhir(Node** head, Node** tail) {
    // Balik kalau antrian emang udah kosong
    if (*tail == NULL) return;
    
    Node* temp = *tail;
    // Kalau cuma ada satu orang di antrian
    if (*head == *tail) {
        *head = *tail = NULL;
    } else {
        // Geser tail ke orang sebelumnya
        *tail = (*tail)->prev;
        // Putus hubungan ke node yang mau dihapus
        (*tail)->next = NULL;
    }
    // Hapus memori biar nggak bocor
    free(temp);
}

void hapusNama(Node** head, Node** tail, char nama[]) {
    // Cari orangnya mulai dari depan
    Node* temp = *head;
    while (temp != NULL && strcmp(temp->nama, nama) != 0) {
        temp = temp->next;
    }
    
    // Kalau nggak ketemu, ya udah balik aja
    if (temp == NULL) return;
    
    // Kalau yang dihapus itu yang paling depan atau paling belakang
    if (temp == *head) hapusAwal(head, tail);
    else if (temp == *tail) hapusAkhir(head, tail);
    else {
        // Kalau di tengah, sambungin tetangga kiri dan kanannya
        temp->prev->next = temp->next; 
        temp->next->prev = temp->prev; 
        free(temp);
    }
}