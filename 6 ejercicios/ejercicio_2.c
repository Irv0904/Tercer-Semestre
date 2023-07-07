/*	
	Nombre: Lista Simple con Inserta Despues con Lista Ordenada y Verificacion de Lista
	Autor: Irving Jhon Villarreal
	Hora de entrega: 13/06/2023
	Nota:100
*/
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

struct cnodo{
	int num;
	struct cnodo *liga;
};

typedef struct cnodo nodo;

void *creaMemoria(int n);
nodo *creaNodo();
void iteractivo(nodo *i);
nodo *nodoFinal (nodo *i);
int  verifica_orden_ascendente(nodo * i);
void ordenarLista(nodo*i);
nodo *liberiaMemoria(nodo *i);
nodo *insertar_despues_x(nodo *i);
int verificacion(nodo *i, int num);

int main(){
	int num;
	nodo *i=NULL;
	i=nodoFinal(i);
	iteractivo (i);
	verificacion(i,num);
	return(0);
}

int verificacion(nodo *i, int num)
{
	int ingr;
	//nodo *i=NULL;
	int quiere;
	num = verifica_orden_ascendente(i);
	if(num==1)
	{
		printf("\n\n\t\tNO esta ordenada\n\n");
		printf("\n\tQuiere ordena la Lista e ingresar datos\n\t\t1-Si o 2-NO\n\t\tRespuesta:");
		scanf("%d", & quiere);
		fflush(stdin);
		if(quiere == 1)
		{
			ordenarLista(i);
			iteractivo (i);
			i=insertar_despues_x(i);
			iteractivo (i);
			printf("Dese ingresar mas nodos:\n\t\t0->NO\t 1->SI\n\t\tRespuesta:  ");
			scanf("%d", &ingr);
			fflush(stdin);
			while(ingr != 0)
			{
				system("CLS");
				iteractivo (i);
				i=insertar_despues_x(i);
				iteractivo (i);
				printf("Desea ingresar mas nodos:\n\t\t0->NO\t1->SI\n\t\tRespuesta:  ");
				scanf("%d", &ingr);
				fflush(stdin);
			}
			i=liberiaMemoria(i);
		}
		else
		{
			i=liberiaMemoria(i);
		}
	}
	else
	{
		printf("SI esta ordenada\nSigamos...");
		//ordenarLista(i);
		//iteractivo (i);
		i=insertar_despues_x(i);
		iteractivo (i);
		printf("Desea ingresar mas nodos:\n\t\t0->NO\t 1->SI\n\t\tRespuesta:  ");
		scanf("%d", &ingr);
		fflush(stdin);
		while(ingr != 0)
		{
			system("CLS");
			iteractivo (i);
			i=insertar_despues_x(i);
			iteractivo (i);
			printf("Dese ingresar mas nodos:\n\t\t0->NO\t1->SI\n\t\tRespuesta:  ");
			scanf("%d", &ingr);
			fflush(stdin);
		}
		i=liberiaMemoria(i);
	}
	return 0;
}

void *creaMemoria(int n){
	void *i=(int *)malloc(n);
	if(i==NULL){
		printf("No hay memoria");
		getchar();
		exit(1);
	}
	return(i);
}

nodo *creaNodo(){
	return(nodo *)creaMemoria(sizeof(nodo));
} 

void iteractivo(nodo *i){
	nodo *v;
	if(i!=NULL){
		printf("\n");
		for(v=i;v!=NULL;v=v->liga){
			printf("%5d->", v->num);
		}
		printf("%s", v);
	printf("\n\n");
	}
	else
		printf("\n*****Lista vacia...*****\n");
	return;
}

nodo *liberiaMemoria(nodo *i){
	nodo *v=NULL;
	if(i!=NULL){
		while(i!=NULL){
			v=i;
			i=i->liga ;
			v->liga= NULL;
			free(v);
		}
		printf("\n\n*****MEMORIA LIBERADA...*****\n");
	}
	else
		printf("\n*****LISTA LIBERADA...*****\n\n");
	return(i);
}

nodo *nodoFinal (nodo *i)
{
	int j,num;
	nodo *l,*q;
	i=creaNodo();
	printf("Ingrese un numero, para salir ingrese una letra: ");
	j=scanf("%d",&num);
	fflush(stdin);
	if(j==1)
	{
		i->num=num;
		i->liga=NULL;
		l=i;
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
		return i;
	}
	else
	{
		free(i);
		return(NULL);
	}
}

int verifica_orden_ascendente(nodo *i)
{
	nodo *q,*t;
	q= i;
		
	while ( q->liga != NULL)
	{
			
		t=q->liga;
		
		do{
			if( q->num <= t->num)
			{
				t = t->liga;
			}
			else return (1);
		}while (t != NULL);
		q = q->liga;   
		}
		
	return (0);	
}

void ordenarLista(nodo* i) {
	int band;
	nodo* v;
	nodo* l = NULL;
	
	if (i == NULL)
		return;
	
	do {
		band = 0;
		v = i;
		
		while (v->liga != l) {
            if (v->num > v->liga->num) {
					int temp = v->num;
					v->num = v->liga->num;
					v->liga->num = temp;
					band = 1;
            }
            v = v->liga;
		}
		
		l = v;
	} while (band);
}

nodo *insertar_despues_x(nodo *i)
{
	nodo *v,*l;
	int band=1,j,dato,x;
	v=i;
	printf("\nIngrese el numero de referencia: ");
	scanf("%d", &x);
	printf("\nIngrese el numero: ");
	j=scanf("%d", &dato);
	if(j==1)
	{
		while((v->num!=x)&&(band==1)){
			if(v->liga!=NULL){
				v=v->liga;
			}
			else{
				band=0;
			}
		}
		if(band==1){
			if(v->num<dato)
			{
				l=creaNodo();
				l->num=dato;
				l->liga=v->liga;
				v->liga=l;
			}
			else
			{
				printf("\n\n***\tEl numero que ingreso es invalido\n\n");
			}
		}
		else{
			printf("\ndado com referencia es nulo");
		}
	}
	return i;	
}