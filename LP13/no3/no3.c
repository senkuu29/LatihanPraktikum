//  nama : deden ahmad jamil
// nim : 2501518

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 3

// struct
typedef struct Node {
    char kode[4];// tiga hurup dan satu karakter null
    struct Node* next;
} Node;

//hash dari jumlah nilai ascii hurufnya
int hash(char *kata) {
    int sum = 0;
    
    // tambahin nilai ascii tiap huruf satu per satu dari awal ke akhir
    for (int i = 0; kata[i] != '\0'; i++) {
        sum += (int)kata[i];
    }
    
    return sum % 3; // total ascii di-modulo 3
}

// masukin teks ke dalam hash table
void insert(Node** hashTable, char *kata) {
    int index = hash(kata); // cari posisi lacinya
    
    // pesam node
    Node* newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->kode, kata);
    newNode->next = NULL; // buntutnya kasih null
    
    // kalau lacinya masih kosong, langsung tempatin aja
    if (hashTable[index] == NULL) {
        hashTable[index] = newNode;
    } else {
        // kalau bentrok, telusuri sampai nemu ujung antrean
        Node* temp = hashTable[index];
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode; // kaitin data baru di ujung antrean
    }
}

void display(Node** hashTable) {
    for (int i = 0; i < SIZE; i++) {
      printf("Indeks %d: ", i);
      
      Node* curr = hashTable[i];
      
      // telusurin isi lacinya kloo memang ada datnya
      while (curr != NULL) {
          printf("%s -> ", curr->kode);
          curr = curr->next;// geser ke gerbong sebelah
      }
      printf("NULL\n");
    }
}

int main() {
    // siapin 3 laci kosong dari awal
    Node* hashTable[SIZE] = {NULL};
    
    char inputKode[4]; // wadah 3 huruf + 1 null
    
    // 3 kali
    for (int i = 0; i < 3; i++) {
        scanf("%s", inputKode);
        insert(hashTable, inputKode);
    }
    printf("\nOutput:\n");
    display(hashTable);
    
    return 0;
}