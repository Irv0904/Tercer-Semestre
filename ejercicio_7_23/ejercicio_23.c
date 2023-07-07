#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct cnodo
{
    int dato;
    struct cnodo *liga;
};

typedef struct cnodo nodo;

void *creaMemoria(int n);
nodo *creaNodo();
void iterativo(nodo *p);
nodo *nodoFinal(nodo *p);
nodo *liberaMemoria(nodo *p);
int listaCompleta(nodo *p);
int buscarNumero(nodo *p, int num);
nodo *completarLista(nodo *p);

int main()
{
    nodo *p = NULL;

    p = nodoFinal(p);
    iterativo(p);
    p = completarLista(p);
    iterativo(p);
    p = liberaMemoria(p);

    return 0;
}

void *creaMemoria(int n)
{
    void *p = malloc(n);
    if (p == NULL)
    {
        printf("No hay memoria");
        getchar();
        exit(1);
    }
    return p;
}

nodo *creaNodo()
{
    return (nodo *)creaMemoria(sizeof(nodo));
}

void iterativo(nodo *p)
{
    nodo *v;
    if (p != NULL)
    {
        printf("\n");
        v = p;
        do
        {
            printf("%5d->", v->dato);
            v = v->liga;
        } while (v != p);
        printf("NULL\n");
        printf("\n\n");
    }
    else
    {
        printf("\n*****Lista vacia...*****\n");
    }
    return;
}

nodo *nodoFinal(nodo *p)
{
    int j, num;
    nodo *l, *v;
    p = creaNodo();
    printf("Ingrese un digito: ");
    j = scanf("%d", &num);
    fflush(stdin);
    if (j == 1)
    {
        p->dato = num;
        p->liga = p;
        l = p;
        do
        {
            v = creaNodo();
            printf("Ingrese un digito: ");
            j = scanf("%d", &num);
            fflush(stdin);
            if (j == 1)
            {
                v->dato = num;
                v->liga = p;
                l->liga = v;
                l = v;
            }
            else
            {
                free(v);
                break;
            }
        } while (j == 1);
        printf("\n*****Creando Lista Enlazada Circular...*****\n\n");
    }
    else
    {
        free(p);
        return NULL;
    }
    return p;
}

nodo *liberaMemoria(nodo *p)
{
    if (p != NULL)
    {
        nodo *v = p;
        do
        {
            p = p->liga;
            free(v);
            v = p;
        } while (v != NULL);
        printf("\n\t\t>->->->->->->->->-");
        printf("\n\t\t|Memoria Liberada|*");
        printf("\n\t\t<-<-<-<-<-<-<-<-<-");
    }
    else
    {
        printf("\n\nLista vacia");
    }
    return p;
}

int listaCompleta(nodo *p)
{
    int numEsperado = p->dato + 1;
    nodo *q = p->liga;

    while (q != p)
    {
        if (q->dato != numEsperado)
        {
            return numEsperado;
        }
        numEsperado++;
        q = q->liga;
    }

    return -1; // Si la lista está completa, devuelve -1
}

int buscarNumero(nodo *p, int num)
{
    nodo *q = p;

    do
    {
        if (q->dato == num)
        {
            return 1;
        }
        q = q->liga;
    } while (q != p);

    return 0;
}

nodo *completarLista(nodo *p)
{
    nodo *q = p;
    int numA = p->dato + 1;
    srand(time(NULL));

    while (listaCompleta(p) != -1) // Mientras la lista no esté completa
    {
        if (!buscarNumero(p, numA))
        {
            nodo *nuevoNodo = creaNodo();
            nuevoNodo->dato = numA;

            if (numA < p->dato)
            {
                nuevoNodo->liga = p;
                q->liga = nuevoNodo;
                p = nuevoNodo;
            }
            else
            {
                while (q->liga != p && q->liga->dato < numA)
                {
                    q = q->liga;
                }
                nuevoNodo->liga = q->liga;
                q->liga = nuevoNodo;
            }
        }

        numA++;
    }

    return p;
}
