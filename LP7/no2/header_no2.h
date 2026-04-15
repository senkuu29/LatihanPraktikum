// nama : deden ahmad jamil
// nim : 2501518

#include <stdio.h>
#include <string.h>

#define MAX 100 // batas maksimal

// struktur stack buat nampung huruf tiap kata
typedef struct {
  char data[MAX];
  int top;
} Stack;

// inisialisasi stack biar siap dipake
void init(Stack *s) {
  s->top = -1; // -1 artinya stack masih kosong melompong
}

// fungsi ngecek stack kosong atau nggak
int isEmpty(Stack *s) {
  return s->top == -1; // Kalau top -1 berarti gak ada isinya
}

// Masukin huruf ke stack
void push(Stack *s, char c) {
    if (s->top < MAX - 1) { // cek dulu jangan sampe penuh
      s->top++;
      s->data[s->top] = c; // huruf masuk ke tumpukan
    }
}

// ngeluarin huruf dari stack
char pop(Stack *s) {
  if (!isEmpty(s)) { // cek jangan sampe kosong
    return s->data[s->top--]; // Ambil datanya terus topnya turun
  }
  return '\0';
}