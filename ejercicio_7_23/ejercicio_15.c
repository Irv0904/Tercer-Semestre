/*
	Name:evualua un polinomio
	Copyright:Todos los derecho reservados 
	Author: Irving Jhon Villarreal Lasso
	Date: 23/05/23 14:24
	Description: Este codigo evalua un polinomio y da el resultado
	Calificacion:
*/
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<math.h>

struct cnodo{
	float coef;
	float expo;
	struct cnodo *liga;
};

typedef struct cnodo nodo;

void *creaMemoria(float n);
nodo *creaNodo();
nodo *ordenarLista_a(nodo* i); 
void iteractivo(nodo *i);
nodo *nodoFinal (nodo *i);
nodo *liberiaMemoria(nodo *i);
float evaluar (nodo *i, float x);

int main(){
	float num, expo, x, res;
	nodo *i=NULL;
	i=nodoFinal(i);
	iteractivo (i);
	i=ordenarLista_a(i);
	iteractivo (i);
	printf("Ingrese el valor de x: ");
	scanf("%f",&x);
	fflush(stdin);
	res=evaluar(i,x);
	//i=suma_polinomio(i);
	//iteractivoTotal(i);
	printf("El reultado es: %.1f ", res);
	i=liberiaMemoria(i);
}

void *creaMemoria(float n){
	void *i=(float *)malloc(n);
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
			if(v->expo==0)
				printf("%.1fx-> ", v->coef);
			else
				printf("%.1fx^%.0f -> ", v->coef,v->expo);
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


nodo *nodoFinal (nodo *i){
	float coef;
	float expo;
	int j;
	nodo *l,*v;
	i=creaNodo();
	i=creaNodo();
	printf("Ingrese un coeficiente: ");
	j=scanf("%f",&coef);
	printf("Ingrese un exponente: ");
	j=scanf("%f",&expo);
	fflush(stdin);
	if(j==1){
		i->coef=coef;
		i->expo=expo;
		i->liga=NULL;
		l=i;
		do{
			v=creaNodo();
			v=creaNodo();
			printf("\nIngrese un coeficiente:");
			j=scanf("%f",&coef);
			printf("Ingrese un exponente: ");
			j=scanf("%f",&expo);
			fflush(stdin);
			if(j==1){
				v->coef=coef;
				v->expo=expo;
				v->liga=NULL;
				l->liga=v;
				l=v;
			}
			else{
				free(v);
				break;
			}
		}while(j==1);
		printf("\n*****creando Listas enlazada...*****\n\n");
	}
	else{
		free(i);
		return(NULL);
	}
	return i;
}

float evaluar(nodo *i, float x)
{
	nodo *q=i;
	float res;
	if(q != NULL)
	{
		res=q->coef*pow(x,q->expo);
		res += evaluar(q->liga,x);
	}
	return res;
}

nodo *ordenarLista_a(nodo* i) 
{
	int band;
	nodo* v;
	nodo* l = NULL; 
	do {
		band = 0;
		v = i;
		while (v->liga != l) {
			if (v->expo < v->liga->expo) {
				int temp = v->expo;
				int temp2 = v->coef;
				v->expo=v->liga->expo;
				v->coef=v->liga->coef;
				v->liga->expo=temp;
				v->liga->coef=temp2;
				band = 1;
			}
			v = v->liga;
		}
		l = v;
	} while (band);
	return i;
}