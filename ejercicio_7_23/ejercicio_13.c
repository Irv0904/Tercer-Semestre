/*
	Name: Menu de listas doble
	Nota: 100
	Author: Irving Jhon Villarreal Lasso
	Date: 30/05/23 14:13
	Description: Se realizo un menu de todas la lista simple
*/
#include<stdio.h>
#include<stdlib.h>
#include<locale.h>

struct cnodo{
	int num;
	struct cnodo *ligader;
	struct cnodo *ligaizq;
};

typedef struct cnodo nodo;


void *creaMemoria(int n);
nodo *creaNodo();
nodo *cfinaldb(int x);

nodo *buscarUltimo(nodo *p);

void recursivoizq (nodo *p);
void recursivoder (nodo *p);

nodo *liberamemoriadb(nodo *p);

int main()
{
    int x;
	setlocale(LC_ALL,"");
	system("color 0F");
	nodo *p = NULL;
	nodo *f = NULL;
    printf("Ingrese el numero, letra para terminar: ");
    scanf("%d",&x);
    fflush(stdin);
    p = cfinaldb(x);

	recursivoder(p);
    f=buscarUltimo(p);
    printf("\n\n");
	recursivoizq(f);
}

void *creaMemoria(int n)
{
	void *p = (int *)malloc(n);
	if(p==NULL)
	{
		printf("No hay memoria");
		getchar();
		exit(1);
	}
    return p;
}

nodo *creaNodo()
{
	return(nodo *)creaMemoria(sizeof(nodo));
}


nodo *cfinaldb(int x)
{

	nodo *p = NULL;
	nodo *t = NULL;
	nodo *f = NULL;
	int j;
	p = creaNodo();
	p->ligaizq = NULL;
	p->ligader = NULL;
	p->num = x;
	t = p;
	do
	{
		f = creaNodo();
		printf("Introduzca un numero, letra para terminar:");
		j = scanf("%d", &x);
		fflush(stdin);
		if (j == 1)
		{
			f->num = x;
			f->ligader = NULL;
			f->ligaizq = t;
			t->ligader = f;
			t = f;
		}
		else
		{
			free(f);
			break;
		}
	} while (j == 1);
	return p;
}

nodo *liberamemoriadb(nodo *p)
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
		printf("\n\t\t>->->->->->->->->-");
		printf("\n\t\t|Memoria Liberada|*");
		printf("\n\t\t<-<-<-<-<-<-<-<-<-");
	}
	else
		printf("\n\nLista vacia");
	return p;
}

void recursivoder (nodo *p){
	if(p != NULL){
		printf("%d->",p->num);
		if(p->ligader!=NULL){
			recursivoder (p->ligader);
		}
		else{
			printf("%s",p->ligader);
		}
	}
	else{
		printf("\n*****Lista Vacia...*****\n");
	}
}

void recursivoizq (nodo *f){

	if(f != NULL){
		printf("%d->",f->num);
		if(f->ligaizq!=NULL){
			recursivoizq (f->ligaizq);
		}
		else{
			printf("%s",f->ligaizq);
		}
	}
	else{
		printf("\n*****Lista Vacia...*****\n");
	}
}

nodo *buscarUltimo(nodo *p)
{
	if(p!=NULL)
	{
		nodo *v=p;
		while(v->ligader!=NULL)
		{
			v = v->ligader;
		}
		return v;
	}
	return p;
}