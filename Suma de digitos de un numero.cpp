/*
Ejemplo de:
    Suma de los digitos de un numero
*/
#include<stdio.h>
#include<stdlib.h>

int main()
{
    int i,num,a,suma;
    printf ("ingrese el numero");
    scanf ("%d", &num);
    suma=0;
    a=num;
    while (num>0)
    {
      suma=suma+(num%10);
      num=num/10;
    }
    printf ("la suma de los digitos de %d es %d\n",a,suma);
    system ("pause > nul");
}
    