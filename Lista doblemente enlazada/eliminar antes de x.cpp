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
nodo *eliminar_antes_x(nodo *p, nodo *f, int x);
void iterativoDer(nodo *p);
nodo *liberamemoria(nodo *p);

int main(){
	nodo *p = NULL;
	nodo *f = NULL;
	int x,j;
	//p = cfinaldb();
	p = ciniciodb();	
	f = buscarUltimo(p);
	printf("\n\t******************************\n\t*Recorriendo hacia la derecha*\n\t******************************\n");
	iterativoDer(p);
	printf("Numero de referencia: ");
	j=scanf("%d",&x);
	fflush(stdin);
	if(j==1)
	{
		p=eliminar_antes_x(p,f,x);
		printf("\n\t******************************\n\t*Recorriendo hacia la derecha*\n\t******************************\n");
		iterativoDer(p);
		liberamemoria(p);
	}
	else
	{
		printf("404");
	}
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

nodo *cfinaldb()
{
	printf("\n\t\t\t*** Crear Final - Lista Doble ***\n");

	nodo *p = NULL;
	nodo *q = NULL;
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
		q = p;
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
				v->ligaizq = q;
				q->ligader = v;
				q = v;
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

void iterativoIzq(nodo *f)
{
	nodo *t = NULL;
	if(f != NULL)
	{
		t=f;
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

nodo *eliminar_antes_x(nodo *p,nodo *f, int x)
{
	nodo *q=NULL;
	nodo *k=NULL;
	nodo *a=NULL;
	q=p;
	while((q->ligader!=NULL)&&(q->num!=x))
	{
		q=q->ligader;
	}
	if(q->num==x)
	{
		if(p==q)
		{
			printf("NO hay nodo para eliminar");	
		}	
		else
		{
			k=q->ligaizq;
			if(p==k)
			{
				p=q;
				p->ligaizq=NULL;
			}
			else
			{
				a=k->ligaizq;
				q->ligaizq=a;
				a->ligader=q;
			}
		}
		free(k);
	}
	else
	{
		printf("No se encuentra");
	}
	return (p);
}
