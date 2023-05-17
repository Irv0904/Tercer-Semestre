//LE FALTA,REVISAR

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
nodo *liberiaMemoria(nodo *i);
nodo *eliminar_despues_x(nodo *i);
int main(){
	int num;
	nodo *i=NULL;
  	i= comienzo();
	iteractivo (i);
	i=eliminar_despues_x(i);
	iteractivo (i);
	i=eliminar_despues_x(i);
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
	fflush(stdin);
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

nodo *eliminar_despues_x(nodo *i) {
	nodo *v,*l,*t;
	int band=1,x,j;
	v=i;
	printf("Ingrese el numero de referencia: ");
	j=scanf("%d", &x);
	if(j==1){
		while((v->num!=x)&&(band=1))
		{
			if(v->liga!=NULL){
				l=v;
				v=v->liga;
			}
			else
			{
				band=0;
			}
		}
		if(band==0){
			printf("No existe numero despues...");
		}
		else
		{					
			t=v;
			v=v->liga;
			if(t->liga!=NULL)
			{
				t->liga=v->liga;
				v->liga=t;
			}
			else
			{
				printf("\nNo hay numero despues de la referencia\n");
			}
		}
		free (v);
	}
	return i;	
}
