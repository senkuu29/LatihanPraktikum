// nama : deden ahmad jamil
// nim : 2501518

#include <stdio.h>
#include <stdlib.h>

// struct tree atau adt tree
typedef struct Tree {
  int data;
  struct Tree *left;
  struct Tree *right;
} Tree;

Tree* createNode (int data){
  // penasn node dengan malloc
  Tree *baru = (Tree*) malloc(sizeof(Tree));
  // isi datanya
  baru->data = data;
  baru->left = NULL;
  baru->right = NULL;
  return baru;
}


void insert(Tree **t, int data){
  // jika posisi saat ini kosong (NULL), buat simpul baru
  if((*t) == NULL){
    (*t) = createNode(data);
  }
  // jika data baru lebih kecil atau sama dengan data simpul saat ini, arahkan ke cabang kiri (rekusif)
  else if(data <= (*t)->data){
    insert(&((*t)->left), data);
  }
  // jika data baru lebih besar dari data saat ini arahkan ke cabang knaan (rekusif)
  else{
    insert(&((*t)->right), data);
  }
}

int search(Tree *root, int target) {
  // kalau node kosong → berarti udah mentok, data gak ada
  if (root == NULL) return 0;

  // kalau data ketemu → langsung return 1 (true)
  if (target == root->data) return 1;

  // kalau target lebih kecil → cari ke kiri
  if (target < root->data) {
    return search(root->left, target);
  }else { 
    // kalau target lebih besar → cari ke kanan
    return search(root->right, target);
  }
}

int main(){
  Tree *root = NULL;

  // data awal BST
  int data[] = {30, 23, 40, 13, 25, 33, 44};
  int n = sizeof(data)/sizeof(data[0]);

  for (int i = 0; i < n; i++) {
    insert(&root, data[i]);
  }

  int input;
  scanf("%d", &input);

  // cek
  if (search(root, input) && input == 33) {
    printf("Pedang ditemukan!!!\n");
  } else {
    printf("Pedang tidak ditemukan!!\n");
  }

  return 0;

}