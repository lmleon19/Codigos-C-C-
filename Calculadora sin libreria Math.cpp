/*
Ejemplo de:
    Calculadora sin libreria Math
*/

#include<stdio.h>
#include<stdlib.h>

int factorial (int l);
float log_natural1 (float num);
float log_natural2 (float num);
float raiz (float num);
float seno (float num);
float coseno(float num);
float tangente (float num);
float promedio(int l);
float exponencial(float num);
float potencia (float num,float c);
float suma (int l);
float resta (float num,float a);
float multiplicacion (int l);
float division (float num,float a);

int main()
{
    int opcion,l,k;
    float a,b,c,num;
    do
    {
        system ("cls");
        printf ("*****************MENU*******************\n\n");
        
        printf ("  01)  Sacar el factorial\n");
        printf ("  02)  Logaritmo natural\n"); 
        printf ("  03)  Raiz cuadrada\n");
        printf ("  04)  Seno\n");
        printf ("  05)  coseno\n");
        printf ("  06)  tangente\n");
        printf ("  07)  Promedio\n");
        printf ("  08)  exponencial\n");
        printf ("  09)  Potencia\n");
        printf ("  10)  suma\n");
        printf ("  11)  resta\n");
        printf ("  12)  multiplicacion\n");
        printf ("  13)  division\n");
        printf ("  00)  Para finalizar el menu\n\n");
        printf ("Ingrese el numero de la opcion que decee realizar\n");
        scanf  ("%d", &opcion);
        printf ("********************************************************\n\n");
        
        if (opcion==1)
        {
            printf ("ingrese el numero al cual desea sacar su factorial\n"); 
            scanf ("%d", &l);
            b=factorial(l);
            printf ("el factorial de %d es %.0f=\n\n",l,b);      
        }
        if (opcion==2)
        {
            printf ("ingrese el numero\n");
            scanf ("%f",&num);
            if (num>0)
            {
                if (num<=2)
                {
                  b=log_natural1(num);
                  printf ("el logaritmo natural de %.2f es=%.4f\n\n",num,b);
                }
                else
                { 
                  b=log_natural2(num);
                  printf ("el logaritmo natural de %.2f es=%.4f\n\n",num,b);    
                }
             }
             else
             {
              printf ("no existe log natural de %.2f\n\n",num);
             }                    
        } 
        if (opcion==3)
        {
            printf("Ingrese el numero a calcular: \n");
            scanf("%f",&num);
            b=raiz (num);
            printf ("la raiz de %.3f es %.3f\n\n",num,b);          
        }
        if (opcion==4)
        {
           printf ("ingrese el numero\n"); 
           scanf ("%f", &num);           
           b=seno(num);
           printf ("el seno de %.2f es %.4f\n\n",num,b);
        }
        if (opcion==5)
        {
           printf ("ingrese el numero\n"); 
           scanf ("%f", &num);
           b=coseno(num);
           printf ("el coseno de %.2f es %.4f\n\n",num,b);
        }
        if (opcion==6)
        {
           printf ("ingrese el numero\n"); 
           scanf ("%f", &num);
           b=tangente(num);
           printf ("la tangente de%.2f es%.4f\n\n",num,b);
        }
        if (opcion==7)
        {
           printf ("ingrese la cantidad total de notas\n");
           scanf ("%d", &l);
           b=promedio(l);
           printf("el promedio de las %d notas es=%f\n\n",l,b);
        }
        if (opcion==8)
        {
           printf ("ingrese el numero\n"); 
           scanf ("%f", &num);
           b=exponencial(num);
           printf ("la exponencial de %f es= %.4f\n\n",num,b);
        }
        if (opcion==9)
        {
           printf ("\nIngrese el numero\n");
           scanf ("%f",&num);
           printf ("a cuantas veces lo decea elevar\n");
           scanf ("%f",&c);
           b=potencia(num,c);
           printf("\n");
           printf ("El numero %.2f elevado a %.2f es=%.2f\n\n",num,c,b);
        }
        if (opcion==10)
        {
           printf ("ingrese la cantidad total de numeros\n");
           scanf ("%d", &l);
           b=suma(l);
           printf ("la suma de los %d numeros es=%.2f\n\n",l,b);  
        }
        if (opcion==11)
        {
           printf ("ingrese el minuendo\n");
           scanf ("%f", &num);          
           printf ("ingrese el sustraendo\n");
           scanf ("%f", &a);
           b= resta(num,a);
           printf ("el resultado entre la resta de %f y %a es =%.4f\n\n",num,a,b);
         }
        if (opcion==12)
        {
           printf ("ingrese la cantidad total de numeros que decea multiplicar\n");
           scanf ("%d", &l);   
           b= multiplicacion(l);           
           printf ("la multiplicacion de los %d numeros es=%.2f\n\n",l,b);
        }
        if (opcion==13)
        {
           printf ("ingrese el divisor\n");
           scanf ("%f", &num);
           printf ("ingrese el dividendo\n");
           scanf ("%f", &a);
           b= division(num,a);
           printf ("la division entre %.2f y %.2f es =%.4f\n\n",num,a,b);
        }
        system("\n\npause");  
                      
        } 
     while (opcion!=0);
     printf ("\n\n********************FINN********************\n"); 
     printf ("\n\n***************Luis Miguel Leon***************\n");
     printf ("****************Felipe Moncada***************\n");      
  system ("pause>nul");
}




int factorial (int l)
{
    int a,i;
    i=1;
    a=1;
    while (i<=l)
    {
    a=a*i;
    i++;
    }
    return a;
}

float log_natural1 (float num)
{
    float d,a=1,b=0,c,h=(-1);
    int i,j;  
    d = (num-1);
    for(i=1;i<=30;i++)
    {
                     for(j=i;j<=i;j++)
                     {
                           a=a*d;           
                     }
                     h=h*(-1);
                     c=a/i;
                     c=c*h;
                     b=b+c;
    }
    return b;    
}

float log_natural2(float num)
{
   int i,j;
   float e,pot=1,x;
   e=(2.718281828);
   x=(num-1);
   for(i=1;i<=30;i++)
   {
     for(j=1;j<=x;j++)
     {
     pot=pot*e;
     }
     x=(x+(num/pot))-1;
   }
   return x;
}
      




float raiz (float num)
{
    int i;
    float a,b,c;
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
    return b;
}

float seno (float num)
{
    float b,c,d,e,f;
    int i;
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
    return c;
}

float coseno(float num)
{
    float b,c,d,e,f,g;
    int i;
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
    return c;
}

float tangente (float num)
{
   float a,b,c;
   a=seno(num);
   b=coseno(num);
   c=a/b;
   return c;
}

float promedio(int l)
{
      float a,b,c,promedio,notas;
      int i;
      a=0;
      for (i=1; i<=l; i++)
      {
        printf ("ingrese la nota numero %d\n",i);
        scanf ("%f", &notas);
        a=a+notas;
      }
      promedio=a/l;
      return promedio;
}

float exponencial(float num)
{
    float b,c,d,e,f;
    int i;
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
    return c;
}

float potencia (float num,float c)
{
   int i; 
   float x;  
   x=1;
   for(i=1;i<=c;i++)
   {
      x=x*num;
   }   
   return x;
}

float suma (int l)
{
   int i;
   float x1,x2;
   x1=0;
   for (i=1; i<=l; i++)
   {
       printf ("ingrese el numero %d\n",i);
       scanf ("%f", &x2);
       x1=x1+x2;
   }   
   return x1;
}

float resta (float num,float a)
{
      float c;
      c=num-a;
      return c;
}

float multiplicacion (int l)
{
      int i;
      float x1,x2;
      x1=1;
      for (i=1; i<=l; i++)
      {
         printf ("ingrese el numero %d\n",i);
         scanf ("%f", &x2);
         x1=x1*x2;
      }
      return x1;
}

float division (float num,float a)
{
      float c;
      c=num/a;
      return c;
}           
           
           
                