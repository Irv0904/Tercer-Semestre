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
void recursivo (nodo *p);
nodo *nodoFinal (nodo *p);
nodo *liberiaMemoria(nodo *p);
nodo *busqueda_recursiva(nodo *p,int num);
int main(){
	//int num;
	nodo *p=NULL;
	p=nodoFinal(p);
	recursivo(p);
	p=liberiaMemoria(p);
}

void *creaMemoria(int n){
	void *p=(int *)malloc(n);
	if(p==NULL){
		printf("No hay memoria");
		getchar();
		exit(1);
	}
	return(p);
}

nodo *creaNodo(){
	return(nodo *)creaMemoria(sizeof(nodo));
} 

void recursivo (nodo *p){
	if(p != NULL){
		printf("%5d->",p->num);
		if(p->liga!=NULL){
			recursivo (p->liga);
		}
		else{
			printf("%s",p->liga);
		}
	}
	else{
		printf("\n*****Lista Vacia...*****\n");
	}
}

nodo *liberiaMemoria(nodo *p){
	nodo *v=NULL;
	if(p!=NULL){
		while(p!=NULL){
			v=p;
			p=p->liga ;
			v->liga= NULL;
			free(v);
		}
		printf("\n\n*****MEMORIA LIBERADA...*****\n");
	}
	else
		printf("\n*****LISTA LIBERADA...*****\n\n");
	return(p);
}

nodo *nodoFinal (nodo *p){
	int j,num;
	nodo *l,*v;
	p=creaNodo();
	printf("\nIngrese un digito: ");
	j=scanf("%d",&num);
	fflush(stdin);
	if(j==1){
		p->num=num;
		p->liga=NULL;
		l=p;
		do{
			v=creaNodo();
			printf("Ingrese un digito:");
			j=scanf("%d",&num);
			fflush(stdin);
			if(j==1){
				v->num=num;
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
		free(p);
		return(NULL);
	}
	return p;
}