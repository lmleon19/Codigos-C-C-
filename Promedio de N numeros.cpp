/*
Ejemplo de:
    Promedio de N numeros
*/

#include<stdio.h>
#include<stdlib.h>

int main()
{
    int promedio,num,i,a,notas;
    
    printf ("ingrese la cantidad total de notas");
    scanf ("%d", &num);
    a=0;
    for (i=1; i<=num; i++)
    {
        printf ("ingrese la nota numero %d\n",i);
        scanf ("%d", &notas);
        a=a+notas;
    }
    promedio=a/num;
    printf ("el promedio es %d\n",promedio);
    system ("pause");
}
    