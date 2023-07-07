/*	
	Nombre: Lista Simple con Inserta Despues con Lista Ordenada y Verificacion de Lista
	Autor: Irving Jhon Villarreal
	Fecha de entrega: 13/06/2023
	Nota: 100
*/
#include<stdio.h>
#include<stdlib.h>

struct cnodo{
	int num;
	struct cnodo *liga;
};

typedef struct cnodo nodo;


void *creaMemoria(int n);
nodo *creaNodo();

nodo *lista_1 (nodo *p);
void recursivo_1(nodo *p);
nodo *libera_lista_1(nodo *p);

nodo *lista_2 (nodo *f);
void recursivo_2(nodo *f);
nodo *libera_lista_2(nodo *f);

nodo *lista_3(nodo *p, nodo *f);
void recursivo_3(nodo *z);
nodo *libera_lista_3(nodo *z);

void ordenarLista(nodo*z);
int main(){
	int num;
	nodo *p=NULL;
   	nodo *f=NULL;
   	nodo *z=NULL;

	printf("\t\t\tLista 1:\n");
	p=lista_1(p);
	recursivo_1(p);

	printf("\n\n\t\t\tLista 2:\n");
	f=lista_2(f);
	recursivo_2(f);

	printf("\n\n\t\t\tLista 3 y mezclada y ordenada descendente:\n");
	z=lista_3(p,f);
	ordenarLista(z);   
	recursivo_3(z);

	libera_lista_1(p);
	libera_lista_2(f);	
	libera_lista_3(z);
}

void *creaMemoria(int n)
{
	void *i=(int *)malloc(n);
	if(i==NULL)
	{
		printf("No hay memoria");
		getchar();
		exit(1);
	}
	return(i);
}

nodo *creaNodo()
{
	return(nodo *)creaMemoria(sizeof(nodo));
} 

void recursivo_1(nodo *p)
{
	if(p != NULL)
	{
		printf("%5d->",p->num);
		if(p->liga!=NULL)
			recursivo_1 (p->liga);
		else
			printf("%s",p->liga);
	}
	else
		printf("\n*****Lista Vacia...*****\n");
}

void recursivo_2 (nodo *f)
{
	if(f != NULL)
	{
		printf("%5d->",f->num);
		if(f->liga!=NULL)
			recursivo_2 (f->liga);
		else
			printf("%s",f->liga);
	}
	else
		printf("\n*****Lista Vacia...*****\n");
}

void recursivo_3 (nodo *z)
{
	if(z != NULL)
	{
		printf("%5d->",z->num);
		if(z->liga!=NULL)
			recursivo_2 (z->liga);
		else
			printf("%s",z->liga);
	}
	else
		printf("\n*****Lista Vacia...*****\n");
}

nodo *libera_lista_1(nodo *p)
{
	nodo *q=NULL;
	if(p!=NULL)
	{
		while(p!=NULL)
		{
			q=p;
			p=p->liga ;
			q->liga= NULL;
			free(q);
		}
		printf("\n\n\t\t*****LA MEMORIA DE LA LISTA 1 HA SIDO LIBERADA...*****\n\n");
	}
	else
		printf("****NO HAY LISTA PARA LIBERADA...*****\n\n");
	//free(p);	
	return p;
}

nodo *libera_lista_2(nodo *f)
{
	nodo *q=NULL;
	if(f!=NULL)
	{
		while(f!=NULL)
		{
			q=f;
			f=f->liga ;
			q->liga= NULL;
			free(q);
		}
		printf("\n\n\t\t*****LA MEMORIA DE LA LISTA 2 HA SIDO LIBERADA...*****\n\n");
	}
	else
		printf("****NO HAY LISTA PARA LIBERADA...*****\n\n");
	//free(p);	
	return f;
}

nodo *libera_lista_3(nodo *z)
{
	nodo *q=NULL;
	if(z!=NULL)
	{
		while(z!=NULL)
		{
			q=z;
			z=z->liga ;
			q->liga= NULL;
			free(q);
		}
		printf("\n\n\t\t*****LA MEMORIA DE LA LISTA 3 HA SIDO LIBERADA...*****\n\n");
	}
	else
		printf("****NO HAY LISTA PARA LIBERADA...*****\n\n");
	//free(p);	
	return z;
}

nodo *lista_1 (nodo *p)
{
	int j,num;
	nodo *l,*q;
	p=creaNodo();
	printf("Ingrese un numero, para salir ingrese una letra: ");
	j=scanf("%d",&num);
	fflush(stdin);
	if(j==1)
	{
		p->num=num;
		p->liga=NULL;
		l=p;
		do
		{
			q=creaNodo();
			printf("Ingrese un numero, para salir ingrese una letra: ");
			j=scanf("%d",&num);
			fflush(stdin);
			if(j==1)
			{
				q->num=num;
				q->liga=NULL;
				l->liga=q;
				l=q;
			}
			else
			{
				free(q);
				break;
			}
		}while(j==1);
		printf("\n*****Creando Listas enlazada...*****");
		printf("\n");
		return p;
	}
	else
	{
		free(p);
		return(NULL);
	}
}

nodo *lista_2 (nodo *f)
{
	int j,num;
	nodo *l,*q;
	f=creaNodo();
	printf("Ingrese un numero, para salir ingrese una letra: ");
	j=scanf("%d",&num);
	fflush(stdin);
	if(j==1)
	{
		f->num=num;
		f->liga=NULL;
		l=f;
		do
		{
			q=creaNodo();
			printf("Ingrese un numero, para salir ingrese una letra: ");
			j=scanf("%d",&num);
			fflush(stdin);
			if(j==1)
			{
				q->num=num;
				q->liga=NULL;
				l->liga=q;
				l=q;
			}
			else
			{
				free(q);
				break;
			}
		}while(j==1);
		printf("\n*****Creando Listas enlazada...*****");
		printf("\n");
		return f;
	}
	else
	{
		free(f);
		return(NULL);
	}
}

nodo* lista_3(nodo* p, nodo* f) 
{
	nodo *r = NULL;
	nodo* z = NULL;
	nodo* t = NULL;
	nodo* q = NULL;

	q = p;
	t = f;
	if (q== NULL) 
		return t;
	if (t == NULL) 
		return q;

	if (q->num > t->num) 
	{ // Cambio de operador de comparación
		z = creaNodo();
		r = creaNodo();
		z->num = t->num;
		r->num = q->num;
		z->liga = r;
		r->liga = lista_3(q->liga, t->liga);
	} 
	else 
	{
		z = creaNodo();
		r = creaNodo();
		r->num = t->num;
		z->num = q->num;
		z->liga = r;
		r->liga = lista_3(q->liga, t->liga);
	}

	return z;
}

void ordenarLista(nodo* z) {
	int band;
	nodo* v;
	nodo* l = NULL;
	
	if (z == NULL)
		return;
	
	do {
		band = 0;
		v = z;
		
		while (v->liga != l) {
            if (v->num < v->liga->num) {
					int temp = v->num;
					v->num = v->liga->num;
					v->liga->num = temp;
					band = 1;
            }
            v = v->liga;
		}
		
		l = v;
	} while (band);
}
