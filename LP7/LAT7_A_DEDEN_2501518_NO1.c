#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 5

typedef struct Stack
{
  int data[MAX_SIZE];
  int top;
}Stack;

// inisialisasi stack top -1 itu kosong
void initStack(Stack *s){
  s->top = -1;
}

// untuk mengecek apakah kosong
int isEmpty(Stack *s) {
  return(s->top == -1);
}

// untuk mengecek apakah penuh 
int isFull(Stack *s) {
  return(s->top == MAX_SIZE - 1);
}

// memasukan element ke stack
void push (Stack *s, int value) {
  if (isFull(s))
  {
    printf("ERROR: Stack Overlow! Stack sudah penuh.\n");
    return;
  }
  s->top++;
  s->data[s->top] = value;
  printf("PUSH: %d berhasil dimasukan ke stack.\n", value);
}

// untuk mengeluarkan elemen dari stack
int pop (Stack *s) {
  if (isEmpty(s))
  {
    printf("ERROR: Stack Underflow! Stack kosong .\n");
    return -1;
  }
  
  // simpen nilai toop di variabel sementara
  int removedValue = s->data[s->top];

  // untuk menghilangkan dari stack 
  s->top--;
  
  printf("POP: %d berhasil dikeluarkan dari Stack.\n", removedValue);

  // mengembalikan nilai yang di keluarkan
  return removedValue;
}

// untuk melihat element atas tanpa menghapus
int peek(Stack *s) {
  if (isEmpty(s))
  {
    printf("[INFO] stack kosong, tidak ada elemen.\n");
    return -1;
  }
  return s->data[s->top];
}

// tampilkan isi stack
void displayStack(Stack *s) {
  if (isEmpty(s))
  {
    printf("Stack: [ KOSONG ]\n");
    return;
  }
  printf("Stack (TOP -> BOTTOM): \n");
  for (int  i = s->top; i >= 0; i--)
  {
    printf("[%d] ", s->data[i]);
  }
  printf("\n");
}

int main(){
  Stack myStack;
  initStack(&myStack);

  printf("IsEmpty? %s\n", isEmpty(&myStack) ? "YA" : "TIDAK");
  displayStack(&myStack);

  printf("-- Melakukan PUSH ---\n");
  push(&myStack, 10);
  push(&myStack, 20);
  push(&myStack, 30);
  push(&myStack, 40);
  push(&myStack, 50);
  displayStack(&myStack);

  // cek apakah stack penuh
  printf("\nIsFull? %s \n", isFull(&myStack) ? "YA" : "TIDAK");
  
  // push saat penuh (test overlow)
  printf("\n -- test overlow --");
  push(&myStack, 99);

  // lihat element atas
  printf("\n peek (element teratas): %d\n", peek(&myStack));

  // melakukan pop
  printf("\n-- melakukan pop --");
  pop(&myStack);
  pop(&myStack);
  displayStack(&myStack);

  // pop semua element
  printf("\n -- test stack underflow --\n");
  pop(&myStack);

  printf("\nIsEmpty? %s\n", isEmpty(&myStack) ? "YA" : "TIDAK");

  return 0;
}

