/*
Ejemplo de:
    Calcular Raiz Cuadrada sin libreria Math
*/
#include<stdio.h>
#include<stdlib.h>

int main()
{
    int i;
    float a,b,num,c;    
   printf("Ingrese el numero a calcular: ");
   scanf("%f",&num);
   c=1;
   while((c*c)<=num)
   {
      c=c+0.1;
   }
   a=c;         
   for(i=0;i<10;i++)
    {
      b=num;
      b=b/a;
      b=b+a;
      b=b/2;
      a=b;
    }

    printf("su raiz cuadrada es: %f",b);
    
    system ("pause");
}
