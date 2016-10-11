//
//  main.c
//  TP2 NF16 Exercice 2
//


#include <stdio.h>
#define NMAX 10


struct Un_Tableau_Entier{
    int tab[NMAX];
    int ncase;          // donne le nombre de case reellement utilisees dans le tableau
};

struct Menu{
    char strtab[20][60];  // tableau de max 20 chaines de caracteres, ces chaines pouvant faire jusaqu'a 60 caracteres
    int nbitem;         // donne le nombre d'item du menu
};

typedef struct {
    float d;      // valeur du petit diametre du tonneau
    float D;      // valeur du grand diametre du tonneau
    float L;      // longueur du tonneau
    char * contenu; // que contient le tonneau ?
} Tonneau;

float volume_acces_normal (Tonneau tonneau){  // acces aux champs de facon classique
    
    float V; // variable a retourner, associee au volume
    
    V=3.14159*tonneau.L*(tonneau.d/2.0+(2/3)*(tonneau.D/2.0-tonneau.d/2.0))*2; // calcul du volume
    
    return V;
}

float volume_acces_pointeur (Tonneau *t){  // acces aux champs par les pointeurs
    
    float V; // variable a retourner, associee au volume
    
    V=3.14159*t->L*(t->d/2.0+(2/3)*(t->D/2.0-t->d/2.0))*2; // calcul du volume
    
    return V;
}

int main() {
    
    struct Un_Tableau_Entier test;
    test.ncase=0;
    
    Tonneau tonneau;
    Tonneau t;
    
    // on initialise les valeurs pour les tonneaux
    
    tonneau.d= 3.5;
    tonneau.D= 6.0;
    tonneau.L= 8.0;
    
    t.d= 3.5;
    t.D= 6.0;
    t.L= 8.0;
    
    // calcul et affichage de la valeur du volume
    
    printf("Volume du tonneau : %f\n",volume_acces_normal(tonneau)); // volume pour une valeur passee de maniere classique
    printf("Volume du tonneau : %f\n",volume_acces_pointeur(&t)); // volume pour une valeur passe en pointeur
    
    return 0;
}
