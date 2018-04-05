/*
Ejemplo de:
    Registro de equipos y jugadores de futbol 
*/

#include<stdio.h>
#include<stdlib.h>
#define MAX 3

typedef char texto[20];

typedef struct Jugador
{
   texto nombre;
   texto apellido;
   int edad;       
   int goles;   // goles convertidos por el jugador
} Jugador;

typedef struct Equipo
{
    texto nombreEquipo;
    Jugador Datos[MAX];
}Equipo;

typedef struct Partido
{
    int numPartido; 
    Equipo local;
    Equipo visita;
    int golesLocal;  // goles convertidos por el equipo local
    int golesVisita;  // goles convertidos por el equipo visita   
}Partido;

void llenaPartido(Partido *A)
{
    int i;
    printf ("ingrese el numero del partidos\n");
    scanf ("%d",&((*A).numPartido));
    printf ("ingrese el numbre del equipo local\n");
    scanf ("%s",&(((*A).local).nombreEquipo));
    for (i=0;i<MAX;i++)
    {
       printf ("numbre del jugador %d es:\n",i+1);
       scanf ("%s",&((((*A).local).Datos[i]).nombre));
       printf ("apellido del jugador %d es:\n",i+1);
       scanf ("%s",&((((*A).local).Datos[i]).apellido));
       printf ("edad del jugador %d es:\n",i+1);
       scanf ("%d",&((((*A).local).Datos[i]).edad));
       printf ("cantidad de goles del jugador %d es:\n",i+1);
       scanf ("%d",&((((*A).local).Datos[i]).goles));  
    }
    printf ("ingrese el numbre del equipo visita\n");
    scanf ("%s",&((*A).visita));
    for (i=0;i<MAX;i++)
    {
       printf ("numbre del jugador %d es:\n",i+1);
       scanf ("%s",&((((*A).visita).Datos[i]).nombre));
       printf ("apellido del jugador %d es:\n",i+1);
       scanf ("%s",&((((*A).visita).Datos[i]).apellido));
       printf ("edad del jugador %d es:\n",i+1);
       scanf ("%d",&((((*A).visita).Datos[i]).edad));
       printf ("cantidad de goles del jugador %d es:\n",i+1);
       scanf ("%d",&((((*A).visita).Datos[i]).goles));  
    }
}

void muestraPartido(Partido A) 
{
     int i;
     printf ("\n\n\n\n\n\n");
     printf ("el numero de partido es : %d\n",A.numPartido);
     printf ("el nombre del equipo local es : %s\n",A.local.nombreEquipo);
     for (i=0;i<MAX;i++)
     {
         printf ("el nombre del jugador %d es : %s\n",i+1,A.local.Datos[i].nombre);
         printf ("el apellido del jugador %d es : %s\n",i+1,A.local.Datos[i].apellido);
         printf ("la edad del jugador %d es : %d\n",i+1,A.local.Datos[i].edad);
         printf ("La cantidad de goles del jugador %d es : %d\n",i+1,A.local.Datos[i].goles);
     }
     printf ("el numbre del equipo visita es %s\n",A.visita);
     for (i=0;i<MAX;i++)
     {
         printf ("el nombre del jugador %d es : %s\n",i+1,A.visita.Datos[i].nombre);
         printf ("el apellido del jugador %d es : %s\n",i+1,A.visita.Datos[i].apellido);
         printf ("la edad del jugador %d es : %d\n",i+1,A.visita.Datos[i].edad);
         printf ("La cantidad de goles del jugador %d es : %d\n",i+1,A.visita.Datos[i].goles);
     }
     
     
}
char resultado(Partido A)
{
  char empate[20]={"empate"};   
  int i,x=0,y=0;   
  for (i=0;i<MAX;i++)
    {
       x=x+A.local.Datos[i].goles; 
    }
  for (i=0;i<MAX;i++)
    {
       y=y+A.local.Datos[i].goles; 
    }
  
  if (x>y)
      return *A.local.nombreEquipo; 
  if (x<y)  
      return *A.visita.nombreEquipo;
  if (x==y)  
      return *empate;   
}

int main()
{
   Partido A;
   llenaPartido(&A);
   muestraPartido(A);
   printf("Resultado del partido : %s\n",resultado(A));
//   printf("Goleador del partido  : %s\n",goleador(A));  
   system("pause");   
}