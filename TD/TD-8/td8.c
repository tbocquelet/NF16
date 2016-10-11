#include "td8.h"

arbre max(arbre A)
{
    if (A==NULL) return NULL; // renvoie null si l'arbre est vide
    while (A->droite!=NULL) // renvoie un pointeur sur le noeud contenant la cle max
    {
        A=A->droite;
    }
    return A;
}

arbre min(arbre A)
{
    if (A==NULL) return NULL; // renvoie null si l'arbre est vide
    while (A->gauche!=NULL) // renvoie un pointeur sur le noeud contenant la cle min
    {
        A=A->gauche;
    }
    return A;
}

arbre succ(arbre A, int a)
{
    arbre tmp;

    if (A->cle==a) return A;
    if (A->cle<a) return succ(A->droite, a);
    tmp=succ(A->gauche, a);
    if (tmp!=NULL) return tmp;
    return A;
}