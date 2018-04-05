/*
Ejemplo de:
    Reserva de Vuelos de avion en consola
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


typedef struct nodo
{       char vuelo[10];
        char horasalida[10];
        char inicio[15];
        char horallegada[10];
        char llegada[15];
        struct nodo *link;
}nodo;
typedef nodo *lista;

//******************************************************************************

typedef struct cliente {
  int rut;
  char nombre1[15];
  char nombre2[15];
  char nombre3[15];
  char nombre4[15];
  int telefono;
  char direccion[30];
}cliente;

//******************************************************************************

typedef struct reserva {
  int rut;
  int asiento;
  char vuelo[10];
  int fecha;
  char idaovuelta[10];
}reserva;

//******************************************************************************
//******************************************************************************
//******************************************************************************  
float precio_final_de_vuelo(reserva pasaje);        //**************************
float precio_final_de_vuelo2(reserva pasaje);       //**************************
int convertir_a_digito (int mes, int dia, int ano); //**************************
int validar_numero_vuelo (char aux[]);              //**************************
int contardigitos (int ano);                        //**************************
int validar_fecha (int dia , int mes , int ano);    //**************************
int validacion_de_espacio(reserva pasaje);          //**************************
void precios_aviones();                             //**************************
void posicion_asientos();                           //**************************
void info_aviones();                                //**************************
void mostra_informacion();                          //**************************
void viajes_ida();                                  //**************************
void leer_archivo();                                //**************************
void buscar_archivo();                              //**************************
void viajes_vuelta();                               //**************************
void leer_archivo2();                               //**************************
void buscar_archivo2();                             //**************************
//******************************************************************************
//******************************************************************************  
//******************************************************************************

int main()
{
  int opcion,opc;
  
  
  do{
     system("cls");
     
     printf("[][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]");
     printf("[][][][][][][][][][][][][]                        [][][][][][][][][][][][][][][]");
     printf("[][][][][][][][][][][][][]      AIR EXPRESS       [][][][][][][][][][][][][][][]\n");
     printf("                             ------------------\n");
     printf("                             \n");
     printf("  \\ \\***MENU PRINCIPAL***//                         \n\n");
     printf(" [1]  Informacion de vuelos, precios, etc.\n");
     printf(" [2]  Reservar vuelos.\n");
     printf(" [3]  Mostrar asientos disponibles.\n");
     printf(" [4]  Buscar vuelos ya encargados.\n");
     printf(" [0]  Salir. \n\nIngrese su opcion:");
     scanf("%d", &opcion);
     if(opcion==1)
     {
               mostra_informacion();
     }
     if(opcion==2)
     {        
              system("cls");
              printf("\n\n\nRESERVAS DE VUELOS\n\n\n");         
              printf(" [1] Viajes de ida\n");
              printf(" [2] Viajes de ida y vuelta\n"); 
              printf("    \nIngrese su opcion:");   
              scanf("%d", &opc);
              if (opc==1)
              {
                  viajes_ida();
              }
              if(opc==2)
              {
                  viajes_ida();
                  viajes_vuelta();
              }     
     }
     if(opcion==3)
     {         
              system ("cls"); 
              printf("\n\n\nMUESTRA DE RESERVA DE VUELOS\n\n\n");         
              printf(" [1] Viajes de ida\n");
              printf(" [2] Viajes de vuelta\n"); 
              printf("  \nIngrese su opcion:");   
              scanf("%d", &opc);
              if (opc==1)
              {
                  leer_archivo();
              }
              if(opc==2)
              {
                  leer_archivo2();
              }
               
                    
     }
     if(opcion==4)
     { 
              system ("cls"); 
              printf("\n\n\nMUESTRA DE RESERVA DE VUELOS\n\n\n");         
              printf(" [1] Viajes de ida\n");
              printf(" [2] Viajes de vuelta\n"); 
              printf("  \nIngrese su opcion:");   
              scanf("%d", &opc);
              if (opc==1)
              {
                  buscar_archivo();
              }
              if(opc==2)
              {
                  buscar_archivo2();
              }    
     }
     
  }while(opcion!=0);
  
system ("pause");
}

//******************************************************************************

void viajes_ida()
{
  int i,x,a,b,y,l;
  float z;
  char vue[10],aux[10];
  char ida[5]={"ida"};

  int dia,mes,ano;
  FILE *reservas;
  FILE *clientes;
  reserva pasaje;
  cliente ficha;
  strcpy(pasaje.idaovuelta,ida);
  system("cls");
  // Lectura de datos por teclado
    printf("\n\nINGRESO DE DATOS\n\n");
    
    do{               
         printf("\n[]Introduzca la fecha cuando va a viajar :");
         scanf("%d",&a);
         b=a;
         dia=b/1000000;
         b=b%1000000;
         mes=b/10000;
         b=b%10000;
         ano=b;
         b=validar_fecha(dia,mes,ano); 
         if(b==1)
         {
             pasaje.fecha=a;
             y=0;   
         }
         else
         {
             y=1;
             printf("La fecha esta erronea no sirve para guardar\n");
         }   
    }while(y!=0);
    
    do{ 
         printf("\n[]Introduzca num de rut :");
         scanf("%d",&a);
         ano=a;
         b=contardigitos (ano);
         if(b==8)
         {
            ficha.rut=a;
            pasaje.rut=a;
            y=0;
         }
         else
         {
            y=1;
            printf("El RUT esta erronea no sirve para guardar\n"); 
         }
      }while(y!=0);  
  
    printf("\n[]Introduzca nombre completo (2 nombres y 2 apellidos :");
    scanf("%s",ficha.nombre1);
    scanf("%s",ficha.nombre2);
    scanf("%s",ficha.nombre3);
    scanf("%s",ficha.nombre4);
    
    do{
            printf("\nIntroduzca vuelo :");
            scanf("%s",&vue);
            vue[0] = toupper(vue[0]);
            vue[1] = toupper(vue[1]);
            vue[2] = toupper(vue[2]);
            strcpy(aux,vue);
            b=validar_numero_vuelo (aux);
            if(b==1)
            {
                strcpy(pasaje.vuelo,vue);
                y=0;
            }
            if(b==0)
            {
                y=1;
                printf("El Vuelo no existe\n"); 
            }
            
      }while(y!=0);
    printf("\nASIENTOS\n\n");
    do{
        printf("[1]Primera clase\n");
        printf("[2]Clase economica\n");
        printf("\nIngrese su opcion:");
        scanf("%d",&a);
        if (a==1)
        {
              printf ("[]Ingrese su numero de asiento");
              scanf ("%d",&b);
              if (b<19)
              {
                  pasaje.asiento=b;
                  y=1;
              }
              else
              {
               printf("el numero ingresado no existe o es de clase economica");  
               y=0;
              }
        }         
        if(a==2)
        {
             printf ("[]Ingrese su numero de asiento"); 
             scanf ("%d",&b);
             if(b>19 && b<149)
             {
                  pasaje.asiento=b;
                  y=1;
             }
             else
             {
               printf("el numero ingresado no existe o es de primera clase");  
               y=0;
              }
        } 
    }while(y!=1); 
    
    printf("[]Ingrese su direccion : ");
    scanf ("%s",&ficha.direccion);
    printf("[]Ingrese su telefono : ");
    scanf ("%d",&ficha.telefono);
    printf("\nFecha: %d\n",pasaje.fecha);
    printf("Asiento: %d\n",pasaje.asiento);
    printf("Vuelo: %s\n",pasaje.vuelo);
    printf("RUT: %d\n",pasaje.rut);
    printf("RUT: %d\n",ficha.rut);
    printf("Telefono: %d\n",ficha.telefono);
    printf("Nombre %s %s %s %s\n",ficha.nombre1,ficha.nombre2,ficha.nombre3,ficha.nombre4);
    printf("Direccion: %s\n",ficha.direccion);
    system ("pause");
    
    x=validacion_de_espacio(pasaje);

    z=precio_final_de_vuelo(pasaje);


    if(x!=1)
        printf("LO SENTIMOS EL PUESTO QUE SOLICITA YA SE ENCUENTRA RESERVADO");
    else
    {     
       printf("\n\nEL VUELO SALE :%f\nLo compra\n1)si\n2)no",z); 
       scanf("%d",&l);  
       if(l==1)
       {  
          // Grabación del archivo
          clientes = fopen("clientes.dat","a+t");
          if (clientes == NULL) 
              printf("Error al abrir el archivo");
          else
          {
              fwrite(&ficha,sizeof(cliente),1,clientes);
          }  
          fclose(clientes);
          fflush(stdin);
          reservas = fopen("reservas.dat","a+t");
          if (reservas == NULL) 
              printf("Error al abrir el archivo");
          else
          {
              fwrite(&pasaje,sizeof(reserva),1,reservas);
              printf("\n\n***************PASAJERO GUARDADO***************\n");  
          }
          fclose(reservas);     
          fflush(stdin);
       }
       
    }

  system("pause");
}

//******************************************************************************

void leer_archivo()
{
  FILE *reservas;
  FILE *clientes;
  reserva pasaje;
  char vuelo[8],vector[150];
  int fecha,x=0,i,j;
  
  printf ("[]Ingrese la fecha en la cual decea viajar:");
  scanf ("%d",&fecha);
  printf ("[]Ingrese el nombre del vuelo:");
  scanf ("%s",&vuelo);
  vuelo[0] = toupper(vuelo[0]);
  vuelo[1] = toupper(vuelo[1]);
  vuelo[2] = toupper(vuelo[2]);
  // Lectura de datos desde el archivo
  reservas = fopen("reservas.dat","rb");
  if (reservas == NULL) 
       printf("Error al abrir el archivo");
  else
  {
      system("cls");
      while(!feof(reservas))
      {
         fread(&pasaje,sizeof(reserva),1,reservas);
         if(!feof(reservas))
         {
            if(pasaje.idaovuelta[0]== 'i')
            {    
                if(pasaje.fecha==fecha)
                 {
                    if (pasaje.vuelo[4]==vuelo[4] && pasaje.vuelo[5]==vuelo[5])
                    {                 
                        vector[x]=pasaje.asiento;
                        x++;
                    }
                 }
            }
         }
      }
     fclose(reservas);
     fflush(stdin); 
  }
  printf("\n\n                     NUMERO DE ASIENTOS DISPONIBLES\n\n");
  for(i=0;i<148;i++)
  {
     int a=0;               
     for(j=0;j<x;j++)
     {               
         if (vector[j]!=i)
             a++;              
     }
     if(a==x)
            printf ("%d   ",i+1);
  }
  
  printf("\n\n");
  
  
  
  system("pause");
}

//******************************************************************************

void buscar_archivo()
{
  int s=0,buscado;
  FILE *reservas;

  reserva pasaje;

  // Lectura de datos desde el archivo
  reservas = fopen("reservas.dat","rb");
  if (reservas == NULL)
        printf("Error al abrir el archivo");
  else
  {
      system("cls");
      printf("\n\nBUSQUEDA DE PASAJERO\n\n");
      printf("Introduzca num de RUT a buscar:");
      scanf("%d",&buscado);
      while(!feof(reservas))
      {
         fread(&pasaje,sizeof(reserva),1,reservas);         
         if(!feof(reservas) && pasaje.rut==buscado)
         {               
                 printf("\n\nNum rut: %d", pasaje.rut);
                 printf("\nAsiento: %d", pasaje.asiento);
                 printf("\nFecha: %d", pasaje.fecha);
                 printf("\nVuelo: %s", pasaje.vuelo);
                 printf("\nVuelo: %s", pasaje.idaovuelta);
                 printf("\n***********************************\n");
                 
            s++;
         }
      }
      fclose(reservas);
     
  }
  if(s==0) printf("\n\nNO SE ENCONTRO EL PASAJERO");
  fflush(stdin);
  
  system("pause");
}

//******************************************************************************

void viajes_vuelta()
{
  int i,x,a,b,y,l;
  float z;
  char vue[10],aux[10];
  char ida[5]={"ida"};

  int dia,mes,ano;
  FILE *reservas;
  FILE *clientes;
  reserva pasaje;
  cliente ficha;
  strcpy(pasaje.idaovuelta,ida);
  system("cls");
  // Lectura de datos por teclado
    printf("\n\nINGRESO DE DATOS\n\n");
    
    do{               
         printf("\n[]Introduzca la fecha cuando va a viajar :");
         scanf("%d",&a);
         b=a;
         dia=b/1000000;
         b=b%1000000;
         mes=b/10000;
         b=b%10000;
         ano=b;
         b=validar_fecha(dia,mes,ano); 
         if(b==1)
         {
             pasaje.fecha=a;
             y=0;   
         }
         else
         {
             y=1;
             printf("La fecha esta erronea no sirve para guardar\n");
         }   
    }while(y!=0);
    
    do{ 
         printf("\n[]Introduzca num de rut :");
         scanf("%d",&a);
         ano=a;
         b=contardigitos (ano);
         if(b==8)
         {
            ficha.rut=a;
            pasaje.rut=a;
            y=0;
         }
         else
         {
            y=1;
            printf("El RUT esta erronea no sirve para guardar\n"); 
         }
      }while(y!=0);  
  
    printf("\n[]Introduzca nombre completo (2 nombres y 2 apellidos :");
    scanf("%s",ficha.nombre1);
    scanf("%s",ficha.nombre2);
    scanf("%s",ficha.nombre3);
    scanf("%s",ficha.nombre4);
    
    do{
            printf("\n[]Introduzca vuelo :");
            scanf("%s",&vue);
            vue[0] = toupper(vue[0]);
            vue[1] = toupper(vue[1]);
            vue[2] = toupper(vue[2]);
            strcpy(aux,vue);
            b=validar_numero_vuelo (aux);
            if(b==1)
            {
                strcpy(pasaje.vuelo,vue);
                y=0;
            }
            if(b==0)
            {
                y=1;
                printf("El Vuelo no existe\n"); 
            }
            
      }while(y!=0);
    printf("\nASIENTOS\n\n");
    do{
        printf("[1]Primera clase\n");
        printf("[2]Clase economica\n");
        printf("\nIngrese su opcion:");
        scanf("%d",&a);
        if (a==1)
        {
              printf ("[]ingrese su numero de asiento");
              scanf ("%d",&b);
              if (b<19)
              {
                  pasaje.asiento=b;
                  y=1;
              }
              else
              {
               printf("el numero ingresado no existe o es de clase economica");  
               y=0;
              }
        }         
        if(a==2)
        {
             printf ("[]Ingrese su numero de asiento"); 
             scanf ("%d",&b);
             if(b>19 && b<149)
             {
                  pasaje.asiento=b;
                  y=1;
             }
             else
             {
               printf("el numero ingresado no existe o es de primera clase");  
               y=0;
              }
        } 
    }while(y!=1); 
    
    printf("[]Ingrese su direccion : ");
    scanf ("%s",&ficha.direccion);
    printf("[]Ingrese su telefono : ");
    scanf ("%d",&ficha.telefono);
    
    printf("\nFecha: %d\n",pasaje.fecha);
    printf("Asiento: %d\n",pasaje.asiento);
    printf("vuelo: %s\n",pasaje.vuelo);
    printf("RUT: %d\n",pasaje.rut);
    printf("RUT: %d\n",ficha.rut);
    printf("Telefono: %d\n",ficha.telefono);
    printf("Nombre %s %s %s %s\n",ficha.nombre1,ficha.nombre2,ficha.nombre3,ficha.nombre4);
    printf("Direccion: %s\n",ficha.direccion);
    system ("pause");
    
    x=validacion_de_espacio(pasaje);

    z=precio_final_de_vuelo2(pasaje);


    if(x!=1)
        printf("LO SENTIMOS EL PUESTO QUE SOLICITA YA SE ENCUENTRA RESERVADO");
    else
    {     
       printf("\n\nEL VUELO SALE :%f\nLo compra\n1)si\n2)no",z); 
       scanf("%d",&l);  
       if(l==1)
       {  
          // Grabación del archivo
          clientes = fopen("clientes.dat","a+t");
          if (clientes == NULL) 
              printf("Error al abrir el archivo");
          else
          {
              fwrite(&ficha,sizeof(cliente),1,clientes);
          }  
          fclose(clientes);
          fflush(stdin);
          reservas = fopen("reservas.dat","a+t");
          if (reservas == NULL) 
              printf("Error al abrir el archivo");
          else
          {
              fwrite(&pasaje,sizeof(reserva),1,reservas);
              printf("\n\n***************PASAJERO GUARDADO***************\n");  
          }
          fclose(reservas);     
          fflush(stdin);
       }
       
    }

  system("pause");
}

//******************************************************************************

void leer_archivo2()
{
  FILE *reservas;
  FILE *clientes;
  reserva pasaje;
  char vuelo[8],vector[150];
  int fecha,x=0,i,j;
  
  printf ("[]Ingrese la fecha en la cual decea viajar:");
  scanf ("%d",&fecha);
  printf ("[]Ingrese el nombre del vuelo:");
  scanf ("%s",&vuelo);
  vuelo[0] = toupper(vuelo[0]);
  vuelo[1] = toupper(vuelo[1]);
  vuelo[2] = toupper(vuelo[2]);
  // Lectura de datos desde el archivo
  reservas = fopen("reservas.dat","rb");
  if (reservas == NULL) 
       printf("Error al abrir el archivo");
  else
  {
      system("cls");
      while(!feof(reservas))
      {
         fread(&pasaje,sizeof(reserva),1,reservas);
         if(!feof(reservas))
         {
            if(pasaje.idaovuelta[0]== 'v')
            {    
                if(pasaje.fecha==fecha)
                 {
                    if (pasaje.vuelo[4]==vuelo[4] && pasaje.vuelo[5]==vuelo[5])
                    {                 
                        vector[x]=pasaje.asiento;
                        x++;
                    }
                 }
            }
         }
      }
     fclose(reservas);
     fflush(stdin); 
  }
  printf("\n\n                     NUMERO DE ASIENTOS DISPONIBLES\n\n");
  for(i=0;i<148;i++)
  {
     int a=0;               
     for(j=0;j<x;j++)
     {               
         if (vector[j]!=i)
             a++;              
     }
     if(a==x)
            printf ("%d   ",i+1);
  }
  
  printf("\n\n");
  
  
  
  system("pause");
}

//******************************************************************************

void buscar_archivo2()
{
  int s=0,buscado;
  FILE *reservas;

  reserva pasaje;

  // Lectura de datos desde el archivo
  reservas = fopen("reservas.dat","rb");
  if (reservas == NULL)
        printf("Error al abrir el archivo");
  else
  {
      system("cls");
      printf("\n\nBUSQUEDA DE PASAJERO\n\n");
      printf("[]Introduzca num de RUT a buscar:");
      scanf("%d",&buscado);
      while(!feof(reservas))
      {
         fread(&pasaje,sizeof(reserva),1,reservas);         
         if(!feof(reservas) && pasaje.rut==buscado)
         {               
                 printf("\n\nNum rut: %d", pasaje.rut);
                 printf("\nAsiento: %d", pasaje.asiento);
                 printf("\nFecha: %d", pasaje.fecha);
                 printf("\nVuelo numero: %s", pasaje.vuelo);
                 printf("\nVuelo de: %s", pasaje.idaovuelta);
                 printf("\n***********************************\n");
                 
            s++;
         }
      }
      fclose(reservas);
     
  }
  if(s==0) printf("\n\nNO SE ENCONTRO EL PASAJERO");
  fflush(stdin);
  
  system("pause");
}

//******************************************************************************

float precio_final_de_vuelo(reserva pasaje)
{
   char A[20][20] = {"Santiago","AXS002","AXS003","AXS004","AXS005","AXS006","AXS007","AXS008","AXS009","AXS010","AXS011","AXS012","AXS013","AXS014","AXS015","AXS016","AXS017","AXS018","AXS019","AXS020"};
    int a,b,ori,des,s,dia,mes,ano,c,i;
    int y=0;
    float xdia1=0.05,xdia2=0.05,pasaje1,h,total1,total2;
          
         s=pasaje.fecha;
         dia=s/1000000;
         s=s%1000000;
         mes=s/10000;
         s=s%10000;
         ano=s;
    
         if(ano==2010)
         {
            if(mes<7)
            {   
               if(dia<31)
               {
                    b=convertir_a_digito (mes,dia,ano);
                    y=1;
               }   
           }      
        }
        if(ano==2009)
        {
            if(mes>7 && mes<13)
            {
                if(dia<31)
                {
                    b=convertir_a_digito (mes,dia,ano);
                    y=1;
                } 
           }
       }
       if(ano==2010)
       {
          if(mes==7)
          {  
              if(dia<31)
              {
                   b=convertir_a_digito (mes,dia,ano);
                   y=1;
              }       
          }
       }
       if(ano==2009)
       {
          if(mes==7)
          {  
              if(dia<31)
              {
                   b=convertir_a_digito (mes,dia,ano);
                   y=1;
              } 
         }
       }
    printf("%d\n",b);
    
      
      c=pasaje.asiento;
      if(c>18)
         c=1;
      if(c<19)
         c=0;
         
      ori=1;     
      for(i=0;i<20;i++)
      { 
          if(pasaje.vuelo[3]==A[i][3])
              des=i;
      }   

         printf("\n ORIGEN: %s\n",A[ori-1]);
         printf("\n DESTINO: %s\n",A[des-1]);
    if ((ori==1||ori==2)&&(des==1||des==2))
    {
              pasaje1=164000;
              printf("\n\n%f\n",pasaje);
    }
    if((ori==1||ori==3)&&(des==1||des==3))
    {
               pasaje1=160000;
               printf("\n%f\n",pasaje);
    }
    if((ori==1||ori==4)&&(des==1||des==4))
    {
               pasaje1=174000;
               printf("\n%f\n",pasaje);         
    }
    if((ori==1||ori==5)&&(des==1||des==5))
    {
               pasaje1=127800;
               printf("\n%f\n",pasaje);                           
    }
    if((ori==1||ori==6)&&(des==1||des==6))
    {
               pasaje1=97600;
               printf("\n%f\n",pasaje);                           
    }
    if((ori==1||ori==7)&&(des==1||des==7))
    {
               pasaje1=77900;
               printf("\n%f\n",pasaje);                           
    }
    if((ori==1||ori==8)&&(des==1||des==8))
    {
               pasaje1=99000;
               printf("\n%f\n",pasaje);                           
    }
    if((ori==1||ori==9)&&(des==1||des==9))
    {
               pasaje1=142000;
               printf("\n%f\n",pasaje);                  
    }
    if((ori==1||ori==10)&&(des==1||des==10))
    {
               pasaje1=188900;
               printf("\n%f\n",pasaje);                
    }
    if((ori==1||ori==11)&&(des==1||des==11))
    {
               pasaje1=197500;
               printf("\n%f\n",pasaje);                           
    }
    h=b;
    
    if(c==1)
    {
         total1=pasaje1-((xdia1*h*pasaje1)/100);
         total2=pasaje1*0.993-((xdia2*h*pasaje1)/100);
         return total1;
    }
    else
    {
         total1=pasaje1-((xdia1*h*pasaje1)/100);
         total1=total1+40000;
         total2=pasaje1*0.993-((xdia2*h*pasaje1)/100);
         total2=total2+38000;
         return total1;
    }
    system("pause");        
}

//******************************************************************************

float precio_final_de_vuelo2(reserva pasaje)
{
   char A[20][20] = {"Santiago","AXS002","AXS003","AXS004","AXS005","AXS006","AXS007","AXS008","AXS009","AXS010","AXS011","AXS012","AXS013","AXS014","AXS015","AXS016","AXS017","AXS018","AXS019","AXS020"};
    int a,b,ori,des,s,dia,mes,ano,c,i;
    int y=0;
    float xdia1=0.05,xdia2=0.05,pasaje1,h,total1,total2;
          
         s=pasaje.fecha;
         dia=s/1000000;
         s=s%1000000;
         mes=s/10000;
         s=s%10000;
         ano=s;
    
         if(ano==2010)
         {
            if(mes<7)
            {   
               if(dia<31)
               {
                    b=convertir_a_digito (mes,dia,ano);
                    y=1;
               }   
           }      
        }
        if(ano==2009)
        {
            if(mes>7 && mes<13)
            {
                if(dia<31)
                {
                    b=convertir_a_digito (mes,dia,ano);
                    y=1;
                } 
           }
       }
       if(ano==2010)
       {
          if(mes==7)
          {  
              if(dia<31)
              {
                   b=convertir_a_digito (mes,dia,ano);
                   y=1;
              }       
          }
       }
       if(ano==2009)
       {
          if(mes==7)
          {  
              if(dia<31)
              {
                   b=convertir_a_digito (mes,dia,ano);
                   y=1;
              } 
         }
       }
    printf("%d\n",b);
    
      
      c=pasaje.asiento;
      if(c>18)
         c=1;
      if(c<19)
         c=0;
         
      ori=1;     
      for(i=0;i<20;i++)
      { 
          if(pasaje.vuelo[3]==A[i][3])
              des=i;
      }   

         printf("\n ORIGEN: %s\n",A[ori-1]);
         printf("\n DESTINO: %s\n",A[des-1]);
    if ((ori==1||ori==2)&&(des==1||des==2))
    {
              pasaje1=164000;
              printf("\n\n%f\n",pasaje);
    }
    if((ori==1||ori==3)&&(des==1||des==3))
    {
               pasaje1=160000;
               printf("\n%f\n",pasaje);
    }
    if((ori==1||ori==4)&&(des==1||des==4))
    {
               pasaje1=174000;
               printf("\n%f\n",pasaje);         
    }
    if((ori==1||ori==5)&&(des==1||des==5))
    {
               pasaje1=127800;
               printf("\n%f\n",pasaje);                           
    }
    if((ori==1||ori==6)&&(des==1||des==6))
    {
               pasaje1=97600;
               printf("\n%f\n",pasaje);                           
    }
    if((ori==1||ori==7)&&(des==1||des==7))
    {
               pasaje1=77900;
               printf("\n%f\n",pasaje);                           
    }
    if((ori==1||ori==8)&&(des==1||des==8))
    {
               pasaje1=99000;
               printf("\n%f\n",pasaje);                           
    }
    if((ori==1||ori==9)&&(des==1||des==9))
    {
               pasaje1=142000;
               printf("\n%f\n",pasaje);                  
    }
    if((ori==1||ori==10)&&(des==1||des==10))
    {
               pasaje1=188900;
               printf("\n%f\n",pasaje);                
    }
    if((ori==1||ori==11)&&(des==1||des==11))
    {
               pasaje1=197500;
               printf("\n%f\n",pasaje);                           
    }
    h=b;
    
    if(c==1)
    {

         total2=pasaje1*0.98-((xdia2*h*pasaje1)/100);
         return total1;
    }
    else
    {
         total2=pasaje1*0.98-((xdia2*h*pasaje1)/100);
         total2=total2+36000;
         return total1;
    }
    system("pause");        
}

//******************************************************************************

int convertir_a_digito (int mes, int dia, int ano)
{
    int j;
                  if(mes==01)
                  {
                         j=153+16+dia;
                         return j;
                  }
                  if(mes==02)
                  {
                         j=184+16+dia;     
                         return j;
                  }
                  if(mes==03)
                  {
                         j=212+16+dia;
                         return j;   
                  }
                  if(mes==04)
                  {
                         j=243+16+dia;
                         return j;
                  }
                  if(mes==05)
                  {
                        j=273+16+dia;
                        return j;
                  }
                  if(mes==06)
                  {
                        j=304+16+dia;
                        return j;
                  }
                  if(mes==07)
                  {
                      if(dia<15)
                      {   
                        j=334+dia;
                        return j;
                      }
                      else
                      {
                        j=dia-15;
                        return j;
                      }
                  }
                  if(mes==8)
                  {
                        j=16+dia; 
                        return j;
                  }
                  if(mes==9)
                  {
                        j=31+16+dia; 
                        return j;   
                  }
                  if(mes==10)
                  {
                        j=61+16+dia;
                        return j;
                  }
                  if(mes==11)
                  {
                        j=92+16+dia;
                        return j;
                  }
                  if(mes==12)
                  {
                        j=122+16+dia; 
                        return j;  
                  }
}

//******************************************************************************

int validar_numero_vuelo (char aux[])
{
    char mar[20][10]={"AXS001","AXS002","AXS003","AXS004","AXS005","AXS006","AXS007","AXS008","AXS009","AXS010","AXS011","AXS012","AXS013","AXS014","AXS015","AXS016","AXS017","AXS018","AXS019","AXS020"};
    int i,j,cont=0;
    for (i=0;i<20;i++)
    {
       for(j=0;j<6;j++)
       {
          if(aux[j]!=mar[i][j])               
               cont++;
       }
       if(cont==0)
              return 1;
       cont=0;
    }
    
    return 0;
}

//******************************************************************************

int contardigitos (int ano)
{
    int z=0;
    while (ano>0)
    {
      z=z+1;
      ano=ano/10;
    }
    return z;
}

//******************************************************************************

int validar_fecha (int dia , int mes , int ano)
{
    if(ano==2010)
    {
       if(mes<7)
       {   
          if(dia<31)
             return 1;
       }      
    }
    if(ano==2009)
    {
       if(mes>7 && mes<13)
       {
          if(dia<31)
             return 1;
       }
    }
    if(ano==2010)
    {
      if(mes==7)
      {  
        if(dia<15)
            return 1;       
      }
    }
    if(ano==2009)
    {
      if(mes==7)
      {  
        if(dia>=15 && dia<32)
            return 1;
      }
    }
    return 0;
}

//******************************************************************************

int validacion_de_espacio(reserva pasaje)
{
  
  int buscador,buscador2;
  char buscador3[10];
  FILE *reservas;
  reserva pasaje2;
  // Lectura de datos desde el archivo
  reservas = fopen("reservas.dat","rb");
  if (reservas == NULL) 
         printf("");
  else
  {
      system("cls");
      
      buscador=pasaje.fecha;
      buscador2=pasaje.asiento;
      strcpy(buscador3,pasaje.vuelo);
      while(!feof(reservas))
      {
         fread(&pasaje2,sizeof(reserva),1,reservas);         
         if(!feof(reservas) && pasaje2.fecha==buscador && pasaje2.idaovuelta[0]==pasaje.idaovuelta[0] && pasaje2.asiento==buscador2 && pasaje2.vuelo[4]==buscador3[4] && pasaje2.vuelo[5]==buscador3[5])
         {
             printf("\n***********************************\n");
             return 0;
         }
      }
      //fclose(reservas);
      
  }
  fclose(reservas);
  fflush(stdin);
  return 1; 
}

//******************************************************************************


void precios_aviones()
{
    char A[20][20] = {"Santiago","Arica","Iquique","Antofagasta","Copiapo","La Serena","Talca","Concepcion","Puerto Montt","Balmaceda","Punta Arenas"};
    int a,b,ori,des,s,dia,mes,ano,c;
    int y=0;
    float xdia1=0.05,xdia2=0.05,pasaje,h,total1,total2;
    do{
         printf("ingrese la fecha que en la que desea viajar\n");
         scanf("%d",&b);
         s=b;
         dia=s/1000000;
         s=s%1000000;
         mes=s/10000;
         s=s%10000;
         ano=s;
    
         if(ano==2010)
         {
            if(mes<7)
            {   
               if(dia<31)
               {
                    b=convertir_a_digito (mes,dia,ano);
                    y=1;
               }   
           }      
        }
        if(ano==2009)
        {
            if(mes>7 && mes<13)
            {
                if(dia<31)
                {
                    b=convertir_a_digito (mes,dia,ano);
                    y=1;
                } 
           }
       }
       if(ano==2010)
       {
          if(mes==7)
          {  
              if(dia<31)
              {
                   b=convertir_a_digito (mes,dia,ano);
                   y=1;
              }       
          }
       }
       if(ano==2009)
       {
          if(mes==7)
          {  
              if(dia<31)
              {
                   b=convertir_a_digito (mes,dia,ano);
                   y=1;
              } 
         }
       }
       if(y!=1)
           printf("Esta fecha es incorrecta");
       
    }while(y!=1);
    printf("%d\n",b);
    
    printf("Ingrese en que clase va a viajar\n\n" 
           "1)Clase economica.\n"
           "2)Primera clase. \n");
           scanf("%d",&c);
         printf("\n\n PUNTOS DE EMBARQUE\n\n"
                "[1]  Santiago\n"
                "[2]  Arica\n"
                "[3]  Iquique\n"
                "[4]  Antofagasta\n"
                "[5]  Copiapo\n"
                "[6]  La Serena\n"
                "[7]  Talca\n"
                "[8]  Concepcion\n"
                "[9]  Puerto Montt\n"
                "[10] Balmaceda\n"
                "[11] Punta Arenas\n"
                "Indique el indice de Origen y Destino separado por un espacio\n");
         scanf("%d %d",&ori,&des);
         printf("\n ORIGEN: %s\n",A[ori-1]);
         printf("\n DESTINO: %s\n",A[des-1]);
    if ((ori==1||ori==2)&&(des==1||des==2))
    {
              pasaje=164000;
              printf("\n\n%f\n",pasaje);
    }
    if((ori==1||ori==3)&&(des==1||des==3))
    {
               pasaje=160000;
               printf("\n%f\n",pasaje);
    }
    if((ori==1||ori==4)&&(des==1||des==4))
    {
               pasaje=174000;
               printf("\n%f\n",pasaje);         
    }
    if((ori==1||ori==5)&&(des==1||des==5))
    {
               pasaje=127800;
               printf("\n%f\n",pasaje);                           
    }
    if((ori==1||ori==6)&&(des==1||des==6))
    {
               pasaje=97600;
               printf("\n%f\n",pasaje);                           
    }
    if((ori==1||ori==7)&&(des==1||des==7))
    {
               pasaje=77900;
               printf("\n%f\n",pasaje);                           
    }
    if((ori==1||ori==8)&&(des==1||des==8))
    {
               pasaje=99000;
               printf("\n%f\n",pasaje);                           
    }
    if((ori==1||ori==9)&&(des==1||des==9))
    {
               pasaje=142000;
               printf("\n%f\n",pasaje);                  
    }
    if((ori==1||ori==10)&&(des==1||des==10))
    {
               pasaje=188900;
               printf("\n%f\n",pasaje);                
    }
    if((ori==1||ori==11)&&(des==1||des==11))
    {
               pasaje=197500;
               printf("\n%f\n",pasaje);                           
    }
    h=b;
    
    if(c==1)
    {
         total1=pasaje-((xdia1*h*pasaje)/100);
         total2=pasaje*0.993-((xdia2*h*pasaje)/100);
         printf("HOY EL VALOR DE SU(S) PASAJE(S) ES(SON):\n\nSOLO IDA: %f\nIDA Y VUELTA: %f\n",total1,total2*2);
    }
    else
    {
         total1=pasaje-((xdia1*h*pasaje)/100);
         total1=total1+40000;
         total2=pasaje*0.993-((xdia2*h*pasaje)/100);
         total2=total2+38000;
         printf("HOY EL VALOR DE SU(S) PASAJE(S) ES(SON):\n\nSOLO IDA: %f\nIDA Y VUELTA: %f\n",total1,total2*2);
    }
    system("pause");    
}

//******************************************************************************

void posicion_asientos()
{
   printf("                             POSICION DE ASIENTOS                      \n");
   printf("                 |                                   |      \n");
   printf("                |          Primera Clase              |     \n");
   printf("               |                                       |   \n");
   printf("              |   A     B      C      D      F      G   |  \n");
   printf("             |                                           | \n");
   printf("             |   1      2      3      4      5      6    | \n");
   printf("             |   7      8      9      10     11     12   | \n");
   printf("             |   13     14     15     16     17     18   | \n");
   printf("             |                                           | \n");
   printf("             |             Econimica Clase               | \n");
   printf("             |                                           | \n");
   printf("             |   19     20     21     22     23     24   | \n");
   printf("             |   25     26     27     28     29     30   | \n");
   printf("             |   31     32     33     34     35     36   | \n");
   printf("             |   37     38     39     40     41     42   | \n");
   printf("             |   43     44     45     46     47     48   | \n");
   printf("             |   49     50     51     52     53     54   | \n");
   printf("             |   55     56     57     58     59     60   | \n");
   printf("             |   61     62     63     64     65     66   | \n");
   printf("             |   67     68     69     70     71     72   | \n");
   printf("             |   73     74     75     76     77     78   | \n");
   printf("             |   79     80     81     82     83     84   | \n");
   printf("             |   85     86     87     88     89     90   | \n");
   printf("             |   91     92     93     94     95     96   | \n");
   printf("             |   97     98     99     100    101    102  | \n");
   printf("             |   103    104    105    106    107    108  | \n");
   printf("             |   109    110    111    112    113    114  | \n");
   printf("             |   115    116    117    118    119    120  | \n");
   printf("             |   121    122    123    124    125    126  | \n");
   printf("             |   127    128    129    130    131    132  | \n");
   printf("             |   133    134    135    136    137    138  | \n");
   printf("             |   139    140    141    142    143    144  | \n");     
   printf("             |   145    146                  147    148  | \n"); 
   printf("              |                                         |  \n");
   printf("               |                                       |   \n");
   printf("                |                                     |    \n");
   printf("                 |                                   |     \n");
   printf("                  |                                 |      \n");
   printf("                   |                               |       \n");
   printf("                    |                             |        \n");
   system ("pause"); 
}

//******************************************************************************
                          
void info_aviones()
{
    char S[15]="SANTIAGO"; 
    char L[15][15]={"ARICA       ","IQUIQUE     ","ANTOFAGASTA ","COPIAPO     ","LA SERENA   ","TALCA       ","CONCEPCION  ","PUERTO MONTT","BALMACEDA   ","PUNTA ARENAS"}; 
    char horasS1[10][10]={"05:00.AM","06:00.AM","07:00.AM","08:00.AM","09:00.AM","*10:00.AM","11:00.AM","12:00.PM","*13:00.PM","14:00.PM"}; 
    char horasL1[10][10]={"07:40.AM","08:25.AM","09:00.AM","09:30.AM","10:00.AM","*07:00.AM","12:10.PM","13:45.PM","*07:00.PM","17:30.PM"}; 
    char horasS2[10][10]={"15:00.PM","16:00.PM","17:00.PM","18:00.PM","19:00.PM","*20:00.PM","21:00.PM","22:00.PM","*23:00.PM","24:00.PM"}; 
    char horasL2[10][10]={"17:40.AM","18:25.AM","19:00.AM","19:30.AM","20:00.PM","*07:00.AM","22:10.PM","23:45.PM","*07:00.AM","03:30.AM"}; 
    char nombreV[20][10]={"AXS001","AXS002","AXS003","AXS004","AXS005","AXS006","AXS007","AXS008","AXS009","AXS010","AXS011","AXS012","AXS013","AXS014","AXS015","AXS016","AXS017","AXS018","AXS019","AXS020"};
    
    int i;
    char pausa;
    lista p,k;
    FILE *infovuelos;
    p=NULL;
    
    for (i=0;i<20;i++)
    {
      lista l;
      l = (lista) malloc (sizeof(nodo));
      l->link=p;
      p=l;     
    }
    k=p;
    system("cls");
    
    for (i=0;i<10;i++)
    {
         strcpy(p->vuelo,nombreV[i]);
         strcpy(p->horasalida,horasS1[i]);
         strcpy(p->horallegada,horasL1[i]);
         strcpy(p->inicio,S);
         strcpy(p->llegada,L[i]);  
         p=p->link;
    }
    for (i=10;i<20;i++)
    {
         strcpy(p->vuelo,nombreV[i]);
         strcpy(p->horasalida,horasS2[i-10]);
         strcpy(p->horallegada,horasL2[i-10]);
         strcpy(p->inicio,S);
         strcpy(p->llegada,L[i-10]);  
         p=p->link;
    }
       
    printf("\n\n VUELO------LUGAR SALIDA------LUGAR LLEGADA------HORA SALIDA------HORA LLEGADA\n");
    printf("|         |               |                  |                |        \n");
    for (i=1;i<=20;i++)
    {
         printf("|         |               |                  |                |        \n");
         printf("| %s  | %s      |   %s   |   %s     |    %s\n",k->vuelo,k->inicio,k->llegada,k->horasalida,k->horallegada);
         k=k->link;
    }
    
    
  system("pause"); 
 
}

//******************************************************************************

void mostra_informacion()
{
     int opcion2;
     do{
         system("cls");
         printf("\n\n\nINFORMACIONES\n\n\n");
         printf("[1] Lugar salida, lugar llegada, hora salida, hora llegada,\n");
         printf("[2] Precios de vuelos segun fecha\n");
         printf("[3] Posicion de asientos\n");
         printf("[0] Volver a menu principal \n\n");
         printf("Ingrese su opcion:");
         scanf("%d", &opcion2);
         if(opcion2==1)
         {
              info_aviones();   
         }
         if(opcion2==2)
         {
              precios_aviones(); 
         }
         if(opcion2==3)
         {
              posicion_asientos(); 
         }  
      }while (opcion2!=0);    
}