#include <stdio.h>
#include <stdlib.h>

// 1. Structure Noeud d'un arbre

typedef struct Noeud
{
    struct Noeud *gauche;
    struct Noeud *droit;
    int cle;
} Noeud;

typedef Noeud *arbre;

////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////// Fonctions ajoutees //////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////

int maxi(int a, int b);
int Menu();

////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////// Fonctions du TP /////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////

// 2. Inserer la valeur n dans l'arbre ayant pour racine 'root'. ---- Version iterative ----

Noeud *insererNoeud (int n, Noeud *root);

// 3. Inserer la valeur n dans l'arbre ayant pour racine 'root'. ---- Version recursive ----

Noeud *insererNoeud_rec (int n, Noeud *root);

// 4. Verifier si l'arbre de racine root est un arbre binaire de recherche.

int verifier(Noeud* root);

// 5. Rechercher une valeur n dans l'arbre de racine root. ---- Version iterative ----

Noeud *recherche(int n, Noeud *root);

// 6. Rechercher une valeur n dans l'arbre de racine root. ---- Version recursive ----

Noeud *recherche_rec(int n, Noeud *root);

// 7. Retourne la hauteur de l'arbre de racine root.

int hauteur(Noeud *root);

// 8. Retourne la somme des valeurs de tous les Noeuds de l'arbre de racine root.

int somme(Noeud *root);

// 9. Afficher les valeurs de tous les Noeuds de l'arbre de racine root dans l'ordre decroissant.

void afficherDecroissant (Noeud * root);

// 10. Afficher les valeurs de tous les Noeuds de l'arbre de racine root sous la forme d'un arbre.

void afficherStructure (Noeud * root);

// 11. Supprime la valeur n de l'arbre de racine root.

Noeud *supprimer (int n, Noeud * root);

// 12. Detruire l'arbre de racien root.

Noeud *detruire (Noeud * root);





