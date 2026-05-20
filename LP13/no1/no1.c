// nama : deden ahmad jamil
// nim : 2501518

#include <stdio.h>
#include <stdlib.h>

#define M 10 // ukuran maks slot

// buat linked list
typedef struct Node {
    int resi;
    struct Node* next;
} Node;

// fungsihash
int hash(int k) {
    int a = 18;
    int b = 15;
    int p = 13;
    int m = M;  // ukuran maks
    
    return (((a * k) + b) % p) % m; //rumus hash
}

// insert data ke tabel
void insert(Node** hashTable, int nomorResi) {
    int index = hash(nomorResi); // cari nilai indeks di nomor resi
    
    //pesan node
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->resi = nomorResi;
    newNode->next = NULL;
    
    // kalo indeks masih kosong
    if (hashTable[index] == NULL) {
        hashTable[index] = newNode; // langsung isi slot kosong
    } else {
        Node* temp = hashTable[index];
        
        // perulangan mencari node paling ujung
        while (temp->next != NULL) {
            temp = temp->next;   // bergeser
        }
        temp->next = newNode;// gantungin node baru di paling akhir
    }
}

//cetak
void display(Node** hashTable) {
    // ngecek setiap slot indeks tabel
    for (int i = 0; i < M; i++) {
        Node* curr = hashTable[i]; // pointer penunjuk node aktif
        
        // perulangan menelusuri rantai linked list
        while (curr != NULL) {
            printf("%d disimpan pada indeks ke-%d\n", curr->resi, i);
            curr = curr->next;   // pindah ke data di belakangnya
        }
    }
}

int main() {
    // inisialisasi tabel mengosongkan seluruh slot
    Node* hashTable[M] = {NULL};
    
    int inputResi;
    
    // perulangan untuk menerima 3 kali input resi dari user
    for (int i = 0; i < 3; i++) {
        scanf("%d", &inputResi);      // data input resi
        insert(hashTable, inputResi); // untuk menyimpan ke tabel
    }
    
    display(hashTable);
    
    return 0;
}