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
nodo *elimina_despues_x(nodo *p, int x);
void iterativoDer(nodo *p);
nodo *liberamemoria(nodo *p);

int main(){
	nodo *p = NULL;
	nodo *f = NULL;
	int x;
	p = cfinaldb();
	//p = ciniciodb();	
	f= buscarUltimo(p);
	printf("\n\t******************************\n\t*Recorriendo hacia la derecha*\n\t******************************\n");
	iterativoDer(p);
	do{
		printf("hola y 0 para salir: ");
		scanf("%d", &x);
		fflush(stdin);
		p=elimina_despues_x(p,x);
		printf("\n\t******************************\n\t*Recorriendo hacia la derecha*\n\t******************************\n");
		iterativoDer(p);
	}while(x!=0);
	liberamemoria(p);
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
	printf("Ingrese el numero Letra para terminar: ");
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
			printf("Ingrese el numero Letra para terminar: ");
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

nodo *cfinaldb()
{
	printf("\n\t\t\t*** Crear Final - Lista Doble ***\n");

	nodo *p = NULL;
	nodo *l = NULL;
	nodo *q = NULL;
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
			q = creaNodo();
			printf("Introduzca un numero:");
			j = scanf("%d", &dato);
			fflush(stdin);
			if (j == 1)
			{
				q->num = dato;
				q->ligader = NULL;
				q->ligaizq = l;
				l->ligader = q;
				l = q;
			}
			else
			{
				free(q);
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

nodo *buscarUltimo(nodo *p)
{
	if(p!=NULL)
	{
		nodo *q=p;
		while(q->ligader!=NULL)
		{
			q = q->ligader;
		}
		return q;
	}
	return p;
}

void iterativoDer(nodo *p)
 {
 	nodo *t = NULL;
 	if(p != NULL)
	{
	 	t=p;
	 	printf("\n%s",t->ligaizq);
	 	while(t != NULL)
		 {
		 	printf("<-%d->", t->num);
		 	t = t->ligader;
		 }
		 printf("%s",t);
		 printf("\n");
	}
	else 
		printf("\n\tLista vacia...");
 }

void iterativoIzq(nodo *q)
{
	nodo *t = NULL;
	if(q != NULL)
	{
		t=q;
		printf("\n%s",t->ligader);
		while(t != NULL)
		{
			printf("<-%d->", t->num);
			t = t->ligaizq;
		}
		printf("%s",t);
		printf("\n\n");
	}
	else
		printf("\n Vacia");
}

nodo *liberamemoria(nodo *p)
{
	nodo *q = NULL;
	if(p != NULL)
	{
		while(p!=NULL)
		{
			q = p;
			p = p->ligader;
			q->ligader = NULL;
			free(q);
		}
		printf("\n\t\t******************\n\t\t*Memoria Liberada*\n\t\t******************");
	}
	else
		printf("\n\nLista vacia");
}

nodo *elimina_despues_x(nodo *p, int x)
{
	nodo *q = NULL;
	nodo *t = NULL;
	nodo *r = NULL; 
	nodo *f = NULL;
	f=p;
	
	while(f->ligader!=NULL)
	{
		f=f->ligader;
	}
	q=p;
	while((q->ligader != NULL)&&(q->num!=x))
	{
		q=q->ligader;	
	}
	if(q->num==x)
	{
		if((p==q)&&(p->ligader!=NULL))
		{
			t=p->ligader;
			if(t->ligader!=NULL)
			{
				r=t->ligader;
				p->ligader=r;
				t->ligaizq=NULL;
				t->ligader!=NULL;
				r->ligaizq=p;
			}
			else
			{
				p->ligader=NULL;
				t->ligaizq=NULL;
				p->ligader!=NULL;
			}
		}
		else
		{
			if(f==q)
			{
				printf("NO hay nodo para eliminar");
			}
			else
			{
				t=q->ligader;
				if(f==t)
				{
					r=q->ligaizq;
					t->ligaizq=NULL;
					q->ligader=NULL;
					q->ligaizq=r;
					r->ligader=q;
				}
				else
				{
					r=t->ligader;
					t->ligader=NULL;
					t->ligaizq=NULL;
					r->ligaizq=q;
					q->ligader=r;
				}
			}
		}
		free(t);
	}
	else
		printf("\nEl elmento no se encuentra\n");
	
	return p;
}
