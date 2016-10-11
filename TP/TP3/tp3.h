//
//  tp3.h
//  TP3 bibliothèque
//

#define MAX 40
#include <stdlib.h>
#include <stdio.h>
#include <string.h>


struct Livre {
    
    char titre[MAX];
    char auteur[MAX];
    char edition[MAX];
    int disponible;
    struct Livre *suivant;
    
};

typedef struct Livre T_Livre;


struct Rayon {
    
    char theme_rayon[MAX];
    int nombre_livres;
    struct Livre *premier;
    struct Rayon *suivant;
    
};

typedef struct Rayon T_Rayon;


struct Biblio {
    
    char nom[MAX];
    struct Rayon *premier;
    
};

typedef struct Biblio T_Biblio;


    // 1. Declarations des fonctions pour initialiser les structures

T_Livre *creerLivre(char *titre, char *auteur, char *edition);
T_Rayon *creerRayon(char *theme);
T_Biblio *creerBiblio(char *nom);

    // 2. Declaration de la fonction d'ajout d'un livre

int ajouterLivre(T_Rayon *rayon, T_Livre *livre);

    // 3. Declaration de la fonction d'ajout d'un rayon

int ajouterRayon(T_Biblio *biblio, T_Rayon *rayon);

    // 4. Declaration de la fonction d'affichage de tous les rayons de la bibliotheque

void afficherBiblio(T_Biblio *biblio);

    // 5. Declaration de la fonction d'affichage de tous les livres d'un rayon

void afficherRayon(T_Rayon *rayon);

    // 6. Declaration de la fonction d'emprunt d'un livre

int emprunterLivre(T_Rayon *rayon, char *titre);

    // 7. Declaration de la fonction de suppression d'un livre dans un rayon

int supprimerLivre(T_Rayon *rayon, char *titre);

    // 8. Declaration de la fonction de suppression d'un rayon et de tous ses livres

int supprimerRayon(T_Biblio *biblio, char *nom_rayon);

    // 9. Declaration de la fonction de recherche de livres

void rechercherLivres(T_Biblio *biblio, char* critereTitre);

    // 10. Declaration de la fonction pour traiter la liste des emprunts

void traiterListeEmprunts(T_Biblio *biblio);
