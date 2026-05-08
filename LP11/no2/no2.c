// nama : deden ahmad jamil
// nim : 2501518

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// struct atau adt nya
typedef struct tree {
    char name[100];
    int childCount;
    int depth;
    int totalMembers;
    struct tree* child;
    struct tree* sibling;
}Ntree;

// fungsi untuk membuat node baru
Ntree* createNode(const char* name, int depth) {
    Ntree* newNode = (Ntree*)malloc(sizeof(Ntree));

    strcpy(newNode->name, name);
    newNode->childCount = 0;
    newNode->depth = depth;
    newNode->totalMembers = 0;
    newNode->child = NULL;
    newNode->sibling = NULL;

    return newNode;
}

// fungsi pencarian
Ntree* searchNode(Ntree* root, const char* targetName) {
    if (root == NULL) return NULL; // ck apakah tree kosong
    if (strcmp(root->name, targetName) == 0) return root;

    // pencarian ke arah anak pertama
    Ntree* found = searchNode(root->child, targetName);
    if (found != NULL) return found; // kalo pencarian di anak berhasil

    // pencarian ke arah saudara berikutnya
    return searchNode(root->sibling, targetName);
}

// prosedur Insert node
void insertNodeByName(Ntree* root, const char* parentName, const char* newNodeName) {
    Ntree* parent = searchNode(root, parentName);
    if (parent == NULL) {
        printf("Parent '%s' tidak ditemukan!\n", parentName);
        return;
    }

    // buat node baru dengan kedalaman  depth parent + 1
    Ntree* newNode = createNode(newNodeName, parent->depth + 1);

    if (parent->child == NULL) {
        parent->child = newNode; // hubungkan parent ke anak pertama
    } else {
        Ntree* temp = parent->child;
        while (temp->sibling != NULL) { // perulangan akan terus berlanjut smape kosong
            temp = temp->sibling;
        }
        temp->sibling = newNode; // hubungkan di anak terakhir
    }
    parent->childCount++;
}

// hitung total anggota 
int updateAllMembers(Ntree* root) {
    if (root == NULL) return 0;

    int childrenSum = 0;
    Ntree* temp = root->child;
    
    // itung semua anak
    while (temp != NULL) {
        childrenSum += updateAllMembers(temp);
        temp = temp->sibling;
    }

    // stiap node dihitung sebagai 1 anggota
    if (root->child == NULL) {
        root->totalMembers = 1;
    } else {
        root->totalMembers = childrenSum;
    }

    return root->totalMembers;
}

// fungsi untuk menghapus memori satu node beserta anaknya
void freeNodeAndChildren(Ntree* root) {
    if (root == NULL) return;
    Ntree* temp = root->child;
    while (temp != NULL) {
        Ntree* next = temp->sibling;
        freeNodeAndChildren(temp);
        temp = next;
    }
    free(root);
}

// delete node beserta seluruh subtree-nya berdasarkan nama
Ntree* deleteSubtreeByName(Ntree* root, const char* targetName) {
    if (root == NULL) return NULL; // cekk kondisi apakah root kosong

    //validasi kasus khusus jika yang dihapus adalah root utamanya
    if (strcmp(root->name, targetName) == 0) {
        freeNodeAndChildren(root);
        return NULL;
    }

    Ntree* parent = root;
    Ntree* curr = parent->child;
    Ntree* prev = NULL;

    // cari node di dalam list anak
    while (curr != NULL && strcmp(curr->name, targetName) != 0) {
        prev = curr;
        curr = curr->sibling;
    }

    if (curr != NULL) {
        // kalo node target adalah anak pertama
        if (prev == NULL) {
            parent->child = curr->sibling;
        } else {
            // kalo node target adalah saudara dari node lain
            prev->sibling = curr->sibling;
        }
        
        curr->sibling = NULL; // putuskan koneksi sibling
        freeNodeAndChildren(curr); // hapus seluruh memori node dan anak
        parent->childCount--;
        return parent;
    }

    // crii di anak pertama
    deleteSubtreeByName(parent->child, targetName);
    // crii di saudara berikutnya
    deleteSubtreeByName(parent->sibling, targetName);
    
    return root;
}

// cari node dan tampilkan
bool searchAndPrintPath(Ntree* root, const char* targetName, char path[][100], int level) {
    if (root == NULL) return false;

    // smpan nama node saat ini ke dalam
    strcpy(path[level], root->name);

    // kalo ketemu, cetak seluruh dari level 0 
    if (strcmp(root->name, targetName) == 0) {
        printf("[FOUND] \"%s\"\n\tJalur: ", targetName);
        for (int i = 0; i <= level; i++) {
            printf("%s", path[i]);
            if (i < level) printf(" -> ");
        }
        printf("\n");
        return true;
    }

    // level path bertambah
    if (searchAndPrintPath(root->child, targetName, path, level + 1)) return true;

    //level path tetap karena parentnya sama
    if (searchAndPrintPath(root->sibling, targetName, path, level)) return true;

    return false;
}

// print tree
void printTree(Ntree* root, int isLast[], int depth) {
    if (root == NULL) return;

    for (int i = 0; i < depth; i++) {
        if (i == depth - 1) {
            if (isLast[i]) printf("\\-- ");
            else printf("|-- ");
        } else {
            if (isLast[i]) printf("    ");
            else printf("|   ");
        }
    }

    //detail
    printf("[D:%d] %-30s (anak:%d | anggota:%d)\n", root->depth, root->name, root->childCount, root->totalMembers);

    Ntree* temp = root->child;
    while (temp != NULL) {
        // untuk garis \-- atau |--
        isLast[depth] = (temp->sibling == NULL);
        printTree(temp, isLast, depth + 1);
        temp = temp->sibling;
    }
}

int main() {
    // inisialisasi root
    Ntree* root = createNode("UPI", 0);

    // cabang 1 BEM Rema
    insertNodeByName(root, "UPI", "BEM Rema UPI");
    insertNodeByName(root, "BEM Rema UPI", "Departemen Akademik");
    insertNodeByName(root, "Departemen Akademik", "Divisi Beasiswa");
    insertNodeByName(root, "Departemen Akademik", "Divisi PKM");
    
    // cbang 2 Senat  Robotika
    insertNodeByName(root, "UPI", "Senat Mahasiswa");
    insertNodeByName(root, "Senat Mahasiswa", "HIMA FPMIPA");
    insertNodeByName(root, "HIMA FPMIPA", "Prodi Komputer");
    insertNodeByName(root, "Prodi Komputer", "Tim Robotika");

    updateAllMembers(root);

    printf("\n");
    int isLast[100] = {0};
    printTree(root, isLast, 0);

    printf("\n");
    char path[100][100];
    searchAndPrintPath(root, "Tim Robotika", path, 0);

    return 0;
}