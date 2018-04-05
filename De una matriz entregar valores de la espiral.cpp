/*
Ejemplo de:
    Valores de forma de una espiral, en un matriz
*/
#include<stdio.h>
#include<stdlib.h>


int espiral (int **a,int n,int m)
{
    int i;
         for (i=0;i<m;i++)
         {
             printf ("%d",a[n][m]);
         }
         for (i=1;i<n;i++)
         {
             printf ("%d",a[n][m]);
         }
         for (i=n-1;i<0;i--)
         {
             printf ("%d",a[n][m]);
         }
         for (i=m-1;i<1;i--)
         {
             printf ("%d",a[n][m]);
         }
         for (i=1;i<m-1;i++)
         {
             printf ("%d",a[n][m]);
         }
         for (i=3;i<n-1;i--)
         {
             printf ("%d",a[n][m]);
         }
    } 
         
int main ()
{
    int a[100][100],n,m,i,j;
    printf ("ingrese el largo y ancho de la matriz");
    scanf ("%d",&n);
    scanf ("%d",&m);
    for (i=0;i=n;i++)
    {
       for (j=0;i=m;i++)
       { 
       printf ("ingrese el valor del espacio [%d,%d]\n",i,j)
        scanf ("%d",&  a[n][m]);
       }
    }
    int esperal (**a,n,m);
    
    
    
    
    
    
    
    
    
    
    
     
    system ("pause>nul");
}