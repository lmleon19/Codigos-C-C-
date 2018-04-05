/*
Ejemplo de:
    Manejo simple de Nodos y Punteros
*/


#include<stdio.h>
#include<stdlib.h>

typedef struct Nodo
{
    int dato;
    struct Nodo *link;
}nodo;

typedef nodo*lista;

void agregar (lista *L , int e)
{
     lista p;
     p = (lista) malloc (sizeof(nodo));
     p->dato =e;
     p->link = *L;
     *L = p;
}

void mostrar (lista L)
{
     lista p;
     p =L;
     while (p!= NULL)
     {
           printf ("dato es %d\n",p->dato);
           p = p->link;
     }
}



int main()
{
    lista L;
    L = NULL;
    printf ("agregando dato 1\n");
    agregar(&L,1);
    mostrar (L);
    printf ("agregando dato 2\n");
    agregar(&L,2);
    mostrar (L);
    printf ("agregando dato 3\n");
    agregar(&L,3);
    mostrar (L);
    system("pause>nul");
}