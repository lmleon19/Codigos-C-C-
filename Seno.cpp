/*
Ejemplo de:
    Calcular SENO sin libreria Math
*/
#include<stdio.h>
#include<stdlib.h>

int main()
{
    float num,a,b,c,d,e,f;
    int i;
    printf("ingrese el numero");
    scanf("%f",&num);
    num=(num*3.1415926536);
    num=num/180;
    c=num;
    b=num;
    d=1;
    e=1;
    for (i=1;i<=20;i++)
    {
         b=b*num*num;
         e=e*(d+1)*(d+2);
         d=d+2;
         f=b/e;
         if (i%2==0)
         {
             c=c+f;
         }
         else
         {
            c=c-f;
         }
    }
    printf ("el seno es %.4f",c);
    
    system("pause");
}