/*
	Name:Crear Arbol con dintistos recorrido
	Author: Irving Jhon Villarreal Lasso
	Date: 23/05/23 14:24
	Description: Este codigo se usa para hacer un arbol con distinto recorridos
	Calificacion:
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<locale.h>

typedef struct datos{
   int info;
   struct datos *ligader;
   struct datos *ligaizq;
   
}Arbol;

void *crearMemoria(int n);
Arbol *creaNodo();
Arbol *creaArbol(Arbol *apNodo);
void preOrden(Arbol *apNodo);
void inOrden(Arbol *apNodo);
void posOrden(Arbol *apNodo);

int main()
{
   setlocale(LC_ALL," " );
   Arbol *apNodo = NULL;
   int dato;
   apNodo = creaNodo();
   printf("Ingrese La raiz principal: ");
   apNodo=creaArbol(apNodo);
   printf("\nArbol en PreOrden\n\n");
   preOrden(apNodo);
   printf("\n\nArbol en InOrden\n\n");
   inOrden(apNodo);
   printf("\n\nArbol en PosOrden\n\n");
   posOrden(apNodo);
}

void *crearMemoria(int n)
{
   void *p = (int *)malloc(n);
   if(p== NULL)
   {
      printf("NO HAY MEMORIA, PARA CREAR NODO");
      getchar();
      exit(1);
   }
}

Arbol *creaNodo()
{
   return(Arbol *)crearMemoria(sizeof(Arbol));
}

void preOrden(Arbol *apNodo)
{
   if(apNodo != NULL)
   {
      printf("%5d ",apNodo->info);
      preOrden(apNodo->ligaizq);
      preOrden(apNodo->ligader);
   }
}

void inOrden(Arbol *apNodo)
{
   if(apNodo != NULL)
   {
      inOrden(apNodo->ligaizq);
      printf("%5d ",apNodo->info);
      inOrden(apNodo->ligader);
   }
}

void posOrden(Arbol *apNodo)
{
   if(apNodo != NULL)
   {
      inOrden(apNodo->ligaizq);
      inOrden(apNodo->ligader);
      printf("%5d ",apNodo->info);
   }
}

Arbol *creaArbol(Arbol *apNodo)
{
   Arbol *otroArbol;
   int resp;

   scanf("%d", &(apNodo->info));

   printf("Existe nodo por izquierda de %d?\n1->Si \t 2->No: ",apNodo->info);
   scanf("%d", &resp);
   fflush(stdin);
   if (resp == 1) {
      otroArbol = creaNodo();
      printf("\nIngrese la informacion del nodo: ");
      apNodo->ligaizq =otroArbol;
      creaArbol(apNodo->ligaizq);
   } 
   else {
      apNodo->ligaizq = NULL;
   }

   printf("Existe nodo por derecha de %d?\n1->Si \t 2->No: ", apNodo->info);
   scanf("%d", &resp);
   fflush(stdin);
   if (resp == 1) {
      otroArbol = creaNodo();
      printf("\nIngrese la informacion del nodo: ");
      apNodo->ligader = otroArbol;
      creaArbol(apNodo->ligader);
   } 
   else {
      apNodo->ligader = NULL;
   }

   return apNodo;
}