// nama: Deden Ahmad Jamil
// nim: 2501518

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 5

// struct nya
typedef struct Tiket {
    char nama[MAX][50];
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

// fungsi peek: untuk melihat data paling awal
char* peek(Queue *Q){
    if (Q->head == -1){
        printf("Queue Kosong!\n");
        return NULL;
    }
    return Q->nama[Q->head];
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
        strcpy(Q->nama[Q->tail], data);
    }
}

// prosedur dequeue: mengeluarkan elemen dari antrean melingkar
void dequeue(char teks[], Queue *Q){
    if (isEmpty(Q)){
        printf("Antrean kosong!\n");
    } else {
        char remove[50];
        strcpy(remove, Q->nama[Q->head]);

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
        printf("Daftar Antrian saat ini: ");
        while (1){
            printf("%s ", Q->nama[i]);
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

    printf("Input jumlah pembeli: ");
    scanf("%d", &berapa);
    getchar(); //menghapus buffer

    // perulangan untuk memasukan judul lagu
    for(int i = 0; i < berapa; i++){
        printf("Masukkan nama ke-%d: ", i+1);
        scanf(" %[^\n]", lagu);

        enqueue(&myQueue, lagu);
    }

    printf("\n--- Kondisi Awal ---\n");
    // menampilkan isi queue
    displayQueue(&myQueue);
    
    printf("\n--- Proses Loket ---\n");
    dequeue("Melayani pembeli:",&myQueue); //mengeluarkan
    
    printf("\n--- Kondisi Terbaru ---\n");
    // menampilkan isi queue
    displayQueue(&myQueue);

    // mengeluarkan 
    dequeue("Antrean berikutnya:",&myQueue);

    return 0;
}