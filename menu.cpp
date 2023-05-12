#include<stdio.h>
#include<stdlib.h>

struct datos{
	int num;
	struct datos *liga;
};

typedef struct datos  nodo;

void *creaMemoria(int n);
nodo *creaNodo();
void recursivo (nodo *i);
nodo *nodoFinal (nodo *i);
nodo *comienzo();
nodo *liberiaMemoria(nodo *i);

void desicion(){
	nodo *i = NULL;
	int opc;
	printf("Lo quieres\n1-> Crear lista enlazada desde inicio\n");
	printf("2-> Crear lista enlazada desde el final\n");
	scanf("%d",opc);
	switch(opc){
		case 1:
			i= comienzo();
		case 2:
	  		i = nodoFinal(i);
		default:
			printf("No hay error");	
	}		
}

/*void desicion(){
	int res;
	printf("\nEliga lo que usted quiera hacer\n");
	printf("\n1->INSERTAR UN NUMERO DESDE EL INICIO\n2->INSERTAR UN NUMERO DESDE EL FINAL\n");
	printf("3->INSERTA UN NUMERO ANTES DE...\n4->INSERTAR UN NUMERO DESPUES DE...\n");
	printf("5->ELIMINAR EL PRIMER NUMERO\n6->ELIMINAR EL ULTIMO NUMERO");
	printf("7->ELIMINAR UN NUMERO ANTES DE...\n8->BUSQUEDA DE UN NUMERO DESORDENADA\n");
	printf("9->BUSQUEDA DE UN NUMERO OREDENADA\n10->BUSQUEDA DE UN NUMERO RECURSIVO\n\nRESPUESTA: ");
	scanf("%d",&res);
	
	switch(res){
		case 1:
			des_den();
			break;
		case 2:
			des_den();
			break;
		case 3:
			des_den();
			break;
		case 4:
			des_den();
			break;
		case 5:
			des_den();
			break;
		case 6:
			des_den();
			break;
		case 7:
			des_den();
			break;
		case 8:
			des_den();
			break;
		case 9:
			des_den();
			break;
		case 10:
			des_den();
			break;
		default:
			printf("\nOpcion Invalida");

	}
}*/
	
int main(){
	printf("*******************************\n");
	printf("*Bienvenido a listas enalzadas*");
	printf("\n*******************************\n");
	desicion();
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

nodo *comienzo(){
	int num,j;
	nodo *i, *v;
	i = creaNodo();
	printf("\nIngrese un digito: ");
	j=scanf("%d",&num);
	fflush(stdin);
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
