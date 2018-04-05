/*
Ejemplo de:
    Verificar si es numero primo
*/
#include<stdio.h>
#include<stdlib.h>

int main()
{
    int a,i,num,b;
    a=0;
    printf ("ingrese un numero\n");
    scanf ("%d", &num);
    for (i=1;i<=num;i++)
    {
       if (num%i==0)
       a=a+1;
    }
    if (a==2)
    printf ("es primo\n");
    else
    printf ("no es primo\n");
    system ("pause > nul");
}