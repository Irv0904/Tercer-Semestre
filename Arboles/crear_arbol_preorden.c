#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct datos{
   int info;
   struct datos *ligader;
   struct datos *ligaizq;
   
}Arbol;

void *crearMemoria(int n);
Arbol *creaNodo();
Arbol *creaArbol(int apNodo);

int main()
{
   Arbol *p = NULL;
   int apNodo, j;

   printf("Ingrese La raiz principal: ");
   j=scanf("%d",&apNodo);
   fflush(stdin);
   if(j == 1)
   {
      p=creaNodo();
      p=creaArbol(apNodo);
   }   
   else
      printf("No es un nodo");
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

Arbol *creaArbol(int apNodo)
{
   int res;
   Arbol *p=NULL;
   Arbol *otro=NULL;
   p->info=apNodo;
   printf("¿Existe un nodo por izquierda?\n1-Si\t2->No\nRespuesta: ");
   scanf("%d", & res);
   if(res == 1){
      otro=creaNodo();
      p->ligaizq=otro;
      creaArbol(p->ligaizq);
   }
   else
      p->ligaizq=NULL;

   printf("¿Existe un nodo por derecha?\n1-Si\t2->No\nRespuesta: ");
   scanf("%d", &res);
   if(res == 1){
      otro=creaNodo();
      p->ligader=otro;
      creaArbol(p->ligader);
   }
   else
      p->ligader=NULL;

   return p;
}