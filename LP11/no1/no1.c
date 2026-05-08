// nama : deden ahmad jamil
// nim : 2501518

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// struct atau adt
typedef struct tree {
  char name[100];
  int childCount; // buat ngihitung jumlah anak
  struct tree* child;
  struct tree* sibling;
} Ntree;

// fungsi untuk membuat node baru
Ntree* createTree(const char* folderName) {
  Ntree* newNode = (Ntree*)malloc(sizeof(Ntree));
  strcpy(newNode->name, folderName);

  newNode->childCount = 0; // awalnya belum punya anak

  newNode->child = NULL;
  newNode->sibling = NULL;
  
  return newNode;
}

// prosedur untuk menambahkan anak
void addChild(Ntree* parent, Ntree* newNode) {
  if (parent == NULL || newNode == NULL) return; // batalin kalo kosong

  // kalo belum punya anak hubungkan parent->child ke newnode
  if (parent->child == NULL) {
    parent->child = newNode;
  } else {
    // kalo sudah ada anak cari antrean saudara terakhir
    Ntree* temp = parent->child;
    while (temp->sibling != NULL) {
      temp = temp->sibling;
    }
    temp->sibling = newNode; // hubungkan di saudara terakhir
  }
  
  parent->childCount++;
}

// prosedur print
void printTree(Ntree* root, int kedalaman) {
  if (root == NULL) return;

  // untuk nyetak spasinya
  for (int i = 0; i < kedalaman; i++) {
    printf("  "); 
  }

  // cetak nama folder
  printf("- %s\n", root->name);

  printTree(root->child, kedalaman + 1);
  printTree(root->sibling, kedalaman);
}

int main() {
  // membuat node root
  Ntree* root = createTree("Folder Utama");

  // membuat node ssemester
  Ntree* sem1 = createTree("Semester 1");
  Ntree* sem2 = createTree("Semester 2");

  addChild(root, sem1);
  addChild(root, sem2);

  // mngisi smester 1
  Ntree* alpro = createTree("Algoritma Pemrograman");
  Ntree* kalkulus = createTree("Kalkulus");
  
  addChild(sem1, alpro);
  addChild(sem1, kalkulus);
  
  // mngisi smester 2
  Ntree* strukdat = createTree("Struktur Data");
  addChild(sem2, strukdat);

  // mngisi subfolder
  Ntree* tree = createTree("Tree");
  Ntree* ntree = createTree("N-Tree");

  addChild(strukdat, tree);
  addChild(strukdat, ntree);

  printf("Struktur Folder:\n");
  printTree(root, 0);

  return 0;
}