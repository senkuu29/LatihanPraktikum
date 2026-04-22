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

int cariRute(Tree *root, int target) {
  // kalau kosong → gak ada
  if (root == NULL) {
    printf("PENCURI TIDAK ADA DI SINI!\n");
    return 0;
  }

  // kalau ketemu
  if (target == root->data) {
    printf("PENCURI KETEMU!\n");
    return 1;
  }

  // kalau ke kiri
  if (target < root->data) {
    printf("KIRI - ");
    return cariRute(root->left, target);
  }else {
    // kalau ke kanan
    printf("KANAN - ");
    return cariRute(root->right, target);
  }
}

int main(){
  // root awal kosong
  Tree *root = NULL;

  // data yang bakalan dimasukin ke bst nya
  int data[] = {50, 30, 70, 20, 40, 60, 80};
  // hitung jumlah elemen di array data
  int n = sizeof(data)/sizeof(data[0]);

  // loop buat masukin datanya satu satu
  for (int i = 0; i < n; i++) {
    insert(&root, data[i]);
  }

  int target;
  printf("Target: ");
  scanf("%d", &target);
  printf("Rute: ");
  cariRute(root, target);

  return 0;
}