//Paso la prueba

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
nodo *ciniciodb();
nodo *cfinaldb();
nodo *buscarUltimo(nodo *p);
void recursivoizq (nodo *f);
void recursivoder (nodo *p);
nodo *liberamemoria(nodo *p);

int main(){
	nodo *p = NULL;
	nodo *f = NULL;
	int x,j;
	//p = cfinaldb();
	p = ciniciodb();	
	f = buscarUltimo(p);
	printf("\n\t******************************\n\t*Recorriendo hacia la derecha*\n\t******************************\n");
	printf("%s->",p->ligaizq);
	recursivoder (p);
	printf("\n");
	printf("\n\t********************************\n\t*Recorriendo hacia la izquierda*\n\t********************************\n");
	printf("%s->",p->ligaizq);
	recursivoizq (f);
	return 0;
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
}

nodo *creaNodo()
{
	return(nodo *)creaMemoria(sizeof(nodo));
}

nodo *ciniciodb()
{
	nodo *p = NULL; nodo *k =NULL;
	int dato, j;
	
	p = creaNodo();
	printf("Ingrese el numero, Letra para terminar: ");
	j = scanf("%d",&dato);
	fflush(stdin);
	if(j==1)
	{
		p->num = dato;
		p->ligader = NULL;
		p->ligaizq = NULL;
		do
		{
			k=creaNodo();
			printf("Ingrese el numero, Letra para terminar: ");
			j = scanf("%d",&dato);
			fflush(stdin);
			if(j == 1)
			{
				k->num=dato;
				k->ligader=p;
				p->ligaizq=k;
				k->ligaizq=NULL;
				p=k;
			}
			else
			{
				free(k);
				break;
			}
		}while(j==1);
	}
	else
	{
		free (p);
		return NULL;
	}
	return p;
}

nodo *buscarUltimo(nodo *p)
{
	if(p!=NULL)
	{
		nodo *f=p;
		while(f->ligader!=NULL)
		{
			f = f->ligader;
		}
		return f;
	}
	return p;
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
}

void recursivoder (nodo *p){
	if(p != NULL){
		printf("%d-><-",p->num);
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
		printf("%d-><-",f->num);
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

