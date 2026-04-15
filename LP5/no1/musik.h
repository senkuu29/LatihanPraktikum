// nama : deden ahmad jamil
// nim : 2501518

#ifndef MUSIK_H
#define MUSIK_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// struct Musik
typedef struct Musik {
  char judul[100];
  char Penyanyi[100];
  struct Musik *next;
  struct Musik *prev;
} Musik;

// untuk melacak lagu yang diputar 
extern Musik *current;

Musik* createNode(char judul[], char penyanyi[]);
void addSong(Musik **head, char judul[], char penyanyi[]);
void showPlaylist(Musik *head);
void searchByTitle(Musik *head, char target[]);
void searchByArtist(Musik *head, char target[]);
void playSong(Musik *head, char target[]);
void previousSong();
void nextSong();

#endif