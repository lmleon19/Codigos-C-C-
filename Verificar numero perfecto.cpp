/*
Ejemplo de:
    Verificar si un numero es Perfecto.
*/
#include<stdio.h>
#include<stdlib.h>

int main()
{
    int a,b,i,num,salir;
    printf ("ingese un numero\n");
    scanf ("%d", &num);
    a=0;
    for (i=1;i<=num;i++)
     {
      if (num%i==0)
      a=a+i;
     }
    b=a-num;
    if (b==num)
      printf ("es numero perfecto\n");
    else
      printf ("no es numero perfecto\n");
    system ("pause");
} 