/*
Ejemplo de:
    Verificar signo de un numero
*/
#include<stdio.h>
#include<stdlib.h>

int main ()
{
    int num;
    printf ("ingrese un numero ");
    scanf ("%d", &num);
     if (num > 0)
    {
              printf ("el numero es positivo");
    }
    else
    {
        if (num < 0)
        {
                   printf ("el numero es negativo");
        }
        else
        {
                   printf ("el numero es un cero");
        }        
    }
    system ("pause"); 
}