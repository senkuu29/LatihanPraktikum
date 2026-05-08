// nama : deden ahmad jamil
// nim : 2501518

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//adtnya
typedef struct Edge {
  int destinationID;
  int kapasitas;
  struct Edge* nextEdge;
} Edge;

// ini buat nyimpen data lokasi node/vertex
typedef struct Node {
  int id;
  char nama[50];
  int riskLevel;
  int visited; 
  Edge* headEdge;
  struct Node* next;
} Node;

// bungkus utama buat grafnya
typedef struct {
  Node* first;
} Graf;

// create node
Node* createNode(int id, char nama[], int risk) {
  // pesan node
    Node* newNode = (Node*)malloc(sizeof(Node));
  // isi datanya
    newNode->id = id;
    strcpy(newNode->nama, nama);
    newNode->riskLevel = risk;
    newNode->visited = 0;
    newNode->headEdge = NULL;
    newNode->next = NULL;
  
    return newNode;
}

// masukin node baru ke dalam list graf
void addNode(Graf* g, int id, char nama[], int risk) {
  Node* newNode = createNode(id, nama, risk);
  if (g->first == NULL) {
    g->first = newNode;
  } else {
    // Kalau sudah ada isinya, taruh di paling belakang
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
    //kaloo ga ketemu
    return NULL; 
}

// nambahin jlur antar node edge
void addEdge(Graf* g, int startID, int destID, int kap) {
    Node* startNode = searchNode(g, startID);
    if (startNode == NULL) return;

    // pake konsep insert first buat edge nya
    Edge* newEdge = (Edge*)malloc(sizeof(Edge));
    newEdge->destinationID = destID;
    newEdge->kapasitas = kap;
    newEdge->nextEdge = startNode->headEdge;
    startNode->headEdge = newEdge;
}

// print atau cetak
void printGraf(Graf* g) {
    Node* tempNode = g->first;
    printf("\n=== Graf Jaringan Distribusi ===\n");
    while (tempNode != NULL) {
      printf("[%d] %s (Risk: %d)\n", tempNode->id, tempNode->nama, tempNode->riskLevel);
      Edge* tempEdge = tempNode->headEdge;
        while (tempEdge != NULL) {
          Node* dest = searchNode(g, tempEdge->destinationID);
          if (dest != NULL) {
            printf("  -> [%d] %s (kapasitas: %d kg)\n", dest->id, dest->nama, tempEdge->kapasitas);
          }
          tempEdge = tempEdge->nextEdge;
        }
      tempNode = tempNode->next;
    }
}

// hapus edge dari node ke node lain
void deleteEdge(Graf* g, int startID, int destID) {
    Node* startNode = searchNode(g, startID);
    if (startNode == NULL) return;

    Edge *curr = startNode->headEdge, *prev = NULL;
    while (curr != NULL && curr->destinationID != destID) {
      prev = curr;
      curr = curr->nextEdge;
    }
    if (curr != NULL) {
      if (prev == NULL) startNode->headEdge = curr->nextEdge;
      else prev->nextEdge = curr->nextEdge;
      free(curr);
      printf("\n[Sistem] Edge dari %d ke %d berhasil dihapus.\n", startID, destID);
    }
}

// hpus node dan bersihin semua jalur yang nyambungnya
void deleteNode(Graf *g, int deleteID) {
    Node *delNode = searchNode(g, deleteID);
    if (delNode == NULL) {
      printf("\n[Sistem] Node %d tidak ditemukan.\n", deleteID);
      return;
    }

    // hpuss semua edge dari node lain yang mengarah ke delNode
    Node *currNode = g->first;
    while (currNode != NULL) {
      // lewati node yang emang mau dihapus
        if (currNode->id != deleteID) {
          Edge *cEdge = currNode->headEdge;
          Edge *pEdge = NULL;
          while (cEdge != NULL) {
            // klo ketemu jalur yang tujuannya si target hapus
            if (cEdge->destinationID == deleteID) {
              // ptus jlur sambungkan list sebelum ke setelahnya
              if (pEdge == NULL) currNode->headEdge = cEdge->nextEdge;
              else pEdge->nextEdge = cEdge->nextEdge;
              
              Edge *temp = cEdge;
              cEdge = cEdge->nextEdge;
              free(temp);
            } else {
              pEdge = cEdge;
              cEdge = cEdge->nextEdge;
            }
          }
        }
        // pindah ke node selanjutnya
      currNode = currNode->next;
    }

    // hapus edge yang keluar dari node ini
    Edge *currEdge = delNode->headEdge;
    while (currEdge != NULL) {
      // simpen alamat jlur skrng
      Edge *temp = currEdge;
      currEdge = currEdge->nextEdge;
      free(temp);
    }

    // lepas nde dari list utama graf biar ga dipanggil lagi
    if (g->first == delNode) {
      //klo node yang dihpus ada di paling depan geser headnya
      g->first = delNode->next;
    } else {
      // cri node sebelumnya trus sambungkan ke node setelahnya
      Node *prevNode = g->first;
      while (prevNode->next != delNode) prevNode = prevNode->next;
      prevNode->next = delNode->next;
    }

    free(delNode);
    printf("\n[Sistem] Lokasi ID %d dan semua koneksinya berhasil dihapus.\n", deleteID);
}

int main() {
    Graf g;
    g.first = NULL;

    // bikim node nya
    addNode(&g, 1, "Los Pollos Hermanos", 7);
    addNode(&g, 2, "Lavanderia Industrial", 9);
    addNode(&g, 3, "Casa de Walter White", 8);
    addNode(&g, 4, "Casa de Jesse Pinkman", 5);
    addNode(&g, 5, "Punto de Venta Norte", 4);
    addNode(&g, 6, "Deposito Secreto", 6);

    // nambahin edge
    addEdge(&g, 1, 2, 50);
    addEdge(&g, 1, 3, 30);
    addEdge(&g, 2, 4, 20);
    addEdge(&g, 3, 5, 40);
    addEdge(&g, 4, 5, 10);
    addEdge(&g, 5, 1, 15);
    addEdge(&g, 3, 6, 25);
    addEdge(&g, 6, 4, 5);
    printGraf(&g);

    // cari node
    int cariID = 3;
    printf("\n=== Mencari Node ID %d ===\n", cariID);
    Node* found = searchNode(&g, cariID);
    if(found) printf("Ditemukan: %s\n", found->nama);
    else printf("Tidak ditemukan.\n");

    //hapus edge
    deleteEdge(&g, 1, 3);
    printGraf(&g);

    // hapus node
    deleteNode(&g, 2);
    printGraf(&g);

    return 0;
}