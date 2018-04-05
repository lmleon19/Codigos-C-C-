/*
Ejemplo de:
    Leer, Escribir y Buscar en un fichero
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct s_alumno {
  int rut;
  char nombre[30];
  int asiento;
  int vuelo;
  int fecha;
}s_alumno;

typedef s_alumno lista;


void leer_archivo();        // Prototipos
void escribir_archivo();
void buscar_archivo();

int main()
{
  char opcion;
  do{
     system("cls");
     printf("\n\n\nEJEMPLO CON FICHEROS\n\n\n 1) Ingresar alumno\n 2) Listar alumnos\n 3) Buscar alumno\n 0) Salir \n\nIngrese su opcion:");
     scanf("%c", &opcion);
     switch(opcion){
          case '1':{
               escribir_archivo();
               break;
               }
          case '2':{
               leer_archivo();
               break;
               }
          case '3':{
               buscar_archivo();
               break;
               }
     }
  }while(opcion!='0');
  return 0;
}

void leer_archivo()
{
  
  FILE *archivo;
  lista alumno;
  // Lectura de datos desde el archivo
  archivo = fopen("alumnos.dat","rb");
  if (archivo == NULL) printf("Error al abrir el archivo");
  else
  {
      system("cls");
      printf("\n\nLISTADO DE ALUMNOS\n\n");
      while(!feof(archivo))
      {
         fread(&alumno,sizeof(struct s_alumno),1,archivo);         
         if(!feof(archivo)){
            printf("\nNombre: %s ", alumno.nombre);
            printf("%s ",alumno.nombre2);
            printf("%s ",alumno.nombre3);
            printf("%s \n",alumno.nombre4);
            printf("\n\nNum rut: %d", alumno.rut);
            printf("\n\nNum telefono: %d", alumno.telefono);
            printf("\n\nDireccion: %s", alumno.direccioncasa);
            printf("\nasiento: %d\n\n", alumno.asiento);
            printf("\nvuelo: %d\n\n", alumno.vuelo);
            printf("\nvuelo: %d\n\n", alumno.vuelo);
            printf("***********************************\n");
         }
      }
      fclose(archivo);
  }
  fflush(stdin);
  system("pause");
}

void escribir_archivo()
{
  int i;
  char pausa;
  FILE *archivo;
  lista alumno;
  system("cls");
  // Lectura de datos por teclado
    printf("\n\nINGRESO DE DATOS\n\n");
    printf("Introduzca num de rut :");
    scanf("%d",&alumno.rut);
    printf("Introduzca nombre :");
    scanf("%s",alumno.nombre);
    printf("Introduzca asiento :");
    scanf("%d",&alumno.asiento);
    printf("Introduzca vuelo :");
    scanf("%d",&alumno.vuelo);
    
  // Grabación del archivo
  archivo = fopen("alumnos.dat","a+t");
  if (archivo == NULL) 
      printf("Error al abrir el archivo");
  else
  {
       fwrite(&alumno,sizeof(lista),1,archivo);
       printf("Alumno guardado...");
       fclose(archivo);
  }  
  fflush(stdin);
  system("pause");
}

void buscar_archivo()
{
  char pausa;
  int sw=0,buscado;
  FILE *archivo;
  lista alumno;
  // Lectura de datos desde el archivo
  archivo = fopen("alumnos.dat","rb");
  if (archivo == NULL) printf("Error al abrir el archivo");
  else
  {
      system("cls");
      printf("\n\nBUSQUEDA DE ALUMNO\n\n");
      printf("Introduzca num de vuelo a buscar:");
      scanf("%d",&buscado);
      while(!feof(archivo) && sw==0)
      {
         fread(&alumno,sizeof(lista),1,archivo);         
         if(!feof(archivo) && alumno.vuelo==buscado)
         {
            printf("\n\nNum rut: %i", alumno.rut);
            printf("\nNombre: %s", alumno.nombre);
            printf("\naseinto: %i\n\n", alumno.asiento);
            printf("***********************************");
            sw=1;
         }
      }
      fclose(archivo);
  }
  if(sw==0) printf("\n\nNO SE ENCONTRO EL ALUMNO");
  fflush(stdin);
  system("pause");
}
