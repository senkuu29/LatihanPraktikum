#include <stdio.h>

// adt internal dan termasuk struct
typedef struct
{
  int x;
  int y;
} Titik;

// Pakai tanda bintang (*) biar fungsinya bisa intip isi koordinat x dan y
int cekSikuSiku(Titik *A, Titik *B, Titik *C)
{
  int D1, D2, D3;

  D1 = ((B->x - A->x) * (B->x - A->x)) + ((B->y - A->y) * (B->y - A->y));
  D2 = ((C->x - B->x) * (C->x - B->x)) + ((C->y - B->y) * (C->y - B->y));
  D3 = ((C->x - A->x) * (C->x - A->x)) + ((C->y - A->y) * (C->y - A->y));

  if ((D1 + D2 == D3) || (D1 + D3 == D2) || (D2 + D3 == D1))
  {
    return 1; // Mengembalikan 1 jika siku-siku
  }
  else
  {
    return 0; // Mengembalikan 0 jika bukan siku-siku
  }
}

int main()
{
  Titik A, B, C;

  Titik *pA = &A;
  Titik *pB = &B;
  Titik *pC = &C;

  int status;

  printf("Titik A : ");
  scanf("%d %d", &pA->x, &pA->y);
  printf("Titik B : ");
  scanf("%d %d", &pB->x, &pB->y);
  printf("Titik C : ");
  scanf("%d %d", &pC->x, &pC->y);

  status = cekSikuSiku(&A, &B, &C);

  printf("\nOutput:\n");
  if (status == 1)
  {
    printf("Segitiga tersebut adalah Segitiga siku-siku\n");
  }
  else
  {
    printf("Segitiga tersebut BUKAN Segitiga siku-siku\n");
  }
  return 0;
}