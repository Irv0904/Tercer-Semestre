#include <stdio.h>
#include <stdlib.h>
#include<locale.h>
// Definición de la estructura de un nodo
typedef struct Nodo {
    int dato;
    struct Nodo* siguiente;
} Nodo;

// Definición de la estructura de la cola
typedef struct Lista {
    Nodo* inicio;
    Nodo* fin;
} Lista;

// Prototipos de funciones
void inicializarCola(Lista* cola);
int estaVacia(Lista cola);
void insertarCola(Lista* cola, int dato);
void eliminarCola(Lista* cola);
int frenteCola(Lista cola);
void mostrarMenu();

// Función principal
int main() {
    setlocale(LC_ALL, " ");
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
                break;
            case 2:
                eliminarCola(&cola);
                break;
            case 3:
                printf("Frente de la cola: %d\n", frenteCola(cola));
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

// Inicialización de la cola
void inicializarCola(Lista* cola) {
    cola->inicio = NULL;
    cola->fin = NULL;
}

// Verificar si la cola está vacía
int estaVacia(Lista cola) {
    return (cola.inicio == NULL);
}

// Insertar un elemento en la cola
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

// Eliminar un elemento de la cola
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

// Obtener el elemento en el frente de la cola
int frenteCola(Lista cola) {
    if (estaVacia(cola)) {
        printf("La cola está vacía.\n");
        return -1; // Valor sentinela o manejo de error
    } else {
        return cola.inicio->dato;
    }
}

// Mostrar el menú de opciones
void mostrarMenu() {
    printf("\n--- Menu de Cola ---\n");
    printf("1. Agregar \n");
    printf("2. Eliminar \n");
    printf("3. Mostrar \n");
    printf("4. Salir\n");
    printf("Ingrese una opción: ");
}
