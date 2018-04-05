/*
Ejemplo de:
    Multiplicacion de numeros al Azar
*/
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main()
{
    int n1,n2,res,n,k,i,j;
    printf ("cuantas multiplicaciones decea hacer:\n");
    scanf ("%d",&n);
    srand(time(NULL));
    k=0;
    i=0;
    j=0;
    while ( n!=k)
    {
           n1=rand ()%12+1;
           n2=rand ()%12+1;
           printf ("El resulta de %dx%d es:",n1,n2);
           scanf ("%d", &res);
           if (res==(n2*n1))
           {
              printf ("   Resultado correcto\n\n");
              i++;
           }
           else
           { 
               printf ("Resultado incorrecto intente denuevo\n");
               printf ("El resulta de %dx%d es:\n",n1,n2);
               scanf ("%d",&res);
               if (res==(n2*n1))
               {
                  printf ("   Resultado correcto\n\n");
                  i++;
                  }
                  else
                  { 
                  printf ("Resultado incorrecto el resultado era %d\n\n",n2*n1);
                  j++;
                  }
           
           }
           k++;
    }
    printf ("Obtuvo %d correctas y %d incorrectas\n",i,j);
    system ("pause");
}

      