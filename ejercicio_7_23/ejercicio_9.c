#include<stdio.h>
#include<stdlib.h>

struct cnodo{
	int num;
	struct cnodo *ligader;
	struct cnodo *ligaizq;
};

typedef struct cnodo nodo;


void *creaMemoria(int n);
nodo *creaNodo();
nodo *cfinaldb();
void iterativoDer(nodo *p);
nodo *busqueda_recursiva(nodo* p, int num);
nodo *liberamemoria(nodo *p);

int main(){
	nodo *p = NULL;
    int num;
	p = cfinaldb();
	printf("\n\t*Recorriendo hacia la derecha*\n");
	iterativoDer(p);
    printf("Ingrese el numero a buscar: ");
    scanf("%d", &num);
    fflush(stdin);
    nodo *resultado = busqueda_recursiva(p, num);
    if (resultado != NULL) {
        printf("El numero %d se encuentra en la lista.\n", num);
    } else {
        printf("El numero %d no se encuentra en la lista.\n", num);
    }
	p=liberamemoria(p);
}

void *creaMemoria(int n){
	void *p=(int *)malloc(n);
	if(p==NULL){
		printf("No hay memoria");
		getchar();
		exit(1);
	}
	return(p);
}

nodo *creaNodo()
{
	return (nodo *)creaMemoria(sizeof(nodo));
}

nodo *cfinaldb()
{
	printf("\n\t\t\t*** Crear Final - Lista Doble ***\n");

	nodo *p = NULL;
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
		p->num = dato;
		l = p;
		do
		{
			v = creaNodo();
			printf("Introduzca un numero:");
			j = scanf("%d", &dato);
			fflush(stdin);
			if (j == 1)
			{
				v->num = dato;
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

void iterativoDer(nodo *p)
{
 	nodo *t = NULL;
    if(p != NULL)
	{
        t=p;
        printf("\n");
        while(t != NULL)
		{
            printf("%d->", t->num);
            t = t->ligader;
		}
		printf("\n");
	}
	else 
		printf("\n\tLista vacia...");
}

nodo *liberamemoria(nodo *p)
{
	nodo *v = NULL;
	if(p != NULL)
	{
		while(p!=NULL)
		{
			v = p;
			p = p->ligader;
			v->ligader = NULL;
			free(v);
		}
		printf("\n\t\t******************\n\t\t*Memoria Liberada*\n\t\t******************");
	}
	else
		printf("\n\nLista vacia");
    return p;
}

nodo *busqueda_recursiva(nodo *p, int num) {
    if (p != NULL) {
        if (p->num == num) {
            return p;
        } else {
            nodo *encontrado_izq = busqueda_recursiva(p->ligaizq, num);
            if (encontrado_izq != NULL) {
                return encontrado_izq;
            }
            nodo *encontrado_der = busqueda_recursiva(p->ligader, num);
            if (encontrado_der != NULL) {
                return encontrado_der;
            }
        }
    }
    return NULL;
}
