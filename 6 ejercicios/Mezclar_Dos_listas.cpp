//PASO LA PRUEBA
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

nodo *lista_3(nodo *p, nodo *f, nodo *k);
void recursivo_3(nodo *k);
nodo *libera_lista_3(nodo *k);

int main(){
	nodo *p=NULL;
   nodo *f=NULL;
   nodo *k=NULL;

   printf("\t\t\tLista 1:\n");
	p=lista_1(p);
   recursivo_1(p);

   printf("\n\n\t\t\tLista 2:\n");
   f=lista_2(f);
   recursivo_2(f);

   printf("\n\n\t\t\tLista 3 y mezclada:\n");
   k=lista_3(p,f,k);
   recursivo_3(k);

   k=libera_lista_3(k);
   p=libera_lista_1(p);
   f=libera_lista_2(f);
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

void recursivo_3 (nodo *k)
{
	if(k != NULL)
   {
		printf("%5d->",k->num);
		if(k->liga!=NULL)
			recursivo_2 (k->liga);
		else
			printf("%s",k->liga);
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

nodo *libera_lista_3(nodo *k)
{
	nodo *q=NULL;
	if(k!=NULL)
	{
		while(k!=NULL)
		{
			q=k;
			k=k->liga ;
			q->liga= NULL;
			free(q);
		}
		printf("\n\n\t\t*****LA MEMORIA DE LA LISTA 3 HA SIDO LIBERADA...*****\n\n");
	}
	else
		printf("****NO HAY LISTA PARA LIBERADA...*****\n\n");
	//free(p);	
	return k;
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

nodo *lista_3(nodo *p, nodo *f, nodo *k)
{
   nodo *q, *t, *r,*e;
   q=p;
   t=f;
   k=creaNodo();
   k->num=q->num;
   k->liga=NULL;
   e=k;
   while((q->liga!=NULL)||(t->liga!=NULL))
   {
      q=q->liga;
      r=creaNodo();
      r->num=t->num;
      r->liga=NULL;
      e->liga=r;
      e=r;
      r=creaNodo();
      r->num=q->num;
      r->liga=NULL;
      e->liga=r;
      e=r;
      t=t->liga;
   }
   printf("\n*****creando Listas enlazada...*****\n\n");
   return(k);
}