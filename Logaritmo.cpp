/*
Ejemplo de:
    Calcular Logaritmo sin libreria Math
*/
#include<stdio.h>
#include<stdlib.h>
 
float logaritmo(float)
{
    float num,a,b,c,d,e,f;
    int i;
    printf("ingrese el numero");
    scanf("%f",&num);
    c=1;
    b=1;
    e=1;
    d=1;
    for(i=1;i<=10;i++)
    {
        b=b*num;
        e=e*(d+1);
        d=d++;
        f=b/e;
        c=c+f;
     }
} 
      return c  

        
        
int main()
{ 
    float num,a,b,c,d,e,f;
    int i;
    printf("ingrese el numero");
    scanf("%f",&num);
    float logaritmo (num)
   system ("pause");

}
        
        