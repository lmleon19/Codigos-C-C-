/*
Ejemplo de:
    Juego el Colgado
*/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<iostream.h>

int main() 
{
   char frase[60],rep[100],temporal[100]; 
    char pal;
      int longitud,i,j,inicial,acertado=0,temp=0,chance=5;
       bool repetido=false,gano=false;
       
     printf("Introduzca la palabra(s) a adivinar: ");
     gets(frase);

    system("clear");

    longitud = 0;
    inicial = 0;
    j = 0;

    rep[0] = ' ';
    rep[1] = '\0';


       do 
       {
	      system("clear");
          temp=0;
 
          if(inicial == 0) 
          {
             for(i=0;i<strlen(frase);i++) 
             {
                 if(frase[i] == ' ') 
                 {
                      temporal[i] = ' ';
                      longitud++;
                 }
                 else 
                 {
                      temporal[i] = '_';	
                      longitud++;
                 }
           }
         }

         inicial = 1;

         temporal[longitud] = '\0';

         for(i=0;i<strlen(rep);i++) 
         {
              if(rep[i] == pal) 
              {
                    repetido = true;
                    break;
              } 
              else 
              {
                    repetido = false;
              }
        }
 
        if(repetido == false) 
        {
             for(i=0;i<strlen(frase);i++) 
             {
	               if(frase[i] == pal) 
                   {
	                   temporal[i] = pal;
	                   acertado++;
	                   temp=1;
	               } 
            }
        }
 
 
        if(repetido == false) 
        {
            if(temp == 0) 
            {
                 chance = chance - 1;
            }
        }
        else 
        {
             printf("Caracter Repetido o Ya Consultado");
             printf("\n\n");
        }
 
         printf("\n");
 
        for(i=0;i<strlen(temporal);i++) 
        {
          printf(" %c ",temporal[i]);
        }
 
        printf("\n");
 
        if(strcmp(frase,temporal) == 0) 
        {
 	      gano = true;
	      break;
        }
 
        printf("\n");
        printf("Letras Acertadas: %d",acertado);
        printf("\n");
        printf("Oportunidades Restantes: %d",chance);
        printf("\n");
 
        rep[j] = pal;
        j++;
   
        printf("Introduzca un caracter para adivinar la cadena:");
        scanf("\n%c",&pal); 
      }while(chance != 0);


   if(gano) 
   {
    	printf("\n\n");
        printf("Felicitaciones, adivinastes la palabra");
   }
   else
   {
	   printf("\n\n");
       printf("Perdistes, mejor suerte para la proxima");
   }

   printf("\n\n");
   return 0;
} 