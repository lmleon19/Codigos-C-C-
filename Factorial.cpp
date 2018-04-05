/*
Ejemplo de:
    Calcular Factorial de un Numero sin libreria Math
*/
#include<stdio.h>
#include<stdlib.h>

int main()
{
    int i,num,k,a,p;
    printf ("ingrese la cantidad de factorial\n");
    scanf ("%d", &num);
    i=1;
    a=1;
    p=0;
    for (i=1; i<=num; i++)
    {
        a=a*i;
    }
    printf ("El resultado es %d\n",a);
    system ("pause");
}
    