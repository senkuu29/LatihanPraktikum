// nama: deden ahmad jamil
// nim : 2501518

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include "musik.c"

int main(){
  Musik *head = NULL;

  // deklarasi variabel
  int pilihan;
  char sub;
  char judul[50], penyanyi[50];

  // fitur"nya
  printf("\nWhat do you want to do today\n");
  printf("1. Add Song\n");
  printf("2. Search Song\n");
  printf("3. Show Playlish\n");
  printf("4. Play Song\n");
  printf("5. Previous Song\n");
  printf("6. Next Song\n");
  printf("0. Keluar\n");
  do
  {
    printf("\nPilih menu: ");
    scanf(" %d", &pilihan);

    switch (pilihan)
    {
    case 1:
      // input data
      printf("Judul lagu: ");
      scanf(" %[^\n]s", judul);
      
      printf("Penyanyi lagu: ");
      scanf(" %[^\n]s", penyanyi);
      
      addSong(&head, judul, penyanyi);
      break;
    case 2:
        // pilih sub search
        printf("a. By title\n");
        printf("b. By artist\n");

        printf("Pilih: ");
        scanf(" %c", &sub);
        
        // serch by title
        if (sub == 'a')
        {
            printf("Masukkan judul: ");
            scanf(" %[^\n]s", judul);
            searchByTitle(head, judul);
        }else if (sub == 'b') //serch by artist
        {
            printf("Masukkan penyanyi: ");
            scanf(" %[^\n]s", penyanyi);
            searchByArtist(head, penyanyi);
        }
      break;
    case 3:
      showPlaylist(head);  // fitur melihat semua data
      break;
    case 4:
        printf("Masukkan judul lagu yang ingin diputar: ");
        scanf(" %[^\n]s", judul);
        playSong(head, judul);  // untuk memutar lagu
        break;
      break;
    case 5:
        previousSong(); // untuk mundur satu langkah
        break;
      break;
    case 6:
        nextSong();  // untuk maju satu langkah
      break;
    case 0:
      printf("keluar..\n");
      break;
    default:
      printf("Pilihlah sesuai dengan nomor yang ada (0-6)\n");
      break;
    }
  } while (pilihan != 0);
}