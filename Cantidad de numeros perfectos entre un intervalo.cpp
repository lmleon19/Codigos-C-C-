/*
Ejemplo de:
    Cantidad de numeros perfectos entre un intervalo
*/
#include<stdio.h>
#include<stdlib.h>

int main()
{
    int a,b,i,num1,num2,k,j;
    printf ("ingese un numero del intervalo menor\n");
    scanf ("%d", &num1);
    printf ("ingese un numero del intervalo mayor\n");
    scanf ("%d", &num2);
    k=0;
    for (num1;num1<=num2;num1++)
    {
       a=0;
       for (i=1;i<=num1;i++)
       {
         if (num1%i==0)
         a=a+i;
       }
       b=a-num1;
       if (b==num1)
       {
                   
       printf ("%d\n",num1);
       k=k+1;
       }
    }
    printf ("son %d numeros perfectos",k);
    system ("pause");
} 