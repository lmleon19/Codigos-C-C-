/*
Ejemplo de:
    Calculo mejor alumno de un curso
*/

#define MAX 100
#include<stdio.h>
#include<stdlib.h>

typedef struct Persona
{
     int Ide;
     int Edad;
     float Peso;
     float Altura;       
}Persona;

typedef struct Alumno
{
     Persona Datos;
     int AgnoIngreso;
     float Notas[3];
}Alumno;

typedef struct Curso
{
     Alumno Arreglo[MAX];
     int NumProfesor;       
}Curso;
    


void llenaCurso (Curso *C, int n)
{
     int i,j;
     for (i=0 ;i<n ;i++)
     {
        printf("Identificacion      : ");
        scanf("%d", &(((((*C).Arreglo[i]).Datos).Ide)));   
        printf("Edad                : ");
        scanf("%d",&(((((*C).Arreglo[i]).Datos).Edad)));
        printf("Peso                : ");
        scanf("%f", &(((((*C).Arreglo[i]).Datos).Peso))); 
        printf("Altura              : ");
        scanf("%f", &(((((*C).Arreglo[i]).Datos).Altura))); 
        printf("Año de ingreso      : ");
        scanf("%d", &((((*C).Arreglo[i]).AgnoIngreso)));
        for (j=0 ;j<3 ;j++)
        {
          printf("ingrese la nota %d   : ",j+1);
          scanf("%f", &((((*C).Arreglo[i]).Notas[j])));  
        }    
     } 
}


void muestraCurso (Curso C, int n)
{ 
  int i,j;
  for (i=0 ;i<n ;i++)
  {
        printf("Identificacion      :%d\n",C.Arreglo[i].Datos.Ide);
        printf("La Edad             :%d\n",C.Arreglo[i].Datos.Edad);
        printf("Su Peso             :%.2f\n",C.Arreglo[i].Datos.Peso);
        printf("La altura           :%.2f\n",C.Arreglo[i].Datos.Altura);
        printf("El año de ingreso es:%d\n",C.Arreglo[i].AgnoIngreso);
        for (j=0 ;j<3 ;j++)
        {
           printf("La nota %d es :%.2f\n",j+1,C.Arreglo[i].Notas[j]);
        }
  }

}


int mejorCurso(Curso C, int n)
{
    int i,j,x;
    float a,aux;
    aux=0,0;
    for (i=0 ;i<n ;i++)
    {
        for (j=0 ;j<3 ;j++)
        {
           a=a+C.Arreglo[i].Notas[i];
        }
        a=a/3;
        while (a>aux)
        {
            aux=a;
            x=C.Arreglo[i].Datos.Ide;
        }
    }
    return x;
    
}

void despliegaCurso(Curso C, int n)
{ 
    int i,f;
    float g;
    printf ("Los alumnos que ingresaron antes del 2003 y pesan mas de 60 kilos son:");  
    for (i=0 ;i<n ;i++)
    {
        if ((C.Arreglo[i].AgnoIngreso<2003) && (C.Arreglo[i].Datos.Peso>60))
        {
            printf("\n\n\n");                                 
            printf("Identificacion      :%d\n",C.Arreglo[i].Datos.Ide);
            printf("Su Edad es          :%d\n",C.Arreglo[i].Datos.Edad);                                                           
        }
    }
    printf ("\n\n\n");       
}
int main()
{
    Curso C;
    int n, x;
    printf("Ingrese Cantidad de Alumnos : ");
    scanf("%d",&n); 
    llenaCurso(&C,n);
    muestraCurso(C,n);  
    
    //identificador del mejor alumno
    x = mejorCurso(C,n);
    printf("El mejor alumno es %d\n",x); 
    /* muestra IDE y EDAD de los alumnos que ingresan antes del 2003 y pesan mas de 60 kilos */
    despliegaCurso(C, n);   
    system("pause");
} 

