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

// pabrik node
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

void inorder(Tree *t){
  if (t == NULL) return;
  inorder(t->left);         //kiri
  printf("%d ", t->data);   //root
  inorder(t->right);        //kanan
}

void preorder(Tree *t){
  if (t == NULL) return;
  printf("%d ", t->data);   //root
  preorder(t->left);        //kiri
  preorder(t->right);       //kanan
}

void postorder(Tree *t){
  if (t == NULL) return;
  postorder(t->left);       //krii
  postorder(t->right);      //kanan
  printf("%d ", t->data);   //root
}

int main(){
  // deklarasi variabel yang di butuhkan

  int jmlBuku;          //variabel untuk loop
  Tree* root = NULL;    // root ini untuk varibel julukan
  int data;             // intuk nampung datanya
  
  printf("=== Sistem Perpustakaan Digital ===\n");
  printf("Masukkan jumlah buku yang ingin didaftarkan: ");
  scanf(" %d", &jmlBuku);
  for (int i = 0; i < jmlBuku; i++)
  {
    printf("Masukkan ID buku ke-%d: ", i+1);
    scanf(" %d", &data);
    insert(&root, data);    // datanya di masukan pake fungsi insert
  }

  printf("\n--- Hasil Traversal BST ---\n");
  printf("Kunjungan Preorder : ");
  preorder(root);
  printf("\n");
  printf("Kunjungan Inorder : ");
  inorder(root);
  printf("\n");
  printf("Kunjungan Postorder: ");
  postorder(root);
  printf("\n");

  return 0;
}