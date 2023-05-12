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
nodo *comienzo();
nodo *liberiaMemoria(nodo *i);
nodo *elmininar_x(nodo *i);
int main(){
	int des;
	nodo *i=NULL;
  	i= comienzo();
	iteractivo (i);
	i=elmininar_x(i);
	iteractivo (i);
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
		printf("\n\t*****creando Listas enlazada...*****\n");
	}
	else{
		free(i);
		return (NULL);
	}
	v=i	;
	return i;	
}

nodo *elmininar_x(nodo *i) {
	nodo *v,*l;	
	int ver,x,BAND =1;
	v=i;
	printf("Ingrese el dato que va a el:iminar ");
	ver=scanf("%d",&x);
	fflush(stdin);
	if(ver==1){
		while((v->num!=x)&&(BAND == 1))
		{
			if(v->liga!=NULL){
				l=v;
				v=v->liga;
			}
			else{
				BAND=0;
			}
		}
		if(BAND==0){
			printf("\nEl dato %d no se encuentra para eliminar",x);
		}
		else{
			if(i==v){
				i=v->liga;
			}
			else{
				l->liga=v->liga;
			}
		}
		free(v);
	}
	return(i);
}

