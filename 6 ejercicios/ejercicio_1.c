/*	
	Nombre: Lista Simple con Inserta Despues con Lista Ordenada y Verificacion de Lista
	Autor: Irving Jhon Villarreal
	Fecha de entrega: 13/06/2023
	Nota: 100
*/
#include<stdio.h>
#include<stdlib.h>

struct cnodo{
	int num;
	struct cnodo *liga;
};

typedef struct cnodo nodo;

void *creaMemoria(int n);
nodo *creaNodo();
void iteractivo(nodo *i);
nodo *comienzo();
int  verifica_orden_ascendente(nodo * i);
void ordenarLista(nodo*i);
int verificacion(nodo *i, int num);
nodo *nodoFinal (nodo *i);
//void recursivo (nodo *i);
nodo *liberiaMemoria(nodo *i);
nodo *insertar_antes_x(nodo *i);

int main(){
	int num;
	nodo *i=NULL;
	i=comienzo();
	iteractivo (i);
	verificacion(i,num);
	return 0;
}

int verificacion(nodo *i, int num)
{
	int ingr;
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
			i=insertar_antes_x(i);
			iteractivo (i);
			printf("Dese ingresar mas nodos:\n\t\t0->NO\t 1->SI\n\t\tRespuesta:  ");
			scanf("%d", &ingr);
			fflush(stdin);
			while(ingr != 0)
			{
				system("CLS");
				iteractivo (i);
				i=insertar_antes_x(i);
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
		printf("\n\t\t\tSI esta ordenada\n\t\t\tSigamos...");
		i=insertar_antes_x(i);
		iteractivo (i);
		printf("Desea ingresar mas nodos:\n\t\t0->NO\t 1->SI\n\t\tRespuesta:  ");
		scanf("%d", &ingr);
		fflush(stdin);
		while(ingr != 0)
		{
			system("CLS");
			iteractivo (i);
			i=insertar_antes_x(i);
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

nodo *comienzo(){
	int num,j;
	nodo *i, *v;
	i = creaNodo();
	printf("\nIngrese un dato: ");
	j=scanf("%d",&num);
	fflush(stdin);
	if(j == 1){
		i ->num = num;
		i -> liga=NULL;	
		do{
		v= creaNodo();
		printf("Ingrese un dato: ");
		j=scanf("%d", &num);
		fflush(stdin);
		if (j == 1){
			v->num = num;
			v->liga=i;
			i=v;
		}
		else{
			free(v);
			break;
		}
		}while(j ==1);
		printf("\n*****creando Listas enlazada...*****\n");
	}
	else
	{
		free(i);
		return (NULL);
	}
	v=i	;
	return i;	
}

void ordenarLista(nodo* i)
{
	int band;
	nodo* v;
	nodo* l = NULL;
	if (i == NULL)
		return;
	do
	{
		band = 0;
		v = i;
		while (v->liga != l) {
			if (v->num < v->liga->num)
			{
				int temp = v->num;
				v->num = v->liga->num;
				v->liga->num = temp;
				band = 1;
			}
			v = v->liga;
		}
		l = v;
	}while (band);
}

int verifica_orden_ascendente(nodo *i)
{
	nodo *q, *t;
	q= i;
	while ( q->liga != NULL)
	{
		t=q->liga;
		do
		{
			if( q->num >= t->num)
			{   
				q=t;
				t = t->liga;
			}
			else return (1);
		}while (t != NULL);		  
	}// fin deldo while
	return (0);
}

nodo *insertar_antes_x(nodo *i)
{
	nodo *v,*l,*k;
	int band=1,j,dato,x;
	v=i;
	printf("\nIngrese el dato de referencia: ");
	scanf("%d",&x);
	printf("Ingrese el numero: ");
	j=scanf("%d",&dato);
	if(j==1)
	{
		while((v->num!=x)&&(band==1)){
			if(v->liga!=NULL){
				l=v;
				v=v->liga;
			}
			else{
				band=0;
				break;
				}
		}
		printf("%d", band);
		if(band==1){
			if(i==v)
			{
				k=creaNodo();
				k->num=dato;
				//printf("1");
				k->liga=i;
				i=k;
			}
			else
			{
				if((l->num>dato)&&(v->num<dato))
				{
					printf("1");
					k=creaNodo();
					k->num=dato;
					l->liga=k;
					k->liga=v;
				}
				else
					printf("\n\n***\tEl numero que ingreso es invalido\n\n");
			}
		}
	}
	else
		printf("El numero dado no se encuentra");
	return i;
}