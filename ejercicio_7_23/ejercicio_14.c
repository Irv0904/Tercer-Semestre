#include <stdio.h>
#include <stdlib.h>

struct cnodo{
	int dato;
	struct cnodo *ligader;
    struct cnodo *ligaizq;
};

typedef struct cnodo nodo;

nodo *creaNodo();
nodo *cfinaldb(nodo *p);
void iterativoDer(nodo *p);
nodo *insertarecursivoDoble(nodo *p, int num, int ref);
void liberamemoria(nodo *p);

int main(){
    nodo *p = NULL;
    int num, ref;

    p = cfinaldb(p);
    iterativoDer(p);
    printf("Ingrese el número a insertar: ");
    scanf("%d", &num);
    printf("Ingrese la referencia: ");
    scanf("%d", &ref);

    p = insertarecursivoDoble(p, num, ref);

    iterativoDer(p);

    liberamemoria(p);
    return 0;
}

void liberamemoria(nodo *p)
{
    nodo *v = NULL;
    while (p != NULL) {
        v = p;
        p = p->ligader;
        free(v);
    }
    printf("\n\t\t******************\n\t\t* Memoria Liberada *\n\t\t******************\n");
}

void iterativoDer(nodo *p)
{
    if (p == NULL) {
        printf("\n\tLista vacía...\n");
        return;
    }

    printf("NULL <- ");
    while (p != NULL) {
        printf("%d <-> ", p->dato);
        p = p->ligader;
    }
    printf("NULL\n");
}

nodo *creaNodo(){
	return (nodo *)malloc(sizeof(nodo));
} 

nodo *nodoFinal(nodo *p)
{
    if (p == NULL) {
        printf("Lista vacía...\n");
        return p;
    }

    while (p->ligader != NULL) {
        p = p->ligader;
    }

    return p;
}

nodo *cfinaldb(nodo *p)
{
	printf("\n\t\t\t*** Crear Final - Lista Doble ***\n");

	nodo *l = NULL;
	nodo *v = NULL;
	int dato, j;

	p = creaNodo();
	printf("Introduzca un numero:");
	j = scanf("%d", &dato);
	fflush(stdin);

	if (j == 1)
	{
		p->ligaizq = NULL;
		p->ligader = NULL;
		p->dato = dato;
		l = p;
		do
		{
			v = creaNodo();
			printf("Introduzca un numero:");
			j = scanf("%d", &dato);
			fflush(stdin);
			if (j == 1)
			{
				v->dato = dato;
				v->ligader = NULL;
				v->ligaizq = l;
				l->ligader = v;
				l = v;
			}
			else
			{
				free(v);
				break;
			}
		} while (j == 1);
	}
	else
	{
		free(p);
		return NULL;
	}

	return p;
}

nodo *insertarecursivoDoble(nodo *p, int num, int ref)
{
    if (p == NULL) {
        printf("\n:: El nodo dado como referencia no existe en la lista. \n");
        return p;
    }

    if (p->dato == ref) {
        nodo *x = creaNodo();
        x->dato = num;
        x->ligader = p->ligader;
        if (p->ligader != NULL) {
            p->ligader->ligaizq = x;
        }
        p->ligader = x;
        x->ligaizq = p;
    } else {
        p->ligader = insertarecursivoDoble(p->ligader, num, ref);
    }

    return p;
}
