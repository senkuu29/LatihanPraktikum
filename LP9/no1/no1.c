// nama: Deden Ahmad Jamil
// nim: 2501518

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 5

// struct nya
typedef struct Musik {
    char judulLagu[MAX][50];
    int head;
    int tail;
} Queue;

// inisiasi head dan tailnya = -1 sama aja kayak kosong
void initQueue(Queue *Q){
    Q->head = -1;
    Q->tail = -1;
}

// fungsi memeriksa apakah queue kosong
int isEmpty(Queue *Q){
    if (Q->head == -1 && Q->tail == -1){
        return 1;
    }else{
        return 0;
    }
}

// fungsi untuk mengecek apakah queue full atau tidak
int isFull(Queue *Q){
    if ((Q->tail + 1) % MAX == Q->head){
        return 1;
    } else{
        return 0;
    }
}

// prosedur enqueue: memasukan elemen ke antrean melingkar
void enqueue(Queue *Q, char data[]){
    if (isFull(Q)){
        printf("Antrean penuh! %s ditolak.\n", data);
    } else {
        if (Q->head == -1){
            Q->head = 0;
        }
        Q->tail = (Q->tail + 1) % MAX;
        strcpy(Q->judulLagu[Q->tail], data);
    }
}

// prosedur dequeue: mengeluarkan elemen dari antrean melingkar
void dequeue(char teks[], Queue *Q){
    if (isEmpty(Q)){
        printf("Antrean kosong!\n");
    } else {
        char remove[50];
        strcpy(remove, Q->judulLagu[Q->head]);

        if (Q->head == Q->tail){
            Q->head = -1;
            Q->tail = -1;
        } else {
            Q->head = (Q->head + 1) % MAX;
        }
        printf("%s %s\n", teks, remove);
    }
}

// prosedur displayqueue: untuk menampilkan data elemen yang ada 
void displayQueue(Queue *Q){
    if (isEmpty(Q)){
        printf("Queue kosong\n");
    } else {
        int i = Q->head;
        printf("\n");
        while (1){
            printf("Berhasil menambahkan: %s\n", Q->judulLagu[i]);
            if (i == Q->tail) break;
            i = (i + 1) % MAX;
        }
        printf("\n");
    }
}

int main(){
    Queue myQueue;
    initQueue(&myQueue);

    // deklarasi variabel yng dibutuhkan
    int berapa;
    char lagu[50];

    printf("Input jumlah lagu: ");
    scanf("%d", &berapa);
    getchar(); //menghapus buffer

    // perulangan untuk memasukan judul lagu
    for(int i = 0; i < berapa; i++){
        printf("Masukkan lagu ke-%d: ", i+1);
        scanf(" %[^\n]", lagu);

        enqueue(&myQueue, lagu);
    }

    // menampilkan isi queue
    displayQueue(&myQueue);
    
    // menghapus queue
    dequeue("Memutar lagu: ", &myQueue);
    dequeue("Lagu berikutnya: ", &myQueue);

    return 0;
}