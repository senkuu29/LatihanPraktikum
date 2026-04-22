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

// inorder
void inorder(Tree *root) {
  if (root != NULL) {
    inorder(root->left);
    printf("%c ", root->data);
    inorder(root->right);
  }
}

// preorder
void preorder(Tree *root) {
  if (root != NULL) {
    printf("%c ", root->data);
    preorder(root->left);
    preorder(root->right);
  }
}

Tree* search(Tree *root, char target) {
  // kalau kosong atau ketemu → balik
  if (root == NULL || root->data == target)
    return root;
  // kalau lebih kecil → kiri
  if (target < root->data) {
    return search(root->left, target);
  }else {
    // kalau lebih besar → kanan
    return search(root->right, target);
  }
}

void deleteTree(Tree *root) {
  if (root == NULL) return;   //kalo kosong balik

  deleteTree(root->left);   // hapus cabang kiri
  deleteTree(root->right);  // hapus cabang kanan
  free(root);
}

void deleteRightSubtree(Tree *node) {
  // kalo node kosong atau ga punya cabang kanan, balik
  if (node == NULL || node->right == NULL)
    return;
  // hapus cabang kanan
  deleteTree(node->right);
  node->right = NULL;
}

int main() {
  Tree *root = NULL;
  int n;

  printf("Jumlah data: ");
  scanf("%d", &n);

  char x;

  // input karakter
  printf("Masukkan %d karakter : ", n);
  for (int i = 0; i < n; i++) {
    scanf(" %c", &x);
    insert(&root, x);
  }

  printf("\nTree Awal (In-Order): ");
  inorder(root);

  printf("\nTree Awal (Pre-Order): ");
  preorder(root);

  char target;
  printf("\n\nMasukkan karakter target: ");
  scanf(" %c", &target);

  Tree *found = search(root, target);

  if (found == NULL) {
    printf("Karakter tidak ditemukan.\n");
  }else {
    printf("Karakter %c ditemukan.\n", target);

    if (found->right != NULL) {
      deleteRightSubtree(found);
      printf("Cabang kanan dari %c berhasil dihapus.\n", target);
    } else {
      printf("Tidak ada cabang kanan.\n");
    }
  }

  printf("\nTree Baru (Pre-Order): ");
  preorder(root);

  return 0;
}

