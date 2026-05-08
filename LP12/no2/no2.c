// nama : deden ahmad jamil
// nim : 2501518

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// adt
typedef struct Edge {
  int destinationID;
  int kapasitas;
  struct Edge* nextEdge;
} Edge;

// struct node
typedef struct Node {
  int id;
  char nama[50];
  int riskLevel;
  int visited;
  Edge* headEdge;
  struct Node* next;
} Node;

// bungkus buat grap
typedef struct {
  Node* first;
} Graf;

// create node
Node* createNode(int id, char nama[], int risk) {
  // pesan node
    Node* newNode = (Node*)malloc(sizeof(Node));
    // isi node
    newNode->id = id;
    strcpy(newNode->nama, nama);
    newNode->riskLevel = risk;
    newNode->visited = 0;
    newNode->headEdge = NULL;
    newNode->next = NULL;

    return newNode;
}

// add node
void addNode(Graf* g, int id, char nama[], int risk) {
  // siapin node baru
    Node* newNode = createNode(id, nama, risk);
    // kalo kosng
    if (g->first == NULL) g->first = newNode;
    else {
      // kalo udah ada isinya
      Node* temp = g->first;
      while (temp->next != NULL) temp = temp->next;
      temp->next = newNode;
    }
}

// cari node sesuai dengan id
Node* searchNode(Graf* g, int id) {
  Node* temp = g->first;
  while (temp != NULL) {
      if (temp->id == id) return temp;
      temp = temp->next;
  }
  // kalo ga ketemu
  return NULL;
}

// nambahin jlur antar node edge
void addEdge(Graf* g, int startID, int destID, int kap) {
  // cri dulu lokasi asalnya ada atau nggak
    Node* startNode = searchNode(g, startID);
    if (startNode == NULL) return; //gada batalin

    // siapin memori buat jalur baru
    Edge* newEdge = (Edge*)malloc(sizeof(Edge));
    // isi data tujuan
    newEdge->destinationID = destID;
    newEdge->kapasitas = kap;

    // smbungkan jalur baru ke daftar jalur lokasi asal
    newEdge->nextEdge = startNode->headEdge;
    startNode->headEdge = newEdge;
}

// print cetak
void printGraf(Graf* g) {
    Node* tempNode = g->first;
    printf("\nGraf jaringan distribusi:\n");

    while (tempNode != NULL) {
        printf("[%d] %s (Risk:%d)\n", tempNode->id, tempNode->nama, tempNode->riskLevel);
        Edge* tempEdge = tempNode->headEdge;

        while (tempEdge != NULL) {
          Node* dest = searchNode(g, tempEdge->destinationID);
          if (dest != NULL) printf("  -> [%d] %s (kapasitas: %d kg)\n", dest->id, dest->nama, tempEdge->kapasitas);
          tempEdge = tempEdge->nextEdge;
        }
        tempNode = tempNode->next;
    }
}

// delete
void deleteEdge(Graf* g, int startID, int destID) {
  // cari lokasi asalnya
    Node* startNode = searchNode(g, startID);
    if (startNode == NULL) return;

    // varibel buat nyehapus
    Edge *curr = startNode->headEdge, *prev = NULL;
    // cari sampe id pas
    while (curr != NULL && curr->destinationID != destID) {
      prev = curr;
      curr = curr->nextEdge;
    }

    // proses hapus
    if (curr != NULL) {
    // kalo target ada di awal
      if (prev == NULL) startNode->headEdge = curr->nextEdge;
      // kalo di tengah atau akhir sambungin jlur sblum ke jlr sesudah
      else prev->nextEdge = curr->nextEdge;

      free(curr);
      printf("\n[Sistem] Edge dari %d ke %d dihapus.\n", startID, destID);
    }
}

// menghapus node beserta jalurnya
void deleteNode(Graf *g, int deleteID) {
  // cari node yang akan di hapus
    Node *delNode = searchNode(g, deleteID);
    if (delNode == NULL) return;
  
  // cek semua jalur ynag mengengarah ko node ini
    Node *currNode = g->first;
    while (currNode != NULL) {
      if (currNode->id != deleteID) {
        Edge *cEdge = currNode->headEdge, *pEdge = NULL;
        while (cEdge != NULL) {
          if (cEdge->destinationID == deleteID) {
            if (pEdge == NULL) currNode->headEdge = cEdge->nextEdge;
            else pEdge->nextEdge = cEdge->nextEdge;
            Edge *temp = cEdge; cEdge = cEdge->nextEdge; free(temp);
          }else { 
            pEdge = cEdge; cEdge = cEdge->nextEdge; 
          }
        }
      }
      currNode = currNode->next;
    }

  // hapus semua jalur milik node ini sendiri
    Edge *currEdge = delNode->headEdge;
    while (currEdge != NULL) { Edge *temp = currEdge; currEdge = currEdge->nextEdge; free(temp); }
    
    // lepas dari daftar ptus smbungan node dari utama grap
    if (g->first == delNode) g->first = delNode->next;
    else {
        Node *prevNode = g->first;
        while (prevNode->next != delNode) prevNode = prevNode->next;
        prevNode->next = delNode->next;
    }
    free(delNode);
    printf("Node %d dihapus.\n", deleteID);
}

// fungsi untuk meriset status kunjungan semua node jadi nol
void resetVisited(Graf *g) {
  // mlai dari node pertama di graf
    Node *temp = g->first;
    // telusuri semua node satu per satu sampai habis
    while (temp != NULL) { 
      temp->visited = 0; temp = temp->next; 
    }
}

// untuk menelusuri graf secara melebar
void BFS(Graf *g, int startID) {
  // cari titik awal
    Node *s = searchNode(g, startID);
    if (s == NULL) return;

  // siapkan atrean dan reset kunjungan
    Node *queue[100]; 
    int head = 0, tail = 0;
    resetVisited(g);

  // masukkan titik awal ke antrean dan tandai sudah dikunjungi
    queue[tail++] = s; 
    s->visited = 1;

    printf("\nHasil BFS: ");
    // selama antrean belum kosong lanjut
    while (head < tail) {
      // ambil lokasi dari depan antrean 
        Node *curr = queue[head++];
        printf("%s", curr->nama);
      
      // ck semua tetangga (jalur keluar) dari lokasi sekarang
        Edge *e = curr->headEdge;
        while (e != NULL) {
          Node *dest = searchNode(g, e->destinationID);
          if (dest != NULL && dest->visited == 0) { dest->visited = 1; queue[tail++] = dest; }
          e = e->nextEdge;
        }
        if (head < tail) 
        printf(" -> ");
    }
    printf("\n");
}

void processDFS(Graf *g, Node *n, int *isFirst) {
  // brhenti jika node kosong atau sudah pernah dikunjungi
    if (n == NULL || n->visited) return;

  // Ctak tanda panah  ->  jika ini bukan lokasi pertama yang dicetak
    if (!(*isFirst)) printf(" -> ");

  // cetak nama lokasi dan tandai sudah dikunjungi
    printf("%s", n->nama);
    n->visited = 1; 
    *isFirst = 0;

  // cek semua jalur yang keluar dari lokasi ini
    Edge *e = n->headEdge;
    while (e != NULL) {
      // Cari data node tujuan dari jalur tersebut
        Node *dest = searchNode(g, e->destinationID);
      
      // untuk masuk lebih dalam ke node tujuan
        processDFS(g, dest, isFirst);
      //geser ke jalur berikutnya milik node sekarang
        e = e->nextEdge;
    }
}

void DFS(Graf *g, int startID) {
  // Cari dulu lokasi awal berdasarkan id
    Node *s = searchNode(g, startID);
    // kalo lokasi ga ketumu langsung keluar
    if (s == NULL) return;

    // reset status kunjungan
    resetVisited(g);
    printf("\nHasil DFS: "); int isFirst = 1;
    processDFS(g, s, &isFirst);
    printf("\n");
}

int main() {
    Graf g; g.first = NULL;

    // buat node
    addNode(&g, 1, "Los Pollos Hermanos", 7);
    addNode(&g, 2, "Lavanderia Industrial", 9);
    addNode(&g, 3, "Casa de Walter White", 8);
    addNode(&g, 4, "Casa de Jesse Pinkman", 5);
    addNode(&g, 5, "Punto de Venta Norte", 4);
    addNode(&g, 6, "Deposito Secreto", 6);

    // sambungkan edge
    addEdge(&g, 1, 2, 50); addEdge(&g, 1, 3, 30);
    addEdge(&g, 2, 4, 20); addEdge(&g, 3, 5, 40);
    addEdge(&g, 4, 5, 10); addEdge(&g, 5, 1, 15);
    addEdge(&g, 3, 6, 25); addEdge(&g, 6, 4, 5);

    printGraf(&g);

    printf("\n--- Penelusuran Intelijen Jaringan ---");
    BFS(&g, 1);
    DFS(&g, 1);

    // hapus
    deleteEdge(&g, 1, 3);
    deleteNode(&g, 4);

    printf("\n--- Graf Setelah Penghapusan ---");
    printGraf(&g);

    return 0;
}