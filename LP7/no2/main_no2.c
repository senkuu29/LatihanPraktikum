// nama: deden ahmad jamil
// nim: 2501518

#include "header_no2.h"

int main() {
    Stack tumpukan;
    init(&tumpukan);
    
    char kalimat[MAX];
    printf("Masukkan kalimat: ");
    scanf("%[^\n]s", kalimat);

    printf("Kalimat setelah dibalik: ");

    // loop buat baca kalimat huruf demi huruf dari kiri
    for (int i = 0; i <= strlen(kalimat); i++) {
        // kalau belum ketemu spasi dan belum akhir kalimat push terus
        if (kalimat[i] != ' ' && kalimat[i] != '\0') {
          push(&tumpukan, kalimat[i]);
        } 
        // kalau ketemu spasi atau akhir kalimat waktunya kita balikin katanya pop
        else {
            while (!isEmpty(&tumpukan)) {
              printf("%c", pop(&tumpukan));
            }
            if (kalimat[i] == ' ') {
                printf(" "); // tambah spasi lagi biar antar kata gak nempel
            }
        }
    }
    printf("\n");

    return 0;
}