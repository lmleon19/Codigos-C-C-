/*
Ejemplo de:
    Arreglo de Listas
*/
#include<stdio.h>
#include<stdlib.h>

typedef struct Nodo{
    int Dato;
    struct Nodo *Link;
}Nodo;

typedef Nodo *Lista;

void mostrar(Lista L)
{
    Lista p;
    p = L;
    while(p != NULL)
    {
       printf("valor es %d\n",p->Dato);
       p = p->Link;    
    }
}
int suma(Lista L)
{
    Lista p;
    p = L;
    int s = 0;
    while(p != NULL)
    {
       s = s + p->Dato;
       p = p->Link;    
    }
    return s;
}

void agregarIzq(Lista *L, int e)
{
   Lista p;
   p = (Lista) malloc(sizeof(Nodo));
   p->Dato = e;
   p->Link = *L;
   *L = p;
}

void agregarDer(Lista *L, int e)
{
   Lista p, q;
   p = (Lista) malloc(sizeof(Nodo));
   p->Dato = e;
   p->Link = NULL;
   
   if(*L == NULL)
      *L = p;
   else
     {
        q = *L;
        while(q->Link != NULL)
            q = q->Link;
        q->Link = p;        
     }   
}

void Eli_Primer(Lista *L)
{
    Lista p; 
    if(*L != NULL)
    {
        p = (*L)->Link;
        free(*L);
        *L = p;
    }  
}

void Eli_Ultimo(Lista *L)
{
    Lista p, q; 
    if(*L != NULL)
    {
        if((*L)->Link == NULL)  // un solo nodo
        {
           free(*L);  
           *L = NULL;         
        }
        else   // mas de dos nodos
        {
            p = *L;
            q = p->Link;
            while(q->Link != NULL)
            {
                p = q;
                q = p->Link;      
            }
            free(q);
            p->Link = NULL;
        }
    }  
}

void Eliminar(Lista *L, int e)
{
  Lista p,q;
  p = *L;
  q = *L;
  while(q != NULL)
    {
      if(q->Dato != e)  // avanza punteros
	  {
	    p = q;
	    q = q->Link;
	  }
      else
	  {
	    if(p == q)   // si se encuentra de los primeros
	    {
	      *L = p->Link;
	      free(q);
	      q = NULL;  /**   p = *L; q = *L;   **/
	    }
	    else    // si esta entre medio
	    {
	      p->Link = q->Link;
	      free(q);
	      q=NULL; /** q = p->Link **/
	    }
	  }
    }
}

void Insertar(Lista *L, int e)
{
  Lista p,q,t;

  p=(Lista) malloc(sizeof(Nodo));
  p->Dato=e;
  p->Link=NULL;

  if(*L == NULL)
    {
      *L=p;
    }
  else
    {
      q=*L;
      t=*L;
      while(q != NULL)
	  {
	    if(q->Dato < e)
	    {
	      t=q;
	      q=q->Link;
	      if(q == NULL)
	      {
             t->Link = p;     
          }
	    }
	    else
	    {
	      if(q == t)  // para insertar al comienzo
		  {
		    p->Link=q;
		    *L=p;
		    q=NULL;
		  }
	        else
		    {             // entre medio
		      t->Link=p;
		      p->Link=q;
		      q=NULL;
	        }
	    }
	  }
    }
}

void Llenar(Lista A[], int n)
{
  int i, j, e, m;   
  for(i=0; i<n; i++)
   {
     printf("Insertando en la casilla A[%d]:\n",i);
     printf("cantidad de elementos : ");
     scanf("%d",&m);
     A[i] = NULL;
     for(j=1; j<=m; j++)
     {
        printf("ingrese elementos : ");
        scanf("%d",&e);
        Insertar(&A[i], e);
     }
   }       
}

void Desplegar(Lista A[], int n)
{
   int i;  
   for(i=0; i<n; i++)
   {
      printf("Lista en la casilla %d\n",i);
      mostrar(A[i]);         
   }     
}

int SumaTotal(Lista A[], int n)
{
   int i;
   int s = 0;  
   for(i=0; i<n; i++)
   {
      s = s + suma(A[i]);         
   }     
   return s;
}

int main()
{
   Lista A[100];
   int i, n, e;
   
   printf("Ingrese valor de N ");
   scanf("%d",&n);
   Llenar(A,n);
   Desplegar(A,n);
   printf("La suma total es %d\n",SumaTotal(A,n));
   system("pause");    
}



