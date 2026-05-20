// nama : deden ahmad jamil
// nim : 2501518

#include <stdio.h>
#include <stdlib.h>

#define SIZE 5

// struct node buat nyimpen data dan sambungannya
typedef struct Node {
    int id; // tempat nyimpen id barang
    struct Node* next;
} Node;

//hash
int hash(int k) {
    return (k * 3) % 5;
}

// fungsi masukin barang ke tabel
void insert(Node** hashTable, int idBarang) {
    int index = hash(idBarang); // hitung posisi laci atau indeksnya
    
    // siapin kotak baru di memori
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->id = idBarang;
    newNode->next = NULL;
    
    // kalau lacinya masih kosong, langsung tempatin aja
    if (hashTable[index] == NULL) {
        hashTable[index] = newNode;
    } else {
        // kalau udah ada isinya,cari antrean paling belakang
        Node* temp = hashTable[index];
        while (temp->next != NULL) {
          temp = temp->next;  // geser terus sampe ketemu yang terakhir
        }
        temp->next = newNode;   // kaitin data baru di paling belakang
    }
}

// fungsi buat nampilin isi tabel
void display(Node** hashTable) {
    // cek laci dari 0 sampe 4
    for (int i = 0; i < SIZE; i++) {
        printf("Indeks %d: ", i);
        
        Node* curr = hashTable[i];
        
        // kalau ada isinya, cari satu-satu
        while (curr != NULL) {
            printf("%d -> ", curr->id);
            curr = curr->next;// lanjut ke gerbong sebelah
        }
        printf("NULL\n");
    }
}

int main() {
    // siapin 5 laci kosong
    Node* hashTable[SIZE] = {NULL};
    
    int inputID;
    
    // 4 buah input,bikin perulangannya
    for (int i = 0; i < 4; i++) {
      scanf("%d", &inputID);
      insert(hashTable, inputID); // masukin ke tabel
    }
    
    printf("\nOutput:\n");
    display(hashTable);
    
    return 0;
}