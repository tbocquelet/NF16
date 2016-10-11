//
//  tp3.c
//  TP3 bibliothèque
//

#include "tp3.h"

// utiliser les options du printf pour afficher correctement le tableau, espacement etc et les pipes

    // 1. Definitions des fonctions pour initialiser les structures

T_Livre *creerLivre(char *titre, char *auteur, char *edition){
    
    T_Livre *temp=(T_Livre*)malloc(sizeof(T_Livre));
    strcpy(temp->titre, titre);
    strcpy(temp->auteur, auteur);
    strcpy(temp->edition, edition);
    temp->disponible=1;  // le livre est disponible
    temp->suivant=NULL;

    return temp;
}


T_Rayon *creerRayon(char *theme){

    T_Rayon *temp=(T_Rayon*)malloc(sizeof(T_Rayon));
    strcpy(temp->theme_rayon, theme);
    temp->nombre_livres=0;                    // on initialise la valeur du nombre de livres du rayon
    temp->suivant=NULL;
    
    return temp;
}


T_Biblio *creerBiblio(char *nom){
    
    T_Biblio *temp=(T_Biblio*)malloc(sizeof(T_Biblio));
    strcpy(temp->nom, nom);
    
    return temp;
}


    // 2. Definition de la fonction d'ajout d'un livre


int ajouterLivre(T_Rayon *rayon, T_Livre *livre){

    T_Livre* prec;
    T_Livre* temp;
    int exit=0;
    
    temp=rayon->premier;
    
    /*  STRCMP : Si tous les caractères sont identiques, elle renvoie 0. Si les caractères de la chaine1 sont supérieurs à ceux de la chaine2, la fonction renvoie un nombre positif. Si c'est l'inverse, la fonction renvoie un nombre négatif. */

    
    // si le rayon est vide ou que le titre du livre a inserer est avant celui du premier livre du rayon alors on insere le livre a la place du premier
    
    if(rayon->premier==NULL || strcmp(livre->titre, rayon->premier->titre)<0)
    {
        livre->suivant=rayon->premier;
        rayon->premier=livre;
    }
    
    else
    {
        // on parcourt la liste de livres du rayon
        
        while (exit==0 && temp!=NULL)
        {
            // on teste si le titre du livre a inserer se trouve apres le livre pointe
            
            if(strcmp(livre->titre, temp->titre)>0)     // si oui on stocke la valeur du predecesseur c'est a dire le livre pointe
            {
                prec=temp;
                temp=temp->suivant;
            }
            else if (strcmp(livre->titre, temp->titre)==0)  // si les titres sont identiques, on sort de la boucle
            {
                printf("Le livre existe deja.\n");
                return 0;
            }
            else exit++;    // si le titre du livre se trouve avant celui du livre teste, on sort
        }
        
        if(temp==NULL)  // si on est au bout de la liste et que le livre n'existe pas, on l'insere a la fin
        {
            prec->suivant=livre;
            livre->suivant=NULL;
        }
        else    // si le livre n'existe pas et que le titre se trouve entre deux livres, on l'insere entre deux livres
        {
            prec->suivant=livre;
            livre->suivant=temp;
        }
    }
    
    rayon->nombre_livres++;
    printf("Le livre a bien ete ajoute au rayon.\n");
    return 1;
}


    // 3. Definition de la fonction d'ajout d'un rayon


// il s'agit de la meme fonction que pour ajouter un livre a un rayon, il suffit de remplacer le livre par le rayon et le rayon par la bibliotheque

int ajouterRayon(T_Biblio *biblio, T_Rayon *rayon){
    
    T_Rayon* prec;
    T_Rayon* temp;
    int exit=0;
    
    temp=biblio->premier;
    
    
    if(biblio->premier==NULL || strcmp(rayon->theme_rayon, biblio->premier->theme_rayon)<0)
    {
        rayon->suivant=biblio->premier;
        biblio->premier=rayon;
    }
    
    else
    {
        while (exit==0 && temp!=NULL)
        {
            if(strcmp(rayon->theme_rayon, temp->theme_rayon)>0)
            {
                prec=temp;
                temp=temp->suivant;
            }
            else if (strcmp(rayon->theme_rayon, temp->theme_rayon)==0)
            {
                printf("Le rayon existe deja.\n");
                return 0;
            }
            else exit++;
        }
            
        if(temp==NULL)
        {
            prec->suivant=rayon;
            rayon->suivant=NULL;
        }
        else
        {
            prec->suivant=rayon;
            rayon->suivant=temp;
        }
    }
    
    printf("Le rayon a bien ete ajoute a la bibliotheque.\n");
    return 1;
}


    // 4. Defintion de la fonction d'affichage de tous les rayons de la bibliotheque


void afficherBiblio(T_Biblio *biblio){

    T_Rayon* temp;
    temp=biblio->premier;
    
    if (temp==NULL)
    {
        printf("La bibliotheque est vide.\n");
    }
    else
    {
        printf("\n\n Rayon(s) de la bibliotheque :\n");
        printf("\t Nom \t| Nombre de livres\n");
    
        while (temp!=NULL)
        {
            printf("%10s  | %d\n",temp->theme_rayon,temp->nombre_livres);
            temp=temp->suivant;
        }
    }
}


    // 5. Defintion de la fonction d'affichage de tous les livres d'un rayon


void afficherRayon(T_Rayon *rayon){
    
    T_Livre* temp;
    temp=rayon->premier;
    
    if (temp==NULL)
    {
        printf("Le rayon est vide.\n");
    }
    else
    {
        printf("\n\n Livre(s) du rayon :\n");
        printf("\t Titre \t| Auteur \t| Edition \t| Disponible\n");
    
        while (temp!=NULL)
        {
            if (temp->disponible==1) // si le livre est disponible
            {
                printf("%10s  | %10s| %10s| Oui\n",temp->titre,temp->auteur,temp->edition);
            }
            else // si le livre n'est pas disponible
            {
                printf("%10s  | %10s| %10s| Non\n",temp->titre,temp->auteur,temp->edition);
            }
        
            temp=temp->suivant;
        }
    }
}


    // 6. Defintion de la fonction d'emprunt d'un livre

int emprunterLivre(T_Rayon *rayon, char *titre){

    T_Livre *temp;
    temp=rayon->premier;
    
    if (temp==NULL)
    {
        printf("Le rayon est vide, il n'y a aucun livre a emprunter.\n");
        return 0;
    }
    else
    {
        if (strcmp(titre, temp->titre)!=0) // si le titre du livre recherche est different du titre du premier livre
        {
            while (strcmp(titre, temp->titre)!=0 && temp!=NULL) // tant que l'on n'est pas a la fin de la chaine ou que les titres ne sont pas identiques on continue  && ou || ?
            {
                temp=temp->suivant;
            }
        }
    
        if (temp==NULL) // on est a la fin de la chaine, le livre n'a pas ete trouve
        {
            printf("Le livre n'est pas dans le rayon.\n");
            return 0;
        }
        else if (temp->disponible==1) // on regarde si le livre est disponible
        {
            printf("Vous pouvez emprunter le livre.\n");
            return 1;
        }
        else
        {
            printf("Le livre n'est pas disponible.\n");
            return 0;
        }
    }
}


    // 7. Definition de la fonction de suppression d'un livre dans un rayon

int supprimerLivre(T_Rayon *rayon, char *titre){

    T_Livre *prec;
    T_Livre *temp;
    
    temp=rayon->premier;
    
    if (rayon->premier==NULL)
    {
        printf("Le rayon est vide.\n");
        return 0;
    }
    else
    {
        if (rayon->premier->suivant==NULL && strcmp(titre, rayon->premier->titre)==0) // cas premier sans successeur
        {
            rayon->premier=NULL;
            free(temp);
        }
        else if (rayon->premier->suivant!=NULL && strcmp(titre, rayon->premier->titre)==0) // cas premier avec successeur
        {
            rayon->premier=rayon->premier->suivant;
            rayon->premier=NULL;
            free(temp);
        }
        else
        {
            while (temp->suivant!=NULL && strcmp(titre, temp->suivant->titre)!=0) // on parcourt la liste jusqu'a trouver le livre ou avoir atteint la fin de la liste
            {
                temp=temp->suivant;
            }
            
            if (temp->suivant==NULL) // on est a la fin de la chaine et le livre n'est pas dans le rayon
            {
                printf("Le livre n'est pas dans le rayon.\n");
                return 0;
            }
            else if (strcmp(titre, temp->suivant->titre)==0)
            {
                prec=temp;
                prec->suivant=temp->suivant->suivant;
                free(temp->suivant);
            }
        }
        printf("Le livre a ete supprime du rayon.\n");
        rayon->nombre_livres--;
        return 1;
    }
}

 // 8. Definition de la fonction de suppression d'un rayon et de tous ses livres

int supprimerRayon(T_Biblio *biblio, char *nom_rayon){
    
    T_Rayon *precR;
    T_Rayon *tempR;
    
    T_Livre *precL;
    T_Livre *tempL;
    
    tempR=biblio->premier;
    
    if (biblio->premier==NULL)
    {
        printf("La bibliotheque est vide.\n");
        return 0;
    }
    else
    {
        if (biblio->premier->suivant==NULL && strcmp(nom_rayon, biblio->premier->theme_rayon)==0) // cas premier sans successeur
        {
            tempL=tempR->premier;  // on pointe sur le premier livre du rayon
            
            while (tempL!=NULL)         // on supprime tous les livres du rayon
            {
                precL=tempL;
                tempL=tempL->suivant;
                free(precL);
            }
            
            biblio->premier=NULL;
            free(tempR);
        }
        else if (biblio->premier->suivant!=NULL && strcmp(nom_rayon, biblio->premier->theme_rayon)==0) // cas premier avec successeur
        {
            tempL=tempR->premier;
            
            while (tempL!=NULL)
            {
                precL=tempL;
                tempL=tempL->suivant;
                free(precL);
            }
            
            biblio->premier=biblio->premier->suivant;
            free(tempR);
        }
        else
        {
            while (tempR->suivant!=NULL && strcmp(nom_rayon, tempR->suivant->theme_rayon)!=0) // on parcourt la liste jusqu'a trouver le rayon ou avoir atteint la fin de la liste
            {
                tempR=tempR->suivant;
            }
        
            if (tempR->suivant==NULL) // on est a la fin de la liste et le rayon n'existe pas
            {
                printf("Le rayon n'existe pas.\n");
                return 0;
            }
            else if (strcmp(nom_rayon, tempR->suivant->theme_rayon)==0)
            {
                tempL=tempR->premier;
                
                while (tempL!=NULL)
                {
                    precL=tempL;
                    tempL=tempL->suivant;
                    free(precL);
                }
                
                precR=tempR;
                precR->suivant=tempR->suivant->suivant;
                free(tempR->suivant);  // on supprime le rayon
            }
        }
    }
    
    printf("Le rayon a ete supprime de la bibliotheque.\n");
    return 1;
}

    // 9. Definition de la fonction de recherche de livres

// restera a faire le tri et a finir le fonctionnement de la boucle et c'est bon !
/* void rechercherLivres(T_Biblio *biblio, char* critereTitre){
    
    struct Recherche {
        char titre[MAX];
        char auteur[MAX];
        char edition[MAX];
        int disponibilite;
        char nom_rayon[MAX];
    };
    
    struct Recherche tab[MAX];
        
    int i,j,res;
    
    T_Rayon* tempR;
    T_Livre* tempL;
    
    for (i=0; i<MAX; i++)
    {
        strcpy(tab[i].titre,"           ");
        strcpy(tab[i].auteur,"          ");
        strcpy(tab[i].edition,"         ");
        tab[i].disponibilite=1;
        strcpy(tab[i].nom_rayon,"           ");
    }

    tempR=biblio->premier;
    
    i=0;
    
    while (tempR!=NULL)
    {
        tempL=tempR->premier;
        
        while (tempL!=NULL)
        {
            j=0;
            res=1;
            
           while (critereTitre[j]!='\0')
            {
                if (critereTitre[j]!=tempL->titre[j])
                {
                    res=0;
                }
                
                j++;
            }
            
            if (res==1)
            {
                printf("Livre trouve.\n");
                printf("%s\n",tempL->titre);
                printf("%s\n",tempL->auteur);
                printf("%s\n",tempL->edition);
                printf("%s\n",tempL->titre);
                strcpy(tab[i].titre,tempL->titre);
                strcpy(tab[i].auteur,tempL->auteur);
                strcpy(tab[i].edition,tempL->edition);
                tab[i].disponibilite=tempL->disponible;
                strcpy(tab[i].nom_rayon,tempR->theme_rayon);
                i++;
            }
            
            tempL=tempL->suivant;
        }
        
        tempR=tempR->suivant;
    }

    printf("Titre \t Auteur \t Edition \t Disponibilite \t Rayon \n");
    
    for (j=0; j<i; j++)
    {
        printf("%s\t|%s\t|%s\t|%d\t|%s",tab[i].titre,tab[i].auteur,tab[i].edition,tab[i].disponibilite,tab[i].nom_rayon);
    }
} */


void rechercherLivres(T_Biblio *biblio, char* critereTitre){
    
    int j,res;
    long int taille;
    
    T_Rayon* tempR;
    T_Livre* tempL;
    
    tempR=biblio->premier;
    
    printf("\nTitre\t| Auteur\t| Edition\t| Disponibilite\t| Rayon \n");
    
    while (tempR!=NULL)
    {
        tempL=tempR->premier;
        
        while (tempL!=NULL)
        {
            j=0;
            res=1;
            taille=strlen(critereTitre);
            while (j!=taille)
            {
                if (critereTitre[j]!=tempL->titre[j])
                {
                    res=0;
                }
             
                j++;
            }
            
            if (res==1)
            {
                if (tempL->disponible==1)
                {
                    printf("%s\t| %s\t| %s\t| Oui\t| %s\n",tempL->titre,tempL->auteur,tempL->edition,tempR->theme_rayon);
                }
                else
                {
                    printf("%s\t| %s\t| %s\t| Non\t| %s\n",tempL->titre,tempL->auteur,tempL->edition,tempR->theme_rayon);
                }
            }
            tempL=tempL->suivant;
        }
        
        tempR=tempR->suivant;
    }
}

    // 10. Definition de la fonction pour traiter la liste des emprunts

// facon bourrin de le faire, si on veut le faire plus proprementm on cree une vraie liste chainee prenant en parametre le rayon et le livre et on cherche si oui ou non ils sont empruntables

void traiterListeEmprunts(T_Biblio *biblio){
    
    T_Rayon *tempR;
    T_Livre *tempL;
    
    char nom_rayon[MAX];
    char nom_livre[MAX];

    tempR=biblio->premier;

    char choix=1;
    
    int j,res;
    long int taille;
    
    while (choix==1)
    {
        printf("Entrez un rayon et un livre a rechercher.\n");
        scanf("%s",nom_rayon);
        scanf("%s",nom_livre);
        
        while (tempR!=NULL)
        {
            tempL=tempR->premier;
            
            while (tempL!=NULL)
            {
                if (emprunterLivre(tempR, tempL->titre)==1)
                {
                    printf("Le livre %s est disponible.\n",nom_livre);
                    tempL->disponible=0;
                }
                else
                {
                    printf("Le livre %s n'est pas disponible.\n",nom_livre);
                }
     
                tempL=tempL->suivant;
            }
            
            tempR=tempR->suivant;
        }
        
        printf("Voulez-vous continuer ?\n");
        scanf("%c",&choix);
    }
}



