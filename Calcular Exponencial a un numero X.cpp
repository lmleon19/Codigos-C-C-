/*
Ejemplo de:
    Calcular Exponencial a un numero X
*/
#include<stdio.h>
#include<stdlib.h>

int main()
{
    float num,a,b,c,d,e,f;
    int i;
    printf("ingrese el numero");
    scanf("%f",&num);
    c=1+num;
    b=num;
    e=1;
    d=1;
    for(i=1;i<=29;i++)
    {
        b=b*num;
        e=e*(d+1);
        d=d++;
        f=b/e;
        c=c+f;
    }
    printf ("e elevado a %.1f es=%.3f",num,c);
   system ("pause");
}
        
        
        