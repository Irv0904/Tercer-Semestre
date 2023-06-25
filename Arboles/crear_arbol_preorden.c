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

typedef struct datos
{
   int info;
   struct datos *ligader;
   struct datos *ligaizq;
   
}Arbol;

typedef enum{false, true} bool;

void *crearMemoria(int n);
Arbol *creaNodo();

Arbol *creaArbol(Arbol *apNodo);

void preOrden(Arbol *apNodo);
void inOrden(Arbol *apNodo);
void posOrden(Arbol *apNodo);

Arbol *busqueda_ABB(Arbol *apNodo, int info);
Arbol *busqueda_v1_ABB(Arbol *apNodo, int info);

Arbol *insercion_ABB(Arbol *apNodo, int info);
Arbol *insercion_v1_ABB(Arbol *apNodo, int info);

Arbol *eliminacion_ABB(Arbol *apNodo, int info);

int main()
{
   setlocale(LC_ALL," " );
   Arbol *apNodo = NULL;
   int info;

   apNodo = creaNodo();
   printf("Ingrese La raiz principal: ");
   apNodo=creaArbol(apNodo);

   printf("\nArbol en PreOrden\n\n");
   preOrden(apNodo);

   printf("\n\nArbol en InOrden\n\n");
   inOrden(apNodo);

   printf("\n\nArbol en PosOrden\n\n");
   posOrden(apNodo);

   printf("\n\nIngrese la informacion a buscar: ");
   scanf("%d", &info);
   fflush(stdin);
   apNodo = busqueda_ABB(apNodo,info);

   printf("\n\nIngrese la informacion a buscar: ");
   scanf("%d", &info);
   fflush(stdin);
   apNodo = busqueda_v1_ABB(apNodo,info);

   printf("\n\nIngrese la informacion a ingresar: ");
   scanf("%d", &info);
   fflush(stdin);
   apNodo = insercion_ABB(apNodo, info);

   printf("\nArbol en PreOrden\n\n");
   preOrden(apNodo);

   printf("\n\nArbol en InOrden\n\n");
   inOrden(apNodo);

   printf("\n\nArbol en PosOrden\n\n");
   posOrden(apNodo);

   /*printf("\n\nIngrese la informacion a ingresar: ");
   scanf("%d", &info);
   fflush(stdin);
   apNodo = insercion_v1_ABB(apNodo, info); 

   printf("\nArbol en PreOrden\n\n");
   preOrden(apNodo);

   printf("\n\nArbol en InOrden\n\n");
   inOrden(apNodo);

   printf("\n\nArbol en PosOrden\n\n");
   posOrden(apNodo);*/   

   printf("\n\nIngrese la informacion a eliminar: ");
   scanf("%d", &info);
   fflush(stdin);
   apNodo = eliminacion_ABB(apNodo, info);

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
   if(p == NULL)
   {
      printf("NO HAY MEMORIA, PARA CREAR NODO");
      getchar();
      exit(1);
   }
   return p;
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
      posOrden(apNodo->ligaizq);
      posOrden(apNodo->ligader);
      printf("%5d ",apNodo->info);
   }
}

Arbol *creaArbol(Arbol *apNodo)
{
   Arbol *otroArbol;
   int resp;

   scanf("%d", &(apNodo->info));

   printf("\nExiste nodo por izquierda de %d?\n1->Si \t 2->No: ",apNodo->info);
   scanf("%d", &resp);
   fflush(stdin);
   if (resp == 1) 
   {
      otroArbol = creaNodo();
      printf("\nIngrese la informacion del nodo: ");
      apNodo->ligaizq =otroArbol;
      creaArbol(apNodo->ligaizq);
   } 
   else 
   {
      apNodo->ligaizq = NULL;
   }

   printf("\nExiste nodo por derecha de %d?\n1->Si \t 2->No: ", apNodo->info);
   scanf("%d", &resp);
   fflush(stdin);
   if (resp == 1) 
   {
      otroArbol = creaNodo();
      printf("\nIngrese la informacion del nodo: ");
      apNodo->ligader = otroArbol;
      creaArbol(apNodo->ligader);
   } 
   else
   {
      apNodo->ligader = NULL;
   }

   return apNodo;
}

Arbol *busqueda_ABB(Arbol *apNodo, int info)
{
   if(info < apNodo->info)
   {
      if(apNodo->ligaizq == NULL)
         printf("\nLa informacion dada no se encuentra en el arbol\n");
      else
         busqueda_ABB(apNodo->ligaizq, info);
   }
   else
   {
      if(info > apNodo->info)
      {
         if(apNodo->ligader == NULL)
            printf("\nLa informacion dada no se encuentra en el arbol\n");
         else
            busqueda_ABB(apNodo->ligader, info);
      }
      else
         printf("\nLa informacion dada si esta en el arbol\n");
   }
   return apNodo;
}

Arbol *busqueda_v1_ABB(Arbol *apNodo, int info)
{
   if(apNodo != NULL)
   {
      if(info < apNodo->info)
         busqueda_v1_ABB(apNodo->ligaizq, info);
      else
      {
         if(info > apNodo->info)
            busqueda_v1_ABB(apNodo->ligader, info);
         else
            printf("\nLa inforamacion dada si se encuentra en el arbol\n");
      }
   }
   else
      printf("\nLa informacion dada no se encuentra en el Arbol\n");

   return apNodo;
}

Arbol *insercion_ABB(Arbol *apNodo, int info)
{
   if(info < apNodo->info)
   {
      if(apNodo->ligaizq == NULL)
      {
         Arbol *otroArbol = creaNodo();
         otroArbol->ligaizq = NULL;
         otroArbol->ligader = NULL;
         otroArbol->info = info;
         apNodo->ligaizq = otroArbol;
      }
      else
         insercion_ABB(apNodo->ligaizq, info);
   }
   else
   {
      if(info > apNodo->info)
      {
         if(apNodo->ligader == NULL)
         {
            Arbol *otroArbol = creaNodo();
            otroArbol->ligaizq = NULL;
            otroArbol->ligader = NULL;
            otroArbol->info = info;
            apNodo->ligader = otroArbol;
         }
         else
            insercion_ABB(apNodo->ligader, info);
      }
      else
         printf("\nLa informacion dada ya se encuentra en el Arbol\n");
   }
   return apNodo;
}

Arbol *insercion_v1_ABB(Arbol *apNodo, int info)
{
   if(apNodo != NULL)
   { 
      if(info < apNodo->info)
         insercion_v1_ABB(apNodo->ligaizq, info);
      else
      {
         if(info > apNodo->info)
            insercion_v1_ABB(apNodo->ligader, info);
         else
            printf("La informacion dada ya se encuentra en el arbol");
      }
   }
   else
   {
      Arbol *otroArbol = creaNodo();
      otroArbol->ligaizq = NULL;
      otroArbol->ligader = NULL;
      otroArbol->info = info;
      apNodo = otroArbol;
   }
   return apNodo;
}

Arbol *eliminacion_ABB(Arbol *apNodo, int info)
{
   Arbol *otroArbol, *arbolAux, *arbolAux_1;
   if(apNodo != NULL)
   {
      if(info < apNodo->info)
         eliminacion_ABB(apNodo->ligaizq, info);
      else
      {
         if(info > apNodo->info)
         {
            eliminacion_ABB(apNodo->ligader, info);
         }
         else
         {
            otroArbol = apNodo;
            if(otroArbol->ligader == NULL)
            {
               apNodo = otroArbol->ligaizq;
            }
            else
            {
               if(otroArbol->ligaizq == NULL)
               {
                  apNodo = otroArbol->ligader;
               }
               else
               {
                  arbolAux = apNodo->ligaizq;
                  bool bo = false;
                  while(arbolAux->ligader !=  NULL)
                  {
                     arbolAux_1 = arbolAux;
                     arbolAux = arbolAux->ligader;
                     bo = true;
                  }
                  if(bo == true)
                  {
                     arbolAux_1->ligader = arbolAux->ligaizq;
                  }
                  else
                  {
                     apNodo->ligaizq = arbolAux->ligaizq;
                  }
               }
            }
            free(otroArbol);
         }
      }
   }
   else
      printf("La informacion dada para eliminar no se encuentra en el arbol");

   return apNodo;
}