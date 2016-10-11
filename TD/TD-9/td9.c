//
//  td9.c
//  TD-9
//


#include "td9.h"

// Exercice 2

int pere (int noeud, arbre *a)
{
    if (!a) return -2; // a=0
    if (noeud>=a->nb_noeuds) return -3; // >= car on commence a 0
    return a->vecteurPeres[noeud];
}

// Exercice 6

arbre_kk *creer_Cellule(int valeur)
{
    arbre_kk *cell=(arbre_kk*)malloc(sizeof(arbre_kk)); // 16 ou 32 bits
    if (!cell) return NULL;
    cell->valeur=valeur;
    cell->pere=NULL;
    cell->fils_aine=NULL;
    cell->frere_droit=NULL;
    return cell;
}