/*
Ejemplo de:
    Suma de 2horas
*/
#include<stdio.h>
#include<stdlib.h>

int main()
{
    int h1,h2,j,k,a,b,x,y,z;
    printf ("ingrese la primera hora de forma hhmm\n");
    scanf ("%d",&h1);
    printf ("ingrese la segunda hora de forma hhmm\n");
    scanf ("%d",&h2);
    a=h1%100;
    if (a>=60)
    {
        h1=h1-60;
        h1=h1+100;
    }
    b=h2%100;
    if (b>=60)
    {
        h2=h2-60;
        h2=h2+100;
    }      
    k=h1+h2;
    j=k%100;
    if (j>=60)
    {
         k=k-60;
         k=k+100; 
    }
    
    x=k%100;
    y=k/100;
    z=0;
    if (y>=24)
    {
       z=y/24;
       y=y%24;
    }       
    
    printf ("la suma de las horas y minutos  es %d\n",k);
    printf ("un total de %d dias, %d horas y %d minutos",z,y,x);
    system ("pause >nul");
}   