//
//  tp4.c
//  TP4 - Arbres Binaires de Recherche
//

#include "tp4.h"

////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////// Fonctions ajoutees ////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////

//////////////////////////////////// Fonction max //////////////////////////////////////////////

int maxi(int a, int b)
{
    if(a > b)
        return a;
    else
        return b;
}

//////////////////////////////////// Fonction menu ////////////////////////////////////////////

int Menu()
{
    int Choix;
    do
    {
        printf("             ||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
        printf("             |                                                      |\n");
        printf("             |                    Menu Principal                    |\n");
        printf("             |                                                      |\n");
        printf("             ||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
        printf("\n                 1- Inserer un noeud(iteratif)");
        printf("\n                 2- Inserer un noeud(recursif)");
        printf("\n                 3- Verifier si l'arbre est un ABR");
        printf("\n                 4- Rechercher un noeud(iteratif)");
        printf("\n                 5- Rechercher un noeud(recursif)");
        printf("\n                 6- Hauteur de l'arbre");
        printf("\n                 7- Somme des noeuds");
        printf("\n                 8- Afficher l'arbre dans l'ordre decroissant");
        printf("\n                 9- Afficher la structure de l'arbre");
        printf("\n                10 - Supprimer un noeud");
        printf("\n                11- Detruire l'arbre");
        printf("\n                12- Quitter\n");
        printf("\n\n\n\n\n\n\nChoix :");
        scanf("%d",&Choix);
    } while(Choix < 1 || Choix > 12);
    return Choix;
}


////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////// Fonctions du TP /////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////////////////////
// 2. Inserer la valeur n dans l'arbre ayant pour racine 'root'. ---- Version iterative ----
////////////////////////////////////////////////////////////////////////////////////////////////

Noeud *insererNoeud (int n, Noeud *root)
{
    arbre pred=NULL;
    arbre temp=root;
    
    // si l'arbre est vide on insere en tete
    if (root==NULL)
    {
        root=(Noeud*)malloc(sizeof(Noeud));
        if(!root)
        {
            printf("Erreur lors du malloc.\n");
            return NULL;
        }
        root->cle=n;
        root->gauche=NULL;
        root->droit=NULL;
        printf("Noeud racine cree.\n");
    }
    else
    {   // l'arbre n'est pas vide
        while (temp!=NULL && temp->cle!=n)
        {
            pred=temp;
            if (n<temp->cle) temp=temp->gauche;
            else temp=temp->droit;
        }
        
        // on est sorti de la boucle, soit on est a la fin de l'arbre, soit la cle existe deja
        // si on est a la fin de l'arbre, on insere
        if (temp==NULL)
        {
            if (n<pred->cle)
            {
                // on insere a gauche du dernier element
                pred->gauche=(Noeud*)malloc(sizeof(Noeud));
                if(!pred->gauche)
                {
                    printf("Erreur lors du malloc.\n");
                    return NULL;
                }
                pred->gauche->cle=n;
                pred->gauche->gauche=NULL;
                pred->gauche->droit=NULL;
                printf("Noeud insere a gauche.\n");
            }
            else
            {
                // on insere a droite du dernier element
                pred->droit=(Noeud*)malloc(sizeof(Noeud));
                if(!pred->droit)
                {
                    printf("Erreur lors du malloc.\n");
                    return NULL;
                }
                pred->droit->cle=n;
                pred->droit->gauche=NULL;
                pred->droit->droit=NULL;
                printf("Noeud insere a droite.\n");
            }
            
        }
        // si la cle existe deja, on retourne la racine
        else printf("La cle existe deja, erreur.\n");
    }
    return root;
}

////////////////////////////////////////////////////////////////////////////////////////////////
// 3. Inserer la valeur n dans l'arbre ayant pour racine 'root'. ---- Version recursive ----
////////////////////////////////////////////////////////////////////////////////////////////////

Noeud *insererNoeud_rec (int n, Noeud *root)
{
    // on parcout l'arbre
    if (root!=NULL && root->cle!=n)
    {
        // on va a gauche
        if (n<root->cle)
        {
            if (root->gauche!=NULL) insererNoeud_rec(n, root->gauche);
            else
            {
                // on insere a gauche du dernier element
                root->gauche=(Noeud*)malloc(sizeof(Noeud));
                if(!root->gauche)
                {
                    printf("Erreur lors du malloc.\n");
                    return NULL;
                }
                root->gauche->cle=n;
                root->gauche->gauche=NULL;
                root->gauche->droit=NULL;
                printf("Noeud insere a gauche.\n");
            }
        }
        // on va a droite
        else
        {
            if (root->droit!=NULL) insererNoeud_rec(n, root->droit);
            else
            {
                // on insere a droite du dernier element
                root->droit=(Noeud*)malloc(sizeof(Noeud));
                if(!root->droit)
                {
                    printf("Erreur lors du malloc.\n");
                    return NULL;
                }
                root->droit->cle=n;
                root->droit->gauche=NULL;
                root->droit->droit=NULL;
                printf("Noeud insere a droite.\n");
            }
        }
    }
    else if (root==NULL)
    {
        root=(Noeud*)malloc(sizeof(Noeud));
        if(!root)
        {
            printf("Erreur lors du malloc.\n");
            return NULL;
        }
        root->cle=n;
        root->gauche=NULL;
        root->droit=NULL;
        printf("Noeud racine cree.\n");
    }
    // si la cle existe deja, on retourne la racine
    else printf("La cle existe deja, erreur.\n");
    
    return root;
}

//////////////////////////////////////////////////////////////////////////////////////////////////
// 4. Verifier si l'arbre de racine root est un arbre binaire de recherche.
//////////////////////////////////////////////////////////////////////////////////////////////////

int verifier(Noeud* root)
{
    // comme notre structure Noeud represente deja un arbre binaire, nous n'avons pas a tester cette condition
    // il ne nous reste qu'a tester la condition fils gauche < pere < fils droit
    
    int res1, res2;
    
    // arbre vide
    if (root==NULL)
    {
        printf("Arbre vide.\n");
        return 0;
    }
    
    // fils nuls
    if (root->gauche==NULL) res1=1;
    if (root->droit==NULL) res2=1;
    
    // fils gauche < pere
    if (root->gauche!=NULL && root->gauche->cle<root->cle) res1=verifier(root->gauche);
    // pere < fils droit
    if (root->droit!=NULL && root->cle<root->droit->cle) res2=verifier(root->droit);
    
    if (res1 && res2) return 1;
    else return 0;
}

////////////////////////////////////////////////////////////////////////////////////////////////
// 5. Rechercher une valeur n dans l'arbre de racine root. ---- Version iterative ----
////////////////////////////////////////////////////////////////////////////////////////////////

Noeud *recherche(int n, Noeud *root)
{
    if (root==NULL)
    {
        printf("Arbre vide.\n");
        return root;
    }
    
    while (root!=NULL && root->cle!=n)
    {
        if (n<root->cle) root=root->gauche;
        else root=root->droit;
    }
    
    if (root==NULL) printf("La valeur n'est pas presente dans l'arbre.\n");
    else printf("La valeur est presente dans l'arbre.\n");
    
    return root;
}

////////////////////////////////////////////////////////////////////////////////////////////////
// 6. Rechercher une valeur n dans l'arbre de racine root. ---- Version recursive ----
////////////////////////////////////////////////////////////////////////////////////////////////

Noeud *recherche_rec(int n, Noeud *root)
{
    if (root==NULL || n==root->cle) return root;
    if (n<root->cle) return recherche_rec(n, root->gauche);
    else return recherche_rec(n, root->droit);
}

////////////////////////////////////////////////////////////////////////////////////////////////
// 7. Retourne la hauteur de l'arbre de racine root.
////////////////////////////////////////////////////////////////////////////////////////////////

int hauteur (Noeud* root)
{
    int h = 0;
    
    if((root->droit == NULL) && (root->gauche == NULL))
        return 0;
    else if((root->droit == NULL) || (root->gauche == NULL))
        return 1;
    else
    {
        h = 1 + maxi(hauteur(root->gauche), hauteur(root->droit));
        return h;
    }
}

////////////////////////////////////////////////////////////////////////////////////////////////
// 8. Retourne la somme des valeurs de tous les Noeuds de l'arbre de racine root.
////////////////////////////////////////////////////////////////////////////////////////////////

int somme(Noeud* root)
{
    if(root == NULL)
        return 0;
    else
        return root->cle+somme(root->gauche)+somme(root->droit);
}

////////////////////////////////////////////////////////////////////////////////////////////////
// 9. Afficher les valeurs de tous les Noeuds de l'arbre de racine root dans l'ordre decroissant.
////////////////////////////////////////////////////////////////////////////////////////////////

void afficherDecroissant(Noeud* root)
{
    if(root != NULL)
    {
        afficherDecroissant(root->droit);
        printf("%d ",root->cle);
        afficherDecroissant(root->gauche);
    }
}

////////////////////////////////////////////////////////////////////////////////////////////////
// 10. Afficher les valeurs de tous les Noeuds de l'arbre de racine root sous la forme d'un arbre.
////////////////////////////////////////////////////////////////////////////////////////////////

// Un Noeud sera représenté par : {g,v,d} où g est le sous arbre gauche, v la valeur du Noeud et d le sous-arbre droit.
// Les « _ » indiquent les sous arbres vides.


void afficherStructure (Noeud * root)
{
    if (root==NULL) printf("Arbre vide.\n");
    else
    {
        if (root->gauche!=NULL && root->droit!=NULL)
        {
            printf("{%d,%d,%d}\n", root->gauche->cle, root->cle,root->droit->cle);
            afficherStructure(root->gauche);
            afficherStructure(root->droit);
        }
        
        if (root->gauche==NULL || root->droit==NULL)
        {
            if (root->gauche!=NULL)
            {
                printf("{%d,%d,_}\n", root->gauche->cle, root->cle);
                afficherStructure(root->gauche);
            }
            else if (root->droit!=NULL)
            {
                printf("{_,%d,%d}\n", root->cle,root->droit->cle);
                afficherStructure(root->droit);
            }
            else printf("{_,%d,_}\n", root->cle);
        }
    }
}

////////////////////////////////////////////////////////////////////////////////////////////////
// 11. Supprime la valeur n de l'arbre de racine root.
////////////////////////////////////////////////////////////////////////////////////////////////

Noeud* supprimer(int n, Noeud* root)
{
    Noeud* noeud_a_supprimer;
    Noeud* temp = root;
    
    if(root == NULL)
    {
        printf("Impossible de trouver le noeud a supprimer!\n");
        return NULL;
    }
    
    if (root->cle == n) // on a trouve l'element a supprimer
    {
        noeud_a_supprimer = root;
        if ((noeud_a_supprimer->gauche) == NULL) //s'il n'y a pas de sous-arbre gauche, on retourne le sous-arbre droit
            return noeud_a_supprimer->droit;
        else
        {
            root = noeud_a_supprimer->gauche; //sinon on recherche dans le SAG l'endroit pour inserer le SAD
            while ((root->droit) != NULL)
            {
                root = root->droit;
            }
            root->droit = noeud_a_supprimer->droit;
            return noeud_a_supprimer->gauche;
        }
        free(noeud_a_supprimer);
        printf("Le noeud %d a ete supprime.\n",n);
    }
    else
    {
        if (n < (root->cle))
        {
            root->gauche = supprimer(n, root->gauche);
        }
        else
        {
            root->droit = supprimer(n, root->droit);
        }
    }
    return root;
    
}

////////////////////////////////////////////////////////////////////////////////////////////////
// 12. Detruire l'arbre de racine root.
////////////////////////////////////////////////////////////////////////////////////////////////

Noeud *detruire(Noeud* root)
{
    while(root != NULL)
    {
        root = supprimer(root->cle, root);
    }
    free(root);
    return root;
}