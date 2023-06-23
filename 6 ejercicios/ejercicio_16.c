#include <stdio.h>
#include <stdlib.h>

typedef struct Nodo {
   int dato;
   struct Nodo* siguiente;
} Nodo;

typedef struct Lista {
   Nodo* inicio;
   Nodo* fin;
} Lista;

void inicializarCola(Lista* cola);
int estaVacia(Lista cola);
void insertarCola(Lista* cola, int dato);
void eliminarCola(Lista* cola);
void mostrarLista(Lista cola);
void mostrarMenu();

int main() {
   Lista cola;
   inicializarCola(&cola);

   int opcion, dato;

   do {
      mostrarMenu();
      scanf("%d", &opcion);

      switch (opcion) {
            case 1:
               printf("Ingrese un elemento para agregar a la cola: ");
               scanf("%d", &dato);
               insertarCola(&cola, dato);
               system("PAUSE");
               system("CLS");
               break;
            case 2:
               eliminarCola(&cola);
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

void inicializarCola(Lista* cola) {
   cola->inicio = NULL;
   cola->fin = NULL;
}

int estaVacia(Lista cola) {
   return (cola.inicio == NULL);
}

void insertarCola(Lista* cola, int dato) {
   Nodo* nuevoNodo = (Nodo*)malloc(sizeof(Nodo));
   nuevoNodo->dato = dato;
   nuevoNodo->siguiente = NULL;
   if (estaVacia(*cola)) {
      cola->inicio = nuevoNodo;
      cola->fin = nuevoNodo;
   } else {
      cola->fin->siguiente = nuevoNodo;
      cola->fin = nuevoNodo;
   }
   printf("Elemento agregado correctamente a la cola.\n");
}

void eliminarCola(Lista* cola) {
   if (estaVacia(*cola)) {
      printf("La cola está vacía. No se puede eliminar ningún elemento.\n");
   } else {
      Nodo* nodoEliminar = cola->inicio;
      cola->inicio = cola->inicio->siguiente;
      if (cola->inicio == NULL) {
            cola->fin = NULL;
      }
      free(nodoEliminar);
      printf("Elemento eliminado de la cola correctamente.\n");
   }
}

void mostrarLista(Lista cola) {
   if (estaVacia(cola)) {
      printf("La cola está vacía. No hay elementos para mostrar.\n");
   } else {
      Nodo* actual = cola.inicio;
      printf("Elementos en la cola: ");
      while (actual != NULL) {
            printf("%d ", actual->dato);
            actual = actual->siguiente;
      }
      printf("\n");
   }
}

void mostrarMenu() {
   printf("\n Menu de Colas ---\n");
   printf("1. Agregar \n");
   printf("2. Eliminar \n");
   printf("3. Mostrar \n");
   printf("4. Salir\n");
   printf("Ingrese una opcion: ");
}