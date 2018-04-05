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

int contar(lista L)
{
     lista p;
     p=L;
     int a=0;
     while (p!=NULL)
     {
         p = p->link;
         a=a+1; 
     }
     return a;
     
}

int contarpares (lista L)
{
   lista p;
   p=L;
   int a=0;
   while (p!=NULL)
   {
   if ((p->dato)%2==0)
       a=a+1;
       p=p->link;
   }
   return a;
    
}





int main()
{
    int i,n,x;
    lista L;
    L = NULL;
    printf ("ingrese n");
    scanf ("%d", &n);
    for (i=1; i<=n;i++)
       agregar(&L,i);
    mostrar (L);
    printf ("cantidad de nodos de la lista es %d\n", contar(L));
    x=contarpares(L);
    printf ("existen %d pares",x);
    system("pause>nul");
}