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
nodo *insertePrincipio(nodo *p);
void iterativoDer(nodo *p);
void iterativoIzq(nodo *v);

nodo *liberamemoria(nodo *p);

int main(){
	nodo *p = NULL;
	nodo *v = NULL;
	
	p = cfinaldb();
	//p = ciniciodb();	
	v = buscarUltimo(p);
	printf("\n\t******************************\n\t*Recorriendo hacia la derecha*\n\t******************************\n");
	iterativoDer(p);

	p=insertePrincipio(p);
	printf("\n\t******************************\n\t*Recorriendo hacia la derecha*\n\t******************************\n");
	iterativoDer(p);

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
		nodo *v=p;
		while(v->ligader!=NULL)
		{
			v = v->ligader;
		}
		return v;
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



	int j,ref,x;
	printf("Ingrese el numero de referencia: ");
	scanf("%d",&ref);
	fflush(stdin);
	printf("Ingrese el nuevo numero: ");
	j = scanf("%d",&x);
	fflush(stdin);
	if(j==1)
	{




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

nodo *insertePrincipio(nodo *p)
{
	nodo *v = NULL;
	nodo *l = NULL;
	nodo *k = NULL; 
	int j,dato,x;
	printf("Ingrese el numero de referencia: ");
	scanf("%d",&x);
	fflush(stdin);
	printf("Ingrese el nuevo numero: ");
	j = scanf("%d",&dato);
	fflush(stdin);
	if(j==1)
	{
		v=p;
		while((v->ligader != NULL)&&(v->num!=x))
		{
			v=v->ligader;	
		}
		if(v->num==x)
		{
			l=creaNodo();
			l->num=dato;
			l->ligader=v;
			k=v->ligaizq;
			v->ligaizq=l;
			if(p==v)
			{
				p=l;
				l->ligaizq=NULL;
			}
			else
			{
				k->ligader=l;
				l->ligaizq=k;	
			}
		}
		else
			printf("\nEl elmento no se encuentra\n");
		

	}
	return p;
}
