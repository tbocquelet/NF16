//
//  td9.h
//  TD-9
//


#ifndef __TD_9__td9__
#define __TD_9__td9__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 500
#define k 200

#endif /* defined(__TD_9__td9__) */

// Exercice 1

typedef struct arbre{
    int nb_noeuds;
    int vecteurPeres[MAX];
    int valeurs[MAX];
} arbre;

// Exercice 2

int pere (int noeud, arbre *a);

// Exercice 5

    // pour k connu

typedef struct arbre_k{
    struct arbre_k *pere;
    struct arbre_k *fils[k];
    int valeur;
}arbre_k;

    // pour k inconnu

typedef struct arbre_kk{
    struct arbre_kk *pere;
    struct arbre_kk *fils_aine;
    struct arbre_kk *frere_droit;
    int valeur;
}arbre_kk;

// Exercice 6

arbre_kk *creer_Cellule(int valeur);