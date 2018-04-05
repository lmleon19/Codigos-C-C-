/*
Ejemplo de:
    Menu basico en consola
*/
#include<stdio.h>
#include<stdlib.h>

int main()
{
    int i,a,b;
    int opcion;
    int notas,num;
    do
    {
        system ("cls");
        printf ("************MENU**************\n\n");
        printf ("1)  Opcion 1 \n");
        printf ("2)  Opcion 2 \n");  
        printf ("3)  Opcion 3 \n");
        printf ("4)  Opcion 4 \n");
        printf ("5)  Opcion 5 \n");
        printf ("9)  Opcion 9 (finalizar) \n\n");
        printf ("Ingrese el numero de la opcion que decee realizar\n");
        scanf ("%d", &opcion);
        printf ("***********************************\n");
        
        if (opcion==1)
        {
            printf ("Eligio Opcion 1");
        }
        if (opcion==2)
        {
            printf ("Eligio Opcion 2");
        }
        if (opcion==3)
        {
            printf ("Eligio Opcion 3");
        }
        if (opcion==4)
        { 
            printf ("Eligio Opcion 4");
        }
        if (opcion==5)
        {
            printf ("Eligio Opcion 5"); 
        } 
        
        system("\n\npause");               
    } 
    while (opcion!=9);
    printf ("***************FINN***************\n");
        
    system ("\npause\n");
}