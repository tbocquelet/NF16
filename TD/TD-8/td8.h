#ifndef __TD_8__td8__
#define __TD_8__td8__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#endif /* defined(__TD_8__td8__) */

struct node {
    int cle;
    struct node *gauche;
    struct node *droite;
};

typedef struct node *arbre;

arbre max(arbre A);
arbre min(arbre A);
arbre succ(arbre A, int a);