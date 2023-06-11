
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
void recursivo(nodo *i);
nodo *nodoFinal (nodo *i);
int  verifica_orden_ascendente(nodo * i);
void ordenarLista(nodo*i);
nodo *liberiaMemoria(nodo *i);
nodo *insertar(nodo *i);
int verificacion(nodo *i, int num);

int main(){
	int num;
	nodo *i=NULL;
  	i=nodoFinal(i);
	recursivo(i);
	verificacion(i,num);
	return(0);

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
			recursivo (i);
			i=insertar(i);
			recursivo (i);
			printf("Dese ingresar mas nodos:\n\t\t0->NO\t 1->SI\n\t\tRespuesta:  ");
			scanf("%d", &ingr);
			fflush(stdin);
			while(ingr != 0)
			{
				system("CLS");
				recursivo (i);
				i=insertar(i);
				recursivo (i);
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
		i=insertar(i);
		recursivo (i);
		printf("Desea ingresar mas nodos:\n\t\t0->NO\t 1->SI\n\t\tRespuesta:  ");
		scanf("%d", &ingr);
		fflush(stdin);
		while(ingr != 0)
		{
			system("CLS");
			recursivo (i);
			i=insertar(i);
			recursivo (i);
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

void recursivo (nodo *i){
	if(i != NULL){
		printf("%5d->",i->num);
		if(i->liga!=NULL){
			recursivo (i->liga);
		}
		else{
			printf("%s",i->liga);
		}
	}
	else{
		printf("\n*****Lista Vacia...*****\n");
	}
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
	int j,num;
	nodo *l,*v;
	i=creaNodo();
	printf("\nIngrese un digito: ");
	j=scanf("%d",&num);
	fflush(stdin);
	if(j==1){
		i->num=num;
		i->liga=NULL;
		l=i;
		do{
			v=creaNodo();
			printf("Ingrese digito:");
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
		free(i);
		return(NULL);
	}
	return i;
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

nodo *insertar(nodo *i) {
	nodo *v,*l,*k;	
	int j,dato;
	int band =1;
	v=i;
	printf("\n\nIngrese el dato que va a insertar ");
	j=scanf("%d",&dato);
	fflush(stdin);
	if(j==1){
		while((v->num<dato)&&(band == 1))
		{
			if(v->liga!=NULL){
				l=v;
				v=v->liga;
			}
			else{
				band=0;
				break;
				}
		}
		if(band==1)
		{
			printf("4");
			if((l->num<dato)&&(v->num>dato)&&(v!=i))
			{
				k=creaNodo();
				k->num=dato;
				k->liga=v;
				l->liga=k;
			}
			else{
				if(v->num>dato)
				{
					printf("1");
					k=creaNodo();
					k->num=dato;
					k->liga=v;
					v=k;
					i=v;
				}
				else
					printf("\n\n\t\t\tYa existe ese nuemro\n\n");
			}
		}
		else{
			if((v->num < dato) and (v->liga == NULL))
			{
				k=creaNodo();
				k->num=dato;
				k->liga=NULL;
				v->liga=k;
			}
		}
		return(i);				
	}
}