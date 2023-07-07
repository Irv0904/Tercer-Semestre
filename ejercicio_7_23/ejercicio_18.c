#include <stdio.h>
#include <stdlib.h>

typedef struct Nodo {
   int dato;
   struct Nodo* liga;
} Nodo;

typedef struct Lista {
   Nodo* inicio;
   Nodo* fin;
} Lista;

void inicializarCola(Lista* cola);
int estaVacia(Lista cola);
void pushCola(Lista* cola, int dato);
void mostrarLista(Lista cola);
void mostrarMenu();
Nodo* remover_repetido(Nodo* frente);

int main() {
   Lista cola;
   inicializarCola(&cola);
   int opcion, dato;
   do 
   {
      mostrarMenu();
      scanf("%d", &opcion);
      switch (opcion) 
      {
            case 1:
               printf("Ingrese un elemento para agregar a la cola: ");
               scanf("%d", &dato);
               pushCola(&cola, dato);
               system("PAUSE");
               system("CLS");
               break;
            case 2:
               cola.inicio = remover_repetido(cola.inicio);
               printf("Elementos duplicados eliminados de la cola.\n");
               system("PAUSE");
               system("CLS");
               break;
            case 3:
               mostrarLista(cola);
               system("PAUSE");
               system("CLS");
               break;
            case 4:
               printf("Saliendo del programa...\n");
               break;
            default:
               printf("Opción inválida. Por favor, intente nuevamente.\n");
               break;
      }
   } while (opcion != 4);

   return 0;
}

void inicializarCola(Lista* cola) 
{
   cola->inicio = NULL;
   cola->fin = NULL;
}

int estaVacia(Lista cola) {
   return (cola.inicio == NULL);
}

void pushCola(Lista* cola, int dato) 
{
   Nodo* q = (Nodo*)malloc(sizeof(Nodo));
   q->dato = dato;
   q->liga = NULL;
   if (estaVacia(*cola)) 
   {
      cola->inicio = q;
      cola->fin = q;
   } 
   else
   {
      cola->fin->liga = q;
      cola->fin = q;
   }
   printf("Elemento agregado correctamente a la cola.\n");
}

void mostrarLista(Lista cola) 
{
   if (estaVacia(cola)) 
   {
      printf("La cola está vacía. No hay elementos para mostrar.\n");
   } 
   else
   {
      Nodo* p = cola.inicio;
      printf("Elementos en la cola: ");
      while (p != NULL) {
            printf("%d ", p->dato);
            p = p->liga;
      }
      printf("\n");
   }
}

void mostrarMenu() 
{
   printf("\n Menu de Colas ---\n");
   printf("1. Agregar \n");
   printf("2. Eliminar duplicados \n");
   printf("3. Mostrar \n");
   printf("4. Salir\n");
   printf("Ingrese una opcion: ");
}

Nodo* remover_repetido(Nodo* frente)
{
    if (frente != NULL)
    {
        Nodo *tmp = frente;
        Nodo *tmp2 = NULL;
        Nodo *duplicado = NULL;

        while (tmp != NULL)
        {
            tmp2 = tmp;
            while (tmp2->liga != NULL)
            {
                if (tmp2->liga->dato == tmp->dato)
                {
                    duplicado = tmp2->liga;
                    tmp2->liga = duplicado->liga;
                    free(duplicado);
                }
                else
                {
                    tmp2 = tmp2->liga;
                }
            }
            tmp = tmp->liga;
        }
    }
    else
    {
        printf("\n:: La cola está vacía.");
    }
    return frente;
}
