//PASO LA PRUEBA

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
nodo *nodoFinal (nodo *i);
void recursivo (nodo *i);
nodo *liberiaMemoria(nodo *i);
nodo *elmininar_x(nodo *i);
int main(){
	int num;
	nodo *i=NULL;
  	i=nodoFinal(i);
	recursivo(i);
	//i= comienzo();
	//iteractivo (i);
	i=elmininar_x(i);
	//iteractivo (i);
	recursivo(i);
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

/*void iteractivo(nodo *i){
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
}*/

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

/*nodo *comienzo(){
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
}*/

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

nodo *elmininar_x(nodo *i) {
	nodo *v,*l;	
	int j,num;
	int band =1;
	v=i;
	printf("\n\nIngrese el dato que va a eliminar ");
	j=scanf("%d",&num);
	fflush(stdin);
	if(j==1){
		while((v->num!=num)&&(band == 1))
		{
			if(v->liga!=NULL){
				l=v;
				v=v->liga;
			}
			else
				band=0;	
		}
		if(band==0)
			printf("\n\nEl dato %d no se encuentra para eliminar",num);
		else{
			if(i==v){
				i=v->liga;
			}
			else{
				l->liga=v->liga;
				printf("\n\t*****Actualizando lista enlazada...*****\n");
			}
		}
		
		free(v);
		return(i);				
	}
}