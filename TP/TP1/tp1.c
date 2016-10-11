#include "tp1.h"

void un_un()
{
    float a,b, s;

    printf("Entrez deux reels \n\n");
    scanf("%f %f",&a, &b);

    printf("Voici les reels : %f et %f \n\n",a,b);

    s=a+b;

    printf("La somme vaut : %f \n", s);
}

void un_deux()
{
   int a,b,i;

   printf("Entrez deux variables \n\n");
   scanf("%d %d",&a,&b);

   i=a;
   a=b;
   b=i;

   printf("a=%d et b=%d",a,b);


}

void un_trois()
{
    float x,y,p;
    printf("Entrez un nombre et un pourcentage \n\n");
    scanf("%f %f",&y,&p);

    x=y*p*0.01;

    printf("Le pourcentage de %f par %f est %f \n", y,p,x);
}


void un_quatre()
{
    float temp_F,temp_C;

    printf("Entrez une valeur de température en Fahrenheit \n");
    scanf("%f",&temp_F);

    temp_C=(5.0/9.0)*(temp_F-32.0);
    printf("Voici la température en Celsius:%f",temp_C);
}

void un_cinq()
{
    int a;

    printf("Entrez entier\n\n");
    scanf("%d",&a);

    printf("Décimal : %d, octal : %o, hexa : %x \n", a,a,a);
}

void un_six()
{
   int i;

   printf("Entrez entier i\n\n");
   scanf("%d",&i);
   if(i == 0)
   printf("%d",i);

   else if(i %2 == 0)
   printf("pair\n\n");

   else
   printf("impair\n\n");
}

void un_sept()
{
    char c;

    c='5';
    printf("caractere : %c \n\n",c);

    c=96;

    printf("caractere : %c",c);
}

void deux_deux()
{
   int i=0;

   while(i!=(-1))
   {
     scanf("%d",&i);
   }
}

void deux_trois()
{
    int k, i;



    do
       {
            printf("Quelle table de multiplication ? (zero pour sortir)\n\n");
            scanf("%d",&k);
            i=1;

            if (k==0)
            printf("sortie");

            else if (k<=9 && k>=1)
                while (i<10)
                {
                    printf("%d \n\n", k*i);
                    i++;
                }

            else printf("Ce n'est pas dans les possibilites du prog\n\n");

       }   while (k!=0);

}

void deux_quatre()
{
  char c;

  c=getchar();
  switch(c)
  {
   case '1': printf("Un\n");
             break;
   case '2': printf("Deux\n");
             break;
   case '3': printf("Trois\n");
             break;
   default : printf("autre catactere\n");
             break;
  }

}

void trois_un()
{
   int tab[10];
   int i;

   for(i=0;i<10;i++)
   {
      tab[i]=0;
      printf("%d\n\n",tab[i]);
   }
}

void trois_deux()
{
    int tab[5] = {4,3,2,1,0};
    int i;

    for(i=0;i<5;i++)
   {
      printf("%d\n\n",tab[i]);
   }
}

void trois_trois()
{
   int tab[3][4]={{12,13,14,15},{16,17,18,19},{20,21,22,23}};
   int i,j;

   for(i=0;i<3;i++)
   {
       printf("\n");
      for(j=0;j<4;j++)
      {
        printf("%d\t",tab[i][j]);
      }
   }

}

void trois_quatre()
{

  int m=2,l=3,n=2;
  int mat1[m][l],mat2[l][n],resultat[m][n];

  int i,j,k;

  for(i=0;i<m;i++)
   {
      for(j=0;j<l;j++)
        {
            scanf("%d\n\n",&mat1[i][j]);
        }
   }

    for(i=0;i<l;i++)
   {
      for(j=0;j<n;j++)
        {
            scanf("%d\n\n",&mat2[i][j]);
        }
   }

  for(i=0;i<m;i++)
   { printf("\n");
      for(j=0;j<l;j++)
        {
            printf("%d \t",mat1[i][j]);
        }
   }

   printf("\n\n\n");

 for(i=0;i<l;i++)
   { printf("\n");
      for(j=0;j<n;j++)
        {
            printf("%d \t",mat2[i][j]);
        }
   }

   printf("\n\n\n");

     for(i=0;i<m;i++)
   {    printf("\n");
      for(j=0;j<l;j++)
        {
          for(k=0;k<n;k++)
           {
               resultat[i][k]=mat1[i][j]*mat2[j][k];
                printf("%d \t",resultat[i][k]);
           }
        }
   }


}
