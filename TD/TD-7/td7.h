#ifndef __TD_7__td7__
#define __TD_7__td7__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#endif /* defined(__TD_7__td7__) */

// ex 1 et 2

/*
 typedef struct cellule {
    int nb;
    struct cellule *succ;
} cellule; 
 */

// ex1
void eratosthene(int n);

// ex2
void josephus(int n, int m);


// ex 3

typedef struct cellule {
    int nb;
    struct cellule *succ;
    struct cellule *pred;
} cellule;

typedef cellule *liste;

liste creerListe();
void ajouterEntete(liste l, int x);
void suppression(cellule *c);
void detruireListe(liste l);

// ex 4

typedef struct Pile {
    liste l;
    int nb;
} Pile;


Pile *creerPile();
void detruirePile(Pile* p);
void empiler(Pile *p, int x);
void depiler(Pile *p);
int sommet(Pile *p);
int taille(Pile *p);
int pileVide(Pile *p);

typedef struct File {
    liste l;
    int nb;
} File;


File *creerFile();
void detruireFile(File* f);
void empilerF(File *f, int x);
void depilerF(File *f);
int sommetF(File *f);
int tailleF(File *f);
int pileVideF(File *f);

// ex 5

int evalRPL(char *exp);
