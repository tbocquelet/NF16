#include <stdio.h>
#include <stdlib.h>
#include "TP4.h"

//TP4 : Arbres binaires de recherche

void main()
{
    int valeur;
    int Choix;
    int res;
    int h;
    int s;
    
    Noeud* root;
    Noeud* rec;
    root = NULL;
    Choix = Menu();
    while(Choix!=12)
    {
        if (root == NULL && Choix > 2 && Choix < 12)
        {
            printf("Vous devez d'abord creer un arbre");
            printf("\nAppuyez sur une touche pour retourner au menu principal.\n");
            getchar();
        }
        else
        {
            switch (Choix)
            {
                case 1 :
                    printf("Saisir un entier (-1 pour finir la saisie) : ");
                    scanf("%d",&valeur);
                    while (valeur != -1)
                    {
                        root = insererNoeud(valeur, root);
                        printf("Saisir un entier (-1 pour finir la saisie) : ");
                        scanf("%d",&valeur);
                    }
                    break;
                    
                case 2 :
                    printf("Saisir un entier (-1 pour finir la saisie) : ");
                    scanf("%d",&valeur);
                    while (valeur != -1)
                    {
                        root = insererNoeud_rec(valeur, root);
                        printf("Saisir un entier (-1 pour finir la saisie) : ");
                        scanf("%d",&valeur);
                    }
                    break;
                    
                case 3 :
                    res = verifier(root);
                    if(res == 1)
                        printf("L'arbre est un arbre binaire de recherche!\n");
                    else printf("L'arbre n'est pas un arbre binaire de recherche!\n");
                    printf("\nAppuyez sur une touche pour retourner au menu principal.\n");
                    getchar();
                    break;
                    
                case 4 :
                    printf("Saisir la valeur a rechercher : ");
                    scanf("%d", &valeur);
                    rec = recherche(valeur, root);
                    printf("\nAppuyez sur une touche pour retourner au menu principal.\n");
                    getchar();
                    break;
                    
                case 5 :
                    printf("Saisir la valeur a rechercher : ");
                    scanf("%d", &valeur);
                    rec = recherche_rec(valeur, root);
                    if (rec==NULL) printf("La valeur n'est pas dans l'arbre.\n");
                    else printf("La valeur est dans l'arbre.\n");
                    printf("\nAppuyez sur une touche pour retourner au menu principal.\n");
                    getchar();
                    break;
                    
                case 6 :
                    h = hauteur(root);
                    printf("La hauteur de l'arbre est de %d\n",h);
                    printf("\nAppuyez sur une touche pour retourner au menu principal.\n");
                    getchar();
                    break;
                    
                case 7 :
                    s = somme(root);
                    printf("La somme des noeuds est de %d\n",s);
                    printf("\nAppuyez sur une touche pour retourner au menu principal.\n");
                    getchar();
                    break;
                    
                case 8 :
                    afficherDecroissant(root);
                    printf("\nAppuyez sur une touche pour retourner au menu principal.\n");
                    getchar();
                    break;
                    
                case 9 :
                    afficherStructure(root);
                    printf("\nAppuyez sur une touche pour retourner au menu principal.\n");
                    getchar();
                    break;
                    
                case 10 :
                    printf("Saisir la valeur du noeud a supprimer : ");
                    scanf("%d",&valeur);
                    root = supprimer(valeur,root);
                    printf("\nAppuyez sur une touche pour retourner au menu principal.\n");
                    getchar();
                    break;
                    
                case 11 :
                    root = detruire(root);
                    if(root == NULL)
                        printf("L'arbre est detruit!");
                    printf("\nAppuyez sur une touche pour retourner au menu principal.\n");
                    getchar();
                    break;
            }
        }
        Choix=Menu();
    }
}
