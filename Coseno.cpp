/*
Ejemplo de:
    Calcular COSENO sin libreria Math
*/
#include<stdio.h>
#include<stdlib.h>

int main()
{
    float num,a,b,c,d,e,f,g;
    int i;
    printf("ingrese el numero");
    scanf("%f",&num);
    num=(num*3.1415926536);
    num=num/180;
    c=1;
    b=num*num;
    d=2;
    e=2;
    g=(num*num)/2;
    c=c-g;
    for (i=1;i<=19;i++)
    {
         b=b*num*num;
         e=e*(d+1)*(d+2);
         d=d+2;
         f=b/e;
         if (i%2==0)
         {
             c=c-f;
         }
         else
         {
            c=c+f;
         }
    }
    printf ("el coseno es %.4f",c);
    
    system("pause");
}