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
nodo *buscarUltimo(nodo *i);
nodo *insertePrincipio(nodo *i, nodo *z);
void iterativoDer(nodo *i);
void iterativoIzq(nodo *z);

nodo *liberamemoria(nodo *i);

int main(){
	nodo *i = NULL;
	nodo *z = NULL;
	
	//i = cfinaldb();
	i = ciniciodb();	
	z = buscarUltimo(i);
	printf("\n\t******************************\n\t*Recorriendo hacia la derecha*\n\t******************************\n");
	iterativoDer(i);
	printf("\n\t********************************\n\t*Recorriendo hacia la izquierda*\n\t********************************\n");	
	iterativoIzq(z);
	i=insertePrincipio(i,z);
	printf("\n\t******************************\n\t*Recorriendo hacia la derecha*\n\t******************************\n");
	iterativoDer(i);
	printf("\n\t********************************\n\t*Recorriendo hacia la izquierda*\n\t********************************\n");	
	iterativoIzq(z);
	liberamemoria(i);
	return 0;
}

void *creaMemoria(int n)
{
	void *i = (int *)malloc(n);
	if(i==NULL)
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
	nodo *i = NULL; nodo *k =NULL;
	int dato, j;
	
	i = creaNodo();
	printf("Ingrese el numero Letra para terminar: ");
	j = scanf("%d",&dato);
	fflush(stdin);
	if(j==1)
	{
		i->num = dato;
		i->ligader = NULL;
		i->ligaizq = NULL;
		do
		{
			k=creaNodo();
			printf("Ingrese el numero Letra para terminar: ");
			j = scanf("%d",&dato);
			fflush(stdin);
			if(j == 1)
			{
				k->num=dato;
				k->ligader=i;
				i->ligaizq=k;
				k->ligaizq=NULL;
				i=k;
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
		free (i);
		return NULL;
	}
	return i;
}

nodo *cfinaldb()
{
	printf("\n\t\t\t*** Crear Final - Lista Doble ***\n");

	nodo *i = NULL;
	nodo *l = NULL;
	nodo *v = NULL;
	int dato, j;

	i = creaNodo();
	printf("Introduzca un numero:");
	j = scanf("%d", &dato);
	fflush(stdin);

	if (j == 1)
	{
		i->ligaizq = NULL;
		i->ligader = NULL;
		i->num = dato;
		l = i;
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
		free(i);
		return NULL;
	}

	return i;
}

nodo *buscarUltimo(nodo *i)
{
	if(i!=NULL)
	{
		nodo *z=i;
		while(z->ligader!=NULL)
		{
			z = z->ligader;
		}
		return z;
	}
	return i;
}

void iterativoDer(nodo *i)
 {
 	nodo *t = NULL;
 	if(i != NULL)
	{
	 	t=i;
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

void iterativoIzq(nodo *z)
{
	nodo *t = NULL;
	if(z != NULL)
	{
		t=z;
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

nodo *liberamemoria(nodo *i)
{
	nodo *v = NULL;
	if(i != NULL)
	{
		while(i!=NULL)
		{
			v = i;
			i = i->ligader;
			v->ligader = NULL;
			free(v);
		}
		printf("\n\t\t******************\n\t\t*Memoria Liberada*\n\t\t******************");
	}
	else
		printf("\n\nLista vacia");
}

nodo *insertePrincipio(nodo *i,nodo *z)
{
	nodo *l=NULL;
	nodo *k=NULL;
	nodo *a=NULL;
	int x;
	printf("Ingrese: ");
	scanf("%d",&x);
	
	l=i;
	while((l->ligader!=NULL)&&(l->num!=x))
	{
		l=l->ligader;
	}
	if(l->num==x)
	{
		if((l==i)&&(l==z))
		{
			i=NULL;
			z=NULL;
		}
		else
		{
			if(l==i)
			{
				i=l->ligader;
				i->ligaizq=NULL;	
			}
			else
			{
				if(l==z)
				{
					z=l->ligaizq;
					z->ligader=NULL;	
				}
				else
				{
					k=l->ligaizq;
					a=l->ligader;
					k->ligader=a;
					a->ligaizq=k;
				}
			}
		}
		free(l);
	}
	else
	{
		printf("No se encuentra");
	}
	return (i);
}
