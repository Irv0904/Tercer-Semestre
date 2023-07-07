/*
	Name: Palindromo de palabra o frase
	Nota: 100
	Author: Irving Jhon Villarreal Lasso
	Date: 06/06/23 22:47
	Description: Este codigo sirve para servir si es un palindromo o no
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Definición de la estructura de un nodo de la p doblemente enlazada
typedef struct Nodo
{
   char caracter;
   struct Nodo *ligader;
   struct Nodo *ligaizq;
} Nodo;

Nodo *crear_memoria();
Nodo *crearListaPalabra();
int palindromo(Nodo *p);
void recorrerListader(Nodo *p);
void recorrerListaizq(Nodo *p);


int main()
{
   Nodo *p = crearListaPalabra();
   printf("\n\n\t\t\t   Lista generada:\n\t");
   Nodo *actual = p;
   printf("\t\t\t");
   while (actual != NULL)
   {
      printf("%c", actual->caracter);
      actual = actual->ligader;
   }
   printf("\n");

   recorrerListader(p); 
   recorrerListaizq(p);

   if (palindromo(p))
      printf("\n\n\t\tLa palabra es un palindromo.");
   else
      printf("\n\n\t\tLa palabra no es un palindromo.");
   return 0;

}

Nodo *crear_memoria()
{
   Nodo *p = (Nodo *)malloc(sizeof(Nodo));
   if (p == NULL)
   {
      printf("No hay memoria");
      getchar();
      exit(1);
   }
   return (p);
}

Nodo *crearListaPalabra()
{
   int i;
   Nodo *p = NULL;
   Nodo *q = NULL;

   char palabra[100];
   printf("Ingrese una palabra o frase: ");
   gets(palabra);

   int longitud = strlen(palabra);

   for (i = 0; i < longitud; i++)
   {
      char caracter = tolower(palabra[i]);
      // verfiicar si es un caracter alfabetica (mayusculas o minuscula)
      if (isalpha(caracter))
      {
         Nodo *t = crear_memoria();
         t->caracter = caracter;
         t->ligader = NULL;
         t->ligaizq = q;

         if (q != NULL)
         {
            q->ligader = t;
         }
         else
         {
            p = t;
         }

         q = t;
      }
   }
   return p;
}

int palindromo(Nodo *p)
{
   Nodo *q;
   Nodo *u = p;
   int r;
   // Buscar el ultimo
   while (u->ligader != NULL)
   {
      u = u->ligader;
   }

   for (q = p; q->ligader != NULL; q = q->ligader)
   {
      if (q->caracter == u->caracter)
      {
         u = u->ligaizq;
         r = 1;
      }
      else
      {
         r = 0;
         break;
      }
   }
   return r;
}

void recorrerListader(Nodo *p)
{
	printf("\n\t\t\tRECORRIENDO A LA DERECHA\n");
   Nodo *q = p;
   printf("\t\t(null)");
   while (q != NULL)
   {
      printf("<- %c ->", q->caracter);
      q = q->ligader;
   }
   printf("(null)\n");
}
void recorrerListaizq(Nodo *p)
{
	printf("\n\t\t\tRECORRIENDO A LA IZQUIERDA");
	Nodo *q = p;
	printf("\n\t\t(null)");
	while (q->ligader != NULL)
		q= q->ligader;
	while (q != NULL)
   	{
      printf("<- %c ->", q->caracter);
      q = q->ligaizq;
   	}
	printf("(null)");
	return;
}

Nodo *liberarlista (Nodo *p){
   Nodo *actual = p;
   while (actual != NULL)
   {
      p = actual->ligader;
      actual->ligaizq = NULL; 
      free(actual);
      actual = p; 
   }
   return p; 
}
