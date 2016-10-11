//
//  main.c
//  TP 2 Fibonacci
//


#include <stdio.h>
#include <time.h>

int fibo1(int n){       // methode naive
    
    if (n==0) return 0; // condition initiale de la suite, c'est un cas trivial qui permet l'arret
    if (n==1) return 1; // condition initiale de la suite
    return fibo1(n-1)+fibo1(n-2);  // calcul des termes de la suite
}

/*           ////////////////////////////////////////////////////////////////////////////////////////////
             recursivite rapide qui ne fonctionne pas, ex pour n = 2 : U4=U4+2*U2*U1, c'est impossible car
                                                        U2*U1 !=0
             ////////////////////////////////////////////////////////////////////////////////////////////
 
 int fibo2(int n){
    
    printf("On me demande n = %d \n",n);
    
    if (n==0) return 0;
    else if (n==1) return 1;
    else
    {
        
        // u2n
        if(n%2==0)
        {
            return fibo2(n)+fibo2(n+1)*fibo2(n+1);
            
        }
        // u2n+1
        else
        {
            return fibo2(n)+2*fibo2(n)*fibo2(n-1);
            
        }
    }
   
}

*/

int main() {
    
    int n;  // valeur du n de la suite

    double elapsed; // variable associee au temps d'execution
    
    printf("A quel n s'arrete la suite ? (commence a n=0). Entrez une valeur.\n\n");
    scanf("%d",&n);

    clock_t start, end;
    start= clock();  // lancement de la mesure
    
    printf("%d\n\n", fibo1(n));  // on calcule et affiche la suite
    
    end = clock(); // fin de la mesure
    
    elapsed=((double)end - start)/ CLOCKS_PER_SEC; // conversion en secondes20
    
    printf("Temps ecoule : %lf secondes.\n",elapsed);  // affichage du temps d'execution
    
    return 0;
}
