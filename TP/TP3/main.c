//
//  main.c
//  TP3 bibliothèque
//


#include "tp3.h"


int main(int argc, const char * argv[]) {
    
    T_Livre* livre;
    T_Livre* tempL;
    
    T_Rayon* rayon;
    T_Rayon* tempR;
    
    T_Biblio* biblio;
    
    char nom_biblio[MAX];
    char nom_rayon[MAX];
    char titre[MAX];
    char auteur[MAX];
    char edition[MAX];
    
    int choix;
    
    while (choix!=9)
    {
        printf("\nQue voulez-vous faire ?\n 1. Creer une bibliotheque\n 2. Ajouter un rayon a la bilbiotheque\n 3. Ajouter un livre dans un rayon\n 4. Afficher les rayons de la bibliotheque\n 5. Afficher les livres d'un rayon\n 6. Retirer un livre\n 7. Supprimer un rayon\n 8. Rechercher un livre par son titre\n 9. Quitter\n");
        scanf("%d",&choix);
        
        switch (choix)
        {
            case 1:
                printf("Vous souhaitez creer une bibliotheque, entrez son nom.\n");
                scanf("%s",nom_biblio);
                biblio=creerBiblio(nom_biblio);
                break;
                
            case 2:
                printf("Vous souhaitez ajouter un rayon a la bibliotheque, entrez son nom.\n");
                scanf("%s",nom_rayon);
                rayon=creerRayon(nom_rayon);
                ajouterRayon(biblio, rayon);
                break;
                
            case 3:
                printf("Vous souhaitez ajouter un livre a un rayon. Quel est le nom du rayon ?\n");
                scanf("%s",nom_rayon);
                tempR=biblio->premier;
    
                while (tempR!=NULL && strcmp(tempR->theme_rayon,nom_rayon)!=0)
                {
                    tempR=tempR->suivant;
                }
                if (tempR==NULL) printf("Rayon introuvable.\n");
                else if (strcmp(tempR->theme_rayon,nom_rayon)==0)
                {
                    printf("Quel est le titre du livre ?\n");
                    scanf("%s",titre);
                    printf("Quel est l'auteur?\n");
                    scanf("%s",auteur);
                    printf("Quel est l'editeur ?\n");
                    scanf("%s",edition);
                    livre=creerLivre(titre, auteur, edition);
                    ajouterLivre(tempR, livre);
                }
                break;
                
            case 4:
                printf("Vous souhaitez afficher les rayons de la bibliotheque.\n");
                afficherBiblio(biblio);
                break;
                
            case 5:
                printf("Vous souhaitez afficher les livres d'un rayon. Lequel ?\n");
                scanf("%s",nom_rayon);
                tempR=biblio->premier;
                while (tempR!=NULL && strcmp(tempR->theme_rayon,nom_rayon)!=0)
                {
                    tempR=tempR->suivant;
                }
                if (tempR==NULL) printf("Rayon introuvable.\n");
                else if (strcmp(tempR->theme_rayon,nom_rayon)==0) afficherRayon(tempR);
                
                break;
                
            case 6:
                printf("Vous souhaitez retirer un livre. Quel est le nom du livre ?\n");
                scanf("%s",titre);
                printf("Quel est le nom du rayon ?\n");
                scanf("%s",nom_rayon);
                tempR=biblio->premier;
                while (tempR!=NULL && strcmp(tempR->theme_rayon,nom_rayon)!=0)
                {
                    tempR=tempR->suivant;
                }
                if (tempR==NULL) printf("Rayon introuvable.\n");
                else if (strcmp(tempR->theme_rayon,nom_rayon)==0) supprimerLivre(tempR, titre);
                
                break;
                
            case 7:
                printf("Vous souhaitez supprimer un rayon. Quel est le nom du rayon ?\n");
                scanf("%s",nom_rayon);
                supprimerRayon(biblio, nom_rayon);
                break;
                
            case 8:
                printf("Vous souhaitez rechercher un livre. Quel est son titre ?\n");
                scanf("%s",titre);
                rechercherLivres(biblio, titre);
                break;
           /* case 10:
                printf("Vous souhaitez emprunter un livre. Quel est son titre?\n");
                scanf("%s",titre);
                emprunterLivre(rayon, titre);
                break;*/

            default:
                break;
        }

    }
    
    printf("Aurevoir.\n");
    
    return 0;
}
