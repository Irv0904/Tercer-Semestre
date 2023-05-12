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
void recursivo (nodo *i);
nodo *nodoFinal (nodo *i);
nodo *comienzo();
nodo *liberiaMemoria(nodo *i);

void desicion() {
	nodo *i =NULL;
    int des;
    printf("\nOperaciones en lista enlazada simple:\n");
	printf("1. Desde Inicio\n");
    printf("2. Desde Final\n");
    printf("3. Al menu\n");
    printf("Ingrese su eleccion: ");
    scanf("%d", &des);

    switch (des) {
        case 1:
  			i= comienzo();
			printf("\nRecorriendo la lista desde el inicio: \n");	
			recursivo (i);
			break;
        
	    case 2:
			i=nodoFinal(i);
			printf("\n\nRecorriendo la lista desde final:\n ");
			recursivo (i);
			break;
        case 3:
        	i= comienzo();
			i=nodoFinal(i);
			break;
        default:
                printf("Opcion invalida\n");
        }
    } 	

int main(){
	int des;
	nodo *i=NULL;
	desicion();
	i=liberiaMemoria(i);
	
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

nodo *comienzo(){
	int num,j;
	nodo *i, *v;
	i = creaNodo();
	printf("\nIngrese un digito: ");
	j=scanf("%d",&num);
	//fflush(stdin);
	if(j == 1){
		i ->num = num;
		i -> liga=NULL;	
		
		do{
		v= creaNodo();
		printf("Ingrese dato: ");
		j=scanf("%d", &num);
		//fflush(stdin);
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
	else{
		free(i);
		return (NULL);
	}
	v=i	;
	return i;	
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
		printf("\n*****creando Listas enlazada...*****");
	
	}
	else{
		free(i);
		return(NULL);
	}
	return i;
}
