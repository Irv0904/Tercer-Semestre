#include<stdio.h>
#include<stdlib.h>

typedef struct Nodo{
    int dato;
    struct Nodo *liga;
}Nodo;

typedef struct Pila{
    Nodo *tope;
}Pila;


void *creaMemoria(int n);
Nodo *creaNodo();
void pilaInicial(Pila *pila);
int pilaVacia(Pila pila);
void ingresarPila(Pila *pila, int dato);
void eliminarPila (Pila *pila);
int pilaCima(Pila pila);
void pilaRecorrida(Pila pila);
void liberarPila(Pila *pila);

int main()
{
    int opcion, dato;
    Pila pila;
    pilaInicial(&pila);

    do {
        system("CLS");
        printf("\n--- Menu de Pila ---\n");
        printf("1. Ingresar \n");
        printf("2. Eliminar \n");
        printf("3. Mostrar \n");
        printf("4. Mostrar la cima \n");
        printf("5. liberar \n");
        printf("6. Salir\n");
        printf("Ingrese una opción: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                printf("Ingrese un elemento para apilar: ");
                scanf("%d", &dato);
                ingresarPila(&pila, dato);
                pilaRecorrida(pila);
                system("PAUSE");
                break;
            case 2:
                eliminarPila(&pila);
                pilaRecorrida(pila);
                system("PAUSE");
                break;
            case 3:
                pilaRecorrida(pila);
                system("PAUSE");
                break;
            case 4:
                printf("Cima de la pila: %d\n", pilaCima(pila));
                system("PAUSE");
                break;  
            case 5:
            printf("\nLiberando\n");
                liberarPila(&pila);
                pilaRecorrida(pila);
                system("PAUSE");
                break;
            case 6:
                printf("Saliendo del programa...\n");
                liberarPila(&pila);
                system("PAUSE");
                break;
            default:
                printf("Opción inválida. Por favor, intente nuevamente.\n");
                system("PAUSE");
                break;
        }
    } while (opcion != 6);

    return 0;
}

void *creaMemoria(int n){
	void *i=(int *)malloc(n);
	if(i==NULL){
		printf("No hay memoria");
		getchar();
		exit(1);
	}
	return(i);
}

Nodo *creaNodo(){
	return(Nodo *)creaMemoria(sizeof(Nodo));
} 

void pilaInicial(Pila *pila)
{
    pila->tope = NULL;
}

int pilaVacia(Pila pila)
{
    return (pila.tope == NULL);
}

void ingresarPila(Pila *pila, int dato)
{
    Nodo * nuevaPila = creaNodo();
    nuevaPila->dato = dato;
    nuevaPila->liga = pila->tope;
    pila->tope = nuevaPila;

    printf("\nElemento ingresado a la pila\n");
}

void eliminarPila(Pila *pila)
{
    if(pilaVacia(*pila))
    {
        printf("\nNo hay datos en la pila\n");
    }
    else
    {
        Nodo *pilaEliminada = pila->tope;
        pila->tope = pila->tope->liga;
        free(pilaEliminada);
        printf("\nElemento eliminado de la pila\n");
    }
}

int pilaCima(Pila pila)
{
    if(pilaVacia(pila))
    {
        printf("\nLa pila esta vacia\n");
        return -1;
    }
    else 
        return pila.tope->dato;
}

void pilaRecorrida(Pila pila)
{
    if(pilaVacia(pila))
        printf("\nPila Vacia\n");
    else
    {
        Nodo *pilaActual = pila.tope;
        printf("\nElementos dentro de la pila\n");
        while(pilaActual != NULL)
        {
            printf("%d ", pilaActual->dato);
            pilaActual = pilaActual->liga;
        }
        printf("\n");
    }
}

void liberarPila(Pila *pila){
    Nodo *pilaActual = pila->tope;
    Nodo *pilaSiguiente;
    while(pilaActual != NULL){
        pilaSiguiente = pilaActual->liga;
        free(pilaActual);
        pilaActual = pilaSiguiente;
    }

    pila->tope = NULL;
}