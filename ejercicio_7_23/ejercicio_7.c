/*	
	Nombre: Lista Simple con Inserta Despues con Lista Ordenada y Verificacion de Lista
	Autor: Irving Jhon Villarreal
	Fecha de entrega: 13/06/2023
	Nota:
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

nodo *lista_2(nodo *p);
void recursivo_2(nodo *z);
nodo *libera_lista_2(nodo *z);

nodo *lista_3(nodo *p);
void recursivo_3(nodo *f);
nodo *libera_lista_3(nodo *z);

int main()
{
    nodo *z = NULL;
	nodo *p = NULL;
    nodo *f = NULL;
	printf("\t\t\tLista 1:\n");
	p=lista_1(p);
	recursivo_1(p);
    printf("\n");

    z = lista_2(p);
    recursivo_2(z);
    printf("\n");

    f = lista_3(p);
    recursivo_3(f);    
    printf("\n");

	p = libera_lista_1(p);
    z = libera_lista_2(z);
    f = libera_lista_3(f);

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

void recursivo_3(nodo *f)
{
	if(f != NULL)
	{
		printf("%5d->",f->num);
		if(f->liga!=NULL)
			recursivo_1 (f->liga);
		else
			printf("%s",f->liga);
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

nodo *lista_1 (nodo *p)
{
	int j,num;
	nodo *l,*q;
	p=creaNodo();
	printf("Ingrese un numero: ");
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
			printf("Ingrese un numero: ");
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


void recursivo_2(nodo *z)
{
	if(z != NULL)
	{
		printf("%5d->",z->num);
		if(z->liga!=NULL)
			recursivo_1 (z->liga);
		else
			printf("%s",z->liga);
	}
	else
		printf("\n*****Lista Vacia...*****\n");
}

nodo *lista_2(nodo *p)
{
	nodo *z = NULL;
	nodo *q = NULL;
	nodo *r = NULL;
	q = p;
	if (q != NULL) {
		while (q != NULL)
        {
			if (q->num > 0)
            {
				if (z == NULL)
                {
					z = creaNodo();
					r = z;
				} 
                else
                {
					r->liga = creaNodo();
					r = r->liga;
				}
				r->num = q->num;
				r->liga = NULL;
			}
			q = q->liga;
		}
		printf("\n*****Creando Lista Enlazada Positiva...*****\n");
	}
	return z;
}

nodo *libera_lista_2(nodo *z)
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
		printf("\n\n\t\t*****LA MEMORIA DE LA LISTA 2 HA SIDO LIBERADA...*****\n\n");
	}
	else
		printf("****NO HAY LISTA PARA LIBERADA...*****\n\n");
	//free(p);	
	return z;
}

nodo *libera_lista_3(nodo *f)
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
		printf("\n\n\t\t*****LA MEMORIA DE LA LISTA 3 HA SIDO LIBERADA...*****\n\n");
	}
	else
		printf("****NO HAY LISTA PARA LIBERADA...*****\n\n");
	//free(p);	
	return f;
}


nodo *lista_3(nodo *p)
{
	nodo *f = NULL;
	nodo *q = NULL;
	nodo *r = NULL;
	q = p;
	if (q != NULL) {
		while (q != NULL)
        {
			if (q->num < 0)
            {
				if (f == NULL)
                {
					f = creaNodo();
					r = f;
				} 
                else
                {
					r->liga = creaNodo();
					r = r->liga;
				}
				r->num = q->num;
				r->liga = NULL;
			}
			q = q->liga;
		}
		printf("\n*****Creando Lista Enlazada Negativa...*****\n");
	}
	return f;
}