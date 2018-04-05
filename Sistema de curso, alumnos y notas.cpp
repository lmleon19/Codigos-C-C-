/*
Ejemplo de:
    Sistema de curso, alumnos y notas
*/

#include<stdio.h>
#include<stdlib.h>

typedef struct alumno
{
   int ide;
   int edad;
   float notas[3];       
}alumno;

void llenarAlumno(alumno *A)
{
  int i;
  printf("Identificacion  : ");
  scanf("%d",&((*A).ide));   
  printf("Edad            : ");
  scanf("%d",&((*A).edad));   
  for(i=0; i<3; i++)
  {
     printf("Nota %d          : ",i+1);
     scanf("%f",&((*A).notas[i]));          
  }
}
void mostrarAlumno(alumno A)
{
  int i;
  printf("Identificacion : %d\n",A.ide);   
  printf("Edad           : %d\n",A.edad);   
  for(i=0; i<3; i++)
  {
     printf("Nota %d  : %f\n",i+1,A.notas[i]);          
  }
}

float promedioAlumno(alumno A)
{
  int i; 
  float s=0;
  for(i=0; i<3; i++)
  {
     s += A.notas[i];          
  }
  return s/3.0;
}
void llenarCurso(alumno C[], int n)
{ int i;
  for(i=0; i<n; i++)
  {
     llenarAlumno(&C[i]);         
  }   
}

void mostrarCurso(alumno C[], int n)
{ int i;
  for(i=0; i<n; i++)
  {
     mostrarAlumno(C[i]);         
  }   
}

int main()
{
  alumno C[45];
  int n;
  printf("Ingrese cantidad de alumnos : ");
  scanf("%d",&n);   

  llenarCurso(C, n);  
  mostrarCurso(C, n);  
  system("pause");    
}
