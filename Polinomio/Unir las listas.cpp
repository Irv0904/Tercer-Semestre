/*
	Name:Menu de listas enlazadas 
	Copyright:Todos los derecho reservados 
	Author: Irving Jhon Villarreal Lasso
	Date: 23/05/23 14:24
	Description: Este codigo se usa para hacer un menu de diferentes partes de listas enlazadas
	Calificacion: 
*/

//23/05/23 14:24

#include<stdio.h>
#include<stdlib.h>
#include<locale.h>
struct cnodo
{
	int num;
	struct cnodo *liga;
};

typedef struct cnodo nodo;

void *creaMemoria(int n);
nodo *creaNodo();
nodo *comienzo();
nodo *nodoFinal (nodo *p);
void recursivo (nodo *p);
void iteractivo(nodo *p);
nodo *liberarMemoria(nodo *p);

int main()
{
	setlocale(LC_ALL,"");
	system("color 0F");
	nodo *p=NULL;
	int opc,lec,num;
	int x,j,k,ref;
	p=comienzo();
	iteractivo(p);
										
}

void *creaMemoria(int n)
{
	void *p=(int *)malloc(n);
	if(p==NULL)
	{
		printf("No hay memoria");
		getchar();
		exit(1);
	}
	return(p);
}

nodo *creaNodo()
{
	return(nodo *)creaMemoria(sizeof(nodo));
}



void iteractivo(nodo *p)
{
	nodo *q;
	if(p!=NULL)
	{
		printf("\n");
		for(q=p;q!=NULL;q=q->liga)
		{
			printf("%5d->", q->num);
		}
		printf("%s", q);
	printf("\n\n");
	}
	else
		printf("\n*****Lista vacia...*****\n\n");
	return;
}

nodo *liberarMemoria(nodo *p)
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
		
		printf("\n\n\t\t*****MEMORIA LIBERADA...*****\n\n");
	}
	else
	{
		
		printf("****NO HAY LISTA PARA LIBERADA...*****\n\n");
	}
	//free(p);	
	return p;
}

nodo *comienzo()
{
	int num,j;
	nodo *p, *q;
	p = creaNodo();
	printf("Ingrese un número, para salir ingrese una letra: ");
	j=scanf("%d",&num);
	fflush(stdin);
	if(j == 1)
	{
		p ->num = num;
		p -> liga=NULL;	
		
		do
		{
		q= creaNodo();
		printf("Ingrese un número, para salir ingrese una letra: ");
		j=scanf("%d", &num);
		fflush(stdin);
		if (j == 1)
		{
			q->num = num;
			q->liga=p;
			p=q;
		}
		else
		{
			free(q);
			break;
		}
		}while(j ==1);
		printf("\n*****Creando Listas enlazada...*****\n");
		printf("\n");
		q=p;
		return p;
	}
	else
	{
		free(p);
		return (NULL);
	}	
}

nodo *nodoFinal (nodo *p)
{
	int j,num;
	nodo *l,*q;
	p=creaNodo();
	printf("Ingrese un número, para salir ingrese una letra: ");
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
			printf("Ingrese un número, para salir ingrese una letra: ");
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
