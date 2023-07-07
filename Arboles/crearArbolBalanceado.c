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

typedef struct datos
{
    int info;
    struct datos *ligader;
    struct datos *ligaizq;
}Arbol;

typedef enum{false, true} bool;

Arbol *insertaBalanceado(Arbol *nodo, int info, bool bo);

int main()
{
    bool bo = false;
    Arbol *nodo = NULL;
    int info;
    printf("Ingrese el numero: ");
    scanf("%d", &info);
    insertaBalanceado(nodo, info,bo);
}

Arbol *insertaBalanceado(Arbol *nodo, int info, bool bo)
{
    Arbol *otroArbol, *nodoArbol, *nodoArbol2;
    if(nodo != NULL)
    {
        if(info < nodo->info)
        {
            insertaBalanceado(nodo->ligaizq, info, bo);
            if(bo == true)
            {
                
            }
        }
    }
}