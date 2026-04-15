// nama : deden ahmad jamil
// nim : 2501518

#include "header.h"

int main() {
    Stack tumpukan;
    init(&tumpukan);
    
    char ekspresi[MAX];
    int seimbang = 1; // kita asumsiin bener dulu di awal

    printf("Masukkan ekspresi: ");
    scanf("%[^\n]s", ekspresi);

    // loop buat ngecek setiap karakter dari kiri ke kanan
    for (int i = 0; i < strlen(ekspresi); i++) {
      // kalau ketemu kurung buka, langsung masukin (Push)
      if (ekspresi[i] == '(') {
        push(&tumpukan, '(');
      } 
        // kalau ketemu kurung tutup, kita keluarin pasangannya (Pop)
      else if (ekspresi[i] == ')') {
        if (isEmpty(&tumpukan)) {
          seimbang = 0; // ada tutup tapi gak ada bukanya artinya ga seimbang
          break;
        }
        pop(&tumpukan);
      }
    }

    // di akhir stack harus kosong biar bisa dibilang seimbang
    if (seimbang && isEmpty(&tumpukan)) {
        printf("Kurung seimbang.\n");
    } else {
        printf("Kurung tidak seimbang.\n");
    }

    return 0;
}