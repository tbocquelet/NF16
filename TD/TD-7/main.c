#include "td7.h"

int main(int argc, const char * argv[]) {
 
    
    //const int n=9;
    //const int m=5;
    int res;
    char exp[30]="5 9 8 + 4 6 * * 7 + *";
    printf("%s\n",exp);
    //eratosthene(n);
    //josephus(n, m);
    
    res=evalRPL(exp);
    printf("Resultat :%d\n",res);
    
    return 0;
}
