//ESTE ES LA FINAL

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
nodo *eliminarFinal(nodo *p, nodo *f);
void iterativoDer(nodo *p);

nodo *liberamemoria(nodo *p);

int main(){
	nodo *p = NULL;
	nodo *f = NULL;
	
	//p = cfinaldb();
	p = ciniciodb();	
	f = buscarUltimo(p);
	printf("\n\t*Recorriendo hacia los dos lados*\n");
	iterativoDer(p);
	
	p=eliminarFinal(p,f);
	
	printf("\n\t*Recorriendo hacia los dos lados*\n");
	iterativoDer(p);
	liberamemoria(p);
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
		printf("\n\t\t*Memoria Liberada*\n");
	}
	else
		printf("\n\nLista vacia");
}

nodo *eliminarFinal(nodo *p,nodo *f)
{
	nodo *t=NULL;
	t=f;
	if(t->ligaizq!=NULL)
	{
		f=t->ligaizq;
		f->ligader=NULL;
	}
	else{
		f = NULL;
		p=NULL;
	}
	free();
	return (p);
}
