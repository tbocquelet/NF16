#include "td7.h"

////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////// EX 1 ///////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////

void eratosthene(int n)
{

    // ecrire a la suite tous les nombres de 2 a n

    int i;
    
    cellule *c;
    cellule *l=NULL;
    cellule *prec;
    
    for (i=n; i>=2; i--)
    {
        c=(cellule*)malloc(sizeof(cellule));
        c->nb=i;
        c->succ=l;  // on insere en tete
        l=c;
    }
    
    // barrer tous les multiples
    
    while (l!=NULL)
    {
        
        printf("%d\n",l->nb);
        
        c=l->succ;
        prec=l;
        
        while (c!=NULL)
        {
            if(c->nb%l->nb==0)
            {
                prec->succ=c->succ;
                free(c);
                c=prec->succ;
            }
            else
            {
                prec=c;
                c=c->succ;
            }
        }
        prec=l;
        l=l->succ;
        free(prec);
    }
}

////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////// EX 2 ///////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////

void josephus(int n, int m)
{

    int i;
    
    cellule *c;
    cellule *l;
    cellule *dernier;
    
    // on cree le cercle
    
    dernier=(cellule*)malloc(sizeof(cellule));
    
    dernier->nb=n;
    printf("%d\t",dernier->nb);
    dernier->succ=NULL;
    l=dernier;
    
    for (i=n-1; i>=1; i--)
    {
        c=(cellule*)malloc(sizeof(cellule));
        c->nb=i;
        printf("%d\t",c->nb);
        c->succ=l;  // on insere en tete
        l=c;
    }
    
    dernier->succ=l;  // c'est ici que le cercle est boucle, le dernier est chaine au premier

    // on tue les gens
    
    while (l->succ!=l)
    {
        for (i=2; i<m; i++)
        {
            l=l->succ;
        }
        
        printf("\n%d est mort\n",l->succ->nb);
        c=l->succ;
        l->succ=c->succ;
        free(c);
        l=l->succ;
    }
    
    // on tue le dernier
    
    printf("\n%d est mort\n",l->nb);
    free(l);
}

////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////// EX 3 ///////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////


liste creerListe()
{
    // on cree juste la sentinelle
    
    cellule *l;
    l=(cellule*)malloc(sizeof(cellule));
    l->pred=l;
    l->succ=l;
    l->nb=0;
    return l;
}

void ajouterEntete(liste l, int x)
{
    cellule *c;
    c=(cellule*)malloc(sizeof(cellule));
    c->nb=x;
    c->succ=l->succ;
    c->pred=l;
    l->succ=c;
    c->succ->pred=c;
}

void suppression(cellule *c)
{
    c->pred->succ=c->succ;
    c->succ->pred=c->pred;
    free(c);
}

void detruireListe(liste l)
{
    while (l!=l->succ)
    {
        suppression(l->succ);
    }
    free(l);
}

////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////// EX 4 ///////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////

Pile *creerPile()
{
    Pile *p=(Pile*)malloc(sizeof(Pile));
    p->l=creerListe();
    p->nb=0;
    return p;
}

void detruirePile(Pile* p)
{
    detruireListe(p->l);
    free(p);
}
void empiler(Pile *p, int x)
{
    ajouterEntete(p->l, x); // on empile sur la tete
    p->nb++;
}

void depiler(Pile *p)
{
    if (p->nb!=0)
    {
        suppression(p->l->succ); // le dernier ajoute est celui juste apres la tete
        p->nb--;
    }
}

int sommet(Pile *p)
{
    return p->l->succ->nb;
}

int taille(Pile *p)
{
    return p->nb;
}

int pileVide(Pile *p)
{
    return p->nb==0;
}

////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////// EX 6 ///////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////

File *creerFile()
{
    File *f=(File*)malloc(sizeof(File));
    f->l=creerListe();
    f->nb=0;
    return f;
}

void detruireFile(File* f)
{
    detruireListe(f->l);
    free(f);
}

void empilerF(File *f, int x)
{
    ajouterEntete(f->l, x); // on empile sur la tete
    f->nb++;
}

void depilerF(File *f)
{
    if (f->nb!=0)
    {
        suppression(f->l->pred); // le premier ajoute est celui juste avant la tete
        f->nb--;
    }
}

int sommetF(File *f)
{
    return f->l->pred->nb;
}

int tailleF(File *f)
{
    return f->nb;
}

int pileVideF(File *f)
{
    return f->nb==0;
}

////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////// EX 5 ///////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////

int evalRPL(char *exp)
{
    Pile *p=creerPile();
    int i=0,nb,nb1,nb2;
    
    while (exp[i]==' ')
    {
        i++;
    }
    
    while (exp[i]!='\0')
    {
        // si c'est un chiffre
        if (exp[i]>='0' && exp[i]<='9')
        {
            nb=0;
            while (exp[i]>='0' && exp[i]<='9')
            {   // pour les nombres a plusieurs chiffres !!! car on lit chaque caractere un a un
                nb*=10;
                nb+=exp[i]-'0';
                i++;
            }
            empiler(p, nb);
        }
        // si c'est un operateur
        else
        {
            nb2=sommet(p);
            depiler(p);
            nb1=sommet(p);
            depiler(p);
            
            switch (exp[i])
            {
                case '+': nb=nb1+nb2; break;
                case '-': nb=nb1-nb2; break;
                case '*': nb=nb1*nb2; break;
                case '/': nb=nb1/nb2; break;
                default: printf("Erreur\n"); detruirePile(p); return 0;
            }
            empiler(p, nb);
            i++;
        }
        
        while (exp[i]==' ')
        {
            i++;
        }
    }
    nb=sommet(p);
    detruirePile(p);
    return nb;
}

























