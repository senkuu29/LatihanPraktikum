// nama : deden ahmad jamil
// nim : 2501518

#include <stdio.h>
#include <string.h>

#define MAX 100 // inisialisasi batas max

// struktur stack
typedef struct {
    char data[MAX];
    int top;
} Stack;

// inisialisasi stack biar gak random isinya
void init(Stack *s) {
  s->top = -1; // Top -1 artinya stack masih kosong melompong
}

// fungsi ngecek stack kosong atau nggak
int isEmpty(Stack *s) {
  return s->top == -1; // kalau top masih -1 berarti kosong
}

// fungsi buat masukin kurung ke stack
void push(Stack *s, char c) {
    if (s->top < MAX - 1) {
      s->top++;
      s->data[s->top] = c; // masukin karakter ke puncak
    }
}

// fungsi buat ngeluarin kurung dari stack
char pop(Stack *s) {
    if (!isEmpty(s)) {
      return s->data[s->top--]; // Ambil datanya terus topnya turun
    }
    return '\0'; 
}
